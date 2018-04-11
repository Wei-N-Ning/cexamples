//
// Created by wein on 4/12/18.
//

#ifndef CEXAMPLES_LOADFILE_H
#define CEXAMPLES_LOADFILE_H

#include <stdlib.h>

struct FileContentWrapper {
    void *buf;
    size_t sz;
    const char *path;
};

typedef struct FileContentWrapper fcw_t;

int64_t fileSize(const char *filePath);

fcw_t *LoadFile(const char *filePath);

void UnloadFile(fcw_t *f);

#endif //CEXAMPLES_LOADFILE_H
