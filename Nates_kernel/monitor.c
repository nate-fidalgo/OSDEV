
/* 
    Video card mono/colour detection.
    Return values:  false=colour 
                    true=monochrome
*/
#define TRUE  1
#define FALSE 0

int detectVideoType(void) ;

int detectVideoType(void)
{
   char c=(*(volatile unsigned short int *)0x410)&0x30;

    //c can be 0x00 or 0x20 for colour, 0x30 for mono.
   if( c == 0x30 )
   return TRUE ;   

   return FALSE ;
}
