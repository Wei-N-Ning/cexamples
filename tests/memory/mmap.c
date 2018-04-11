//
// Created by wein on 4/11/18.
//

#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#include <stddef.h>

// gnu
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <testdata.h>

void RunTinyTests();

static int64_t fileSize(const char *filePath) {
    struct stat st;
    stat(filePath, &st);
    return st.st_size;
}

void test_readMemoryMappedFile() {
    int fd;
    void *p = NULL;
    char buf[0x40];
    const char *filePath = testDataPath("1");
    int64_t sz = fileSize(filePath);
    memset(buf, 0, 0x40);
    assert(14 == sz);
    fd = open(filePath, O_RDONLY);
    p = mmap(NULL, (size_t)sz, PROT_READ, MAP_PRIVATE, fd, 0);
    memcpy(buf, p, (size_t)sz);
    munmap(p, (size_t)sz);
    assert(0 == strcmp("there is a cow", buf));
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}