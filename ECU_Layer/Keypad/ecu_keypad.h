/* 
 * File:   ecu_keypad.h
 * Author: Mostafa
 *
 * Created on 03 , 2 2024, 03:32 pm
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/*    Includes Section    */
#include "ecu_keypad_cfg.h"
#include "../../MCAL_Layer/GPIO/Hal_GPIO.h"

/*    Macros Declarations Section   */
#define KEYPAD_ROWS    4
#define KEYPAD_COLUMNS 4 

/*    Macro Function Declarations Section    */

/*    Data Type Declarations Section    */
typedef struct
{
    pin_config_t keypad_rows_pins[KEYPAD_ROWS];
    pin_config_t keypad_columns_pins[KEYPAD_COLUMNS];
}keypad_t;

/*    Functions Declarations Section    */

Std_ReturnType keypad_initilize(const keypad_t *keypad);
Std_ReturnType keypad_get_value_pressed(const keypad_t *keypad, uint8 *value); 

#endif	/* ECU_KEYPAD_H */

