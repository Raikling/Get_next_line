#include "get_next_line.h"

int main(void)
{
   char *line;
   int i = 0;
   int fd = open("test.txt", O_RDWR);
   if (fd == -1)
      return (1);
   while ((line = get_next_line(fd)) != NULL)
   {
      printf("line %d : %s", ++i,line);
      free(line);
      i++;
   }

   return (0);
}