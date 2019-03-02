#include <stdio.h>
#include <stdlib.h>

void read_n(int *);
void PrintData(int, int *, int);
void Split(int, int, int *, int);
int input(const char *, int *);

main() {

    /* Initializing variables */
    int n, *A;

    /* I/O flow && VarCheck */
    read_n(&n);

    /* Main part */
    A = (int *) malloc(sizeof(int) * n);
    Split(n, n, A, 0);
    free(A);
}

void read_n(int *n) {

    /* I/O flow && VarCheck */
    while (1) {
        input("Type natural number \"n\": ", n);
        if (*n > 0) {
            break;
        } else {
            printf("Error! \"n\" must be natural!\n\n");
            continue;
        }
    }
}

void PrintData(int initial, int *Data, int N) {

    /* Initializing variables */
    int i;

    /* Main part */
    printf("%d =", initial);
    for (i = 0; i < N; i++ ) {
        printf(" %d %s", Data[i], (N - i == 1) ? "\n" : "+");
    }
}

void Split(int initial, int R, int *A, int q) {

    /* Initializing variables */
    int i, last = R;

    /* Main part */
    if (!R) {
        PrintData(initial, A, q);
    } else {
        if (q > 0 && last > A[q-1]) {
            last = A[q-1];
        }
        for (i = 1; i <= last; i ++ ) {
            A[q] = i;
            Split(initial, R - i, A, q + 1);
        }
    }
}

int input(const char *out, int *res) {

    /* This function allows you to assign some integer value to a variable. If you type something but integer,
     * the program asks you to type proper value. It's an endless loop, so you must type an integer */

    /* Initializing variables */
    int a, flag = -1, multiplier = 1, counter = 0, flag2 = 0;
    *res = 0;

    /* Main part */
    while (1) {
        printf("%s", out); /* Prints user-specified string */
        while (1) {
            a = getchar(); /* Gets one typed char at a time */
            if (a == '-' && flag == -1 && !flag2) { /* Detects a negative sign */
                multiplier = -1;
                flag2 = 1;
                continue;
            } else if (a == '+' && flag == -1 && !flag2) { /* Detects a positive sign */
                multiplier = 1;
                flag2 = 1;
                continue;
            } else if (a >= '0' && a <= '9' && flag != 0) { /* Detects digits */
                *res = (*res * 10) + (a - '0'); /* Making of the answer */
                flag = 1; /* «1» if a digit was detected */
                ++counter; /* Counts a number of successfully scanned digits */
            } else if (a != '\n') { /* Detects «garbage» */
                flag = 0; /* «0» if «garbage» was detected */
                *res = 0; /* Answer is equals to zero now */
                counter = 0;
                multiplier = 1;
            } else if (a == '\n') { /* Detects End-Of-Line char */
                break; /* End-Of-Line («Enter button usually) is the only way to finish a number */
            }
        }
        if (flag == 1) { /* Checks whether only digits were typed */
            break; /* Congrats! Your number were successfully scanned */
        }
        flag = -1; /* «-1» if a previous attempt to scan a number was a fail */
    }
    *res *= multiplier; /* Applies negative sign, if necessary */

    return counter; /* Returns a number of successfully scanned digits */
}
