
#include <unistd.h>
#include <stdio.h>

int main() {
    const size_t blockSize = 4096;
    char buf[blockSize];
    size_t bytesRead = read(0, buf, blockSize);
    printf("read: %d\n", (int)bytesRead);
    return 0;
}

