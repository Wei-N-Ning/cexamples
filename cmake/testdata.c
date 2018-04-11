
#include "testdata.h"

#include <stddef.h>
#include <memory.h>

#define __BUF_SIZE__ 0x78
static char buf[__BUF_SIZE__];
static size_t s_testDataDirPathLen = 0;

const char *testDataPath(const char *partialPath) {
    const char *dir = testDir();
    size_t sz = strlen(partialPath);
    if (sz > (__BUF_SIZE__ - s_testDataDirPathLen - 1) - 1) {
        return NULL;
    }
    memset(buf, 0, __BUF_SIZE__);
    memcpy(buf, dir, s_testDataDirPathLen);
    buf[s_testDataDirPathLen] = '/';
    memcpy(buf + s_testDataDirPathLen + 1, partialPath, sz);
    return buf;
}

const char *testDir() {
    if (! s_testDataDirPathLen) {
        s_testDataDirPathLen = strlen(TESTDATA_DIR);
    }
    return TESTDATA_DIR;
}
