/*
 * Program:     PIGEN.EXE
 * Source:      pigen.c
 * Author:      Mike Carey
 * Date:        03-06-94
 * Version:     1.0 alfa
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     To generate the pi number.
 *
 */

#include "stdio.h"
 /* #include "string.h"
    #include "stdlib.h" */
#include "math.h"

 main()
  {
   int x, y, z;
   float v1, v2, v3, v4, c1, c2, c3;
   double a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;

    c1 = 48;
    c2 = 32;
    c3 = 20;
    v1 = 1;
    v2 = 18;
    v3 = 57;
    v4 = 239;
    a1 = v1 / v2;
    a2 = v1 / v3;
    a3 = v1 / v4;
    a4 = atan(a1);
    a5 = atan(a2);
    a6 = atan(a3);
    a7 = a4 * c1;
    a8 = a5 * c2;
    a9 = a6 * c3;
    a10 = ((a7 + a8) - a9);
    printf("%f %f %f %f %f %f %f\n", c1, c2, c3, v1, v2, v3, v4);
    printf("%f %f %f %f %f\n", a1, a2, a3, a4, a5);
    printf("%f %f %f %f %f\n", a6, a7, a8, a9, a10);

 }

