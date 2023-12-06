#include "shell.h"

/**
 *prompt - prints prompt 
 *returns = void
*/

void prompt(info_t *info)
{
  char buf[1024];
  int interactive = info->interactive;

  if (interactive = isatty(fileno(stdin)))
        if (getcwd(buf, sizeof(buf)) != NULL)
        {
            write(STDOUT_FILENO, buf, strlen(buf));
	    write(STDOUT_FILENO, "\n$ ", 3);
        }
        else
        {
            perror("Error: cwd error");
        }
	
}



/**
 *read_line - prints prompt and reads line 
 *return - void
 */

void read_line(info_t *info)
{
  info->getline_bytes = getline(&info->buffer, &info->n, stdin);

  if (info->getline_bytes == -1)
  {
    free(info->buffer); /* Free dynamically allocated buffer */
    exit(0);
  }
  if (info->getline_bytes == 1 && info->buffer[0] == '\n')
  {
    free(info->buffer); /* Free dynamically allocated buffer */
    return;
  }

  info->buffer_copy = strdup(info->buffer);

  // Call hashtags(info->buffer_copy) if hashtags function is defined

  /* Tokenize string */
  info->token = strtok(info->buffer, " \n");

  while (info->token != NULL)
  {
    /* Keep adding up to keep track of the number of tokens needed */
    info->ntokens++;
    info->token = strtok(NULL, " \n");
  }

  info->string_arr = malloc(sizeof(char *) * (info->ntokens + 1));

  info->token = strtok(info->buffer_copy, " \n");
  info->i = 0;
  while (info->token != NULL)
  {
    info->string_arr[info->i] = strdup(info->token);
    info->token = strtok(NULL, " \n");
    info->i++;
  }
  info->string_arr[info->i] = NULL;

  // Call executable(info->string_arr) if executable function is defined

  for (info->i = 0; info->string_arr[info->i] != NULL; info->i++)
  {
    free(info->string_arr[info->i]);
  }
  free(info->string_arr);
  free(info->buffer_copy);
  free(info->buffer);
}
