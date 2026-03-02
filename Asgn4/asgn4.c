#include <stdio.h>
#include "asgn4.h"

int main(void) {
    printf("Task 1: isBitSet\n");
    printf("isBitSet(23, 4) = %d (expected 1)\n", isBitSet(23, 4));
    printf("IsBitSet(23, 3) = %d (expected 0)\n", isBitSet(23, 3));

    printf("\nTask 2: setBit\n");
    printf("setBit(5, 3) = %d (expected 13)\n", setBit(5, 3));

    printf("\nTask 3: clearBit\n");
    printf("clearBit(15, 1) = %d ( expected 13)\n", clearBit(15, 1));

    printf("\nTask 4: toggleBit\n");
    printf("toggleBit(8, 3) = %d (expected 0)\n", toggleBit(8, 3));

    printf("\nTask 5: shifts\n");
    printf("multiplyBy2(7) = %d (expected 14)\n", multiplyBy2(7));
    printf("divideBy2(18) = %d (expected 9)\n", divideBy2(18));

    printf("\nTask 6: countSetBits\n");
    printf("countSetBits(23) = %d (expected 4)\n", countSetBits(23));
}