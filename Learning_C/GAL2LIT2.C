/* This program convers gallons to liters using floating-point numbers. */

#include "stdio.h"

 main()
 {
   float gallons, liters;

   printf("Enter number of gallons: ");
   scanf("%f", &gallons);

   liters = gallons * 3.7854;

   printf("%f liters", liters);
}
