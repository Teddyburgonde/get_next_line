#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int get_next_line(const int fd, char **line);
int  ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
static char	*change_stock(char *stock);

#endif 