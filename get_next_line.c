#include "get_next_line.h"
#define BUFFER_SIZE 6

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
    int len;
    char    buf[BUFFER_SIZE];
    char    *stock;

	// verif il y a rien dans stock

    len = 1;
    if (prev_read)
	{
		stock = ft_strdup(prev_read);
		free(prev_read);
	}	
	else
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
    stock = read_line(fd, stock);
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
    do{
		str = get_next_line(fd);
    	printf("%s", str);

	}
	free(str);
	close(fd);
}