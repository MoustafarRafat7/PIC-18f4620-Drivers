/* 
 * File:   Hal_GPIO.c
 * Author: Moustafa
 *
 * Created on 29,11, 2023, 03:36 ?
 */

/*    Includes Section    */
#include "Hal_GPIO.h"
/*    Accessing Tris Registers    */
volatile uint8*TRIS_REGISTERS[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
/*    Accessing Port Registers    */
volatile uint8*PORT_REGISTERS[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
/*    Accessing LAT Registers    */
volatile uint8*LAT_REGISTERS[]={&LATA,&LATB,&LATC,&LATD,&LATE};

/*    Macros Declarations Section   */
/*    Macro Function Declarations Section    */
/*    Data Type Declarations Section    */

/*    Functions Definition Section    */

                         /*    Pin Configuration Section    */

/**
 * 
 * @biref used to determine pin direction @ref direction_t
 * @param pin_config  pointer to struct to configure pins   @ref pin_config_t
 * @return  E_OK if the function works properly
 * @return  E_NOT_OK if there's an issue with the function work
 */
#if PIN_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t* pin_config)
{
    Std_ReturnType ret= E_OK;
    if((NULL == pin_config) || (pin_config->pin >(MAX_PIN-1)))
    {
        ret=E_NOT_OK;
    
    }
    else
    {
        switch(pin_config->direction)
        {
            case GPIO_OUTPUT:
                CLEAR_BIT(*TRIS_REGISTERS[pin_config->port],pin_config->pin);
                break;
            case GPIO_INPUT:
                SET_BIT(*TRIS_REGISTERS[pin_config->port],pin_config->pin);
                break;    
            default :
                        ret=E_NOT_OK;
        }
    }
    return ret;
    
}
#endif
/**
 * 
 * @biref used to get pin direction @ref direction_t
 * @param pin_config  pointer to struct to configure pins   @ref pin_config_t
 * @param direction_status pointer to return the direction status of pin @ref direction_t
 * @return  E_OK if the function works properly
 * @return  E_NOT_OK if there's an issue with the function work
 */
#if PIN_CONFIGURATION == CONFIG_ENABLE          
Std_ReturnType gpio_pin_read_direction_status(const pin_config_t* pin_config,direction_t *direction_status)
{
    Std_ReturnType ret= E_OK;
    if(NULL == pin_config || NULL == direction_status || pin_config->pin > (MAX_PIN-1))
    {
        ret=E_NOT_OK;
    }
    else
    {
       *direction_status=(READ_BIT((*TRIS_REGISTERS[pin_config->port]),pin_config->pin));           
    }
    return ret;
    
}
#endif

/**
 * 
 * @brief Write High or Low on pin
 * @param pin_config pin_config  pointer to struct to configure pins   @ref pin_config_t
 * @param logic its value to determine if pin is set or clear 
 * @return  E_OK if the function works properly
 * @return  E_NOT_OK if there's an issue with the function work
 */
#if PIN_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t* pin_config,logic_t logic)
{
    Std_ReturnType ret= E_OK;
    if(NULL == pin_config || pin_config->pin > (MAX_PIN-1))
    {
        ret=E_NOT_OK;
    
    }
    else
    {
        switch(logic)
        {
            case GPIO_HIGH:
                SET_BIT(*LAT_REGISTERS[pin_config->port],pin_config->pin);
                break;
            case GPIO_LOW:
                CLEAR_BIT(*LAT_REGISTERS[pin_config->port],pin_config->pin);
                break;
            default:
                ret=E_NOT_OK;
        }
    }
    return ret;
    
}
#endif
 
/**
 * 
* @brief read status of pin
 * @param pin_config pin_config  pointer to struct to configure pins   @ref pin_config_t
 * @param logic the value read of pin(set or clear) 
 * @return  E_OK if the function works properly
 * @return  E_NOT_OK if there's an issue with the function work
 */
#if PIN_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t* pin_config,logic_t *logic)
{
    Std_ReturnType ret= E_OK;
    if(NULL == pin_config || pin_config->pin > (MAX_PIN-1))
    {
        ret=E_NOT_OK;
    
    }
    else
    {
      *logic=(READ_BIT((*PORT_REGISTERS[pin_config->port]),pin_config->pin));
    }
    
    return ret;
    
}
#endif
/**
 * @brief to Toggle pin
 * @param pin_config pin_config  pointer to struct to configure pins   @ref pin_config_t 
 * @return  E_OK if the function works properly
 * @return  E_NOT_OK if there's an issue with the function work
 */

#if PIN_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* pin_config)
{
    Std_ReturnType ret= E_OK;
    if(NULL == pin_config || pin_config->pin > (MAX_PIN-1))
    {
        ret=E_NOT_OK;
    
    }
    else
    {
        TOGGLE_BIT(*LAT_REGISTERS[pin_config->port],pin_config->pin);
    }
        
    return ret;
    
}
#endif

/***/
#if PIN_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_initialize(const pin_config_t* pin_config)
{
    Std_ReturnType ret= E_OK;
    if(NULL == pin_config || pin_config->pin >MAX_PIN)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret= gpio_pin_direction_initialize(pin_config);
        ret= gpio_pin_write_logic(pin_config,pin_config->logic);
        
    }
    return ret;
}
#endif

                         /*    Port Configuration Section    */
/**
 *  
 * @brief to determine the direction of port 
 * @param port determine which port we deal with  @ref port_index_t
 * @param direction_status to determine direction of port @ref direction_t
 * @return  E_OK if the function works properly
 * @return  E_NOT_OK if there's an issue with the function work
 */
#if PORT_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_port_direction_initialize(port_index_t port,uint8 direction_status)
{
    Std_ReturnType ret= E_OK;
    if(port > MAX_PORT )
    {
        ret=E_NOT_OK;
    }
    else
    {
      *TRIS_REGISTERS[port]= direction_status;
    }
    return ret;
    
}
#endif
/**
 * 
 * @brief to get the direction of port
 * @param port determine which port we deal with  @ref port_index_t
 * @param direction_status holds the direction status of the port
 * @return  E_OK if the function works properly
 * @return  E_NOT_OK if there's an issue with the function work 
 */
#if PORT_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_port_read_direction_status(port_index_t port,uint8 *direction_status)
{
    Std_ReturnType ret= E_OK;
    if(port > MAX_PORT || NULL == direction_status)
    {
        ret=E_NOT_OK;
    }
    else
    {
      *direction_status=*TRIS_REGISTERS[port];
    }
    
    return ret;
    
}
#endif
/**
 * 
 * @brief to write logic on port
 * @param port determine which port we deal with  @ref port_index_t
 * @param logic to write some logic on port (low/high) @ref logic_t
 * @return  E_OK if the function works properly
 * @return  E_NOT_OK if there's an issue with the function work 
 */
#if PORT_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic(port_index_t port,uint8 logic)
{
    Std_ReturnType ret= E_OK;
    if(port > MAX_PORT )
    {
        ret=E_NOT_OK;
    }
    else
    {
      *LAT_REGISTERS[port]=logic;
    }
    return ret;
    
}
#endif
/**
 * 
 * @brief Read the logic written on  port
 * @param port determine which port we deal with  @ref port_index_t
 * @param logic pointer to read logic status of port (low/high) @ref logic_t
 * @return  E_OK if the function works properly
 * @return  E_NOT_OK if there's an issue with the function work 
 */
#if PORT_CONFIGURATION == CONFIG_ENABLE

Std_ReturnType gpio_port_read_logic(port_index_t port,uint8 *logic)
{
    Std_ReturnType ret= E_OK;
    if(NULL == logic )
    {
        ret=E_NOT_OK;
    
    }
    else
    {
        *logic=*PORT_REGISTERS[port];
    }
    return ret;
    
}
#endif
/**
 * 
 * @brief toggle the port
 * @param port determine which port we deal with  @ref port_index_t
 * @return  E_OK if the function works properly
 * @return  E_NOT_OK if there's an issue with the function work 
 */
#if PORT_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(port_index_t port)
{
    Std_ReturnType ret= E_OK;
     if(port > MAX_PORT )
    {
        ret=E_NOT_OK;
    }
    else
    {
      *LAT_REGISTERS[port]^=PORT_TOGGLE;
    }
    return ret;
    
}
#endif
