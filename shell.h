#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUF 1024

extern char** environ;


typedef struct info
{
  char *buffer;
  int interactive;
  char *buffer_copy;
  ssize_t getline_bytes;
  size_t n;
  int ntokens;
  int i;
  char **string_arr;
  char *token;
} info_t;

#define INFO_INIT \
  {NULL, 0, NULL, 0, 0, 0, 0, NULL, NULL}

void read_line();
void prompt(info_t* info);
