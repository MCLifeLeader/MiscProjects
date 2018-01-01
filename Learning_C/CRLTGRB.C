/* Break attempt and if then else statement. */

#include "stdio.h"

 char ch;   /* Global variable initiated */

 main()
  {
   int a;

   printf("Enter a chariter: ");  /* Chariter entered */
   scanf("%c", &ch);
   if(ch==03)     /* If statement */
     { ch=67;
       printf("YOU GOT IT ON THE BUTTON!!! %d", ch);   /* Than statement */
   }
   else {
    printf("nope wrong answer %d", ch);       /* Else statement */
   }
}

