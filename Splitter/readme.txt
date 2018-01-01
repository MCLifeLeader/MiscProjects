
	File Splitter and Windows File Splitter are designed to split large data
files into smaller more transportable sizes. Then reconstruct the files
back to their original state. The Current Code has been developed under

Versions and Updates...
Windows File Splitter V2.00.00b
	Compleate ReWrite of Windows File Splitter, Older Versions may Not be Supported
   ( In ReWrite, Comming Soon Maybe.....)
Windows File Splitter V1.08.00
	Major problem found in the reading in of long file names, Changed storage meathod
		found in the *.spl file This was changed in the splitter.cpp and effects all code.

Windows File Splitter V1.07.10
	Changed all Variables dealing with file size to unsigned long

Windows File Splitter V1.07.09
	Minor Text changes to greetings message when program is first run.

Windows File Splitter V1.07.08
	Fixed problem with Forced split restore not correctly creating the recovery file.

Windows File Splitter V1.07.06
	Fixed Problem were the Filename Path is being stored in the Splitter *.spl File.

Windows File Splitter V1.07.04
	Broke out sections of code into respective modules for the Main Window Proc
   	and the Dialog boxes proc.
   Made small Causmetic change to the main text that comes up on the screen.

Windows File Splitter V1.07.02
	Updated the naming convention so that it was not limited to a month day year
   		but is now setup to go to 99999999 insted of 12319999
   	Added Support for more than one TER file group in the same directory.

Windows File Splitter V1.06.31
	Slight Causmetic Change to the Inital Start up text.

Windows File Splitter V1.06.30
	Added Auto Combine Feature when double clicking a *.spl file.
	Corrected Memory over run Errors caused by incorrect pointer accessing.

Windows File Splitter V1.06.28
	Added Windows Registry Update Feature, Although Currently, WinSplitr.exe must
	be Placed in File Path in order for Icons to display on *.spl and *.ter
		Files.
	Made the "File New" and "File Open" from the Menu automatically start
		Processing the file *.ter and *.spl files
	Added Text and Icon to the "About" Dialog Box.

Windows File Splitter V1.06.22
	Added Event Tag in the *.TER file For File Error Checking.
	Added Version ID tag to *.SPL as to add reverse compatibility from this point
		on.

Windows File Splitter V1.05.61
	Corrected error between WinSplit and DOSplit control *.SPL Index Files

/******************************/
DOS File Splitter V2.00.00b
   ( In ReWrite, Comming Soon Maybe.....)
	Compleate ReWrite of DOS File Splitter, Older Versions may Not be Supported

DOS File Splitter V1.08.00
	Major problem found in the reading in of long file names, Changed storage meathod
		found in the *.spl file This was changed in the splitter.cpp and effects all code.

DOS File Splitter V1.07.10
	Changed all Variables dealing with file size to unsigned long

DOS File Splitter V1.07.10
	In Development, Add wild card search, and allow for \crdata\filename.ext

DOS File Splitter V1.07.09
	Minor Text changes to greetings message when program is first run.

DOS File Splitter V1.07.08
	Fixed problem with Forced split restore not correctly creating the recovery file.

DOS File Splitter V1.07.06
	Fixed Problem were the Filename Path is being stored in the Splitter *.spl File.

DOS File Splitter V1.07.02
	Updated the naming convention so that it was not limited to a month day year
   	but is now setup to go to 99999999 insted of 12319999
   Added Support for more than one TER file group in the same directory.

DOS File Splitter V1.06.31
	Corrected Case were the *.SPL Control File was removed if the file Processeing
   	Failed.

DOS File Splitter V1.06.30
	Corrected Memory over run Errors caused by incorrect pointer accessing.

DOS File Splitter V1.06.22
	Added Event Tag in the *.TER file For File Error Checking.
	Added Version ID tag to *.SPL as to add reverse compatibility from this point
		on.

DOS File Splitter V1.04.52
	Corrected error between WinSplit and DOSplit control *.SPL Index Files


DOS File Splitter V1.4.27
	Added ablilty to force recovery of the *.TER with out the *.SPL control
		File.

	Added protection against over writing *.TER files and *.SPL file when
		Creating more than one set of *.TER Files.

	Added Data Checks to report if the CRC or size is different.

DOS File Splitter V1.00.00
	Able to split and restore split apart files

Disclaimer of Warranty

THIS SOFTWARE AND THE ACCOMPANYING FILES ARE "AS IS" AND WITHOUT
WARRANTIES AS TO PERFORMANCE OR MERCHANTABILITY OR ANY OTHER WARRANTIES
WHETHER EXPRESSED OR IMPLIED.  Because of the various hardware and
software environments into which (Windows,DOS,OS/2,Linux) File Splitter may
be put, NO WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE IS OFFERED.

Good data processing procedure dictates that any program be thoroughly
tested with non-critical data before relying on it.  The user must
assume the entire risk of using the program.  ANY LIABILITY OF THE
PROGRAMMER WILL BE LIMITED EXCLUSIVELY TO REPLACEMENT OF THE
(WINDOWS,DOS,OS/2,Linux) FILE SPLITTER SOFTWARE.

THIS SOFTWARE AND THE ACCOMPANYING SOURCE CODE IS PROVIDED FOR PUBLIC DOMAIN and
may NOT BE SOLD or MODIFIED for PROFIT. ANY DISTROBUTION OR REDISTROBUTION OF
the files listed below MUST BE included UNTOUCHED AND UNMODIFIED with any new
modifications to the source code or executables separate. Any NEWER versions
released SHOULD have ALL of the files listed below. If any or ALL of the files
listed below are MISSING or DAMAGED you can pick up a new copy on my web page or
contact me via email.

Rights Reserved, Without Prejudice UCC 1-207

(SPLITTER.ZIP)          Name of the ZipFile Containing Files listed Below
	SPLITTER CPP
	WINMAINP CPP
        WNDLGPRC.CPP
        WINREG.CPP
	DOS2MAIN CPP
	OS2MAINP CPP
	SPLITTER H
	SPLITTER RC
	WINSPLTR EXE
	SPLITTER EXE
	SPLITTER.DEF
	README.TXT

Copyright 1998 - 2002 Michael Carey
Web Paged Closed --->  http://www.owt.com/users/mbcarey
mbcarey@trilument.com


