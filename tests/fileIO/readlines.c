//
// Created by wein on 4/12/18.
//

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <loadFile.h>
#include <testdata.h>

void RunTinyTests();

static fcw_t *fcw = NULL;

void SetUpGlobal() {
    fcw = LoadFile(testDataPath("rapidxml.hpp"));
}

void TearDownGlobal() {
    UnloadFile(fcw);
}

void test_searchForCharExpectNotFound() {
    // https://linux.die.net/man/3/memrchr
    assert(! memchr(fcw->buf, '^', fcw->sz));
}

void test_readNLinesFromBuffer() {
    char *lineBuf = NULL;
    FILE *f = fmemopen(fcw->buf, fcw->sz, "r");
    size_t sz = 0;
    int nlines = 4;

    // http://man7.org/linux/man-pages/man3/getline.3.html
    for (int i=0; i < nlines && getline(&lineBuf, &sz, f); ++i) {
        ;
    }
    fclose(f);

    // see:
    // https://stackoverflow.com/questions/35085702/reading-a-c-string-line-by-line
    // https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
    if (lineBuf) free(lineBuf);
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}