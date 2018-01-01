/****************************************************************************
Program:    SPLITTER.EXE
Author:     Mike Carey
Date:			03/26/98
Last Mod:	01/20/99
Compiler:   Borland C++ 5.02
Email:		mbcarey@owt.com

****************************************************************************
Comments:	This program is designed to Split up large files into smaller ones

Note: 		This program is developmental code, so that I can become familare
				with the MS Windows API's, and to Learn how to program in MS
            Windows.
****************************************************************************/

#ifndef __SPLITTER_H
#define __SPLITTER_H

#include <stdio.h>

#define DEBUGSPLIT 1

#define FILEVER "Windows Splitter V1.08.00 Copyright 1998 - 2002 Michael Carey\000\000"

// This is set in Pre-complier defines statment area for the make file.
//#define WINCOMP 1
//#define DOSCOMP 1
//#define OS2COMP 1
//#define OS2GUIP 1
//#define LINUXOS 1

#define LARGBUFF 				6144
#define FILENAME 				2048
#define DSPLBUFF 				512
#define SMALBUFF 				256
#define MAXITEMS 				256

#define DEFUALTFILESZ 		1024000
#define FILESIZELIMIT  		10240

#if WINCOMP == 1

#include <windows.h>
#include "resource.h"

struct WNSCROLLTEXTBUFF {
	WNSCROLLTEXTBUFF *nxt;
   BOOL ShowThisLine;
   char *WnTextBuffer;
};

// Set these Global varables so that the rest of the modules can see these vars
// during compile and link and be able to access them

extern "C" HINSTANCE 	hInst;
extern "C" LPCTSTR 		lpszAppName;
extern "C" LPCTSTR 		lpszTitle;
extern "C" HMENU 			hMenu;
extern "C" HWND 			ghWnd;
extern "C" OPENFILENAME OpnFileName;

extern "C" char	*gFileName;
extern "C" char	*gSFileName;
extern "C" char 	*Buffer;
extern "C" char 	*Buffer;
extern "C" char 	*FileName;
extern "C" char 	*TmpString;

extern "C" int 	gSplitTotal;
extern "C" int		RestoreFlag;
extern "C" int 	SplitFlag;
extern "C" int 	nNumItems;
extern "C" int 	*nNumRows;

extern "C" long 	gSplitSize;

extern "C" WNSCROLLTEXTBUFF *WnScrollTextBuffH;
extern "C" WNSCROLLTEXTBUFF *WnScrollTextBuff;

// winmainp.cpp
LRESULT CALLBACK DlgForceFixProc	 ( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
LRESULT CALLBACK WndProc 			 ( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
LRESULT CALLBACK DlgSplitSizeProc ( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
LRESULT CALLBACK DlgAboutSplitProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

void hscroll( HWND hWnd, int* pnCurPos, WORD wScroll );
void vscroll( HWND hWnd, int* pnCurPos, WORD wScroll );

void Add_Window_String( char *String );
void Add_To_Window_String( char *String );
void CleanUp_Window_Strings( void );
void DisplayTextToScreen( char *String );

void Init_OpenFileStruct( HWND hWnd );
void ProcessFileData( void );

int Check_For_Reg_Entry( void );
int Create_Reg_Entry( void );

void Get_FileName_to_Process( char *ReturnStr, char *InputStr );
void note(const char *String );

#endif

#if DOSCOMP == 1
#  ifdef FILEVER
#    undef FILEVER
#  endif
#  define FILEVER "DOS File Splitter V1.08.00 Copyright 1998 - 2002 Michael Carey\000\000"
#include <conio.h>
#endif

#if OS2COMP == 1
#  ifdef FILEVER
#    undef FILEVER
#  endif
#  define FILEVER "OS/2 File Splitter V1.08.00 Copyright 1998 - 2002 Michael Carey\000\000"
#include <conio.h>
#endif

#if OS2GUIP == 1
#  ifdef FILEVER
#    undef FILEVER
#  endif
#  define FILEVER "OS/2 PM File Splitter V1.08.00 Copyright 1998 - 2002 Michael Carey\000\000"
#endif

#if LINUXOS == 1
#  ifdef FILEVER
#    undef FILEVER
#  endif
#  define FILEVER "Linux File Splitter V1.08.00 Copyright 1998 - 2002 Michael Carey\000\000"
#endif

struct CFGFILEINFO {
  char 			 FileName[ FILENAME ];
  char 			 TerStart[ FILENAME ];
  char 			 TerEnd  [ FILENAME ];
  unsigned long FileSize;
  unsigned long SplitSize;
  unsigned long FileCRC;
  unsigned long SplitVer;
  long 			 SplitTotal;
};

// winmainp.cpp, dos2main.cpp
void note( char *String );
void windisplay( char *String );
// winmainp.cpp, dos2main.cpp

// splitter.cpp
int Force_CRC_Reconstruct( char *FileName );
int Reconstruct_Files( char *FileName );
int Split_Files_Apart( char *FileName, char *SplitFile, unsigned long SplitSize );

void Get_File_Stats( FILE **fp, unsigned long *FileSize, unsigned long *FileCRC );
// splitter.cpp

#endif // __SPLITTER_H


