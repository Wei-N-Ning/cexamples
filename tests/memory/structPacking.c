//
// Created by wein on 4/14/18.
//

#include <assert.h>

void RunTinyTests();

struct Unpacked {
    int a;
    char b;
    int c;
    char t;
};

struct Packed {
    int a;
    int c;
    char b;
    char t;
};

// see:
// https://stackoverflow.com/questions/45116212/are-packed-structs-portable
// start with the largest items first (64 bit then 32 bit the 16 bit then lastly any 8 bit items)
// Ideally align on 32 minimum perhaps 64
void test_nothing() {
    assert(16 == sizeof(struct Unpacked));
    assert(12 == sizeof(struct Packed));
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}
