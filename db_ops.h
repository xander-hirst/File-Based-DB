#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME_LENGTH 32
#define MAX_ADDRESS_LENGTH 64
#define MAX_CITY_LENGTH 16
#define STATE_LENGTH 3
#define MAX_STRUCTARR_SIZE 100

int open_db (char *file_name);
struct snippet* read_snippet();
void read_db();
void print_db();
void add_snippet();
void remove_snippets(char *remove_str);
void save_db();

struct snippet {
  char name [MAX_NAME_LENGTH];
  char addr [MAX_ADDRESS_LENGTH];
  char city [MAX_CITY_LENGTH];
  char state [STATE_LENGTH];
  unsigned int zip;
};
