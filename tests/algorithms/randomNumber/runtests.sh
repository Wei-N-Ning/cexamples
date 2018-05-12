#!/usr/bin/env bash

function buildRandIntelSSE() {
    if ! ( gcc -shared -fPIC -o /tmp/intel.so rand_intel.c )
    then
        echo "fail to build rand() using intel sse intrinsics"
        exit 1
    fi
}

function buildRandStdC() {
    if ! ( gcc -shared -fPIC -o /tmp/stdc.so rand_orig_LCG.c )
    then
        echo "fail to build rand() using std c implementation"
        exit 1
    fi
}

function randIntelSSEIntegrityTest() {
    echo "
from __future__ import print_function
import ctypes, time
m = ctypes.cdll.LoadLibrary('/tmp/intel.so')
sz = 13
seed = 231245
arr_decl = ctypes.c_int * sz
arr = arr_decl()
m.genNRandomNums(arr, sz, seed)
expected = [
    16797, 19094, 4469, 13400, 10440, 3943, 9905, 24635,
    15367, 14335, 1697, 28804, 1526,
]
actual = list(arr)
assert expected == actual, 'num sequence is unexpected:\n{}\n'.format(actual)

sz_large = 0x7FFFF
seed = 2312401
arr_large_decl = ctypes.c_int * sz_large
arr_large = arr_large_decl()
start = time.time()
m.genNRandomNums(arr_large, sz_large, seed)
print('intel: {:.04f}'.format(time.time() - start))
" > /tmp/intel.py
    python /tmp/intel.py
}

function randStdCIntegrityTest() {
    echo "
from __future__ import print_function
import ctypes, time
m = ctypes.cdll.LoadLibrary('/tmp/stdc.so')
sz = 13
seed = 231245
arr_decl = ctypes.c_int * sz
arr = arr_decl()
m.genNRandomNums(arr, sz, seed)
expected = [
    1523, 4618, 25344, 25502, 19896, 14398, 30746, 3180,
    7482, 25905, 13082, 22819, 29738
]
actual = list(arr)
assert expected == actual, 'num sequence is unexpected:\n{}\n'.format(actual)

sz_large = 0x7FFFF
seed = 2312401
arr_large_decl = ctypes.c_int * sz_large
arr_large = arr_large_decl()
start = time.time()
m.genNRandomNums(arr_large, sz_large, seed)
print('stdc: {:.04f}'.format(time.time() - start))
" > /tmp/stdc.py
    python /tmp/stdc.py
}

buildRandIntelSSE
randIntelSSEIntegrityTest
buildRandStdC
randStdCIntegrityTest
