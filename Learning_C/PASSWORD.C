/* password program */

#include "stdio.h"
#include "string.h"

 main()
  {
   if(password()) printf("loged on\n");
   else printf("access denied\n");
  }

  /* Return true if password accepted; fales otherwise. */
  password()
   {
    char s[80];

    printf("Enter password: ");
    gets(s);

    if(strcmp(s, "password")) { /* strings different */
      printf("Invalid password\n");
      return 0;
    }

    /* strings campared the same */
    return 1;
}


