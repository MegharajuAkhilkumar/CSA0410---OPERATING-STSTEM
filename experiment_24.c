#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char write_data[] = "Hello UNIX";
    char read_data[20];

    fd = open("file.txt", O_CREAT | O_RDWR, 0644);

    if(fd == -1) {
        printf("File cannot be opened\n");
        return 1;
    }

    write(fd, write_data, sizeof(write_data) - 1);

    lseek(fd, 0, SEEK_SET);

    read(fd, read_data, sizeof(write_data) - 1);
    read_data[sizeof(write_data) - 1] = '\0';

    printf("File Content: %s\n", read_data);

    close(fd);

    return 0;
}