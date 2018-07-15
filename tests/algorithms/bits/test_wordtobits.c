#include <stdint.h>
#include <assert.h>

int main() {
    uint32_t word = 0xDEADBEEF;
    uint8_t bits[4] = {0xDE, 0xAD, 0xBE, 0xEF};
    
    assert( bits[0] == ((word & 0xFF000000) >> 24) );
    assert( bits[1] == ((word & 0xFF0000) >> 16) );
    assert( bits[2] == ((word & 0xFF00) >> 8) );
    assert( bits[3] == (word & 0xFF) );
    return 0;
}
