#include "shell.h"

/**
 *main - entry point of program
 *return - int
 */


int main()
{
  info_t info = INFO_INIT;
  while(1)
    {
      prompt(&info);
      read_line(&info);
    };
  return (0);
}


