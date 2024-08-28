/* 
 * File:   ecu_relay.c
 * Author: Mostafa
 *
 * Created on 31 , 1 , 2024, 06:41 pm
 */

/*    Includes Section    */
#include "ecu_relay.h"

/*    Functions Definition Section    */

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_initialization(const relay_t *relay)
{
    Std_ReturnType ret = E_OK;
    if(NULL == relay)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t item={.port= relay->relay_port ,
        .pin = relay->relay_pin ,
        .direction = GPIO_OUTPUT , 
        .logic = relay->relay_status
        };
        ret=gpio_pin_initialize(&item);
        
    }
        return ret;
}
/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_turn_on(const relay_t *relay)
{
    Std_ReturnType ret = E_OK;
    if(NULL == relay)
    {
        ret = E_NOT_OK;
    }
    else
    {
         pin_config_t item={.port= relay->relay_port ,
        .pin = relay->relay_pin ,
        .direction = GPIO_OUTPUT , 
        .logic = relay->relay_status
        };
         ret=gpio_pin_write_logic(&item ,GPIO_HIGH);
        
    }
        return ret;
}
/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_turn_off(const relay_t *relay)
{
    Std_ReturnType ret = E_OK;
    if(NULL == relay)
    {
        ret = E_NOT_OK;
    }
    else
    {
         pin_config_t item={.port= relay->relay_port ,
        .pin = relay->relay_pin ,
        .direction = GPIO_OUTPUT , 
        .logic = relay->relay_status
        };
         ret=gpio_pin_write_logic(&item ,GPIO_LOW);
        
        
    }
        return ret;
}
/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_toggle(const relay_t *relay)
{
    Std_ReturnType ret = E_OK;
    if(NULL == relay)
    {
        ret = E_NOT_OK;
    }
    else
    {
         pin_config_t item={.port= relay->relay_port ,
        .pin = relay->relay_pin ,
        .direction = GPIO_OUTPUT , 
        .logic = relay->relay_status
        };
         ret=gpio_pin_toggle_logic(&item);
        
        
    }
        return ret;
}


