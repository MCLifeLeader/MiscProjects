/* This program converts liters to gallons using floating-point numbers. */

#include "stdio.h"

 main()
 {
   float gallons, liters;
   printf("Enter number of liters: ");
   scanf("%f", &liters);
   gallons = liters / 3.7854;
   printf("%f gallons,", gallons);
}
