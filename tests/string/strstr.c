
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

void RunTinyTests();

const char* __strstr(const char* haystack, const char* needle) {
    while (*haystack) {
        const char* needle_p = needle;
        const char* curr = haystack;
        while (*needle_p && *haystack) {
            if (*needle_p == *haystack) {
                ++needle_p, ++haystack;
            } else {
                ++haystack;
                break;
            }
        }
        if (*needle_p == '\0') {
            return curr;
        }
    }
    return NULL;
}

// take 2 - seems cleaner
const char* _strstr(const char* h, const char* n) {
    typedef const char* P;
    while (*h) {
        for (P ndl = n, curr = h; *h; ) {
            if (*h == *ndl) {
                ++h; ++ndl;
            } else {
                ++h; break;
            }
            if (! *ndl) {
                return curr;
            }
        }
    }
    return 0x0;
}


void _assert(const char* haystack, const char* needle, const char *expected) {
    haystack = _strstr(haystack, needle);
    if (expected == NULL) {
        assert(haystack == NULL);
    } else {
        assert(0 == strcmp(expected, haystack));
    }
}

void test_needle_in_the_middle() {
    _assert("iddqdidkfa", "d", "ddqdidkfa");
    _assert("iddqdidkfa", "dd", "ddqdidkfa");
    _assert("iddqdidkfa", "did", "didkfa");
    _assert("iddqdidkfa", "kf", "kfa");
}

void test_needle_at_the_beginning() {
    _assert("iddqdidkfa", "id", "iddqdidkfa");
    _assert("iddqdidkfa", "iddqdi", "iddqdidkfa");
}

void test_needle_at_the_end() {
    _assert("iddqdidkfa", "fa", "fa");
    _assert("iddqdidkfa", "qdidkfa", "qdidkfa");
}

void test_unmatch() {
    _assert("iddqdidkfa", "idnoclip", NULL);
    _assert("iddqdidkfa", "idd...", NULL);
    _assert("iddqdidkfa", "kfa..", NULL);
}

int main() {
    RunTinyTests();
    return 0;
}
