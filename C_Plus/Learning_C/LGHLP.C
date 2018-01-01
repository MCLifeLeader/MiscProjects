/*
 *
 * Compiler:    Ansi C   MicroSoft Quick C
 * Program:     lghlp.c
 * Purpose:     Help information for lgates.c
 * Programmer:  Mike Carey
 * Date:        Jan. 11, 1994
 * Last Mod:
 *
 */

	/*
	 * This file will contain all of the information of logic tables
	 * and misclanious information that someone might need for help.
	 */

  char *orgate[] = {
    "The truth table for the OR gate is.\n",
    "  B   A   =   answer on/off or 1's and 0's\n",
    "  0   0   =   0\n",
    "  0   1   =   1\n",
    "  1   0   =   1\n",
    "  1   1   =   1\n"
  };

  char *norgate[] = {
    "The truth table for the NOR gate is.\n",
    "  B  A  =  answer on/off or 1's and 0's\n",
    "  0  0  =  1\n",
    "  0  1  =  0\n",
    "  1  0  =  0\n",
    "  1  1  =  0\n"
  };

  char *xorgate[] = {
    "The truth table for the XOR gate is.\n",
    "  B  A  =  answer on/off or 1's and 0's\n",
    "  0  0  =  0\n",
    "  0  1  =  1\n",
    "  1  0  =  1\n",
    "  1  1  =  0\n"
  };

  char *xnorgate[] = {
    "The truth table for the XNOR gate is.\n",
    "  B  A  =  answer on/off or 1's and 0's\n",
    "  0  0  =  1\n",
    "  0  1  =  0\n",
    "  1  0  =  0\n",
    "  1  1  =  1\n"
  };

  char *andgate[] = {
    "The truth table for the AND gate is.\n",
    "  B  A  =  answer on/off or 1's and 0's\n",
    "  0  0  =  0\n",
    "  0  1  =  0\n",
    "  1  0  =  0\n",
    "  1  1  =  1\n"
  };

  char *nandgate[] = {
    "The truth table for the NAND gate is.\n",
    "  B  A  =  answer on/off or 1's and 0's\n",
    "  0  0  =  1\n",
    "  0  1  =  1\n",
    "  1  0  =  1\n",
    "  1  1  =  0\n"
  };

  char *notgate[] = {
    "The truth table for the NOT / Inverter gate is.\n",
    "  B  A  =  answer on/off or 1's and 0's\n",
    "  *  0  =  1\n",
    "  *  1  =  0\n"
  };



