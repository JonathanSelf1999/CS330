#ifndef __asgn4__
#define __asgn4__

/*
isValidPosition

checks to see if a given bit position is valid for an in on this machine

why: Shifting by a negative amount or a amount less than or equal to the bits in an in is not valid. this helper pervents
invalid bit positions.

Arguments:
    position - the bit index the individual wants to access (0 being the least significant bit)
    
Returns:
    1 if the position is within [0,(#bits in int) - 1]
    0 otherwise
*/
static int isValidPosition(int position) {
    int width = (int)(sizeof(int) * 8);
    return (position >= 0 && position < width);
}

/*
isBitSet
This function dtermines whether the bit at a given position in 'number' is set (equals 1).

why:
    To test a single bit, we create a mask with a 1 at the desired position
    (1 << position) and & it with the number. if the result is non-zero, that bit must
    have been a 1
    
Arguments:
    number - The integer value 
    position - The bit index 
    
returns:
    1 if the bit is 1
    0 if the bit is 0 or if the position is invalid.
*/
int isBitSet(int number, int position) {

    if (!isValidPosition(position)) return 0;

    return ((number & (1 << position)) != 0) ? 1 : 0;
}
/*setBit
Sets the bit at a given position in 'number' to 1.

why:
    ORing with a mask that has a 1 at the target forces that bit to 1
    while leaving all other bits unchanged
    
Arguments:
    number - the integer to modify
    position - the bit index to set
    
Returns:
    The updated integer with the specfied bit set to 1 
    the original number if the positon is not valid
*/
int setBit(int number, int position) {

    if(!isValidPosition(position)) return number;

    return (number | (1 << position));
}
/*
clearBit
Clears (sets to 0) the bit at a postion in 'number'.

why:
    We build a mask with a 1 at the target position (1 << position),
    invert it so the target bit becomes 0 and all others are 1 ~mask, then & it with
    the number to force that bit to 0
    
Arguments:
    Number - the integer value that will modify
    position - the bit index to clear
    
Returns:
    The updated integer with the specfied bit cleared to 0
    or the orginal number if the position is not valid.
*/
int clearBit(int number, int position) {
    if (!isValidPosition(position)) return number;

    return (number & ~(1 << position));
}
/*toggleBit
Flips the bit at a given position in 'number' 0 would flip to 1 and vice versa

why:
    XOR toggle bits: if the mask bit is 1 XOR flips tha bit; if mask bit is 0, 
    XOR leaves that bit unchanged. using a mask (1 << position) flips exactly one bit.
    
Arguments:
    number - the ineger value 
    position - The bit index to toggle
    
Returns:
The updated int with the specfied bit toggled 
or the original number if the position is not valid.*/
int toggleBit(int number, int position) {

    if (!isValidPosition(position)) return number;

    return (number ^ (1 << position));
}
/*multiplyBy2
Multiplies an integer by 2 using a left shift.

why:
    left shifting by 1 moves all bits left one position, this is equivalent to multiplying by 2 
    in binary arithmetic.
    
Arguments:
 number - the integer to multiply
 
 Returns:
 the integer * 2 (computed as number << 1)
 */
int multiplyBy2(int number) {
    return (number << 1);
}
/*divideBy2
Divides an integer by 2 using a right shift

why:
     right shifting by 1 moves all bits right one position, which equates to dividing a number by 2
     for non-negative integers in binary arithmetic.
     
Arguments:
    number - the integer to divide
    
Returns:
    number / 2 (computed as number >> 1)
*/
int divideBy2(int number) {
    return (number >> 1);
}
/*
countSetBits (Bonus)
Counts how many bits are set to 1 in the binary representation of 'number'.

why:
    Repeadtedly checking the least signficant bit (x & 1) tells us whether the current bit is 1. Shifting right
    moves the next bit into the LSB position this loops through all bits until the value becomes 0.
    
Arguments
    number - the integer whose set bits should be counted 
    
Returns:
    The number of 1 bits in 'number'
*/
int countSetBits(int number) {

    unsigned int x = (unsigned int)number;
    int count = 0;

    while (x != 0u) {
        count += (int)(x & 1u);
        x >>= 1;
    }
    return count;
}
#endif