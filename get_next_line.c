#include <unistd.h>
#define BUFFER_SIZE 6
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int ft_strlen(const char *str)
{
    int  i;

	if (!str)
		return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++; 
	}
	if (s[i] == (char)c)
		return ((char *)(&s[i]));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char		*tab;
	int			i;

	i = 0;
	tab = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (tab)
	{
		while (s[i])
		{
			tab[i] = s[i];
			i++;
		}
		tab[i] = '\0';
	}
	return ((char *)tab);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int	i;
	int	j;
	char	*tab= NULL;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	j = ft_strlen(s + start);
	if (j < len)
		len = j;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tab)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tab[i] = s2[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	free(s1);
	s1 = NULL;
    return (tab);
}

char *read_line(int fd)
{
    int len;
    char    buf[BUFFER_SIZE];
    char    *stock;

	// verif il y a rien dans stock

    len = 1;
    stock = ft_strdup("");
    while (len > 0 && ft_strchr(stock, '\n') == NULL)
    {
        len = read(fd, buf, BUFFER_SIZE);
        stock = ft_strjoin(stock, buf);
    }
    return (stock);
}

char	*extract_line(char *stock)
{
	int	i;
	char	*line;

	i = 0;
	while (stock[i] != '\n')
		i++;
	line = ft_substr(stock, 0, i);
	return (line);
}

char	*extract_surplus_line(char *stock)
{
	int	i;
	int	j;
	char	*new_stock;

	i = 0;
	while (stock[i] != '\n')
		i++;
	i++;
	j = ft_strlen(stock);
	new_stock = ft_substr(stock, i, j);
	free(stock);
	return (new_stock);
}

char *get_next_line(int fd)
{
    static char *stock;
	char	*line;
    
	if (fd == -1 || BUFFER_SIZE <= 0) 
	    return (NULL);
    stock = read_line(fd);
	line = extract_line(stock);
	stock = extract_surplus_line(stock);
	return (line);
}

#include <stdio.h>
int main(void)
{
    int fd;
    static char    *str;
    
    fd = open("example.txt", O_RDONLY);
    str = get_next_line(fd);
    printf("%s", str);
	free(str);
}