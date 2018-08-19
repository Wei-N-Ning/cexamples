
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

void RunTinyTests();

const char* _strstr(const char* haystack, const char* needle) {
    // iterate over the characters in haystack
    for (; *haystack != '\0'; ++haystack) {
        // iterate over the characters in needle;
        // or start over again
        const char* curr = haystack;
        for (const char* needle_p = needle; *haystack != *needle_p; ++needle_p, ++haystack ) {
            if (*needle_p == '\0') {
                return curr;
            }
        }
    }
    return 0x0;
}

void test_needle_in_the_middle() {
    const char* needle = 0x0;
    needle = _strstr("iddqdidkfa", "did");
    assert(needle);
    assert(0 == strcmp("didkfa", needle));

    needle = _strstr("iddqdidkfa", "didkfa........");
    assert(needle);
    assert(0 == strcmp("didkfa", needle));
}

void test_needle_at_the_beginning() {
    const char* needle = 0x0;

    needle = _strstr("iddqdidkfa", "idd");
    assert(needle);
    assert(0 == strcmp("iddqdidkfa", needle));
}

int main() {
    RunTinyTests();
    return 0;
}
