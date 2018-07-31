#include <stdio.h>
#include <stdint.h>

void print_void_pointer() {
    printf("%p\n", (void *)0xDEADBEEF);
}

int main() {
    print_void_pointer();
    return 0;
}
