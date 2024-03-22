#ifndef STD_H_INCLUDED
#define STD_H_INCLUDED



///this file contain the primitive data type but using typedef keyword
///'NULL' is  for null pointer
///'u' is for unsigned
///'s' is for signed
///'int' is for integer numbers
///'boolean' is for boolean values which are true and false
///'8' is for 8 bits
///'16' is for 16 bits
///'32' is for 32 bits

#define NULL ((void*)0)

typedef unsigned char uint8 ;
typedef signed char sint8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned int uint32;
typedef signed int sint32;
typedef enum {false, true} boolean;

#endif // STD_H_INCLUDED
