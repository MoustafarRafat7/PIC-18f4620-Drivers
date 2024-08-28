/* 
 * File:   LED.h
 * Author: Moustafa
 *
 * Created on 29,11, 2023, 04:02 ?
 */

#ifndef LED_H
#define	LED_H

/*    Includes Section    */
#include "../../MCAL_Layer/GPIO/Hal_GPIO.h"

/*    Macros Declarations Section   */
/*    Macro Function Declarations Section    */
/*    Data Type Declarations Section    */
typedef enum
{
    LED_OFF=0,
    LED_ON
}led_status_t;

typedef struct
{
    uint8 port   :4 ;
    uint8 pin    :3 ;
    uint8 status :1 ;
 }led_t;
 

/*    Functions Declarations Section    */
 Std_ReturnType led_initialize(const led_t *led);
 Std_ReturnType led_turn_on(const led_t *led);
 Std_ReturnType led_turn_off(const led_t *led);
 Std_ReturnType led_toggle(const led_t *led);


#endif	/* LED_H */

