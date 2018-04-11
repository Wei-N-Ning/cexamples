//
// Created by wein on 4/12/18.
//

#include "loadFile.h"

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


int64_t fileSize(const char *filePath) {
    struct stat st;
    stat(filePath, &st);
    return st.st_size;
}

fcw_t *LoadFile(const char *filePath) {
    size_t sz;
    struct stat st;
    void *buf = NULL;
    int fd;
    fcw_t *f = NULL;
    stat(filePath, &st);
    sz = (size_t)st.st_size;
    buf = malloc(sz);
    fd = open(filePath, O_RDONLY);
    read(fd, buf, sz);
    close(fd);
    f = malloc(sizeof(fcw_t));
    f->buf = buf;
    f->sz = sz;
    f->path = filePath;
    return f;
}

void UnloadFile(fcw_t *f) {
    if (f->buf) {
        free(f->buf);
        f->buf = NULL;
    }
    free(f);
}
