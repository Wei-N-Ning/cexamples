

#if 1 < 2

#define flag 0
#define message "failed"

#else

#define flag 1
#define message "passed"

#endif

int main() {
    _Static_assert(flag, "hrrrrr");
    return 0;
}
