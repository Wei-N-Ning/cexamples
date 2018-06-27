
#include <testdata.h>
#include <stdio.h>
#include <assert.h>
#include <memory.h>

// gnu
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

void RunTinyTests();

void test_getDirPath() {
    const char *dirPath = testDir();
    assert(dirPath);
}

void test_expectValidDir() {
    const char *dirPath = testDir();
    struct dirent *dir = NULL;
    DIR *d = opendir(dirPath);
    assert(d);
    dir = readdir(d);
    assert(dir);
    assert(dir->d_name);
    closedir(d);
}

void test_getTestDataPath() {
    const char *filePath = testDataPath("1");
    assert(filePath);
}

// useless
void xtest_givenExcessivelyLongPartialPathExpectFailed() {
    const char *filePath = testDataPath(
        "1111111111111111111111111111111111"
        "1111111111111111111111111111111111");
    printf("%s\n", filePath);
    assert(! filePath);
}

void test_expectValidFile() {
    const char *filePath = testDataPath("1");
    char buf[0x40];
    int f = open(filePath, O_RDONLY);
    ssize_t nread = 0;
    assert(-1 != f);
    memset(buf, 0, 0x40);
    nread = read(f, buf, 0x40);
    close(f);
    assert(14 == nread);
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}
