/* 
 * File:   Application.h
 * Author: Moustafa
 *
 * Created on 29 ,11, 2023, 04:11 ?
 */

#ifndef APPLICATION_H
#define	APPLICATION_H


/*    Includes Section    */
#include <stdio.h>
#include <stdlib.h>
#include "ECU_Layer/LED/ecu_led.h"
#include "MCAL_Layer/GPIO/Hal_GPIO.h"
#include "ECU_Layer/Relay/ecu_relay.h"
#include "ECU_Layer/Button/ecu_button.h"
#include "ECU_Layer/DC_Motor/ecu_dc_motor.h"
#include "ECU_Layer/7_Segment/ecu_seven_segment.h"
#include "ECU_Layer/Keypad/ecu_keypad.h"
#include "ECU_Layer/Character_LCD/ecu_character_lcd.h"
/*    Macros Declarations Section   */
#define _XTAL_FREQ 8000000 
/*    Macro Function Declarations Section    */
void application_initialize(void);
/*    Data Type Declarations Section    */
/*    Functions Declarations Section    */
#endif	/* APPLICATION_H */

