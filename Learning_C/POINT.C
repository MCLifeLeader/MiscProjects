/* asigning address values in memory. */

#include "stdio.h"

 main()
  {
   int balance;
   int *address;
   int value;

   balance = 3200;
   address = &balance;
   value = *address;
   printf("balance is: %d\n", value);
}
