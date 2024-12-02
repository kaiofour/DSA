#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * SETS are a collection of unique elements:
 * characteristics:
 * -order doesn't matter
 * -sets are a subsets of its universal set in which the
 * number of elems in a subset is less than or equal to the
 * number of elems in the universal set.
 */

/**
 * implementations: Array, LL, Bit-Vector, Comp-Word
 */

//OPERATIONS: UID (Union, Intersection, Difference)

//BIT VECTOR = ONE-DIMENSIONAL array of BINARY DIGITS

/**
 * sizeof(universalSet) == sizeof(subsets)
 *      -this is regardless of the subset's
 *      number of elements.
 */

/**
 * PROS OF BIT VECTOR
 * - 0(1)
 * - Array implementation of sets
 * - Best implementation of an ADT set
 * - Size if a subset is proportional to its universal set
 */

/**
 * Pre-requisites of Bit-Vector
 * 1. Decimal to Binary Conversion
 * 2. 2's complement AND/OR shortcut
 * 3. BITWISE operators (&, |, ^, ~)
 * 4. SHIFT operations (left shift: <<, right shift: >>)
 *      -logical (0 padding as unsigned)
 *      arithmetic (designated signed bit)
 */

/**
 * Explanation of 2's Complement
 *      -representation of negative numbers in binary
 * example
 * 28 = 0001 1100
 * ~28 = 1110 0011
 * +1 =         1
 * _______________
 * -28 = 1110 0100 (negative 28)
 * 
 */

int main()
{

    return 0;
}