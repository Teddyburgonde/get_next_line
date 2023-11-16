/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:12:38 by tebandam          #+#    #+#             */
/*   Updated: 2023/11/15 21:33:23 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFFER_SIZE 42

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	char			*tab;

	tab = s;
	i = 0;
	while (i < n)
	{
		tab[i] = c;
		i++;
	}
	return (s);
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
	free(s1); // pour eviter les leaks
	s1 = NULL;
    return (tab);
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

static char	*change_stock(char *stock)
{
	char	*new_stock;
	int		i;
	int		j;
	
	if (!stock)
		return (NULL);
	i = 0;
	j = ft_strlen(stock);    
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] != '\0')
		return (NULL);
	i++;
	new_stock = ft_substr(stock, i, j - i);
	free(stock);
	stock = NULL;
	return (new_stock);
}

/* char *get_next_line(int fd)
{
	char	*line;
	char	buf[BUFFER_SIZE];
	int		len;
	static char *stock;
	int	i;
	
	if (fd == -1 ||  BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	len = read(fd, buf, BUFFER_SIZE); // je lis dans fd , stock dans buf de la taille de Buffer_size
	stock = ft_strdup(buf); // PROBLEME  
	while (len > 0 && ft_strchr(stock, '\n') == NULL)
	{
		len = read(fd, buf, BUFFER_SIZE); //valeur de buf a changer car nouvelle lecture
		stock = ft_strjoin(stock, buf);
	}
	while (stock[i] != '\n')
		i++;
	line = ft_substr(stock, 0, i);
	//printf("before : %s\n", stock);
	stock = change_stock(stock);
	//printf("after : %s\n", stock);
	return (line);
} */


char *get_next_line(int fd)
{
	char	*line;
	char	*full_line;
	char	buf[BUFFER_SIZE];
	int		len;
	static char *stock = NULL;
	int	i;
	
	if (fd == -1 ||  BUFFER_SIZE <= 0)
		return (NULL);
	full_line = NULL;
	i = 0;
	ft_memset(buf, 0, BUFFER_SIZE);
	len = read(fd, buf, BUFFER_SIZE); // je lis dans fd , stock dans buf de la taille de Buffer_size
	if (stock != NULL)
		full_line = ft_strjoin(stock, buf);
	else if (len > 0)
	{
		buf[len] = '\0';
		full_line = ft_strdup(buf);
	}
	if (!full_line)
		return (NULL);
	while (full_line && len > 0 && ft_strchr(full_line, '\n') == NULL)
	{
		ft_memset(buf, 0, BUFFER_SIZE);
		len = read(fd, buf, BUFFER_SIZE); //valeur de buf a changer car nouvelle lecture
		if (len <= 0)
			break ;
		full_line = ft_strjoin(full_line, buf);
	}
	if (full_line){
		while (full_line[i] && full_line[i] != '\n')
			i++;
	}
	line = ft_substr(full_line, 0, i + 1);
	stock = change_stock(full_line);
	if (full_line){
		free(full_line);
		full_line = NULL;
	}
	
	// printf("|%s|\n", stock);
	return (line);
}


#include <stdio.h>
int main(void)
{	
	char	*tab;
	//int	i;
	int fd;

	//i = 0;
	fd = open("example.txt", O_RDONLY);

	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	tab = get_next_line(fd);
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	printf("%s", tab);
	//printf("%s", tab);
	// if (tab)
		// free(tab);
	return (0);
}
