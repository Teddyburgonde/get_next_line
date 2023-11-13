/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:12:38 by tebandam          #+#    #+#             */
/*   Updated: 2023/11/13 13:04:24 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 5

//int get_next_line(const int fd, char **line)
//{
    
//}


int main(void)
{
    int fd;
    int stock;
    char    buff[BUFF_SIZE];

    fd = open("example.txt", O_RDWR);        
    stock = read(fd, buff, BUFF_SIZE);
    while (stock > 0)
    {
        stock = read(fd, buff, BUFF_SIZE);
        
    }
    printf("content: %s", buff);
    close(fd);
    return (0);
}


/*


int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char buffer[100];
    size_t bytesRead = read(fd, buffer, sizeof(buffer));
    (void)bytesRead;
    printf("%s\n", buffer);
    close(fd);
    return (0);
}

*/