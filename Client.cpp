/*
 * Client.cpp
 *
 *  Created on: Sep 25, 2014
 *      Author: wangli
 */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <signal.h>
#include "./startup.h"
#include "Client/ClientResponse.h"
#include "Client/Client.h"
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include "common/log/logging.h"
#include "common/Block/ResultSet.h"
#include "utility/command_line.h"
#include "utility/rdtsc.h"
#include "krb5.h"
#include "com_err.h"

void readStrigFromTerminal(string &input) {
  while (true) {
    std::cin.clear();
    std::cin.sync();
    std::string str;
    if (getline(std::cin, str)) {
      bool finish = false;
      for (unsigned i = 0; i < str.length(); i++) {
        if (str[i] == ';') {
          input += str.substr(0, i + 1);
          finish = true;
          break;
        }
      }
      if (finish) break;
      input += str + " ";
    }
  }
}

void submit_command(Client &client, std::string &command, const int &num) {
  bool flag = false;
  if (client.submit(command)) {
    for (int i = 0; i < num; ++i) {
      if (flag) break;
      std::string message;
      ResultSet rs;
      switch (client.getResute(message, rs)) {
        case Client::result:
          rs.print();
          //				if(i!=0)
          //					total_time+=rs.query_time_;
          break;
        case Client::message:
          printf("%s\n", message.c_str());
          break;
        case Client::error:
          printf(
              "\e[0;31m"
              "%s\033[0m\n",
              message.c_str());
          flag = true;
          // truncate();
          break;
        default:
          assert(false);
          break;
      }
    }
  }
  //  switch (client.submit(command, message, rs)) {
  //    case Client::result:
  //      rs.print();
  //      //				if(i!=0)
  //      //					total_time+=rs.query_time_;
  //      break;
  //    case Client::message:
  //      printf("%s", message.c_str());
  //      break;
  //    case Client::error:
  //      printf(
  //          "\e[0;31m"
  //          "%s\033[0m\n",
  //          message.c_str());
  //      break;
  //    default:
  //      assert(false);
  //      break;
  //  }
}

void submit_command_repeated(Client &client, std::string &command,
                             int repeated) {
  double total_time = 0;
  for (int i = 0; i < repeated; i++) {
    ResultSet rs;
    std::string message;
    switch (client.submit(command, message, rs)) {
      case Client::result:
        if (i != 0) total_time += rs.query_time_;
        break;
      case Client::message:
        printf("%s", message.c_str());
        break;
      case Client::error:
        printf(
            "\e[0;31m"
            "%s\033[0m\n",
            message.c_str());
        break;
      default:
        assert(false);
        break;
    }
  }
}
void PrintUsage() {
  cout << "Welcome to use CLAIMS. " << endl;
  cout << "Type: " << endl;
  cout << "\t help; for usage of CLAIMS." << endl;
  cout << "\t copyright; for distribution terms." << endl;
  cout << "\t exit; or shutdown; for exiting CLAIMS." << endl;
}

void PrintCopyright() {
  cout << "Copyright [2012-2015] DaSE@ECNU " << endl
       << " Licensed to the Apache Software Foundation (ASF) under one or more"
       << " contributor license agreements.  See the NOTICE file distributed "
          "with"
       << " this work for additional information regarding copyright ownership."
       << " The ASF licenses this file to You under the Apache License, "
          "Version 2.0"
       << " (the \" License\"); you may not use this file except in compliance "
          "with"
       << " the License.  You may obtain a copy of the License at" << endl
       << "     http://www.apache.org/licenses/LICENSE-2.0" << endl
       << " Unless required by applicable law or agreed to in writing, software"
       << " distributed under the License is distributed on an \" AS IS \" "
          "BASIS,"
       << " WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or "
          "implied."
       << " See the License for the specific language governing permissions and"
       << " limitations under the License." << endl;
}

static int net_read(int fd, char *buf, int len) {
  int cc, len2 = 0;

  do {
    cc = read((int)fd, buf, len);
    if (cc < 0) {
      if ((*__errno_location()) == 4) continue;

      /* XXX this interface sucks! */
      errno = (*__errno_location());

      return (cc); /* errno is already set */
    } else if (cc == 0) {
      return (len2);
    } else {
      buf += cc;
      len2 += cc;
      len -= cc;
    }
  } while (len > 0);
  return (len2);
}

int krbclient(char *hostname, char *portstr, char *service) {
  struct addrinfo *ap, aihints, *apstart;
  int aierr;
  int sock;
  krb5_context context;
  krb5_data recv_data;
  krb5_data cksum_data;
  krb5_error_code retval;
  krb5_ccache ccdef;
  krb5_principal client, server;
  krb5_error *err_ret;
  krb5_ap_rep_enc_part *rep_ret;
  krb5_auth_context auth_context = 0;
  short xmitlen;
  //  char *portstr;
  // char *service = "sample";

  retval = krb5_init_context(&context);
  if (retval) {
    cout << "initializing krb5 context error" << endl;
    //   com_err(argv[0], retval, "while initializing krb5");
    exit(1);
  }

  (void)signal(13, ((__sighandler_t)1));

  memset(&aihints, 0, sizeof(aihints));
  aihints.ai_socktype = SOCK_STREAM;
  aihints.ai_flags = AI_ADDRCONFIG;
  aierr = getaddrinfo(hostname, portstr, &aihints, &ap);
  if (aierr) {
    fprintf(stderr, " error looking up host '%s' port '%s'/tcp: %s\n", hostname,
            portstr, gai_strerror(aierr));

    exit(1);
  }
  if (ap == 0) {
    /* Should never happen.  */
    //    fprintf(stderr,
    //            "%s: error looking up host '%s' port '%s'/tcp: no addresses "
    //            "returned?\n",
    //            argv[0], argv[1], portstr);
    exit(1);
  }

  retval = krb5_sname_to_principal(context, hostname, service, KRB5_NT_SRV_HST,
                                   &server);
  if (retval) {
    cout << "error while creating server name for host" << endl;

    //    com_err(argv[0], retval,
    //            "while creating server name for host %s service %s", argv[1],
    //            service);
    exit(1);
  }

  /* set up the address of the foreign socket for connect() */
  apstart = ap; /* For freeing later */
  for (sock = -1; ap && sock == -1; ap = ap->ai_next) {
    char abuf[NI_MAXHOST], pbuf[NI_MAXSERV];
    char mbuf[NI_MAXHOST + NI_MAXSERV + 64];
    if (getnameinfo(ap->ai_addr, ap->ai_addrlen, abuf, sizeof(abuf), pbuf,
                    sizeof(pbuf), NI_NUMERICHOST | NI_NUMERICSERV)) {
      memset(abuf, 0, sizeof(abuf));
      memset(pbuf, 0, sizeof(pbuf));
      strncpy(abuf, "[error, cannot print address?]", sizeof(abuf) - 1);
      strncpy(pbuf, "[?]", sizeof(pbuf) - 1);
    }
    memset(mbuf, 0, sizeof(mbuf));
    strncpy(mbuf, "error contacting ", sizeof(mbuf) - 1);
    strncat(mbuf, abuf, sizeof(mbuf) - strlen(mbuf) - 1);
    strncat(mbuf, " port ", sizeof(mbuf) - strlen(mbuf) - 1);
    strncat(mbuf, pbuf, sizeof(mbuf) - strlen(mbuf) - 1);
    sock = socket(ap->ai_family, SOCK_STREAM, 0);
    if (sock < 0) {
      fprintf(stderr, "%s: socket: %s\n", mbuf, strerror(errno));
      continue;
    }
    if (connect(sock, ap->ai_addr, ap->ai_addrlen) < 0) {
      fprintf(stderr, "%s: connect: %s\n", mbuf, strerror(errno));
      close(sock);
      sock = -1;
      continue;
    }
    /* connected, yay! */
  }
  if (sock == -1) /* Already printed error message above.  */
    exit(1);
  // printf("connected\n");

  cksum_data.data = hostname;
  cksum_data.length = strlen(hostname);

  retval = krb5_cc_default(context, &ccdef);

  if (retval) {
    cout << "error while getting default ccache " << endl;
    //  com_err(argv[0], retval, "while getting default ccache");
    exit(1);
  }

  retval = krb5_cc_get_principal(context, ccdef, &client);

  if (retval) {
    cout << "error while getting client principal name " << endl;

    //  com_err(argv[0], retval, "while getting client principal name");
    exit(1);
  }

  retval = krb5_sendauth(context, &auth_context, (krb5_pointer)&sock,
                         "KRB5_sample_protocol_v1.0", client, server,
                         AP_OPTS_MUTUAL_REQUIRED, &cksum_data,
                         0, /* no creds, use ccache instead */
                         ccdef, &err_ret, &rep_ret, NULL);

  krb5_free_principal(context, server); /* finished using it */
  krb5_free_principal(context, client);
  krb5_cc_close(context, ccdef);
  if (auth_context) krb5_auth_con_free(context, auth_context);

  if (retval && retval != KRB5_SENDAUTH_REJECTED) {
    printf("sendauth error\n");
    exit(1);
  }
  if (retval == KRB5_SENDAUTH_REJECTED) {
    /* got an error */
    printf("sendauth rejected, error reply is:\n\t\"%*s\"\n",
           err_ret->text.length, err_ret->text.data);
    exit(1);
  } else if (rep_ret) {
    /* got a reply */
    krb5_free_ap_rep_enc_part(context, rep_ret);

    if ((retval = net_read(sock, (char *)&xmitlen, sizeof(xmitlen))) <= 0) {
      if (retval == 0) errno = ECONNABORTED;
      cout << "error while reading data from server" << endl;

      //     com_err(argv[0], errno, "while reading data from server");
      exit(1);
    }
    recv_data.length = ntohs(xmitlen);
    if (!(recv_data.data = (char *)malloc((size_t)recv_data.length + 1))) {
      cout << "error while allocating buffer to read from server" << endl;
      exit(1);
    }
    if ((retval = net_read(sock, (char *)recv_data.data, recv_data.length)) <=
        0) {
      if (retval == 0) errno = ECONNABORTED;
      //  com_err(argv[0], errno, "while reading data from server");
      exit(1);
    }
    recv_data.data[recv_data.length] = '\0';
    printf("krbauth reply len %d,krbauth contents:\n%s\n", recv_data.length,
           recv_data.data);
    free(recv_data.data);
  } else {
    cout << "no error or reply from sendauth" << endl;
    // com_err(argv[0], 0, "no error or reply from sendauth!");
    exit(1);
  }
  freeaddrinfo(apstart);
  krb5_free_context(context);
  //      exit(0);
  close(sock);
  return 0;
}

int recvauth(int server_port, char *server_ip) {
  const int MAXSIZE = 1024;
  // const char *SERVER_IP = "127.0.0.1";

  int sock, recvBytes;
  char buf[MAXSIZE];
  sockaddr_in serv_addr;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    cout << "socket create fail!" << endl;
    exit(1);
  }

  bzero(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(server_port);
  serv_addr.sin_addr.s_addr = inet_addr(server_ip);

  if (connect(sock, (sockaddr *)&serv_addr, sizeof(sockaddr)) == -1) {
    cout << "connect " << server_ip << " error" << endl;
    exit(1);
  }
  if ((recvBytes = recv(sock, buf, MAXSIZE, 0)) == -1) {
    cout << "kerberos_notify_port recv  error!" << endl;
    exit(1);
  }
  buf[recvBytes] = '\0';
  if (buf[0] == 'y')
    return 1;
  else
    return 0;
  close(sock);
}

int main(int argc, char **argv) {
  /* Client */
  if (argc < 4) {
    printf(
        "argc=%d, Illegal input. \nPlease use client master_ip "
        "client_listener_port kerberos_notify_port kerberos_hostname "
        "kerberos_address service_name .\n",
        argc);
    printf(
        "HINT: the master ip and the client_listener_port can be found in "
        "the "
        "configure file.\n");
    return 0;
  }
  int use_kerberos = recvauth(atoi(argv[3]), argv[1]);
  int kerberos_auth_result;
  if (use_kerberos) {
    cout << "use kerberos" << endl;
    if (argc != 7) {
      printf(
          "argc=%d, Illegal input. \nPlease use client master_ip "
          "client_listener_port  kerberos_notify_port  kerberos_hostname "
          "kerberos_address "
          "service_name .\n",
          argc);
      printf(
          "HINT: the master ip and the client_listener_port can be found in "
          "the "
          "configure file.\n");
      return 0;
    }

    char *krb_hostname = argv[4];
    char *krb_port = argv[5];
    char *krb_service = argv[6];
    kerberos_auth_result = krbclient(krb_hostname, krb_port, krb_service);

  } else {
    cout << " not use kerberos" << endl;

    if (argc != 4) {
      printf(
          "argc=%d, Illegal input. \nPlease use client master_ip "
          "client_listener_port kerberos_notify_port.\n",
          argc);
      printf(
          "HINT: the master ip and the client_listener_port can be found in "
          "the "
          "configure file.\n");
      return 0;
    }
  }

  claims::common::Logging claims_logging(argv[0]);
  print_welcome();
  PrintUsage();
  Client client;
  client.connection(argv[1], atoi(argv[2]));
  std::cout << std::endl;
  init_command_line();

  while (1) {
    std::string command, message;

    int num = 0;

    get_commands(command, num);

    command = trimSpecialCharactor(command);

    if (command == "exit;" || command == "shutdown;") {
      break;
    } else if (command.empty()) {
      continue;
    } else if (command == "help;") {
      PrintUsage();
      continue;
    } else if (command == "copyright;") {
      PrintCopyright();
      continue;
    }

    submit_command(client, command, num);

    /*
     * the following command execute the query for a given time and p
     * rint the averaged query response time.*/
    //		submit_command_repeated(client,command,50);
  }
  client.shutdown();
}
