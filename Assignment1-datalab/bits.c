/* 
 * CS:APP Data Lab 
 * 
 * <Frederik Lohner  102105037>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
   
    /*  Create an int z, take the inverse of x and y and AND them
    6 0110  Inverse 1001
    5 0101  Inverse 1010
    Take AND of Inverses 1000
    Inverse it 0111
    */

  int z;
  z = ~(~x&~y);
  return z;
}
/* 
 * evenBits - return word with all even-numbered bits set to 1s
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  
    /*  Begins with a starting point of 01010101 so that all even numbered bits are 1
        Then shifts over by 8, to obtain 0101010100000000 and uses OR operator to obtain
        0101010101010101, then repeats the process with 16.
    */

    int word = 0x55; //85
    word = word | word<<8;
    return word | word<<16;
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {

/* negative is a signed in of value 0000 0000 which when flipped will become 1111 1111 which due to its signed
nature will become a negative 1 */
  int negative = 0x0;
  return ~negative;
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  
   int allBits;
   int allOdd = (0xAA << 8) | 0xAA; /* (1010 1010 << 8 == 1010 1010 0000 0000) == 1010 1010 1010 1010 */
   allOdd = allOdd | (allOdd << 16); /*int with all odd bits set to 1 == 1010 1010 1010 1010 1010 1010 1010 1010 */
   allBits = allOdd | x; /* if x is all even bits then the result will be 1111 1111 1111 1111 1111 1111 1111 1111 */ 
   allBits = ~allBits; /* would return all 0's if every even bit was filled */
   return !allBits;  /*Treats as one bit, so if all 0's returns 0, if all 1's returns 1 */
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
  int allBits;
  int allOdd =(0xAA << 8) | 0xAA;
  allOdd = allOdd | (allOdd << 16); /* Gives us 1010 1010 1010 1010 1010 1010 1010 1010 */
  allBits = x & allOdd;
  allBits = !(!allBits); //! is not, if I have 5000 and not it becomes 0, if you not 0 it becomes 1
  return allBits;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {


  /* xor the nth byte and  then shift left to nth byte and xor the original number. 
  Now the nth byte stores the information of mth byte because we xor nth byte twice. */

  int y = 0;
  n = n<<3; // n == n*3
  m = m<<3; //m == n*3
  y = 0xff & ((x>>n) ^ (x>>m)); // 1111 1111
  x = x ^ (y<<n); 
  x = x ^ (y<<m);
  return x;

}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {

/*  Overflow occurs IF: x and y have the same sign AND x + y has an opposite sign */
  int sum = x + y;  // sum of x + y

   /*Instead of checking the signs and then xoring one with the sum we can xor both with the sum which in turn when AND will return
   a 1 if there is overflow   */
  int sx = x ^ sum;
  int sy = y ^ sum;

  /* The sx and sy will return a negative number (1 in leftmost bit) only if there is overflow so we shift the sign and then bang */
  return !((sx & sy) >> 31);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {

  //in C#, if condition is true, first expression is evaluated and becomes the result; 
  //if false, the second expression is evaluated and becomes the result. As with Java only one of two expressions is ever evaluated.
  //condition ? first_expression : second_expression; 
  
  /*create two variables that either all ones or all zeros given a value of x. Then and z and y with the appropriate variable*/
  int f,g,h;
  f=!x; //convert x to boolean
  g=(~f)+1; //negate two's complement by inverting and adding 1, all bits clear or all bits set.
  h=~g; //h is inverse of g

  return (z&g)+(y&h); //and both of them with respective z or y and then add togetehr
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) { 
  /* Shifts bytes left by 4 and compares it with XOR to 0x3, will return 1 if not 0x3 */
  int comparer = (x >> 4) ^ 0x3;

  int is0to9 = ((0x0f & x) + 0x6) & 0xf0;  //checks if 0 to 9 //15 & x + 6 &240, will return 1 if not 0 to 9

  return !(comparer | is0to9);  //ors it and bans it, if either one is false (1) will return 0.
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  int mask, shift;
  mask = 0xFF; // 11111111
  shift = n<<3; // same as multiplying n by 8 because 2^3 = 8.
  mask = ~(mask << shift); // shift byte-wide mask, flip to get byte-wide mask of 0s
  c = c << shift; // shift bits of c into nth byte
  return (x & mask) | c; // apply mask to x, zeroing x's nth byte, replacing it with byte given by c 
}
/* reverseBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: reverseBits(0x11111111) = 0x88888888
 *            reverseBits(0xdeadbeef) = 0xf77db57b
 *            reverseBits(0x88888888) = 0x11111111
 *            reverseBits(0)  = 0
 *            reverseBits(-1) = -1
 *            reverseBits(0x9) = 0x90000000
 *  Legal ops: ! ~ & ^ | + << >> and unsigned int type
 *  Max ops: 90
 *  Rating: 4
 */
int reverseBits(int x) {
  
int mask1x = ((0x55<<8)|(0x55));
int mask1 = ((mask1x<<16)|(mask1x)); //0x55555555
int mask2x = ((0x33<<8)|(0x33));
int mask2 = ((mask2x<<16)|(mask2x)); //0x33333333
int mask3x = ((0x0F<<8)|(0x0F));
int mask3 = ((mask3x<<16)|(mask3x));// 0x0F0F0F0F
int mask4x = ((0x00<<8)|0xFF);
int mask4 = (mask4x<<16)|mask4x; // 0x00FF00FF
unsigned int y = x;
y = ((y >> 1) & mask1) | ((y & mask1) << 1);
// swap consecutixe pairs
y = ((y >> 2) & mask2) | ((y & mask2) << 2);
// swap nibbles
y = ((y >> 4) & mask3) | ((y & mask3) << 4);
// swap bytes
y = ((y >> 8) & mask4) | ((y & mask4) << 8);
// swap 2-byte long pairs
y = ( y >> 16 ) | ( y << 16);
return y;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
    /* Same concept as overflow one, sign of sum has to be same sign as inputs or overflow */
    int x_y_sum = x + y;
    
    /* Sums XOR x, if different will get 0 if same 1    AND  sums XOR if different 0 same 1... AND WILL RETURN
    1 only if they have the same sign otherwise will return 0, then shift right by 31. */
    int overFlow = ((x_y_sum ^ x) & (x_y_sum ^ y)) >> 31;


    return (x_y_sum >> overFlow) ^ (overFlow << 31);
}
/*
 * Extra credit
 */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
  unsigned float_abs(unsigned uf) {
  unsigned mask = 0x7FFFFFFF;   //0 at start then all 1's
  unsigned minNaN = 0x7F800001;
  unsigned res = uf & mask;   // set sign bit to 0
  
  // return argument if it is NaN, all NaN >= minimum NaN
  if (res >= minNaN)
  {
    return uf;
  }
  else
  {
    return res;
  }
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  return 0;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
    /* Divide into NaN/infinity, Denormalized, Normailized */
    unsigned uSign = uf & 0x80000000; //1 at start then all 0's
    unsigned uNonSign = uf << 1;
    if (uNonSign >= 0xFF000000) { // NaN/infinity
        return uf;
    } else if (uNonSign <= 0x01FFFFFF) { // Denormalized
        uNonSign >>= 2;
        switch (uf & 3) { // Round to even
        case 3:
            ++uNonSign;
            break;
        default:
            break;
        }
        return uSign | uNonSign;
    } else { // Normalized
        return uf - 0x800000;
    }
}
