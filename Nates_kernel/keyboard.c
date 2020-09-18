


unsigned char kbdus[128] = { 0 , 27 , '1' , '2' , '3' , '4' ,'5' ,'6' ,'7' , '8' , '9' , '0' ,
 '-' , '=' , '\b' , '\t' , 'q' , 'w' , 'e' , 'r' , 't' , 'y' , 'u' , 'i' , 'o' , 'p' , '[' , ']' ,
'\n' , 0 , 'a' , 's' , 'd' , 'f' , 'g' , 'h' , 'j' , 'k' , 'l' , ';' , '\'' , '`' , 0 , '\\' , 'z' , 'x' ,
'c' , 'v' , 'b' , 'n' , 'm' , ',' , '.' , '/' , 0 , '*' , 0 , ' ' , 0 , 0, 0 , 0,0,0,0,0,0,0 ,
0 , 0,0,0,0,0,'-',0,0,0,'+' , 0,0,0,0,0,0,0,0,0 } ;

struct KEYBOARD_DATA  
{
int shift_state         ;
int escaped             ;
unsigned char scancode ;
}

KEYBOARD_DATA key_data ;

int shift_state   = 0 ;
int escaped       = 0 ;

/* Handles the keyboard interrupt */
void keyboard_handler( void (*CALLBACKFUNC[])( KEYBOARD_DATA ) , int callback_function_size )
{
    unsigned char scancode;
    /* Read from the keyboard's data buffer */
    scancode = inb(0x60);
    
	
    switch(scancode) 
	{
        case 0x2a: 
            shift_state = 1; 
            break;
 
        case 0xaa: 
            shift_state = 0;
            break;
					
		case 0xe0:
		    escaped = 1;
			break;

        default:
           if (scancode & 0x80) {
              /* Ignore the break code */
           } 
		   else
		   {
              
			 /* Do something with new_char. */
           }
           break;
     }
	 
     key_data.scancode    = scancode    ;	 
	 key_data.shift_state = shift_state ;
	 key_data.shift_state = escaped     ;
	 
	 for( int i = 0 ; i < callback_function_size ; i++ )
	 (*CALLBACKFUNC[i])( key_data ) ;
	 
     outportb(0x20,0x20);
	
}


 #define SCROLL_LED 1
 #define NUM_LED 2
 #define CAPS_LED 4
 
 void kbd_update_leds(unsigned char status){
 	
 	while((inportb(0x64)&2)!=0){} //loop until zero
 	outb(0x60,0xED);
 
 	while((inportb(0x64)&2)!=0){} //loop until zero
 	outb(0x60,status);
 }