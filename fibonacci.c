#include <stdio.h>
#include <stdlib.h>

#define INT_SIZE 100000

int a[INT_SIZE];
int b[INT_SIZE];
int sequence = 0;
int int_bytes = 1;

void add_ints(int a[], int b[]) {
    int carry=0;
    for(int i=0; i<INT_SIZE; i++) {
        if (i > int_bytes) {
            return;
        }
        a[i] = a[i] + b[i] + carry;
        if (a[i] < 1000000000) {
            carry = 0;
        } else {
            carry = 1;
            a[i] = a[i] % 1000000000;
            if (i == int_bytes) {
                int_bytes++;
            }
        }
    }
}

void print_int(int sequence, int a[]) {
    int start = 0;
    for(int i=(INT_SIZE-1); i>= 0; i--) {
        if (start || a[i] > 0) {
            if (! start) {
                printf("% 10d> %d", sequence, a[i]);
                start = 1;
            } else {
                printf("%09d", a[i]);
            }
        }
    }
    printf("\n");
}

void init_int(int sequence, int a[]) {
    a[0] = 1;
    for(int i=1; i<INT_SIZE; i++) {
        a[i] = 0;
    }
}

int main() {
    sequence++;
    init_int(sequence, a);
    sequence++;
    init_int(sequence, b);
    while (1) {
        sequence++;
        if (sequence & 1) {
            add_ints(b, a);
        } else {
            add_ints(a, b);
            if ((sequence % 100) == 0) {
                print_int(sequence, a);
            }
        }
    }
}
