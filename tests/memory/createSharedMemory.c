//
// Created by wein on 6/14/18.
//

// source
// https://stackoverflow.com/questions/5656530/how-to-use-shared-memory-with-linux-in-c

#include <sys/mman.h>
#include <unistd.h>
#include <assert.h>
#include <memory.h>
#include <stdlib.h>

void* createSharedMemory(size_t size) {
    int protection = PROT_READ | PROT_WRITE;
    int visibility = MAP_ANONYMOUS | MAP_SHARED;
    return mmap(NULL, size, protection, visibility, 0, 0);
}

int main() {
    size_t sz = 128;
    void* shmem = createSharedMemory(sz);
    memset(shmem, 0, sz);

    int pid = fork();

    if (pid == 0) {
        // child
        *(int *)shmem = 0xDEAD;
    } else {
        // parent
        sleep(1);
        assert(0xDEAD == *(int *)shmem);
    }

    // parent tears down and returns
    munmap(shmem, sz);
    return 0;
}
