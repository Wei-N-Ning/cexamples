//
// Created by wein on 5/23/18.
//

/*
 * 11      int main() {
   0x00000000004006c4 <+0>:     55      push   rbp
   0x00000000004006c5 <+1>:     48 89 e5        mov    rbp,rsp
   0x00000000004006c8 <+4>:     48 83 ec 10     sub    rsp,0x10
   0x00000000004006cc <+8>:     64 48 8b 04 25 28 00 00 00      mov    rax,QWORD PTR fs:0x28
   0x00000000004006d5 <+17>:    48 89 45 f8     mov    QWORD PTR [rbp-0x8],rax
   0x00000000004006d9 <+21>:    31 c0   xor    eax,eax

12          pthread_t thread;
13          pthread_create(&thread, NULL, worker, NULL);
   0x00000000004006db <+23>:    48 8d 45 f0     lea    rax,[rbp-0x10]
   0x00000000004006df <+27>:    b9 00 00 00 00  mov    ecx,0x0
   0x00000000004006e4 <+32>:    ba b6 06 40 00  mov    edx,0x4006b6
   0x00000000004006e9 <+37>:    be 00 00 00 00  mov    esi,0x0
   0x00000000004006ee <+42>:    48 89 c7        mov    rdi,rax
   0x00000000004006f1 <+45>:    e8 7a fe ff ff  call   0x400570 <pthread_create@plt>

14          pthread_join(thread, NULL);
   0x00000000004006f6 <+50>:    48 8b 45 f0     mov    rax,QWORD PTR [rbp-0x10]
   0x00000000004006fa <+54>:    be 00 00 00 00  mov    esi,0x0
   0x00000000004006ff <+59>:    48 89 c7        mov    rdi,rax
   0x0000000000400702 <+62>:    e8 99 fe ff ff  call   0x4005a0 <pthread_join@plt>

15          return 0;
   0x0000000000400707 <+67>:    b8 00 00 00 00  mov    eax,0x0

16      }
   0x000000000040070c <+72>:    48 8b 55 f8     mov    rdx,QWORD PTR [rbp-0x8]
   0x0000000000400710 <+76>:    64 48 33 14 25 28 00 00 00      xor    rdx,QWORD PTR fs:0x28
   0x0000000000400719 <+85>:    74 05   je     0x400720 <main+92>
   0x000000000040071b <+87>:    e8 60 fe ff ff  call   0x400580 <__stack_chk_fail@plt>
   0x0000000000400720 <+92>:    c9      leave
   0x0000000000400721 <+93>:    c3      ret
 *
 * */

#include <pthread.h>

void *worker(void *arg) {
    return arg;
}

// source:
// pthread_create()
// https://code.woboq.org/userspace/glibc/nptl/pthread_create.c.html
int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, worker, NULL);
    pthread_join(thread, NULL);
    return 0;
}
