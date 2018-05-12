//
// Created by wein on 5/9/18.
//

#ifndef CEXAMPLES_SHORTCUT_H
#define CEXAMPLES_SHORTCUT_H

#define GEN_ARR(arr, sz, func) \
for(int i = 0; i < (sz); i++) {\
    (arr)[i] = (func)();\
}

#define PRINT_ARR(arr, sz, ctrl) \
for(int i = 0; i < (sz); i++) {\
    printf((ctrl), (arr)[i]);\
} \
printf("\n");

#endif //CEXAMPLES_SHORTCUT_H
