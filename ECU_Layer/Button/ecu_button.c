/* 
 * File:   ecu_button.c
 * Author: Mostafa
 *
 * Created on 30,1, 2024, 06:21 pm
 */

/*    Includes Section    */
#include "ecu_button.h"

/*    Functions Definition Section    */

Std_ReturnType button_initialize(const button_t *btn )
{
    Std_ReturnType ret=E_OK;
    if(NULL == btn)
    {
        ret=E_NOT_OK;
    }
    
    else
    {
    gpio_pin_direction_initialize(&(btn->button_pin));
    }
    return ret;
}

Std_ReturnType button_read_status(const button_t *btn ,button_state_t *btn_state)
{
   Std_ReturnType ret=E_OK;
   logic_t button_state= GPIO_LOW ;
    if(NULL == btn || NULL == btn_state)
    {
        ret=E_NOT_OK;
    }   
    else
    {
        ret=gpio_pin_read_logic(&(btn->button_pin),&button_state);
        if(BUTTON_ACTIVE_HIGH == btn->button_logic)
        {
               if(GPIO_HIGH == button_state)
            {
                *btn_state=BUTTON_PRESSED;
            }
            else
            {
                     *btn_state=BUTTON_RELEASED;
            }
        }
        else if(BUTTON_ACTIVE_LOW == btn->button_logic)
            {
            if(GPIO_HIGH == button_state)
            {
                *btn_state=BUTTON_RELEASED;
            }
            else
            {
                     *btn_state=BUTTON_PRESSED;
            }
            
            }
    }
    return ret;
}