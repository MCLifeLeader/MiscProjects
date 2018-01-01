/* Next case!!!! */

#include "stdio.h"

main()
 {
  int i;

  printf("Enter a number less than %d:", 5);
  scanf("%d", &i);
  if(i>=5) i=4;{
    switch(i) {
      case 0: printf("less than 1\n");
	      break;
      case 1: printf("less than 2\n");
	      break;
      case 2: printf("less than 3\n");
	      break;
      case 3: printf("less than 4\n");
	      break;
      case 4: printf("less than 5\n");
	      break;

    }
    printf("\n");
  }
}
