//
// Created by wein on 4/15/18.
//

#include <assert.h>
#include <stdio.h>

#include <testdata.h>

void RunTinyTests();

void test_openNonExistingFileExpectNull() {
    FILE *fp = fopen("/tmp/nonexist", "r");
    assert(! fp);
}

void test_givenEmptyFileExpectNothingRead() {
    const char *filePath = testDataPath("null");
    FILE *fp = fopen(filePath, "r");
    char buf[8];
    size_t sz = fread(buf, 1, 1, fp);
    fclose(fp);
    assert(! sz);
}

void test_readFileExpectNumBytesRead() {
    const char *filePath = testDataPath("1");
    FILE *fp = fopen(filePath, "r");
    char buf[64];
    size_t sz = fread(buf, sizeof(char), sizeof(buf), fp);
    fclose(fp);
    assert(sz < sizeof(buf));
}

// example from CPP reference:
// http://en.cppreference.com/w/c/io/fread
void test_putAllTogether() {
    enum { SIZE = 5 };
    double a[SIZE] = {1.,2.,3.,4.,5.};
    FILE *fp = fopen("/tmp/test.bin", "wb"); // must use binary mode
    fwrite(a, sizeof *a, SIZE, fp); // writes an array of doubles
    fclose(fp);

    double b[SIZE];
    fp = fopen("/tmp/test.bin","rb");
    size_t ret_code = fread(b, sizeof *b, SIZE, fp); // reads an array of doubles
    if(ret_code == SIZE) {
        puts("Array read successfully, contents: ");
        for(int n = 0; n < SIZE; ++n) printf("%f ", b[n]);
        putchar('\n');
    } else { // error handling
        if (feof(fp))
            printf("Error reading test.bin: unexpected end of file\n");
        else if (ferror(fp)) {
            perror("Error reading test.bin");
        }
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}
