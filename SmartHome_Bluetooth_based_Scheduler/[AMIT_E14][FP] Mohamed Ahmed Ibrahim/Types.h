
#ifndef TYPES_H_
#define TYPES_H_

#define HIGH 1
#define LOW  0
#define SET_BIT(PORT,PIN)    ( PORT |=  (1<<PIN) )
#define CLEAR_BIT(PORT,PIN)  ( PORT &= ~(1<<PIN) )
#define READ_BIT(PORT,PIN)   ( 1 &   (PORT>>PIN) )

typedef unsigned char         uint8;
typedef unsigned short        uint16;
typedef unsigned long         uint32;
typedef unsigned long long    uint64;
typedef   signed char         sint8;
typedef          short        sint16;
typedef          long         sint32;
typedef          long long    sint64;

#endif /* TYPES_H_ */
