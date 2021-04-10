/*
 * Program:     RIFTS.EXE
 * Source:      rifts.c
 * Author:      Mike Carey
 * Date:        Nov. 11, 1994
 * Version:     1.0alfa
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     To generate Rifts Characters for roll playing.
 *
 */

 /************************************************************************
 *      This source code has been freely distrobuted for the use of those
 * who might find this useful. Your use of this program and source code
 * is up to your discression. I only require that my name in part or full
 * NOT be removed from any documentation nor the compiled or uncompiled
 * operational versions being used. If you have questions you can contact
 * me at.
 *              Mike Carey
 *              37104 Sagebrush Pl.
 *              Kennewick, Wa. 99337
 *
 *              Phone#: 509-627-7705
 *
 ************************************************************************/

#include "stdio.h"
#include "conio.h"
#include "graph.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
					      /*
					       * Debug macro 1 to run debug
					       * precompiler data
					       */
#define debugl 0
					      /* Redefined to "clrscr" */
#define clrscr _clearscreen(_GCLEARSCREEN)
					      /* Redefined to "settxtpos" */
#define settxtpos _settextposition

#define mkdata "Rifts Character Generator V1.0Alfa By. Michael Carey\n"

			/* Functions called from block MAIN */
  int setarrays1(void);
  int menu(void);
  int savechr(void);
  int loadchr(void);
  int outputchr(void);
			/* Functions called from block menu1 */
  int menofarms(void);
  int scholars(void);
  int magicusers(void);
  int rcc(void);
			/* Functions called from block menofarms */
  int borg(void);
  int crazies(void);
  int cyberknights(void);
  int glitterboys(void);
  int juicers(void);
  int headhunters(void);
  int coalgrunt(void);
  int coalmilspec(void);
  int coalrpaelite(void);
  int coaltechofficer(void);
			/* Functions called from block scholars */
  int bodyfixers(void);
  int cityrats(void);
  int cyberdocs(void);
  int operators(void);
  int roguescholar(void);
  int roguescientist(void);
  int vagabond(void);
  int wildernesscout(void);
			/* Functions called from block magicusers */
  int linewalkers(void);
  int technowizards(void);
  int shifters(void);
  int mystics(void);
			/* Functions called from block rcc */
  int dragonsgh(void);
  int dragonsfire(void);
  int dragonsice(void);
  int dragonsthndrliz(void);
  int bursters(void);
  int coaldogpack(void);
  int psistalkers(void);
  int mindmelters(void);
			/* Function Group 7 called from any */
  int shortmnu(void);
  int chrprsnal(int *);
  int genchrstat(int *);
  int chrskills(int *);
  int wepandequip(int *);
  int chrbase(int *);
  int dsplayit(void);
  int setscrn(void);
  int rndmroll(int *, int *);

			/* Global Variables */
  int communications1[7] = {
     25, 30, 30, 45, 35, 30, 25
  };
  char *communications2[] = {
    "Cryptography",
    "Laser",
    "Optic Systems",
    "Radio: Basic",
    "Radio: Scramblers",
    "Surveillance Systems",
    "T.V./Video"
  };
  int domestic1[6] = {
     35, 30, 40, 35, 40, 35
  };
  char *domestic2[] = {
    "Cook",
    "Dance",
    "Fishing",
    "Play Musical Instrument",
    "Sewing",
    "Sing"
  };
  int electrical1[4] = {
     30, 25, 30, 30
  };
  char *electrical2[] = {
    "Basic Electronics",
    "Computer Repair",
    "Electrical Engineer",
    "Robot Electronics"
  };
  int espionage1[11] = {
     30, 25, 25, 30, 20, 32, 30, 25, 2, 25, 30
  };
  char *espionage2[] = {
    "Detect Ambush",
    "Detect Concealment",
    "Disguise",
    "Escape Artist",
    "Forgery",
    "Intelligence",
    "Pick Pockets",
    "Pick Locks",
    "Sniper",
    "Tracking",
    "Wilderness Survival"
  };
  int mechanical1[6] = {
     25, 25, 25, 25, 20, 25
  };
  char *mechanical2[] = {
    "Aircraft Mechanics",
    "Automotice Mechanics",
    "Locksmith",
    "Mechanical Engineer",
    "Robot Mechanics",
    "Weapons Engineer"
  };
  int medical1[9] = {
     35, 45, 20, 40, 60, 50, 40, 60, 40
  };
  char *medical2[] = {
    "Criminal Sciences and Forensics",
    "First Aid",
    "Holistic Medicine",
    "Paramedic",
    "Medical Doctor",
    "M.D. in Cybernetics",
    "Pathology"
  };
  int military1[2] = {
     60, 60
  };
  char *military2[] = {
    "Demolitions",
    "Demolitions Disposal"
  };
  int phyacrobatics1[14] = {
     1, 60, 60, 80, 60, 40, 15, 30, 5, 2, 1, 1, 1, 1
  };
  char *phyacrobatics2[] = {
    "1d8",
    "Sence of Balance",
    "Walk Tightrope or High Wire",
    "Climb Rope",
    "Back Flip",
    "Climbing",
    "Climbing Bonus",
    "Prowl",
    "Prowl Bonus",
    "+2 Bonus to Roll with Punch or Fall",
    "+1 to PS",
    "+1 to PP",
    "+1 to PE",
    "+1d6 to SDC"
  };
  int phyathletics1[5] = {
     1, 1, 1, 1, 1
  };
  char *phyathletics2[] = {
    "+1 to Parry and Dodge",
    "+1 to Roll with Punch or Fall",
    "+1 to PS",
    "+1d6 to Spd",
    "+1d8 to SDC"
  };
  int phybodybuild1[2] = {
     2, 10
  };
  char *phybodybuild2[] = {
    "+2 to PS",
    "+10 to SDC"
  };
  int phyboxing1[5] = {
     1, 2, 1, 2, 3
  };
  char *phyboxing2[] = {
    "+1 Attack per Melee",
    "+2 to Parry and Dodge",
    "+1 to Roll with Punch or Fall",
    "+2 to PS",
    "+3d6 to SDC"
  };
  int physical1[5] = {
     40, 30, 25, 50, 50
  };
  char *physical2[] = {
    "Climbing",
    "Rappelling",
    "Prowl",
    "Swimming",
    "SCUBA"
  };
  int phygymnastics1[14] = {
     2, 50, 60, 70, 70, 25, 7, 30, 5, 2, 2, 2, 1, 2
  };
  char *phygymnastics2[] = {
    "Kick Attack 2d4",
    "Sense of Balance",
    "Work Parrallel Bars and Rings",
    "Climb Rope",
    "Back Flip",
    "Climbing",
    "Climbing Bonus",
    "Prowling",
    "Prowling Bonus",
    "+2 Bonus to Roll with Punch or Fall",
    "+2 to PS",
    "+2 to PE",
    "+1 to PP",
    "+2d6 to SDC"
  };
  int phyrunning1[3] = {
    1, 4, 1
  };
  char *phyrunning2[] = {
    "+1 to PE",
    "4d4 to Spd",
    "1d6 to SDC"
  };
  int phywrestling1[7] = {
     1, 18, 1, 1, 2, 1, 4
  };
  char *phywrestling2[] = {
    "Body Block Takle 1d4",
    "Pin/Incapacitate on a roll of 18 or better",
    "Crush Squeeze 1d4 damge per squeeze",
    "+1 to Roll with Punch or Fall",
    "+2 to PS",
    "+1 to PE",
    "+4d6 to SDC"
  };
  int pilotskills1[18] = {
     50, 60, 60, 55, 45, 44, 35, 40, 1, 4, 50, 40, 40, 42, 60, 56, 40, 36
  };
  char *pilotskills2[] = {
    "Airplane",
    "Automobile",
    "Boat: Sail Type",
    "Boat: Motor and Hydrofoils",
    "Boat: Sail type Frigeite",
    "Boat: Freighter Ships",
    "Helicopter",
    "Horsemanship",
    "Horsemanship Parry and Dodge Bonus +1",
    "Horsemanship damage Bonus +4",
    "Hover Craft \(Ground\)",
    "Jet Aircraft",
    "Jet Fighters",
    "Jet Packs",
    "Motorcycle",
    "Robots and Power Armor",
    "Truck",
    "Tanks and APCs"
  };
  int pilotrelatedskills1[3] = {
     40, 30, 40
  };
  char *pilotrelatedskills2[] = {
    "Navigation",
    "Read Sensory Equipment",
    "Weapon Systems"
  };
  int rogueskills1[8] = {
     15, 5, 20, 20, 30, 25, 25, 20
  };
  char *rogueskills2[] = {
    "Computer Hacking",
    "Bonus to Cryptogrophy +5%",
    "Concealment",
    "Palming",
    "Pick Locks",
    "Pick Pockets",
    "Prowl",
    "Streetwise"
  };
  int science1[9] = {
     20, 20, 25, 30, 25, 30, 25, 45, 45
  };
  char *science2[] = {
    "Anthropology",
    "Archaeology",
    "Astronomy",
    "Biology",
    "Botany",
    "Chemistry",
    "Mathematics - Basic",
    "Mathematics - Advanced"
  };
  int technical1[9] = {
     35, 40, 30, 50, 30, 25, 25, 35, 25
  };
  char *technical2[] = {
    "Art",
    "Computer Operation",
    "Computer Programming",
    "Language",
    "Literacy",
    "Lore - Deamons and Monsters",
    "Lore - Faerie",
    "Photography",
    "Writing"
  };
  char *wp[] = {
    "WP Archery and Targeting",
    "WP Blunt",
    "WP Chain",
    "WP Knife",
    "WP Sword",
    "WP Revolver",
    "WP Automatic Pistol",
    "WP Bolt Action Rifle",
    "WP Automatic and Semi-Auto Rifles",
    "WP Sub-Machinegun",
    "WP Heavy",
    "WP Energy Pistol",
    "WP Energy Rifle",
    "WP Heavy Energy Weapons",
  };
  int wilderness1[12] = {
     25, 25, 2, 5, 5, 5, 5, 25, 36, 25, 30, 20
  };
  char *wilderness2[] = {
    "Boat Building",
    "Carpentry",
    "Hunting - Prowl",
    "Hunting - Track Animals",
    "Hunting - Skin Animals",
    "Hunting - Wilderness Survival",
    "Hunting - Cook and Catch only",
    "Identify Plants and Fruits",
    "Land Navigation",
    "Preserve Food",
    "Skin and Prepare Animal Hides",
    "Track Animals"
  };
  int savethrows1[10] = {
     14, 14, 16, 15, 99, 12, 12, 10, 12, 16
  };
  char *savethrows2[] = {
    "Roll with Punch Fall",
    "Lethal Poison",
    "Non-Lethal Poison",
    "Harmful Drugs",
    "Acids \(No Save - Dodge Only\)",
    "Insanity",
    "Psionics",
    "Psionics Master",
    "Magic - Spell",
    "Magic - Ritual"
  };

  int attrib1[40] = {
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 1, 2, 3, 4, 5, 6,
     7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
     17, 18, 19, 20, 21, 22, 23, 24, 25, 26
  };
  int attrib2[40] = {
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 1, 2, 2, 3,
     3, 4, 4, 5, 5, 6, 6, 7, 7, 8,
     8, 9, 9, 10, 10, 11, 11, 12, 12, 13
  };
  int attrib3[40] = {
     0, 0, 0, 0, 0, 0, 0, 0, 5, 10,
     15, 20, 25, 30, 35, 40, 45, 50, 55, 60,
     65, 70, 75, 80, 84, 88, 92, 94, 96, 97,
     98, 98, 98, 98, 98, 98, 98, 98, 98, 98
  };
  int attrib4[40] = {
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 1, 2, 3, 4, 5,
     6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
     16, 17, 18, 19, 20, 21, 22, 23, 24, 25
  };
  int attrib5[40] = {
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 2, 3, 4, 5, 6, 8, 10,
     12, 14, 16, 18, 20, 22, 24, 26, 28, 30,
     32, 34, 36, 38, 40, 42, 44, 46, 48, 50
  };
  int attrib6[40] = {
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     5, 10, 15, 20, 25, 30, 35, 40, 45, 50,
     55, 60, 65, 70, 75, 80, 83, 86, 90, 92,
     94, 96, 98, 98, 98, 98, 98, 98, 98, 98
  };

 /**************************************************************************
 * Basic Array map for chrstat[250]
 *
 * 0 to 7:     Base stats, IQ, ME, MA, PS, etc.
 * 8 to 15:    Bonuses from base stats, IQ, ME, MA, PS, etc.
 * 16 to 22:   Physical data/ Hit pts, SDC/MDC, PPE, ISP, Experence
 * 23 to 26:   Stats like/ Age, Weight, Height, Birth Order
 * 27 to 40:   Combat bonuses/ Percentiles and stats
 * 41 to 44:   Combat related skills/ Climb, Palm, Streetwise, Prowl
 * 45 to 54:   Saving Throw stats
 * 55 to 85:   Base OCC/RCC skills-Total:30
 * 86 to 131:  OCC/RCC Related skills-Total:45
 * 132 to 162: OCC/RCC Secondary skills-Total:30
 * 163 to 250: Open Array Manipulation-Total:87
 *
 ***************************************************************************
 * Basic Array map for chrdata[250][80]
 *
 * 0 to 10:     Pg. 18, Birth Order/ Weight/ Height/ Age/ Disposition
 *                Family Origin (Land or Origin)/ Type of Environment
 *                Sentiments toward the Coalition and Non-Humans
 * 11 to 40:    Basic Insanity Data
 * 41 to 54:    Open Array Manipulatoin-Total:23
 * 55 to 85:    Base OCC/RCC Skills-Total:30
 * 86 to 131:   OCC/RCC Related Skills-Total:45
 * 132 to 162:  OCC/RCC Secondary Skills-Total:30
 * 163 to 250:  Open Array Manipulatoin-Total:87
 *
 ***************************************************************************/
				/* Global Varibles */
  int chrstat[250];
  long money=0, blkmarket=0;
  char chrdata[250][80], multiperson[100][80];

 /************************************************************************
   Function Block Group 1
 *************************************************************************/

				/* Function Block MAIN */

 void main(void)
  {
				/* Variable Declaration */
   int option=0, utime=0, a=0, b=0;
   long ltime=0;
   char input[80];
				/* Set seed random time */
   ltime = time(NULL);
   utime = (unsigned int) ltime/2;
   srand(utime);

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     printf("\n  This program was designed to generate a Palladium style character for the\n");
     printf("Rifts Roll Play gaming system. Credit for this gaming system must go to Kevin\n");
     printf("Siembieda and the publisher, Palladium Books, 5926 Lonyo, Detroit, MI 48210.\n");
     printf("This is a FreeWare program and can be freely distrobuted to whome ever\n");
     printf("might find this program useful. Just as a note, you will need the Main Rifts\n");
     printf("Book\n");
					/* Menu selection */
     settxtpos(10, 1);
     printf("\tThe Main Menu\n");
     printf("1. to Make your Character.\n");
     printf("2. to Save your Character to Disk.\n");
     printf("3. to Load your Character from Disk.\n");
     printf("4. to Send Character to Output Device.\n");
     printf("5. to Quit\n");
					/* Input function */
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>5);
					/* switch case */
     switch(option) {
       case 1:
	 setarrays1();
	 menu();
	 break;
       case 2:
	 savechr();
	 break;
       case 3:
	 loadchr();
	 break;
       case 4:
	 outputchr();
	 break;
       case 5:
	 clrscr;
	 printf("Bye.\n");
	 break;
     }
					/* Exit if option == 5 */
   } while(option != 5);
 }
		/*
		 * Function setarrays1 is called from Function Block MAIN
		 * This function is used to set some of the global array
		 * variable data strings.
		 */
 setarrays1()
  {
   int a=0, b=0;
   money=0;
   blkmarket=0;
   for(a=0; a<250; a++) {
     chrstat[a] = 0;
     for(b=0; b<80; b++) {
       chrdata[a][b] = 0;
     }
   }
   for(a=0; a<100; a++) {
     for(b=0; b<80; b++) {
       multiperson[a][b];
     }
   }
 }
		/*
		 * Function menu1 is called from Function Block MAIN
		 * This function is the menu choice selection for
		 * creating the character to be generated.
		 */
 menu()
  {
   int option=0;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
						/* Choosing the character */
     printf("\tChoosing an OCC/RCC Character Class\n");
     printf("1. Men of Arms.\n");
     printf("2. Scholars and Adventurers.\n");
     printf("3. Practitioners of Magic.\n");
     printf("4. RCC Characters.\n");
     printf("5. Display Stats.\n");
     printf("6. Back to Main Menu.\n");
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 menofarms();
	 break;
       case 2:
	 scholars();
	 break;
       case 3:
	 magicusers();
	 break;
       case 4:
	 rcc();
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }

		/*
		 * Function savechr is called from Function Block MAIN
		 * This function will ask for the name of the file to
		 * output it to disk.
		 */
 savechr()
  {
   int a=0, b=0, c=0;
   char input[80];
   FILE *fp;
		/* When finnished, this will save the character to disk. */
/*
 *  do {
 *    clrscr;
 *    settxtpos(1, 20);
 *    printf(mkdata);
 *    printf("Enter in the name of the file to save: ");
 *    gets(input);
 *    if((fp = fopen(input, "w+"))==NULL) {
 *      printf("Error opening the file %s\n", input);
 *      a = 1;
 *    }
 *  } while(a!=0);
 */

 }
		/*
		 * Function savechr is called from Function Block MAIN
		 * This function will ask for the name of the file to
		 * output it to disk.
		 */
 loadchr()
  {
   int a=0, b=0, c=0;
   char input[80];
   FILE *fp;
		/* When finnished, this will load the character to disk. */
/*
 *  do {
 *    clrscr;
 *    settxtpos(1, 20);
 *    printf(mkdata);
 *    printf("Enter in the name of the file to load: ");
 *    gets(input);
 *    if((fp = fopen(input, "r"))==NULL) {
 *      printf("Error opening the file %s\n", input);
 *      a = 1;
 *    }
 *  } while(a!=0);
 */

 }
		/*
		 * Function output is called from Function Block MAIN
		 * This function will out put the character to the
		 * printer on COM or LPT ports.
		 */
 outputchr()
  {
		/* I am not fully shure how I am going to get this part */
		/* of the program to work as of 12-16-94 */
 }

 /************************************************************************
   Function Block Group 2 Called from Funtion menu
 *************************************************************************/

		/*
		 * Function menofarms is called from Function Block menu
		 * This function will allow choice from the men of arms
		 * character OCC classes.
		 */
 menofarms()
  {
   int option=0;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tMEN OF ARMS\n");
     printf("1. Borgs\n");
     printf("2. Crazies\n");
     printf("3. Cyber-Knights\n");
     printf("4. Glitter Boys\n");
     printf("5. Juicers\n");
     printf("6. Headhunters\n");
     printf("7. Coalition Grunt\n");
     printf("8. Coalition Military Specialist\n");
     printf("9. Coalition RPA Elite or \"Sam\"\n");
     printf("10. Coalition Technical Officer\n");
     printf("11. Back to Previous Menu.\n");
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>11);

     switch(option) {
       case 1:
	 borg();
	 break;
       case 2:
	 crazies();
	 break;
       case 3:
	 cyberknights();
	 break;
       case 4:
	 glitterboys();
	 break;
       case 5:
	 juicers();
	 break;
       case 6:
	 headhunters();
	 break;
       case 7:
	 coalgrunt();
	 break;
       case 8:
	 coalmilspec();
	 break;
       case 9:
	 coalrpaelite();
	 break;
       case 10:
	 coaltechofficer();
	 break;
       case 11:
	 clrscr;
     }
   } while(option!=11);
 }
		/*
		 * Function scholars is called from Function Block menu
		 * This function will allow choice from the scholars and
		 * adventures character OCC classes.
		 */
 scholars()
  {
   int option=0;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tSCHOLARS AND ADVENTURES\n");
     printf("1. Body Fixers \(Doctor\)\n");
     printf("2. City Rats \(Streetwise adventurer\)\n");
     printf("3. Cyber-Docs \(Cybernetics M.D.\)\n");
     printf("4. Operators \(Mechanical or Electrical Engineer\)\n");
     printf("5. Rogue Scholar\n");
     printf("6. Rogue Scientist\n");
     printf("7. Vagabond \(Unskilled\)\n");
     printf("8. Wilderness Scout\n");
     printf("9. Back to Previous Menu\n");
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>9);

     switch(option) {
       case 1:
	 bodyfixers();
	 break;
       case 2:
	 cityrats();
	 break;
       case 3:
	 cyberdocs();
	 break;
       case 4:
	 operators();
	 break;
       case 5:
	 roguescholar();
	 break;
       case 6:
	 roguescientist();
	 break;
       case 7:
	 vagabond();
	 break;
       case 8:
	 wildernesscout();
	 break;
       case 9:
	 clrscr;
	 break;
     }
   } while(option!=9);
 }
		/*
		 * Function magicusers is called from Function Block menu
		 * This function will allow choice from the practitioners
		 * of magic character OCC classes.
		 */
 magicusers()
  {
   int option=0;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tPRACTITIONERS OF MAGIC\n");
     printf("1. Line Walkers\n");
     printf("2. Techno-Wizards\n");
     printf("3. Shifters\n");
     printf("4. Mystics\n");
     printf("5. Back to Previous Menu\n");
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>5);

     switch(option) {
       case 1:
	 linewalkers();
	 break;
       case 2:
	 technowizards();
	 break;
       case 3:
	 shifters();
	 break;
       case 4:
	 mystics();
	 break;
       case 5:
	 clrscr;
	 break;
     }
   } while(option!=5);
 }
		/*
		 * Function rcc is called from Function Block menu
		 * This function will allow choice from the RCC
		 * and Psychic RCC character classes.
		 */
 rcc()
  {
   int option=0;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tRACIAL CHARACTER CLASSES AND PSYCHICS\n");
     printf("1. Dragons Great Horned\n");
     printf("2. Dragons Fire\n");
     printf("3. Dragons Ice\n");
     printf("4. Dragons Thunder Lizards\n");
     printf("5. Bursters\n");
     printf("6. Coalition Dog Pack\n");
     printf("7. Psi-Stalkers\n");
     printf("8. Mind Melters\n");
     printf("9. Back to Previous Menu\n");
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>9);

     switch(option) {
       case 1:
	 dragonsgh();
	 break;
       case 2:
	 dragonsfire();
	 break;
       case 3:
	 dragonsice();
	 break;
       case 4:
	 dragonsthndrliz();
	 break;
       case 5:
	 bursters();
	 break;
       case 6:
	 coaldogpack();
	 break;
       case 7:
	 psistalkers();
	 break;
       case 8:
	 mindmelters();
	 break;
       case 9:
	 clrscr;
	 break;
     }
   } while(option!=9);
 }

 /************************************************************************
   Function Block Group 3 Called from Funtion menofarms
 *************************************************************************/

	       /*
		* Function borg is called from Function Block
		* menofarms. This function will generate the character
		* class chosen
		*/
 borg()
  {
   int option=0, data=31;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tBorg Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function crazies is called from Function Block
		* menofarms. This function will generate the character
		* class chosen
		*/
 crazies()
  {
   int option=0, data=32;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tCrazy Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function cyberknights is called from Function Block
		* menofarms. This function will generate the character
		* class chosen
		*/
 cyberknights()
  {
   int option=0, data=33;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tCyber Knight Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function glitterboys is called from Function Block
		* menofarms. This function will generate the character
		* class chosen
		*/
 glitterboys()
  {
   int option=0, data=34;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tGlitterboy Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function juicers is called from Function Block
		* menofarms. This function will generate the character
		* class chosen
		*/
 juicers()
  {
   int option=0, data=35;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tJuicer Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function headhunters is called from Function Block
		* menofarms. This function will generate the character
		* class chosen
		*/
 headhunters()
  {
   int option=0, data=36;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tHeadhunter Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function coalgrunt is called from Function Block
		* menofarms. This function will generate the character
		* class chosen
		*/
 coalgrunt()
  {
   int option=0, data=37;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tCoalition Grunt Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function coalmilspec is called from Function Block
		* menofarms. This function will generate the character
		* class chosen
		*/
 coalmilspec()
  {
   int option=0, data=38;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tCoalition Military Specialist Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function coalrpaelite is called from Function Block
		* menofarms. This function will generate the character
		* class chosen
		*/
 coalrpaelite()
  {
   int option=0, data=39;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tCoalition RPA Elite or \"SAM\" Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function coaltechofficer is called from Function Block
		* menofarms. This function will generate the character
		* class chosen
		*/
 coaltechofficer()
  {
   int option=0, data=310;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tCoalition Technical Officer Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }

 /************************************************************************
   Function Block Group 4 Called from Funtion scholars
 *************************************************************************/

	       /*
		* Function bodyfixers is called from Function Block
		* scholars. This function will generate the character
		* class chosen
		*/
 bodyfixers()
  {
   int option=0, data=41;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tBody Fixer Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function cityrats is called from Function Block
		* scholars. This function will generate the character
		* class chosen
		*/
 cityrats()
  {
   int option=0, data=42;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tCity Rat Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function cyberdocs is called from Function Block
		* scholars. This function will generate the character
		* class chosen
		*/
 cyberdocs()
  {
   int option=0, data=43;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tCyber-Doc Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function operators is called from Function Block
		* scholars. This function will generate the character
		* class chosen
		*/
 operators()
  {
   int option=0, data=44;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tOperator Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function roguescholar is called from Function Block
		* scholars. This function will generate the character
		* class chosen
		*/
 roguescholar()
  {
   int option=0, data=45;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tRogue Scholar Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function roguescientist is called from Function Block
		* scholars. This function will generate the character
		* class chosen
		*/
 roguescientist()
  {
   int option=0, data=46;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tRogue Scientist Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function vagabond is called from Function Block
		* scholars. This function will generate the character
		* class chosen
		*/
 vagabond()
  {
   int option=0, data=47;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tVagabond Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function wildernesscout is called from Function Block
		* scholars. This function will generate the character
		* class chosen
		*/
 wildernesscout()
  {
   int option=0, data=48;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tWilderness Scout Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
 /************************************************************************
   Function Block Group 5 Called from Funtion magicusers
 *************************************************************************/

	       /*
		* Function linewalkers is called from Function Block
		* magicusers. This function will generate the character
		* class chosen
		*/
 linewalkers()
  {
   int option=0, data=51;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tLine Walker Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function technowizards is called from Function Block
		* magicusers. This function will generate the character
		* class chosen
		*/
 technowizards()
  {
   int option=0, data=52;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tTechno-Wizard Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function shifters is called from Function Block
		* magicusers. This function will generate the character
		* class chosen
		*/
 shifters()
  {
   int option=0, data=53;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tShifter Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function mystics is called from Function Block
		* magicusers. This function will generate the character
		* class chosen
		*/
 mystics()
  {
   int option=0, data=54;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tMystic Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }

 /************************************************************************
   Function Block Group 6 Called from Funtion rcc
 *************************************************************************/
	       /*
		* Function dragonsgh is called from Function Block
		* rcc. This function will generate the character
		* class chosen
		*/
 dragonsgh()
  {
   int option=0, data=61;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tGreat Horned Dragon Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function dragonsfire is called from Function Block
		* rcc. This function will generate the character
		* class chosen
		*/
 dragonsfire()
  {
   int option=0, data=62;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tFire Dragon Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function dragonsice is called from Function Block
		* rcc. This function will generate the character
		* class chosen
		*/
 dragonsice()
  {
   int option=0, data=63;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tIce Dragon Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function dragonsthndrliz is called from Function Block
		* rcc. This function will generate the character
		* class chosen
		*/
 dragonsthndrliz()
  {
   int option=0, data=64;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tThunder Lizard Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function bursters is called from Function Block
		* rcc. This function will generate the character
		* class chosen
		*/
 bursters()
  {
   int option=0, data=65;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tBurster Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function coaldogpack is called from Function Block
		* rcc. This function will generate the character
		* class chosen
		*/
 coaldogpack()
  {
   int option=0, data=66;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tCoalition Dog Pack Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function psistalkers is called from Function Block
		* rcc. This function will generate the character
		* class chosen
		*/
 psistalkers()
  {
   int option=0, data=67;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tPsi-Stalker Character Generation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }
	       /*
		* Function mindmelters is called from Function Block
		* rcc. This function will generate the character
		* class chosen
		*/
 mindmelters()
  {
   int option=0, data=68;
   char input[80];

   do {
     clrscr;
     settxtpos(1, 20);
     printf(mkdata);
     settxtpos(5, 1);
     printf("\tMind Melter Character Creation\n");
     shortmnu();
     do {
       printf("Enter your choice and hit Enter: ");
       gets(input);
       option = atoi(input);
     } while(option<1 || option>6);

     switch(option) {
       case 1:
	 chrprsnal(&data);
	 break;
       case 2:
	 genchrstat(&data);
	 break;
       case 3:
	 chrskills(&data);
	 break;
       case 4:
	 wepandequip(&data);
	 break;
       case 5:
	 dsplayit();
	 break;
       case 6:
	 clrscr;
	 break;
     }
   } while(option!=6);
 }

 /************************************************************************
   Function Block Group 7 Called from any function block
 *************************************************************************/

		/*
		 * Function shortmnu is called from Function Block any
		 * This function is repeated many times in the character
		 * generation process.
		 */
 shortmnu()
  {
   printf("1. Character's Personal Data and History\n");
   printf("2. Generate Character Stats and Bonuses\n");
   printf("3. Choose Character Skills, Powers and Abilities\n");
   printf("4. Choose Weapons and Equipment\n");
   printf("5. Display Character Statistics and Data\n");
   printf("6. Back to Previous Menu\n");
 }
		/*
		 * Function chrprsnal is called from Function Block any
		 * This function will allow the user to select the
		 * characters personal data, name, alignment, etc.
		 */
 chrprsnal(int *data)
  {
   int charnum=0, option=0, roll=0, sides=0;
   int value=0;
   char input[80];

   charnum = *data;

   do {
     setscrn();
     printf("Enter in the following information.\n");
     printf("Character Name: ");
     gets(chrdata[0]);
     printf("Alignment: ");
     gets(chrdata[2]);
     printf("Do you want to use random Roll Tables? ");
     gets(input);
     if((stricmp(input, "yes") == 0) || (stricmp(input, "y") == 0)) {

       printf("\tRandom Roll Tables\n");
       printf("This will display the random numbers generated then enter\n");
       printf("the discriptions that follow on pg 18 of the Main Rifts Book\n");
       sides = 100;
       roll = 1;

       value = rndmroll(&roll, &sides);
       printf("Birth Order: %d\n", value);
       printf("Birth Order: ");
       gets(chrdata[3]);

       value = rndmroll(&roll, &sides);
       printf("Weight: %d\n", value);
       printf("Weight: ");
       gets(chrdata[4]);

       value = rndmroll(&roll, &sides);
       printf("Height: %d\n", value);
       printf("Height: ");
       gets(chrdata[5]);

       value = rndmroll(&roll, &sides);
       printf("Disposition: %d\n", value);
       printf("Disposition: ");
       gets(chrdata[6]);

       value = rndmroll(&roll, &sides);
       printf("Family Origin: %d\n", value);

       value = rndmroll(&roll, &sides);
       if(value >= 86) {
	 value = rndmroll(&roll, &sides);
	 printf("Earth Mutant, D-Bee, or Alien: %d\n", value);
	 value = rndmroll(&roll, &sides);
	 printf("Character's appearance: %d\n", value);
       }
       printf("Family Origin: ");
       gets(chrdata[7]);
       printf("Character Appearance: ");
       gets(chrdata[11]);

       value = rndmroll(&roll, &sides);
       printf("Type of Environment: %d\n", value);
       printf("Type of Environment: ");
       gets(chrdata[8]);

       value = rndmroll(&roll, &sides);
       printf("Sentiments toward the Coalition: %d\n", value);
       printf("Sentiments toward Coalition: ");
       gets(chrdata[9]);

       value = rndmroll(&roll, &sides);
       printf("Sentiments toward Non-Humans: %d\n", value);
       printf("Sentiments toward Non-Humans: ");
       gets(chrdata[10]);
     }
     else {
       printf("Birth Order: ");
       gets(chrdata[3]);

       printf("Weight: ");
       gets(chrdata[4]);

       printf("Height: ");
       gets(chrdata[5]);

       printf("Disposition: ");
       gets(chrdata[6]);

       printf("Family Origin: ");
       gets(chrdata[7]);

       printf("Type of Environment: ");
       gets(chrdata[8]);

       printf("Sentiments toward Coalition: ");
       gets(chrdata[9]);

       printf("Sentiments toward Non-Humans: ");
       gets(chrdata[10]);
     }
     printf("Do you wish to keep the above data? ");
     gets(input);
   } while((stricmp(input, "yes") !=0) || (stricmp(input, "y")) !=0);
 }
		/*
		 * Function genchrstat is called from Function Block any
		 * This function will allow the user to generate the
		 * needed stats for the character, ie. IQ, ME, MA, etc.
		 */
 genchrstat(int *data)
  {
   int charnum=0, roll=0, sides=0, value=0;

   charnum = *data;
   printf("%d\n", charnum);
   value = rndmroll(&roll, &sides);
   while(!kbhit());
 }
		/*
		 * Function chrskills is called from Function Block any
		 * This function will allow the user to select the spicific
		 * skills the user wants for thier character.
		 */
 chrskills(int *data)
  {
   int charnum=0, roll=0, sides=0, value=0;

   charnum = *data;
   printf("%d\n", charnum);
   value = rndmroll(&roll, &sides);
   while(!kbhit());
 }
		/*
		 * Function wepandequip is called from Function Block any
		 * This function will allow the user to select spicific
		 * weapons and equipment needed for game playing.
		 */
 wepandequip(int *data)
  {
   int charnum=0, roll=0, sides=0, value=0;

   charnum = *data;
   printf("%d\n", charnum);
   value = rndmroll(&roll, &sides);
   while(!kbhit());
 }
		/*
		 * Function chrbase is called from Function Block any
		 * This function holds all of the spicific data needed
		 * for creating the individual characters wanted by the
		 * user.
		 */
 chrbase(int *data)
  {
   int charnum=0, roll=0, sides=0, value=0;

   charnum = *data;
   printf("%d\n", charnum);
   value = rndmroll(&roll, &sides);
   while(!kbhit());
 }
		/*
		 * Function dsplayit is called from Function Block any
		 * This function will allow the user to see his character
		 * stats and to see any information on skills or bonuses.
		 */
 dsplayit()
  {
   int a=0, b=0, c=0, d=0;

   for(a=0; a<20; a++) {
     printf("%s\n", chrdata[a]);
   }
 }
		/*
		 * Function setscrn is called from Function Block any
		 * This function is repeated many times in the character
		 * generation process.
		 */
 setscrn()
  {
   clrscr;
   settxtpos(1, 20);
   printf(mkdata);
   settxtpos(5, 1);
  }
		/*
		 * Function rndmroll is called from Function Block any
		 * This function will create the random number needed
		 * to create the character.
		 */
 rndmroll(int *roll, int *sides)
  {
   int a=0, i=0, rolltimes=0, numsides=0, tvalue=0;
   long value=0;

   rolltimes = *roll;
   numsides = *sides;
				/*
				 * This loop is neccisary, it is
				 * resopsable for creating the random number,
				 * the number of times it needs to roll up,
				 * the accumlative random rolls.
				 */
   for(i=0; i<rolltimes; i++) {
     tvalue = (rand()%numsides);
     value = value+tvalue+1;
   }

   return(value);
 }

