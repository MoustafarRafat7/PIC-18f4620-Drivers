/* 
 * File:   ecu_seven_segment.h
 * Author: Mostafa
 *
 * Created on 02 , 2 2024, 10:59 PM
 */

#ifndef ECU_SEVEN_SEGMENT_H
#define	ECU_SEVEN_SEGMENT_H

#endif	/* ECU_SEVEN_SEGMENT_H */

/*    Includes Section    */
#include "../../MCAL_Layer/GPIO/Hal_GPIO.h"
#include "ecu_seven_segment_cfg.h"
/*    Macros Declarations Section   */
#define  SEGMENT_PINA 0X00
#define  SEGMENT_PINB 0X01
#define  SEGMENT_PINC 0X02
#define  SEGMENT_PIND 0X03
/*    Macro Function Declarations Section    */
/*    Data Type Declarations Section    */
typedef enum
{
    SEVEN_SEGMENT_COMMON_ANODE,
    SEVEN_SEGMENT_COMMON_CATHODE
}seven_segment_type_t;

typedef struct
{
    pin_config_t seven_segment_pin[4] ;
    seven_segment_type_t seven_segment_type;
}seven_segment_t;

/*    Functions Declarations Section    */
Std_ReturnType seven_segment_initilization(const seven_segment_t *seven_segment);
Std_ReturnType seven_segment_write_number(const seven_segment_t *seven_segment,uint8 number);
                
