/* 
 * File:   ecu_keypad.c
 * Author: Mostafa
 *
 * Created on 03 , 2 , 2024, 03:33 pm
 */

/*    Includes Section    */

#include "ecu_keypad.h"

/*       Datatype Definitions        */
uint8 keypad_values[KEYPAD_ROWS][KEYPAD_COLUMNS]={{'7','8','9','/'}
                                                 ,{'4','5','6','*'}
                                                 ,{'1','2','3','-'}
                                                 ,{'#','0','=','+'}
};
/*       Functions Definitions        */
/**
 * @brief initilize the keypad by setting rows pins as o/p and columns pins as i/p
 * @param keypad [rows&columns] pins configuration 
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */

Std_ReturnType keypad_initilize(const keypad_t *keypad)
{
    Std_ReturnType ret = E_OK;
    uint8 rows_counter=0,columns_counter=0;
    if( NULL == keypad )
    {
        ret = E_NOT_OK;
    }
    else
    {
        for( rows_counter = ZERO_INIT ; rows_counter < KEYPAD_ROWS ; rows_counter++)
        {
        ret=gpio_pin_initialize(&(keypad->keypad_rows_pins[rows_counter]));
        }
        for( columns_counter = ZERO_INIT ; columns_counter < KEYPAD_COLUMNS ; columns_counter++)
        {
        ret=gpio_pin_initialize(&(keypad->keypad_columns_pins[columns_counter]));
        }
       
    }
    return ret;
    
}

/**
 * @brief
 * @param keypad
 * @param value
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */

Std_ReturnType keypad_get_value_pressed(const keypad_t *keypad, uint8 *value)
{
    Std_ReturnType ret = E_OK;
    uint8 rows_counter=0,columns_counter=0,clear_counter=0;
    logic_t pin_logic =GPIO_LOW;
    if( NULL == keypad )
    {
        ret = E_NOT_OK;
    }
    else
    {
         for( rows_counter = ZERO_INIT ; rows_counter < KEYPAD_ROWS ; rows_counter++)
        {
             
            for( clear_counter = ZERO_INIT ; clear_counter < KEYPAD_ROWS ; clear_counter++)
                   {
                        ret=gpio_pin_write_logic(&(keypad->keypad_rows_pins[clear_counter]),GPIO_LOW);
                   }
         
            ret = gpio_pin_write_logic(&(keypad->keypad_rows_pins[rows_counter]),GPIO_HIGH);
           // __delay_ms(10);
            for( columns_counter = ZERO_INIT ; columns_counter < KEYPAD_COLUMNS ; columns_counter++)
                    {
                        ret = gpio_pin_read_logic(&(keypad->keypad_columns_pins[columns_counter]),&pin_logic);  
                            if(GPIO_HIGH == pin_logic)
                                {
                                    *value = keypad_values[rows_counter][columns_counter];
                                }    
                    }
         
         }
         
    
    }
    return ret;
    
}
