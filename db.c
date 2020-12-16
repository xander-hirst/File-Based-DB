#include "db_ops.h"
#include "db.h"

int main(int argc, char *argv[])
{
  char *file_name = argv[1];
 
  int file_status = open_db(file_name);
  if (file_status < 0){
    printf("File not opened successfully (File not found?)\n");
    printf("Usage: db <file_name>\n");
    exit(-1);
  }
  read_db();

  char list[] = {'l','i','s','t','\0'};
  char add[] = {'a','d','d','\0'};
  char remove[] = {'r','e','m','o','v','e','\0'};
  char exitstr[] = {'e','x','i','t','\0'};
  char user_input[MAX_INPUT_SIZE];
  char removal_str[MAX_REMOVAL_TOKEN_SIZE];
  int exittime = -1;
  while (exittime < 0){
    printf("\nEnter 'list' to print database, 'add' to add an entry,\n");
    printf("'remove <removal token>' to remove entries contain that token,\n");
    printf("or 'exit' to save and terminate\n");
    fscanf(stdin,"%s", user_input);
    if (strcmp(user_input,list) == 0){
      print_db();
    }
    if (strcmp(user_input,add) == 0){
      add_snippet();
    }
    if (strcmp(user_input,remove) == 0){
      fscanf(stdin,"%s", removal_str);
      remove_snippets(removal_str);
    }
    if (strcmp(user_input,exitstr) == 0){
      exittime = 1;
      save_db(file_name);
    }
  }
  exit(0);
}//main
