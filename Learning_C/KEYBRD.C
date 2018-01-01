/* KEYBRD.C illustrates:
 *      _bios_keybrd
 */

#include <bios.h>
#include <stdio.h>
#include <ctype.h>

/* Macro to peek at a specified memory address */
#define peek( addr )        (*(unsigned char far *)addr)

main()
{
    unsigned key, shift, scan, ascii = 0;
    int kread = _KEYBRD_READ;
    int kready = _KEYBRD_READY;
    int kshiftstatus = _KEYBRD_SHIFTSTATUS;

    /* If bit 4 of the byte at 0x0040:0x0096 is set, the new keyboard
     * is present.
     */
    if( peek( 0x00400096 ) & 0x10 )
    {
	kread = _NKEYBRD_READ;
	kready = _NKEYBRD_READY;
	kshiftstatus = _NKEYBRD_SHIFTSTATUS;
    }
    printf( "New keyboard %s\n",
	    (kread == _NKEYBRD_READ) ? "present" : "not present" );

    /* Read and display keys until ESC is pressed. */
    while( ascii != 27 )
    {
	/* Drain any keys in the keyboard type-ahead buffer, then get
	 * the current key. If you want the last key typed rather than
	 * the key currently being typed, omit the initial loop.
	 */
	while( _bios_keybrd( kready ) )
	    _bios_keybrd( kread );
	key = _bios_keybrd( kread );

	/* Get shift state. */
	shift = _bios_keybrd( kshiftstatus );

	/* Split key into scan and ascii parts. */
	scan = key >> 8;
	ascii = key & 0x00ff;

	/* Categorize key. */
	if( (ascii == 0) || (ascii == 0xE0 ) )
	    printf( "ASCII: no\tChar: NA\t" );
	else if( ascii < 32 )
	    printf( "ASCII: yes\tChar: ^%c\t", ascii + '@' );
	else
	    printf( "ASCII: yes\tChar: %c \t", ascii );
	printf( "Code: %.2X\tScan: %.2X\t Shift: %.4X\n",
		ascii, scan, shift );
    }
}

