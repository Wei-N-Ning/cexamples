//
// Created by wein on 5/9/18.
//

#include <stdio.h>

#include "shortcut.h"

static unsigned int g_seed;

//Used to seed the generator.
static void fast_srand( int seed ) {
    g_seed = seed;
}

//fastrand routine returns one integer, similar output value range as C lib.
static int fastrand() {
    g_seed = (214013 * g_seed + 2531011);
    return (g_seed >> 16) & 0x7FFF;
}

#define MAX_N 1048576
static int arr[MAX_N];

// in Python:
// sz = 255
// arr_decl = ctypes.c_int * sz
// arr = arr_decl()
// m.genNRandomNums(arr, sz, 123)
// see also:
// https://stackoverflow.com/questions/4145775/how-do-i-convert-a-python-list-into-a-c-array-by-using-ctypes
int genNRandomNums(int *o_arr, int sz, int seed) {
    fast_srand(seed);
    GEN_ARR(o_arr, sz, fastrand);
    return 1;
}

int printNRandomNums(int sz, int seed) {
    sz = (sz > MAX_N) ? MAX_N : sz;
    fast_srand(seed);
    GEN_ARR(arr, sz, fastrand);
    PRINT_ARR(arr, sz, "%d,");
    return 1;
}

//440,19053,23075,13104,32363,
//802,32478,7150,29924,30401,
//440,19053,23075,13104,32363,
//void main(void) {
//    printNRandomNums(5, 123);
//    printNRandomNums(5, 234);
//    printNRandomNums(5, 123);
//}
