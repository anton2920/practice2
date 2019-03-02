#include <stdio.h>

void read_n(int *);

main() {

    /* Initializing variables */
    int n;

    /* I/O flow && VarCheck */
    read_n(&n);

    /* Main part */

}

void read_n(int *n) {

    /* I/O flow && VarCheck */
    while (1) {
        printf("Type natural number «n»: ");
        scanf("%d", n);
        if (*n > 0) {
            break;
        } else {
            printf("Error! «n» must be natural!\n\n");
            continue;
        }
    }
}

