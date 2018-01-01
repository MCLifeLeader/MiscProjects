/*
 *
 * Compiler:    Ansi C   MicroSoft Quick C
 * Program:     getkey.c
 * Purpose:     to test scan code example
 * Programmer:  Mike Carey
 * Date:        Jan. 05, 1994
 *
 */

#include "stdio.h"
#include "dos.h"

 main()
  {
   union scan {
     int c;
     char ch[2];
   } sc;

   do { /* read the keyboard */
     sc.c=get_key();
     if(sc.ch[0]==0) { /* is special key */
       printf("Special key number %d",sc.ch[1]);
     }
     else { /* Regular key */
       putchar(sc.ch[0]);
     }
   } while(sc.ch[0]!='q');
 }
