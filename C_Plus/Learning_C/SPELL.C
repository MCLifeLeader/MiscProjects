/* Spell checking program NOT!!! */

#include "stdio.h"

void check_spelling(void);  /* this is prototyping a function */
			    /* you place the variable type inside
			    the () on this so that the compiler can
			    perform type casting */
int display_errors(float, int);

main()
 {
  int i;
  float a;
  int b;
  printf("1. Check Spelling\n");
  printf("2. Correct Spelling errors\n");
  printf("3. Display Spelling errors\n");
  printf("Strike Any Other Key to Skip\n");
  printf("      Enter your choice: ");

  scanf("%d", &i);

  switch(i) {
    case 1:
      check_spelling();
      break;
    case 2:
      correct_errors();
      break;
    case 3:
      i=display_errors(a,b);
      break;
    default :
      printf("No option selected");
  }
  void check_spelling(void);  /* this is declaring a function */
  {
  printf("hello mike\n");
  }
  int display_errors(float x, int y)
  {
  print("%f, %d\n,x,y);
  return(4);
  }
}

