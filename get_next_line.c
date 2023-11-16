/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:08:58 by tebandam          #+#    #+#             */
/*   Updated: 2023/11/16 09:59:05 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 7

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

char	*ft_strdup(const char *s)
{
	char		*tab;
	int			i;

	i = 0;
	tab = malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (tab)
	{
		while (s[i])
		{
			tab[i] = s[i];
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
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

//fonction qui lis un fichier et qui stock le contenu dans une variable
// static 

char    *read_in_the_file(int fd)
{
    char    buf[BUFFER_SIZE];
    static char *stock;
    int size;
    
    if (fd == -1 || BUFFER_SIZE <= 0)
        return (NULL);
    size = read(fd, buf, BUFFER_SIZE);
    if (size > 0)
        stock = ft_strdup(buf);
    return (stock);
}

// ft_strchr(full_line, '\n')
char    *extract_line(char *stock)
{
    
}

/*
//char *get_next_line(int fd)
#include <stdio.h>
int main(void)
{
    int fd;
    char    *str;
    
    fd = open("example.txt", O_RDONLY);
    str = read_in_the_file(fd);
    printf("%s", str);
    free(str);
}
*/
