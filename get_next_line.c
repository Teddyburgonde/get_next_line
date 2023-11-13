/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:12:38 by tebandam          #+#    #+#             */
/*   Updated: 2023/11/13 11:13:48 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>


int get_next_line(const int fd, char **line)








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




