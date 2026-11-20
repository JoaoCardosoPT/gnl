#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <stdlib.h>
#include <unistd.h>

char *ft_substr(const char *s, unsigned int start, size_t len);
char *ft_strjoin(const char *s1, const char *s2);
int ft_strlen(const char *str);
char *ft_strchr(const char *s, int d);

#endif
