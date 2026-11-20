#include "get_next_line.h"

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

char *ft_strchr(const char *s, int d)
{
    unsigned int i;
    char cc;

    cc = (char)d;
    i = 0;
    while(s[i])
    {
        if (s[i] == cc)
            return((char *)&s[i]);
        i++;
    }
    if (s[i] == cc)
        return((char *)&s[i]);
    return (NULL);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    char *res;
    int i;
    int j;

    i = 0;
    j = 0;  
    if(!s1)
        s1 = "";
    if(!s2)
        s2 = "";
    res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!res)
        return (NULL);
    while(s1[i])
    {
        res[j] = s1[i];
        i++;
        j++;
    }
    i = 0;
    while (s2[i])
    {
        res[j] = s2[i];
        i++;
        j++;

    }
    res[j] = '\0';
    return (res);
}


void *ft_calloc(size_t count, size_t size)
{
    unsigned char *tmp;
    size_t i;

    i = 0;
    tmp = malloc(count * size);
    if (!tmp)
        return (NULL);
    while (i < count * size)
        tmp[i++] = 0;
    return (tmp);
}

char *ft_strdup(const char *s1)
{
    char *dest;
    size_t i;

    dest = (char *)malloc(ft_strlen(s1) + 1);
    if (!dest)
        return (NULL);
    while(s1[i])
    {
        dest[i] = s1[i];
        i++;
    }
    dest[i] = '\0';
    return (0);
}

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t i;
    char *str;
    if (!s)
        return (NULL);
    if (start > ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s + start))
        len = ft_strlen(s + start);
    str = ft_calloc(len + 1, sizeof(char));
    if (!str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    return (str);
}
