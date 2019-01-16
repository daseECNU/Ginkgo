/*
 * Config.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: wangli
 */

#include "Config.h"
#include "Debug.h"
#include <stdlib.h>
#include <libconfig.h++>
#include <unistd.h>
#include <iosfwd>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//#define DEBUG_Config

string gete() {
  char *p = getenv("GINKGO_HOME");
  stringstream sp;
  sp << string(p).c_str() << "conf/config";
  return sp.str();
  //	return "/home/imdb/config/wangli/config";
}
string get_default_logfile_name() {
  char *p = getenv("GINKGO_HOME");
  stringstream sp;
  sp << string(p).c_str() << "/log/claims.log";
  return sp.str();
}
std::string Config::config_file;
Config *Config::instance_ = 0;

/**
 * This parameter specifies the maximum degrees of parallelism
 * for each expander.
 */
int Config::max_degree_of_parallelism;

/*
 * This parameter specifies the data path to search for data file,
 * e.g., T0G0P0,...
 */
std::string Config::data_dir;

/* this parameter control whether expander tracker change the degree
 *  of parallelism in each expander based on the workload.*/
bool Config::enable_expander_adaptivity;

/*
 * This parameter sets the frequency, at which expander tracker keeps
 * track of expander's workload and adaptively change the degree of
 * parallelism if needed.
 */
int Config::expander_adaptivity_check_frequency;

/**
 * This parameter sets the initial degree of parallelism for each segment.
 */
int Config::initial_degree_of_parallelism;

/**
 * THis parameter determines whether the data transmission in data exchanges
 * is pipelined.
 */
bool Config::pipelined_exchange;

int Config::scan_batch;

std::string Config::logfile;

std::string Config::hdfs_master_ip;

int Config::hdfs_master_port;

bool Config::master;

bool Config::local_disk_mode;

/* the port of the ClientListener in the master */
int Config::client_listener_port;

bool Config::enable_codegen;
bool Config::enable_prune_column;
bool Config::enable_parquet;
bool Config::enable_kerberos;

bool Config::distributed_load;

std::string Config::catalog_file;

int Config::thread_pool_init_thread_num;

int Config::load_thread_num;
int Config::memory_utilization;
std::string Config::zk_znode_name;

std::string Config::httpserver_master_ip;

std::string Config::httpserver_master_port;

std::string Config::httpserver_thread_num;

// not used
std::string Config::httpserver_doc_root;

int Config::mysql_port;

std::string Config::mysql_password;

std::string Config::zookeeper_host_list;

std::string Config::krb_listen_address;
std::string Config::krb_server_keyfile;
std::string Config::krb_srvname;
std::string Config::krb_srvinstance;
std::string Config::hdfs_kerb_cache;
int Config::hash_join_bucket_num;
int Config::hash_join_bucket_size;
int Config::expander_buffer_size;
int Config::kerberos_notify_port;
int Config::load_node_num;
Config *Config::getInstance() {
  if (instance_ == 0) {
    instance_ = new Config();
  }
  return instance_;
}

Config::Config() { initialize(); }

Config::~Config() {
  // TODO Auto-generated destructor stub
}

void Config::initialize() {
  if (config_file.empty()) config_file = gete().c_str();

  /**
   * open configure file, which path is specified in CONFIG.
   */
  cfg.readFile(config_file.c_str());

  /*
   * The following lines set the search attribute name and default value for
   * each parameter.
   */

  data_dir = getString("data", "/home/imdb/data/");

  max_degree_of_parallelism = getInt("max_degree_of_parallelism", 4);

  expander_adaptivity_check_frequency =
      getInt("expander_adaptivity_check_frequency", 1000);

  enable_expander_adaptivity = getBoolean("enable_expander_adaptivity", false);

  initial_degree_of_parallelism = getInt("initial_degree_of_parallelism", 1);

  scan_batch = getInt("scan_batch", 10);

  hdfs_master_ip = getString("hdfs_master_ip", "10.11.1.192");

  hdfs_master_port = getInt("hdfs_master_port", 9000);

  logfile = getString("log", get_default_logfile_name().c_str());

  master = getBoolean("master", true);

  local_disk_mode = getBoolean("local_disk_mode", false);

  pipelined_exchange = getBoolean("pipelined_exchange", true);

  client_listener_port = getInt("client_listener_port", 10001);

  catalog_file = getString("catalog_file", data_dir + "CATALOG");

  enable_codegen = getBoolean("enable_codegen", true);

  thread_pool_init_thread_num = getInt("thread_pool_init_thread_num", 100);

  load_thread_num = getInt("load_thread_num", sysconf(_SC_NPROCESSORS_CONF));

  memory_utilization = getInt("memory_utilization", 100);

  httpserver_master_ip = getString("httpserver_master_ip", "127.0.0.1");

  httpserver_master_port = getString("httpserver_master_port", "8097");

  httpserver_thread_num = getString("httpserver_thread_num", "50");

  httpserver_doc_root = getString("httpserver_doc_root", "/home/imdb/doc_root");

  mysql_port = getInt("jdbc_port", 3306);

  mysql_password = getString("mysql_password", "imdb");

  enable_prune_column = getBoolean("enable_prune_column", true);

  enable_parquet = getBoolean("enable_parquet", true);

  enable_kerberos = getBoolean("enable_kerberos", false);

  zk_znode_name = getString("zk_znode_name", data_dir + "CATALOG");

  zookeeper_host_list = getString("zookeeper_host_list", "127.0.0.1:2181");

  krb_listen_address = getString("krb_listen_port", "10010");

  krb_server_keyfile = getString("krb_server_keyfile", "keyfile");

  krb_srvname = getString("krb_srvname", "sample");

  krb_srvinstance = getString("krb_srvinstance", "sample");

  hdfs_kerb_cache = getString("hdfs_kerb_cache", "null");

  hash_join_bucket_num = getInt("hash_join_bucket_num", 1024 * 1024);

  hash_join_bucket_size = getInt("hash_join_bucket_size", 1024);

  expander_buffer_size = getInt("expander_buffer_size", 3000);

  kerberos_notify_port = getInt("kerberos_notify_port", 15000);

  distributed_load = getBoolean("distributed_load", false);

  load_node_num = getInt("load_node_num", 1);
#ifdef DEBUG_Config print_configure();
#endif
}

std::string Config::getString(std::string attribute_name,
                              std::string default_value) {
  std::string ret;
  try {
    ret = (const char *)cfg.lookup(attribute_name.c_str());
  } catch (libconfig::SettingNotFoundException &e) {
    ret = default_value;
  }
  return ret;
}

int Config::getInt(std::string attribute_name, int default_value) {
  int ret;
  try {
    ret = cfg.lookup(attribute_name.c_str());
  } catch (libconfig::SettingNotFoundException &e) {
    ret = default_value;
  }
  return ret;
}

bool Config::getBoolean(std::string attribute_name, bool defalut_value) {
  bool ret;
  try {
    ret = ((int)cfg.lookup(attribute_name.c_str())) == 1;
  } catch (libconfig::SettingNotFoundException &e) {
    ret = defalut_value;
  }
  return ret;
}

void Config::print_configure() const {
  std::cout << "configure file :" << config_file << std::endl;
  std::cout << "The configure is as follows." << std::endl;
  std::cout << "data:" << data_dir << std::endl;
  std::cout << "max_degree_of_parallelism:" << max_degree_of_parallelism
            << std::endl;
  std::cout << "expander_adaptivity_check_frequency:"
            << expander_adaptivity_check_frequency << std::endl;
  std::cout << "enable_expander_adaptivity:" << enable_expander_adaptivity
            << std::endl;
  std::cout << "initial_degree_of_parallelism:" << initial_degree_of_parallelism
            << std::endl;
  std::cout << "hdfs master ip:" << hdfs_master_ip << std::endl;
  std::cout << "hdfs_master_port:" << hdfs_master_port << std::endl;

  std::cout << "log:" << logfile << std::endl;
  std::cout << "master:" << master << std::endl;
  std::cout << "local disk mode:" << local_disk_mode << std::endl;
  std::cout << "client_lisener_port:" << client_listener_port << std::endl;
  std::cout << "catalog_file:" << catalog_file << std::endl;
  std::cout << "codegen:" << enable_codegen << std::endl;
  std::cout << "enable_prune_column: " << enable_prune_column << std::endl;
  std::cout << "enable_parquet: " << enable_parquet << std::endl;
  std::cout << "enable_kerberos: " << enable_kerberos << std::endl;
  std::cout << "load_thread_num:" << load_thread_num << std::endl;
  std::cout << "hash_join_bucket_num: " << hash_join_bucket_num << std::endl;
  std::cout << "hash_join_bucket_size: " << hash_join_bucket_size << std::endl;
  std::cout << "expander_buffer_size: " << expander_buffer_size << std::endl;
  std::cout << "kerberos_notify_port: " << kerberos_notify_port << std::endl;
  std::cout << "distributed_load: " << distributed_load << std::endl;
}

void Config::setConfigFile(std::string file_name) { config_file = file_name; }
