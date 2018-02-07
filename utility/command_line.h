#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

/* An auxiliary structure used for removing duplicated command in the history.*/
static std::string last_command;

/* The maximum length of a command */
const int string_length = 102400;

/* A auxiliary struct storing command */
struct input_struct {
  input_struct();
  /* reset the cotent of the command */

  void reset();

  /* add a string to the command */
  bool append(const char* str);

  /**
   * @brief delete contents after the target and count the number of SQL
   * statements needed to be execute
   * @return the number of SQL statements
   * @author zyhe
   */
  int truncate_til(const char* str, char target, bool& target_match);

  /* the space holding the command */
  char string[string_length];
  /* the index indicating the end of the command */
  int index;
};

/* recovery history from file ".history" */
void recovery_history();

/* store current comment to the ".history" file */
void store_history(char* command);

void init_command_line();

/* get one or more commands from terminal --added by zyhe */
int get_commands(string& str, int& num);
