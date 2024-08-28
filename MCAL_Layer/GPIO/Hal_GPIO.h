/* 
 * File:   Hal_GPIO.h
 * Author: Moustafa
 *
 * Created on 29,11, 2023, 03:36 ?
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/*    Includes Section    */
#include "../proc/pic18f4620.h"
#include "../Mcal_std_types.h"
#include "../device_config.h"
#include "gpio_hal-dcfg.h"

/*    Macros Declarations Section   */
#define  BIT_MASK     1
#define PIN_CONFIGURATION      CONFIG_ENABLE
#define PORT_CONFIGURATION     CONFIG_ENABLE
#define MAX_PORT                 5
#define MAX_PIN                  8
#define PORT_TOGGLE            0XFF 
 

/*    Macro Function Declarations Section    */
#define HWREG8(X)                (*((volatile uint8*)(X)))
#define SET_BIT(REG,BIT_POSN)    (REG |= (BIT_MASK<<BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)  (REG &= ~(BIT_MASK<<BIT_POSN))
#define TOGGLE_BIT(REG,BIT_POSN) (REG ^= (BIT_MASK<<BIT_POSN))
#define READ_BIT(REG,BIT_POSN)   ((REG >> BIT_POSN)&BIT_MASK)

/*    Data Type Declarations Section    */
typedef enum
{
    GPIO_LOW=0,
    GPIO_HIGH
}logic_t;
typedef enum
{
    GPIO_OUTPUT=0,
    GPIO_INPUT
}direction_t;
typedef enum
{
            GPIO_PIN0=0,
            GPIO_PIN1,
            GPIO_PIN2,
            GPIO_PIN3,
            GPIO_PIN4,
            GPIO_PIN5,
            GPIO_PIN6,
            GPIO_PIN7        
}pin_index_t;

typedef enum
{
    PORTA_INDEX=0,
    PORTB_INDEX,         
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX        
}port_index_t;

typedef struct
{
    uint8 port      :3;
    uint8 pin       :3;
    uint8 logic     :1;
    uint8 direction :1;
}pin_config_t;

/*    Functions Declarations Section    */

                         /*    Pin Configuration Section    */


Std_ReturnType gpio_pin_direction_initialize(const pin_config_t* pin_config);
Std_ReturnType gpio_pin_read_direction_status(const pin_config_t* pin_config,direction_t *direction_status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t* pin_config,logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t* pin_config,logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* pin_config);
Std_ReturnType gpio_pin_initialize(const pin_config_t* pin_config);


                         /*    Port Configuration Section    */
Std_ReturnType gpio_port_direction_initialize(port_index_t port,uint8 direction_status);
Std_ReturnType gpio_port_read_direction_status(port_index_t port,uint8 *direction_status);
Std_ReturnType gpio_port_write_logic(port_index_t port,uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index_t port,uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t port);




#endif	/* HAL_GPIO_H */

