/*
 * Program:     INTRPTS.EXE
 * Source:      intrpts.c
 * Author:      Mike Carey
 * Date:        04-08-94
 * Version:     1.0alfa
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     Learn about interupts through the C language.
 *
 */

#include "stdio.h"
#include "dos.h"

 main()
  {
   union scan {
     int c;            /* variable declarations */
     char ch[2];
   } sc;

   char chrs;
   do {
    /* printf("%d\n", chrs); */
   } while((chrs=bdos(1,0,0))!='q'); /* displays direct keyboard input */

   do {
    sc.c=get_key();

    /*   if(sc.ch[0]==0) {
     *    printf("special key number %d\n",sc.ch[1]);
     *  }
     *  else {
     *    putchar(sc.ch[0]);
     *  }
     */
     printf("%d\n",sc.ch[1]);  /* displays keyboard number */
  } while(sc.ch[0]!='q');
 }

 get_key()
  {
    union REGS r, o;

    r.h.ah = 0;
    o.h.ah = 0;
			/* what gets the key board number. */
    /* return int86(0x16, &r, &o); */
    if(int86(0x1b, &r, &r) || int86(0x23, &r, &r) {
      printf("Break Encounterd\n");
    }
    /* return int86(0x19, &r, &r); bootstrap loader */
 }
