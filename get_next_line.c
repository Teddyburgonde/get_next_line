#include "get_next_line.h"
#include <stdio.h>

/*  #ifndef BUFFER_SIZE 
# define BUFFER_SIZE 42
#endif */

char *read_loop(char *buf, char *stock, int *len, int fd)
{
	buf = calloc(sizeof(char), BUFFER_SIZE + 1);
	*len = read(fd, buf, BUFFER_SIZE);
	if (*len == -1 || (*len == 0 && stock[0] == '\0'))
	{
		free(buf);
		free(stock);
		return (NULL);
	}
	stock = ft_strjoin(stock, buf);
	free(buf);
	buf = NULL;
	return (stock);
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

char *read_line(int fd, char *stock)
{
    int 	len;
    char    *buf;

	len = 1;
	buf = NULL;
	if (stock != NULL)
	{
		buf = calloc(sizeof(char), BUFFER_SIZE + 1);
		len = read(fd, buf, BUFFER_SIZE);
		if (len > 0)
			stock = ft_strjoin(stock, buf);
		free(buf);
		buf = NULL;
	}
	else
		stock = calloc(1, 1);
    while (len > 0 && ft_strchr(stock, '\n') == NULL)
    {
		// buf = calloc(sizeof(char), BUFFER_SIZE + 1);
        // len = read(fd, buf, BUFFER_SIZE);
		// if (len == -1 || (len == 0 && stock[0] == '\0'))
		// {
		// 	free(buf);
		// 	free(stock);
		// 	return (NULL);
		// }
		// stock = ft_strjoin(stock, buf);
		// free(buf);
		// buf = NULL;
		stock = read_loop(buf, stock, &len, fd);
    }
	free(buf);
    return (stock);
}

char	*extract_line(char *stock)
{
	int		i;
	char	*line = NULL;

	if (stock == NULL)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	line = ft_substr(stock, 0, i);
	return (line);
}

char	*extract_surplus_line(char *stock)
{
	int	i;
	int	j;
	char	*new_stock;

	if (stock == NULL)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	j = ft_strlen(stock);
	if (i == j)
	{
		free(stock);
		return (NULL);
	}
	new_stock = ft_substr(stock, i, j);
	free(stock);
	return (new_stock);
}

char *get_next_line(int fd)
{
    static char *stock = NULL;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0) 
	    return (NULL);
    stock = read_line(fd, stock);
	line = extract_line(stock);
	stock = extract_surplus_line(stock);
	return (line);
}


/* #include <stdio.h>
int main(void)
{
    int fd;
    static char    *str;
	int i;

	i = 0;
    fd = open("example.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str)
			printf("%s", str);
		if (str == NULL)
			return (0);
		free(str);
	}
	close(fd);
}
 */