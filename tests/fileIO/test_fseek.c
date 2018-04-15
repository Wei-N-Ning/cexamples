//
// Created by wein on 4/15/18.
//

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <loadFile.h>
#include <testdata.h>

void RunTinyTests();

void test_goToEndOfFile() {
    const char *filePath = testDataPath("1");
    FILE *fp = fopen(filePath, "r");
    int success = fseek(fp, 0x0, SEEK_END);
    fclose(fp);
    assert(0 == success);
}

static int64_t fileSize2(const char *filePath) {
    FILE *fp = fopen(filePath, "r");
    fseek(fp, 0, SEEK_END);
    long sz = ftell(fp);
    fclose(fp);
    return sz;
}

void test_fileSize() {
    int64_t sz = fileSize2(testDataPath("rapidxml.hpp"));
    assert(118341 == sz);
}

void test_resetFilePointerPosition() {
    FILE *fp = fopen(testDataPath("1"), "r");
    char buf[64]; for(size_t i=sizeof(buf); i--; buf[i] = 0) ;
    size_t sz = fread(buf, sizeof(char), sizeof(buf), fp);
    rewind(fp);
    fread(buf + sz, sizeof(char), sizeof(buf), fp);
    fclose(fp);
    assert(28 == strlen(buf));
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}