/* Bifurcation fractal program */

#include "stdio.h"
#include "graph.h"

 main()
  {
   int loopit, col, row, a, b;
   int loop, xvar, yvar, x ;
   char input[80];
   float top, bottom, height, vpct;
   float rows, columns;
   float xfunc, start, save, finish;
   float rate;

   _setvideomode(_DEFAULTMODE);
   /* _setvideomode(_VRES16COLOR); */
   _setcolor(4);

   columns = 640;
   rows = 480;

   start = 0;
   printf("Enter Starting Rate \(1\): ");
   scanf("%f", &start);
   /* rate = start; */

   finish = 0;
   printf("Enter Finishing Rate \(3.999\): ");
   scanf("%f", &finish);

   xfunc = 0;
   printf("Enter Starting Population \(.1\): ");
   scanf("%f", &xfunc);

   rate = 0;
   printf("Enter Starting Point \(%f\): ", start);
   scanf("%f", &rate);

   top = 1;
   bottom = 0;
   height = (bottom-top);
   vpct = (1/height);

   _setvideomode(_VRES16COLOR);

   do {
     loopit = 0;
     while(loopit < 25) {
       xfunc = (rate*(xfunc-xfunc*xfunc));
       loopit++;
       /* printf("loopit %d\n", loopit); */
     }

     loopit = 0;
     save = 1000;

     while(loopit < 100) {
       xfunc = (rate*(xfunc-xfunc*xfunc));
       col = ((rate-start)*columns/(finish-start));
       row = (480-(rows-(xfunc-top)*rows*vpct));

       /* printf("loopit %d, col %d, row %d\n", loopit, col, row); */
       _moveto(col,row);
       _setpixel(col,row);
       a = xfunc;
       b = save;

       if((a*100) == (b*100)) {
	 loopit = 100;
       }

       if(loopit == 0) {
	 save = xfunc;
	 loopit++;
       }
     }

     rate = ((finish-start)/columns+rate);
     /* printf("loopit %d, rate %f\n", loopit, rate); */
     /* printf("finish %f, start %f\n", finish, start); */

   } while((!kbhit()) || (rate <= finish));
   gets(input);
   _setvideomode(_DEFAULTMODE);
 }

