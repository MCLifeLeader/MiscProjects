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
			/* intrupt 0x1b and 0x23 are ^break */
#include "stdio.h"
#include "dos.h"

 main()
  {
   union scan {
     int c;            /* variable declarations */
     char ch[2];
   } sc;
   int n;
   do {
    sc.c=get_key();

    n = 29;
    if(sc.ch[1]==n) {
      printf("crtl key pressed\n");
    }

    printf("%d ",sc.ch[1]);
    if(sc.ch[1]==28) {
      printf("\n");
    }

  } while(sc.ch[0]!='q');
 }

 get_key()
  {
    union REGS in, out;

    in.h.ah = 0;
    out.h.ah = 0;
    return int86(0x16, &in, &out);
 }
