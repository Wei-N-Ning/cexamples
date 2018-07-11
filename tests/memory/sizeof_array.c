
#include <assert.h>

int main() {
    int arr[] = {1, 2, 3, 3, 4};
    
    // number of bytes
    assert(sizeof(arr) == 5 * sizeof(int));
    
    // number of elements
    assert(5 == sizeof(arr) / sizeof(int));

    return 0;
}
