/*
 * command_line.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: wangli
 */
#include "command_line.h"
#include <stdio.h>
#include <iosfwd>
#include <iostream>
#include "string_process.h"
using namespace std;

bool input_struct::append(const char* str) {
  while (*str) string[index++] = *str++;
  if (index != string_length)
    return true;
  else
    return false;
}

void input_struct::reset() {
  memset(string, 0, string_length);
  index = 0;
}

input_struct::input_struct() : index(0) { memset(string, 0, string_length); };

int input_struct::truncate_til(const char* str, char target,
                               bool& target_match) {
  int count = 0;
  char* p = str;
  str += strlen(str) - 1;
  while (str != p && *str != target) {
    *str--;
  }
  // check whether if 'str' has target.
  if (str == p && *str != target) {
    while (*str && *str != target) string[index++] = *str++;
    target_match = false;
    return 0;
  } else {
    while (p <= str) {
      if (*p == target) {
        ++count;
      }
      string[index++] = *p++;
    }
    if (*(--p) == target) {
      target_match = true;
    } else {
      target_match = false;
    }
    if (index != string_length)
      return count;
    else
      return 0;
    return count;
  }
}

void recovery_history() {
  string line;
  ifstream input_file("./.history");
  input_struct is;
  if (!input_file) return;
  while (!input_file.eof()) {
    bool last_line;
    getline(input_file, line);
    is.truncate_til(line.c_str(), ';', last_line);
    if (last_line) {
      add_history(is.string);
      is.reset();
    } else {
      is.append("\n");
    }
  }
  input_file.close();
}

void init_command_line() {
  // Configure readline to auto-complete paths when the tab key is hit.
  rl_bind_key('\t', rl_complete);

  // Restore the history from file
  recovery_history();
}

void store_history(char* command) {
  string str(command);
  ofstream output_file("./.history", std::ofstream::out | std::ofstream::app);
  output_file << str << endl;
  output_file.close();
}

int get_commands(string& str, int& num) {
  char* input_line, shell_prompt[10240];
  string line;
  // Create prompt string from user name and current working directory.
  snprintf(shell_prompt, sizeof(shell_prompt), "CLAIMS>");
  // Display prompt and read input (n.b. input must be freed after use)...
  bool first_line = true;
  bool last_line = false;
  input_struct is;
  usleep(100000);
  while (true) {
    if (!first_line)
      snprintf(shell_prompt, sizeof(shell_prompt), "     > ");
    else {
      //			printf("CLAIMS>");
    }
    first_line = false;
    input_line = readline(shell_prompt);
    num = is.truncate_til(input_line, ';', last_line);
    if (last_line) break;
    is.append("\n");
    free(input_line);
  }

  str = trimSpecialCharactor(std::string(is.string));
  // Add input to history.
  if (last_command != str) {
    add_history(str.c_str());
    store_history((char*)str.c_str());
    last_command = str;
  }
}
