/* 
 * File:   ecu_relay.h
 * Author: Mostafa
 *
 * Created on 31 , 1 , 2024, 06:40 pm
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/*    Includes Section    */
#include "../../MCAL_Layer/GPIO/Hal_GPIO.h"

/*    Macros Declarations Section   */
#define  RELAY_OFF 0x00
#define  RELAY_ON  0x01
/*    Macro Function Declarations Section    */
/*    Data Type Declarations Section    */
typedef struct
{
    uint8 relay_port :4 ;
    uint8 relay_pin  :3 ;
    uint8 relay_status :1 ;
}relay_t;

/*    Functions Declarations Section    */
Std_ReturnType relay_initialization(const relay_t *relay);
Std_ReturnType relay_turn_on(const relay_t *relay);
Std_ReturnType relay_turn_off(const relay_t *relay);
Std_ReturnType relay_toggle(const relay_t *relay);
#endif	/* ECU_RELAY_H */

