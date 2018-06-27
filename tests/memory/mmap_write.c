#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <memory.h>
#include <stdio.h>

int main() {
    int fd = open("/tmp/dd.img", O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    printf("m\n");
    size_t sz = 1024 * 1024;
    if (lseek(fd, sz, SEEK_SET) == -1) {
        close(fd);
        perror("lseek");
        return 1;
    }
    write(fd, "", 1);
    char *addr = mmap(0, sz, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        close(fd);
        perror("mmap");
        return 1;
    }
    for (int i = 200; i--; ) {
        memset(addr, 9, sz);
    }
    close(fd);
    return 0;
}

