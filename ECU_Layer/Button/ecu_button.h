/* 
 * File:   ecu_button.h
 * Author: Mostafa
 *
 * Created on 30 jan, 2024, 06:21 ?
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/*    Includes Section    */
#include "../../MCAL_Layer/GPIO/Hal_GPIO.h"
#include "ecu_button_cfg.h"

/*    Macros Declarations Section   */
/*    Macro Function Declarations Section    */
/*    Data Type Declarations Section    */
typedef enum
{
   BUTTON_RELEASED=0,
   BUTTON_PRESSED

}button_state_t;

typedef enum
{
    BUTTON_ACTIVE_LOW=0,
    BUTTON_ACTIVE_HIGH

}button_active_logic_t;

typedef struct
{
    pin_config_t button_pin;
    button_active_logic_t button_logic;
    button_state_t button_status;
}button_t;

/*    Functions Declarations Section    */
Std_ReturnType button_initialize(const button_t *btn );
Std_ReturnType button_read_status(const button_t *btn ,button_state_t *btn_state);

#endif	/* ECU_BUTTON_H */

