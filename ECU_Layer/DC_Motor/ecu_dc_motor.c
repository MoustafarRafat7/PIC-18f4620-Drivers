/* 
 * File:   ecu_dc_motor.c
 * Author: Mostafa
 *
 * Created on 01 ,2, 2024, 07:42 PM
 */
/*    Includes Section    */

#include "ecu_dc_motor.h"

/*       functions Definitions        */
Std_ReturnType dc_motor_initilization(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;
    if(NULL == dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_initialize(&(dc_motor->_dc_motor[MOTOR_INPUT_1]));
        gpio_pin_initialize(&(dc_motor->_dc_motor[MOTOR_INPUT_2]));
    }
    return ret;
}
Std_ReturnType dc_motor_move_right(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;
    if(NULL == dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret=gpio_pin_write_logic(&(dc_motor->_dc_motor[MOTOR_INPUT_1]),GPIO_HIGH);
        ret=gpio_pin_write_logic(&(dc_motor->_dc_motor[MOTOR_INPUT_2]),GPIO_LOW); 
    }
    return ret;
}
Std_ReturnType dc_motor_move_left(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;
    if(NULL == dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret=gpio_pin_write_logic(&(dc_motor->_dc_motor[MOTOR_INPUT_1]),GPIO_LOW);
        ret=gpio_pin_write_logic(&(dc_motor->_dc_motor[MOTOR_INPUT_2]),GPIO_HIGH); 
        
    }
    return ret;
}   
Std_ReturnType dc_motor_stop(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;
    if(NULL == dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret=gpio_pin_write_logic(&(dc_motor->_dc_motor[MOTOR_INPUT_1]),GPIO_LOW);
        ret=gpio_pin_write_logic(&(dc_motor->_dc_motor[MOTOR_INPUT_2]),GPIO_LOW); 
    }
    return ret;
}
