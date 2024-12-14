#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

size_t ft_strlen(const char *str);
char *ft_strdup(const char *str);
char *ft_strchr(const char *str, int c);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *ft_substr(const char *str, unsigned int start, size_t len);
char *ft_strjoin(const char *s1, const char *s2);
char *get_next_line(int fd);



#endif