/* 
 * File:   ecu_led.c
 * Author: Moustafa
 *
 * Created on 29,11, 2023, 04:02 ?
 */

/*    Includes Section    */
#include "ecu_led.h"

/*    Macros Declarations Section   */
/*    Macro Function Declarations Section    */
/*    Data Type Declarations Section    */
/*    Functions Definition Section    */

/**
 * 
 * @param led
 * @return 
 */
 Std_ReturnType led_initialize(const led_t *led)
 {
     
     Std_ReturnType ret= E_OK;
     if(NULL == led)
     {
         ret=E_NOT_OK;
     }
     else
     {
         pin_config_t item={
     .port=led->port,
     .pin =led->pin,
     .direction=GPIO_OUTPUT,
     .logic=led->status
     };
         gpio_pin_initialize(&item);
     }
     
         return ret;
 }
 
 /**
  * 
  * @param led
  * @return 
  */
 Std_ReturnType led_turn_on(const led_t *led)
 {
     Std_ReturnType ret= E_OK;
     if(NULL == led)
     {
         ret=E_NOT_OK;
     }
     else
     {
          pin_config_t item={
     .port=led->port,
     .pin =led->pin,
     .direction=GPIO_OUTPUT,
     .logic=led->status
     };
         gpio_pin_write_logic(&item,GPIO_HIGH);
     }
     
         return ret;
 }
 
 /**
  * 
  * @param led
  * @return 
  */
 Std_ReturnType led_turn_off(const led_t *led)
 {
     Std_ReturnType ret= E_OK;
     if(NULL == led)
     {
         ret=E_NOT_OK;
     }
     else
     {
          pin_config_t item={
     .port=led->port,
     .pin =led->pin,
     .direction=GPIO_OUTPUT,
     .logic=led->status
     };
         gpio_pin_write_logic(&item,GPIO_LOW);
         
     }
     
         return ret;
 }
 
 /**
  * 
  * @param led
  * @return 
  */
 
 
 Std_ReturnType led_toggle(const led_t *led)
 {
     Std_ReturnType ret= E_OK;
     if(NULL == led)
     {
         ret=E_NOT_OK;
     }
     else
     {
          pin_config_t item={
     .port=led->port,
     .pin =led->pin,
     .direction=GPIO_OUTPUT,
     .logic=led->status
     };
         gpio_pin_toggle_logic(&item);
     }
     
         return ret;
 }