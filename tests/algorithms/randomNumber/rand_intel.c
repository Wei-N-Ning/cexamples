//
// Created by wein on 5/9/18.
//

#include <stdio.h>

#include <emmintrin.h>

#include "shortcut.h"

__attribute__ ((aligned (16))) static __m128i cur_seed;

static void srand_sse( unsigned int seed ) {
    cur_seed = _mm_set_epi32( seed, seed+1, seed, seed+1 );
}

static void rand_sse( unsigned int* result ) {
    __attribute__ ((aligned (16))) __m128i cur_seed_split;
    __attribute__ ((aligned (16))) __m128i multiplier;
    __attribute__ ((aligned (16))) __m128i adder;
    __attribute__ ((aligned (16))) __m128i mod_mask;
    __attribute__ ((aligned (16))) __m128i sra_mask;
    __attribute__ ((aligned (16))) __m128i sseresult;
    __attribute__ ((aligned (16))) static const unsigned int mult[4] = { 214013, 17405, 214013, 69069 };
    __attribute__ ((aligned (16))) static const unsigned int gadd[4] = { 2531011, 10395331, 13737667, 1 };
    __attribute__ ((aligned (16))) static const unsigned int mask[4] = { 0xFFFFFFFF, 0, 0xFFFFFFFF, 0 };
    __attribute__ ((aligned (16))) static const unsigned int masklo[4] = { 0x00007FFF, 0x00007FFF, 0x00007FFF, 0x00007FFF };

    adder = _mm_load_si128( (__m128i*) gadd);
    multiplier = _mm_load_si128( (__m128i*) mult);
    mod_mask = _mm_load_si128( (__m128i*) mask);
    sra_mask = _mm_load_si128( (__m128i*) masklo);
    cur_seed_split = _mm_shuffle_epi32( cur_seed, _MM_SHUFFLE( 2, 3, 0, 1 ) );

    cur_seed = _mm_mul_epu32( cur_seed, multiplier );
    multiplier = _mm_shuffle_epi32( multiplier, _MM_SHUFFLE( 2, 3, 0, 1 ) );
    cur_seed_split = _mm_mul_epu32( cur_seed_split, multiplier );

    cur_seed = _mm_and_si128( cur_seed, mod_mask);
    cur_seed_split = _mm_and_si128( cur_seed_split, mod_mask );
    cur_seed_split = _mm_shuffle_epi32( cur_seed_split, _MM_SHUFFLE( 2, 3, 0, 1 ) );
    cur_seed = _mm_or_si128( cur_seed, cur_seed_split );
    cur_seed = _mm_add_epi32( cur_seed, adder);

    sseresult = _mm_srai_epi32( cur_seed, 16);
    sseresult = _mm_and_si128( sseresult, sra_mask );
    _mm_storeu_si128( (__m128i*) result, sseresult );
}

int genNRandomNums(int *o_arr, int sz, unsigned int seed) {
    __attribute__ ((aligned (16))) unsigned int tmp[4];
    __attribute__ ((aligned (16))) unsigned int one;
    int trunk = sz / 4 + 1;
    srand_sse(seed);
    while (trunk > 0) {
        rand_sse(tmp);
        for (int i = 0; i < 4 && sz > 0; ++i) {
            one = tmp[i];
            o_arr[sz - 1] = (int)one;
            sz--;
        }
        trunk--;
    }
    return 1;
}

#define sz 13
#define sz_large 0x7FFF

void RunTinyTests();

void test_perf() {
    int arr[sz];
    int arr_large[sz_large];
    unsigned int seed = 231245;
    genNRandomNums(arr, sz, seed);
    PRINT_ARR(arr, sz, "%d, ");
    genNRandomNums(arr_large, sz_large, seed);
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}
