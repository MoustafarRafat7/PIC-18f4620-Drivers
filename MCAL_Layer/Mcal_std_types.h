/* 
 * File:   Mcal_std_types.h
 * Author: Moustafa
 *
 * Created on 29,11, 2023, 03:57 ?
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/*    Includes Section    */
#include "std_libraries.h"
#include "Compiler.h"
 
/*    Macros Declarations Section   */

#define STD_HIGH       0X01
#define STD_LOW        0X00

#define STD_ON         0X01
#define STD_OFF        0X00

#define STD_ACTIVE     0X01
#define STD_IDLE       0X00

#define E_OK           (Std_ReturnType)0X01
#define E_NOT_OK       (Std_ReturnType)0x00
#define ZERO_INIT      0X00


/*    Macro Function Declarations Section    */
/*    Data Type Declarations Section    */

typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32;
typedef signed   char  sint8;
typedef signed   short sint16;
typedef signed   int   sint32;
typedef uint8          Std_ReturnType;





/*    Functions Declarations Section    */

#endif	/* MCAL_STD_TYPES_H */

