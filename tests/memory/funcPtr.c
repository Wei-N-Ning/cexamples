//
// Created by wein on 4/14/18.
//

int add(int a, int b) {
    int z = a + b;
    return z;
}

// Dump of assembler code for function add:
//   0x00000000004005b6 <+0>:     push   rbp
//   0x00000000004005b7 <+1>:     mov    rbp,rsp
// ....
// caller (main)
// pointer variable
//   0x00000000004005df <+15>:    mov    QWORD PTR [rbp-0x8],0x4005b6
// prepare to call function
//   0x00000000004005e7 <+23>:    mov    rax,QWORD PTR [rbp-0x8]
// pass function arguments
//   0x00000000004005eb <+27>:    mov    esi,0x1e
//   0x00000000004005f0 <+32>:    mov    edi,0xa
//   0x00000000004005f5 <+37>:    call   rax
int main(int argc, char **argv) {
    int (*funcPtr)(int, int) = add;
    funcPtr(10, 30);
    return 0;
}
