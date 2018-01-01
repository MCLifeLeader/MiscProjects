
#include "stdio.h"

 int sum;

 main()
  {
    int i;

    sum = 0;
    fork();
    for(i=0; i<=5; i++) {
      printf("The value of i is %d\n", i);
      fflush(stdout);
      sum += i;
    }
    printf("The sum is %d\n", sum);
    exit(0);
  }
