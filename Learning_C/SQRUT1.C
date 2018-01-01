/* Counting */

#include "stdio.h"
#include "math.h"

main()
 {
  int num;
  double sq_root;

  for(num=1; num<1000; num++) {
    sq_root = sqrt((double) num);
    printf("%d %1f\n", num, sq_root);
  }
}
