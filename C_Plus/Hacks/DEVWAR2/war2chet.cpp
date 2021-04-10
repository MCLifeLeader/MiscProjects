/****************************************************************************
Program:    WAR2CHET.EXE
Output:     war2chet.obj
Source:     war2cheat.cpp
Author:     Mike Carey
Date:       12-24-96
Last Mod:   12-23-97
Compiler:   Borland C++ 4.5

****************************************************************************
Comments:       This source code is public domain as long as my authorship
						(Mike Carey) is in this file.
****************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
// version number
#define WAR2CHET "1.10.8"
// Code Problems Was temp fix.
#define HARDCODE 1

int main(int argc, char *argv[]);
int  pascal Check_Warcraft_Version(FILE *dsf);
void pascal Write_Warcraft_Data(FILE *dsf, long Gold, long Lumber, long Oil, char *PlayerColor);
int pascal Return_Player_Number(char *PlayerColor);

int main(int argc, char *argv[])
{
	int Version, option, FileOpen = 0;
	long Gold, Lumber, Oil;
	char opt[80];
	char *PlayerColor;
	FILE *dsf;

	PlayerColor = new char [80];

	for(option=0; option > 80; option++)
   {
		PlayerColor[option] = NULL;
	}

	if( argc >= 2)
   {
		strcpy(PlayerColor, argv[2]);
	}

	argv[2] = argv[3] = NULL;

	printf("WAR2CHET.EXE V%s\n", WAR2CHET);
	printf("WARCRAFT is a Trademark of Blizzard Entertainment and associates\n");

	if ( argc < 2 )
   {
		do
      {
			printf("\n\n");
			printf("\tYou use this program at your own risk\n");
			printf("\tThis will modify only the registered version of WARCRAFT II\n\tV1.5 Save files.\n");
			printf("\tWarcraft II\(tm\)Save Game Editor\n");
			printf("1. Set resources\n");
			printf("2. Open File\n");
			printf("3. Save Changes\n");
			printf("4. Quit with out Saving\n");
			do
         {
				printf("Enter your choice: ");
				gets(opt);
				option = atoi(opt);
			} while(option < 1 || option > 4);
			switch(option)
         {
				case 1:
#ifdef HARDCODE
					printf("This option has been disabled.\n");
               printf("Do to Errors caused in save file.\n");
               printf("I may have time to fix later....\n");
               printf("Just Select option 3. and save, it\n");
               printf("willplace max resouces for the player\n");
               printf("Color or number of your choice\n");
#else
					printf("Values entered will not always be correctly shown in game\n\n");
					printf("Enter Gold: ");
					gets(opt);
					Gold = atoi(opt);
					printf("Enter Lumber: ");
					gets(opt);
					Lumber = atoi(opt);
					printf("Enter Oil: ");
					gets(opt);
					Oil = atoi(opt);
#endif
					break;
				case 2:
					printf("Enter FileName: ");
					gets(opt);
					if( ( dsf = fopen(opt, "r+b" ) ) == NULL )
               {
						printf("error opening file %s\n", opt);
						break;
					}
					FileOpen = 1;
					Version = Check_Warcraft_Version(dsf);
					break;
				case 3:
						if( FileOpen )
                  {
							if(( Version == 1 ) || ( Version == 2 ))
                     {
								Write_Warcraft_Data(dsf, Gold, Lumber, Oil, PlayerColor);
							}
						}
						else
							printf("You forgot to open the file\n");
						break;
				case 4:
					printf("Everyone likes a Cheater?! \n");
					break;
			}
		} while(option != 4);
	}
	else
   {
		if( ( dsf = fopen(argv[1], "r+b" ) ) == NULL )
      {
			printf("error opening file %s\n", argv[1]);
			exit(1);
		}

		Version = Check_Warcraft_Version(dsf);

		if( argc == 2 )
      {
			Gold = Lumber = Oil = 1000000L;
		}
		else
      {
			if( argc == 3 )
         {
				Lumber = Oil = 1000000L;
			}
			else
         {
				if( argc == 4 )
            {
					Oil = 1000000L;
				}
				else
            {
					Gold = atol(argv[2]);
					Lumber = atol(argv[3]);
					Oil = atol(argv[4]);
				}
			}
		}

		if(( Version == 1 ) || ( Version == 2 ))
      {
			Write_Warcraft_Data(dsf, Gold, Lumber, Oil, PlayerColor); // war2chet
		}
	}

	fcloseall();

	for(option=0; option > 80; option++)
   {
		PlayerColor[option] = NULL;
	}

	delete [] PlayerColor;

	return(0);
}

	/* Check to see if this is a warcraft wave file */

int  pascal Check_Warcraft_Version(FILE *dsf)
{
	register int a, Hit;

	char Header1[6]; // = { 0x57, 0x61, 0x72, 0x32, 0x9F };
	char Header[7];

	Header1[0] = 0x57;
	Header1[1] = 0x61;
	Header1[2] = 0x72;
	Header1[3] = 0x32;
	Header1[4] = 0x9F;
	Header1[5] = NULL;

	if(fseek(dsf, 0x28, SEEK_SET))
   {
		exit(1);
	}

	for(a=0; a<6; a++)
   {
		Header[a] = getc(dsf);
	}

	for(a=0, Hit=0; a<5; a++)
	{
		if(Header1[a] == Header[a])
		{
			Hit++;
		}
	}
	if(Hit == 5)
   {
		return(1);
	}
	else
   {
		Hit = NULL;
		Header1[4] = 0xA1;
		for(a=0, Hit=0; a<5; a++)
		{
			if(Header1[a] == Header[a])
			{
				Hit++;
			}
		}
		if(Hit == 5)
      {
			return(2);
		}
	}

	printf("Wrong Warcraft Save Game file!!!!\n");
	return(0);
}

/* Write the resources to disk. */

void pascal Write_Warcraft_Data(FILE *dsf, long Gold, long Lumber, long Oil, char *PlayerColor)
{
	int option;
	char *opt;
	long Offset = NULL;

	opt = new char [80];


	if(PlayerColor[0] != NULL)
   {
			option = Return_Player_Number(PlayerColor);
			goto CntPnt;
	}
	do
   {
		printf("Enter Player Color or Number to Modify: ");
		gets(opt);
		option = atoi(opt);

	CntPnt:

		if(option == NULL)
      {
			strcpy(PlayerColor,opt);
			option = Return_Player_Number(PlayerColor);
		}

		if(option == 2)
      {
			Offset = 0x04;
		}
		else
      {
			if(option == 3)
         {
				Offset = 0x8;
			}
			else
         {
				if(option == 4)
            {
					Offset = 0xC;
				}
				else
            {
					if(option == 5)
               {
						Offset = 0x10;
					}
					else
               {
						if(option == 6)
                  {
							Offset = 0x14;
						}
						else
                  {
							if(option == 7)
                     {
								Offset = 0x18;
							}
							else
                     {
								if(option == 8)
                        {
									Offset = 0x1C;
								}
							}
						}
					}
				}
			}
		}
	} while(option < 1 || option > 9);

	printf("Color = %s, Number = %d\n", PlayerColor, option);

	if(option != 9)
   {

		fseek(dsf, 0x1B4+Offset, SEEK_SET);
#ifdef HARDCODE
		putc(0x7F,dsf);
		putc(0x7F,dsf);
		putc(0x7F,dsf);
		putc(0x7F,dsf);
#else
		fwrite(&Lumber, sizeof(long), 1, dsf);
//		fprintf(dsf, "%ld", Lumber);
#endif

		fseek(dsf, 0x1F4+Offset, SEEK_SET);
#ifdef HARDCODE
		putc(0x7F,dsf);
		putc(0x7F,dsf);
		putc(0x7F,dsf);
		putc(0x7F,dsf);
#else
		fwrite(&Gold, sizeof(long), 1, dsf);
//		fprintf(dsf, "%ld", Gold);
#endif

		fseek(dsf, 0x234+Offset, SEEK_SET);
#ifdef HARDCODE
		putc(0x7F,dsf);
		putc(0x7F,dsf);
		putc(0x7F,dsf);
		putc(0x7F,dsf);
#else
		fwrite(&Oil, sizeof(long), 1, dsf);
//		fprintf(dsf, "%ld", Oil);
#endif

#ifdef HARDCODE
		Gold = Lumber = Oil = (Gold + Lumber + Oil); // just a hack to keep compiler happy
#endif

	}
	else
   {
		if(option == 9)
      {
			for(Offset = 0; Offset < 0x1C; Offset+=0x04) {

				fseek(dsf, 0x1B4+Offset, SEEK_SET);
#ifdef HARDCODE
				putc(0x7F,dsf);
				putc(0x7F,dsf);
				putc(0x7F,dsf);
				putc(0x7F,dsf);
#else
				fwrite(&Lumber, sizeof(long), 1, dsf);
//				fprintf(dsf, "%ld", Lumber);
#endif

				fseek(dsf, 0x1F4+Offset, SEEK_SET);
#ifdef HARDCODE
				putc(0x7F,dsf);
				putc(0x7F,dsf);
				putc(0x7F,dsf);
				putc(0x7F,dsf);
#else
				fwrite(&Gold, sizeof(long), 1, dsf);
//				fprintf(dsf, "%ld", Gold);
#endif

				fseek(dsf, 0x234+Offset, SEEK_SET);
#ifdef HARDCODE
				putc(0x7F,dsf);
				putc(0x7F,dsf);
				putc(0x7F,dsf);
				putc(0x7F,dsf);
#else
				fwrite(&Oil, sizeof(long), 1, dsf);
//				fprintf(dsf, "%ld", Oil);
#endif
			}
		}
	}

	printf("Written Warcraft Cheat Data\n");

	for(option=0; option > 80; option++)
   {
		opt[option] = NULL;
	}

	delete [] opt;
}

int pascal Return_Player_Number(char *PlayerColor)
{
	int a;

	for(a=0; a<strlen(PlayerColor); a++)
   {
		PlayerColor[a] = toupper(PlayerColor[a]);
	}

   a = 0;

	if(!strcmp("RED", PlayerColor))
   {
		a = 1;
	}
	else
	{
		if(!strcmp("BLUE", PlayerColor))
      {
			a = 2;
		}
		else {
			if(!strcmp("GREEN", PlayerColor))
         {
				a = 3;
			}
			else {
				if((!strcmp("VIOLET", PlayerColor)) || (!strcmp("PURPLE", PlayerColor)))
            {
					a = 4;
				}
				else
            {
					if(!strcmp("ORANGE", PlayerColor))
               {
						a = 5;
					}
					else
               {
						if(!strcmp("BLACK", PlayerColor))
                  {
							a = 6;
						}
						else
                  {
							if(!strcmp("WHITE", PlayerColor))
                     {
								a = 7;
							}
							else
                     {
								if(!strcmp("YELLOW", PlayerColor))
                        {
								   a = 8;
								}
								else
                        {
									if(!strcmp("ALL", PlayerColor))
                           {
										a = 9;
									}
								}
							}
						}
					}
				}
			}
		}
	}

   if (a != NULL)
   {
      return(a);
   }

   if(PlayerColor[0] != NULL)
   {
   	a = atoi(PlayerColor);
   }

	if ((a != NULL) && (a < 10))
   {
		if(a == 1)
      {
			strcpy(PlayerColor, "RED");
		}
		else
      {
			if(a == 2)
         {
				strcpy(PlayerColor, "BLUE");
			}
			else
         {
				if(a == 3)
            {
					strcpy(PlayerColor, "GREEN");
				}
				else
            {
					if(a == 4)
               {
						strcpy(PlayerColor, "VIOLET");
					}
					else
               {
						if(a == 5)
                  {
							strcpy(PlayerColor, "ORANGE");
						}
						else
                  {
							if(a == 6)
                     {
								strcpy(PlayerColor, "BLACK");
							}
							else
                     {
								if(a == 7)
                        {
									strcpy(PlayerColor, "WHITE");
								}
								else
                        {
									if(a == 8)
                           {
										strcpy(PlayerColor, "YELLOW");
									}
									else
                           {
										if(a == 9)
                              {
											strcpy(PlayerColor, "ALL");
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return(a);
}




