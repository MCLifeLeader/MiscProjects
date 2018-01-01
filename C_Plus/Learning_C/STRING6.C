/* four string functions */

#include "stdio.h"
#include "string.h"

 main()
  {
   char s1[80], s2[80];

   printf("Enter two strings: ");

   gets(s1); gets(s2);
   printf("lengths: %d %d\n", strlen(s1), strlen(s2));

   if(!strcmp(s1, s2)) printf("The strings are equal\n");
   else printf("Not equal\n");

   strcat(s1, s2);
   printf("%s\n", s1);

   strcpy(s1, s2);
   printf("%s %s are now the same\n", s1, s2);
}

