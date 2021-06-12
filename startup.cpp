/*
 * startup.h
 *
 *  Created on: Jul 7, 2014
 *      Author: wangli
 */

#ifndef STARTUP_H_
#define STARTUP_H_
#include <stdio.h>
#include "Environment.h"
#include <unistd.h>
#include "Config.h"

void print_welcome() {
  printf("\033[;31m");
  printf("      _____  __  ___  __  __   __   _____   _____  \n");
  printf("     /  ___| | | |  \ | | | | / /  /  ___| /  _  \  \n");
  printf("     | |     | | |   \| | | |/ /   | |     | | | |  \n");
  printf("     | |  _  | | | |\   | | |\ \   | |  _  | | | |  \n");
  printf("     | |_| | | | | | \  | | | \ \  | |_| | | |_| |  \n");
  printf("     \_____/ |_| |_|  \_| |_|  \_\ \_____/ \_____/  \n");
  printf("\033[0m\n");
}

int main_aaa(int argc, char** argv){
	if(argc!=2){
		printf("Invalid input!\n");
		printf("Claims --master/slave\n");
		return -1;
	}
	print_welcome();
	if(strcmp(argv[1],"--master")==0){
		Environment::getInstance(true);
		while(true)
			sleep(1);
	}
	else{
		int pid=fork();
		if(pid!=0){
			printf("Daemon process id is %d\n",pid);
			sleep(1);
			exit(0);
		}
		Config::getInstance();
		printf("Creating Slave daemon...\n");
		printf("Logs are redirected to %s\n",Config::logfile.c_str());
		FILE *file;
		if((file=freopen(Config::logfile.c_str(),"a",stdout))==NULL){
			printf("output redirection fails!\n");
		}
		freopen(Config::logfile.c_str(),"a",stderr);

		Environment::getInstance(false);
		printf("The Slave daemon is successfully created-_-!\n");
		fflush(stdout);
		fclose(stdout);
		//redirect back to console
		freopen("/dev/tty","a",stdout);
		printf("The Slave daemon is successfully created!\n");
		//redirect again to the log file.
		if((file=freopen(Config::logfile.c_str(),"a",stdout))==NULL){
			printf("output redirection fails!\n");
		}
		freopen(Config::logfile.c_str(),"a",stderr);
		while(true)
			sleep(1);
	}
}


#endif /* STARTUP_H_ */
