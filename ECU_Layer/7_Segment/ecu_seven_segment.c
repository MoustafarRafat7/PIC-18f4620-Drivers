/* 
 * File:   ecu_seven_segment.c
 * Author: Mostafa
 *
 * Created on 02 , 2 , 2024, 10:59 PM
 */
/*    Includes Section    */
#include "ecu_seven_segment.h"
/*    Functions Definition Section    */
Std_ReturnType seven_segment_initilization(const seven_segment_t *seven_segment)
{
    Std_ReturnType ret = E_OK;
    if( NULL == seven_segment)
    {
        ret =   E_NOT_OK ; 
        
    }
    else
    {
        ret = gpio_pin_initialize(&(seven_segment->seven_segment_pin[SEGMENT_PINA]));
        ret = gpio_pin_initialize(&(seven_segment->seven_segment_pin[SEGMENT_PINB]));
        ret = gpio_pin_initialize(&(seven_segment->seven_segment_pin[SEGMENT_PINC]));
        ret = gpio_pin_initialize(&(seven_segment->seven_segment_pin[SEGMENT_PIND]));
                
    }
    return ret;
}
Std_ReturnType seven_segment_write_number(const seven_segment_t *seven_segment,uint8 number)
{
    Std_ReturnType ret = E_OK;
    if( ( NULL == seven_segment ) ||  ( number > 9 ) )
    {
        ret =   E_NOT_OK ; 
        
    }
    else
    {
        ret = gpio_pin_write_logic(&(seven_segment->seven_segment_pin[SEGMENT_PINA]),   ( number & 0X01 )       );
        ret = gpio_pin_write_logic(&(seven_segment->seven_segment_pin[SEGMENT_PINB]), ( ( number >> 1 ) & 0X01) );
        ret = gpio_pin_write_logic(&(seven_segment->seven_segment_pin[SEGMENT_PINC]), ( ( number >> 2 ) & 0X01) );
        ret = gpio_pin_write_logic(&(seven_segment->seven_segment_pin[SEGMENT_PIND]), ( ( number >> 3 ) & 0X01) );
        
    }
    return ret;
}
                