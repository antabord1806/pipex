#include "libft.h"

int line_length(char *line)
{
    size_t len = ft_strlen(line);
    if (len > 0 && line[len - 1] == '\r')
        len--;
    return len;
}