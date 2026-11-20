#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *stash;
    char *buffer;
    char *line;
    char *temp;
    int bytes;
    size_t i;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer) 
        return (NULL);
    if (bytes > 0)
        buffer[bytes] = '\0'; 
    while (!stash || !ft_strchr(stash, '\n'))
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < 0)
        {
            free(buffer);
            free(stash);
            stash = NULL;
            return (NULL);
        }
        if (bytes == 0)
           break;
        buffer[bytes] = '\0';
        temp = ft_strjoin(stash, buffer);
        if (!temp)
        {
            free(buffer);
            free(stash);
            stash = NULL;
            return (NULL);
        }
        free(stash);
        stash = temp;
    }
    i = 0;
    if (!stash || stash[0] == '\0')
    {
        free(buffer);
        free(stash);
        stash = NULL;
        return(NULL);
    }
    while (stash && stash[i] && stash[i] != '\n')
        i++;
    line = ; 
}
