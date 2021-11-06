#include <stdio.h>
#include <unistd.h>

unsigned int snooze(unsigned int secs) {
    int r = sleep(secs);
    printf("Slept for %d of %d secs", secs - r, secs);
    return r;
}

int main() {
    printf("start\n");
    snooze(5);
    printf("end\n");
    return 0;
}

