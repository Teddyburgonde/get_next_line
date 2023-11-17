#include "get_next_line.h"
#include <stdio.h>

//#ifndef BUFFER_SIZE 
//# define BUFFER_SIZE 6
//#endif

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

char *read_line(int fd, char *prev_read)
{
    int 	len;
    char    *buf = calloc(BUFFER_SIZE + 1, 1); // TODO 
    char    *stock;

	// verif il y a rien dans stock

    len = 1;
    if (prev_read)
	{
		stock = ft_strdup(prev_read);
		free(prev_read);
	}	
	else
		stock = calloc(1,1);
    while (len > 0 && ft_strchr(stock, '\n') == NULL)
    {
        len = read(fd, buf, BUFFER_SIZE);
		// buf[len] = 0;
        stock = ft_strjoin(stock, buf);
    }
	free(buf);
    return (stock);
}

char	*extract_line(char *stock)
{
	int		i;
	char	*line = NULL;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!i)
		return ( ft_strdup("\n") );
	line = ft_substr(stock, 0, i);
	return (line);
}

char	*extract_surplus_line(char *stock)
{
	int	i;
	int	j;
	char	*new_stock;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	i++;
	j = ft_strlen(stock);
	new_stock = ft_substr(stock, i, j);
	free(stock);
	return (new_stock);
}

char *get_next_line(int fd)
{
    static char *stock = NULL;
	char	*line;
    
	if (fd < 0) 
	    return (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
    stock = read_line(fd, stock);
	line = extract_line(stock);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	stock = extract_surplus_line(stock);
	if (*stock == '\0' && *line == '\0')
	{	
		free(stock);
		stock = NULL;
		free(line);
		line = NULL;
		return (NULL);
	}
	return (line);
}

/*
#include <stdio.h>
int main(void)
{
    int fd;
    static char    *str;

    fd = open("example.txt", O_RDONLY);
    while ((str = get_next_line(fd)))
	{	
    	printf("%s\n", str);
		free(str);
	}
	close(fd);
}
*/
