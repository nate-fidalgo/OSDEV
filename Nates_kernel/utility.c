typedef int size_t;


/********* port reading and writing ***************************/

unsigned char inb (unsigned short ) ;
void outb (unsigned short , unsigned char ) ;

unsigned char inb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

/******************************************************************/



/****************Memory and Memory allocation functions *************************/

void *memcpy(void *dest, const void *src, size_t count);
void *memset(void *dest, char val, size_t count);
unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count);


void *memcpy(void *dest, const void *src, size_t count)
{
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    for(; count != 0; count--) *dp++ = *sp++;
    return dest;
}

void *memset(void *dest, char val, size_t count)
{
    char *temp = (char *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count)
{
    unsigned short *temp = (unsigned short *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}


/*******************************************************************************/


/******************************String  and Character manipulation functions *******************/

size_t strlen(const char *str);

size_t strlen(const char *str)
{
    size_t retval;
    for(retval = 0; *str != '\0'; str++) retval++;
    return retval;
}


unsigned char toUpperCase( unsigned char c)
{
   if( c >= 97 || c <= 122 )
   return c - 32 ;
   
   return c ;
}

unsigned char toLowerCase( unsigned char c)
{
   if( c >= 65 || c <= 90 )
   return c + 32 ; 
  
   return c ;
}


/*********************************************************************************/


/**************************Math functions ****************************************/





/*********************************************************************************/






