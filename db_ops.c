#include "db_ops.h"

static FILE *db;
static struct snippet *data_base[MAX_STRUCTARR_SIZE];
static int snippet_count = 0;
static int write_index = 0;

int open_db (char *file_name){
  db = fopen(file_name, "r");
  if (db == NULL){
    return -1;
  }
  return 0;
}

struct snippet* read_snippet(){
  
  struct snippet *new_entry = (struct snippet *)malloc(sizeof(struct snippet));
  /*these numbers are the max size of each respective array - 1*/
  /*i tried using symbolic constants but they did not work with the scanset*/
  fscanf(db,"%31[^:]:%63[^:]:%15[^:]:%2[^:]:%ud", new_entry->name, new_entry->addr, new_entry->city, new_entry->state, &(new_entry->zip));
  return new_entry;
}

void read_db(){
  int i;

  fscanf(db, "%d", &snippet_count);
  for (i = 0; i < snippet_count; i++){
    data_base[i] = read_snippet();
  }
  write_index = snippet_count;
}

void print_db(){
  int i;
  for (i = 0; i < write_index; i++){
    if (data_base[i] != NULL){
      printf("%s\n%s\n%s, %s %u\n", data_base[i]->name, data_base[i]->addr, data_base[i]->city, data_base[i]->state, data_base[i]->zip);
    }
  }
}

void add_snippet(){
  struct snippet *new_entry = (struct snippet *)malloc(sizeof(struct snippet));
  printf("Enter info in following form\n");
  printf("<name>:<address>:<city>:<state abbrv>:<zip code>\n");
  scanf("%31[^:]:%63[^:]:%15[^:]:%2[^:]:%u", new_entry->name, new_entry->addr, new_entry->city, new_entry->state, &(new_entry->zip));
  data_base[write_index++] = new_entry;
  snippet_count++;
}

void remove_snippets(char *remove_str){
  int i;
  int remove_found;
  for (i = 0; i < write_index; i++){
    remove_found = -1;
    if(data_base[i] != NULL &&(strstr(data_base[i]->name, remove_str) != NULL)){
      remove_found = 1;
    }
    if(data_base[i] != NULL &&(strstr(data_base[i]->addr, remove_str) != NULL)){
      remove_found = 1;
    }
    if(data_base[i] != NULL &&(strstr(data_base[i]->city, remove_str) != NULL)){
      remove_found = 1;
    }
    if(data_base[i] != NULL &&(strstr(data_base[i]->state, remove_str) != NULL)){
      remove_found = 1;
    }
    if (remove_found == 1){
      free(data_base[i]);
      data_base[i] = NULL;
      snippet_count--;
    }
  }
}

void save_db(char *file_name){
  freopen(file_name, "w", db);
  int i;
  fprintf(db, "%d", snippet_count);
  for (i = 0; i < write_index; i++){
    if (data_base[i] != NULL){
      fprintf(db, "%s:%s:%s:%s:%u", data_base[i]->name, data_base[i]->addr, data_base[i]->city, data_base[i]->state, data_base[i]->zip);
    }
  }
}


