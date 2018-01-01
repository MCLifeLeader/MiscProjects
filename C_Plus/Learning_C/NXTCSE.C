/* Next case!!!! */

#include "stdio.h"

main()
 {
  int i;

  for(i=0; i<5; i++) {
    switch(i) {
      case 0: printf("less than 1\n");
      case 1: printf("less than 2\n");
      case 2: printf("less than 3\n");
      case 3: printf("less than 4\n");
      case 4: printf("less than 5\n");
    }
    printf("\n");
  }
}
