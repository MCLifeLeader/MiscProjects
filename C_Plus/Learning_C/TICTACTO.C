/* A simple Tic Tac Toe game. */

#include "stdio.h"
#include "stdlib.h"

 char matrix[3][3]; /* this tic tac toe matrix */

 main()
  {
   char done=0;

   printf("This is the game of tic tac toe.\n");
   printf("You will be playing against the computer.\n");

   done = ' ';

   init_matrix();

   do {
     disp_matrix();
     get_player_move();
     done = check(); /* see if winner */
     if(done!=' ') break; /* winner! */
     get_computer_move();
     done = check(); /* see if winner */
   } while(done==' ');

   if(done=='X') printf("You won!\n");
   else printf("I won!!!!\n");

   disp_matrix(); /* show final positions */
  }

  /* Initialize the matrix. */
  init_matrix()
  {
   int i=0, j=0;

   for(i=0; i<3; i++)
     for(j=0; j<3; j++) matrix[i][j] = ' ';
  }

  /* Get a player's move */
  get_player_move()
  {
   int x=0, y=0;

   printf("Enter cordinates for your X: ");
   scanf("%d%d", &x, &y);

   x--; y--;

   if(matrix[x][y]!=' ') {
     printf("Invalid move!!!!,  try again. :-\(\n");
     get_player_move();
   }
   else matrix[x][y] = 'X';
  }

  /* Get a move from the computer. */

  get_computer_move()
   {
    int i=0, j=0;

    for(i=0; i<3; i++) {
      for(j=0; j<3; j++)
	if(matrix[i][j]==' ') break;
      if(matrix[i][j]==' ') break;
    }
    if(i*j==9) {
      printf("draw Game :-\>\n");
      exit(0);
    }
    else
      matrix[i][j] = 'O';
   }

  /* Display the matrix on the screen. */
  disp_matrix()
   {
    int t=0;

    for(t=0; t<3; t++) {
      printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
      if(t!=2) printf("\n---|---|---\n");
    }
    printf("\n");
  }

  /* See if there is a winner. */
  check()
   {
    int i;

    for(i=0; i<3; i++) /* check rows */
      if(matrix[i][0]==matrix[i][1] &&
	 matrix[i][0]==matrix[i][2]) return(matrix[i][0]);

    for(i=0; i<3; i++) /* check columns */
      if(matrix[0][i]==matrix[1][i] &&
	 matrix[0][i]==matrix[2][i]) return(matrix[0][i]);

    /* Test diagonals */
    if(matrix[0][0]==matrix[1][1] &&
     matrix[1][1]==matrix[2][2])
     return(matrix[0][0]);

    if(matrix[0][2]==matrix[1][1] &&
     matrix[1][1]==matrix[2][0])
     return(matrix[0][2]);

    return ' ';
 }

