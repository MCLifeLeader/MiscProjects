/* Global verible test */

#include "stdio.h"

int count; /* this is a global veriable */

 main()
 {
  int i; /* this is a local varible */

  for(i=0; i<10; i++) {
    count = 1 * 2;
    funcl();
  }
 }

 funcl()
 {
   printf("count: %d", count); /* access global count */
   func2();
 }

  func2()
  {
    int count; /* this is a local variavle */

    for(count=0; count<3; count++) printf(".");
}
