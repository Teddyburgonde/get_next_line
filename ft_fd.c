#include <fcntl.h>
#include <stdio.h>

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

