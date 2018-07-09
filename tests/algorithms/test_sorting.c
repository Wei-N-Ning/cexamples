//
// Created by wein on 4/22/18.
//

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void RunTinyTests();

int _cmpInts(const void *lhs, const void *rhs) {
    int lhs_v = *((int *)lhs);
    int rhs_v = *((int *)rhs);
    if (lhs_v == rhs_v) {
        return 0;
    }
    else if (lhs_v > rhs_v) {
        return 1;
    }
    return -1;
}

int _prtInts(const int *arr, size_t sz) {
    for (size_t i = sz; i--; printf("%d ", arr[sz - 1 - i]) ) ;
    return 0;
}

void test_qsortPrimtives() {
    int sut[8] = {31, 4, 15, 92, 6, 5, 35, 897};
    qsort(sut, 8, sizeof(int), _cmpInts);
    _prtInts(sut, 8);
}

int _cmpIPointers(const void *lhs, const void *rhs) {
    int lhs_v = **((int**)lhs);
    int rhs_v = **((int**)rhs);
    if (lhs_v == rhs_v) {
        return 0;
    }
    else if (lhs_v > rhs_v) {
        return 1;
    }
    return -1;
}

int _prtPointers(int **sut, size_t sz) {
    for (size_t i = sz; i--; printf("%d ", *(sut[sz - 1 - i]))) ;
    return 0;
}

void test_qsortPointers() {
    int *store = malloc(8 * sizeof(int));
    for (int i = 8; i--; store[i] = (23 - i) + (23 + i * 2) * (i % 2)) ;
    int *sut[8];
    for (size_t i = 0; i < 8; ++i) {
        sut[i] = store + i;
    }
    qsort(sut, 8, sizeof(int *), _cmpIPointers);
    _prtPointers(sut, 8);
    free(store);
}

#define MONSTER_NAME_LENGTH 32

struct Monster {
    char name[MONSTER_NAME_LENGTH];
    int price;
    int damage;
};
typedef struct Monster Monster;

double damageRatio(Monster *m) {
    return (double)(m->damage) / (double)(m->price);
}

int _cmpMonsters(const void *lhs, const void *rhs) {
    double lhs_v = damageRatio(*(Monster **)(lhs));
    double rhs_v = damageRatio(*(Monster **)(rhs));
    double d = lhs_v - rhs_v;
    if (fabs(d) < 1e-7) {
        return 0;
    }
    else if (d > 0) {
        return 1;
    }
    return -1;
}

void _prtMonsters(Monster **arr, size_t sz) {
    for (size_t i = 0; i < sz ; ++i) {
        printf("%s: %d/%d, ", arr[i]->name, arr[i]->damage, arr[i]->price);
    }
}

Monster *createMonster(const char *name, int damage, int price) {
    Monster *m = malloc(sizeof(Monster));
    memset(m->name, 0, MONSTER_NAME_LENGTH);
    memcpy(m->name, name, MONSTER_NAME_LENGTH);
    m->damage = damage;
    m->price = price;
    return m;
}

void deleteMonster(Monster *m) {
    free(m);
}

// beware of how the comparison function is implemented:
// *(Monster **)(lhs)
void test_qsortStructs() {
    Monster *arr[8] = {
        createMonster("skeleton", 3, 2),
        createMonster("farmer", 2, 1),
        createMonster("knight", 12, 34),
        createMonster("rogue", 6, 11),
        createMonster("dragon", 40, 99),
        createMonster("angel", 38, 81),
        createMonster("demon", 24, 33),
        createMonster("huntress", 10, 4),
    };
    qsort(arr, 8, sizeof(Monster *), _cmpMonsters);
    _prtMonsters(arr, 8);
    for (size_t i = sizeof(arr) / sizeof(Monster *); i--; deleteMonster(arr[i])) ;
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}