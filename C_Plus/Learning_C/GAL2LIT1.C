/* This program converts gallons to liters. */

#include "stdio.h"

 main()
 {
   int gallons, liters;

   printf("Enter number of gallons; ");
   scanf("%d", &gallons);

   liters = gallons * 4;

   printf("%d liters", liters);
}
