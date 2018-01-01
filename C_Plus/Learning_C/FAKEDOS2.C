/*
 *
 * Compiler:    Ansi C   MicroSoft Quick C
 * Program:     fakedos2.c
 * Purpose:     A joke on all dos users.
 * Programmer:  Mike Carey
 * Date:        Dec. 5, 1993
 *
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "signal.h"

   /*  There a 12 lines of quote codes */

 char *joke[] = {
   "This computer Belongs to me and no one else.\n",
   "Ha Ha Ha Ha Ha Ha Ha get a new computer this ones broken!\n",
   "Fess up you choose the rong type of computer.\n",
   "Watch it one of these days I'm not going to work any more.\n",
   "AAAAARRRRRRRGGGGGGGHHHHHHHHH. My life force is getting weak help me!!\n",
   "The printer will print something I think?.....nope guss not.",
   "Owwww!! Don't hit my keys that hard learn how to type!!\n",
   "Who do you think you are? The person who owns this computer?\n",
   "Nope... I don't like my peas just can't eat em don't like em\n",
   "WILL YOU PLEASE STOP HITTING MY ENTER AND SPACE KEYS THAT HARD\n",
   "I don't like you any more so just type in the password",
   "That command dose not work any more",
   };

 main()
  {
   int a;
   char input[80];
   char leave[]="exit";
   printf("%s\n",__LINE__);
   printf("%s\n",__FILE__);
   printf("%s\n",__DATE__);
   printf("%s\n",__TIME__);

   do {
     a = rand();
     /* printf("%d", a); */
     if(a>30000) {
       get_coment();
       if(a=30000) {
	 a = 0;
       }
     }

     gets(input);
     system(input);
    } while(strcmp(input, leave));
 }

 get_coment()
  {
   int joke1;

   joke1 = rand();
   joke1 = joke1 % 12;
   printf("%s", joke[joke1]);
   /* if(joke1== % 6%) { } */

}
