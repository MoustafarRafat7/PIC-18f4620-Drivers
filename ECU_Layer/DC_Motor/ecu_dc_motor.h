/* 
 * File:   ecu_dc_motor.h
 * Author: Mostafa
 *
 * Created on 01 ,2, 2024, 07:42 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/*    Includes Section    */
#include "../../MCAL_Layer/GPIO/Hal_GPIO.h"
#include "ecu_dc_motor_cfg.h"
/*    Macros Declarations Section   */
#define MOTOR_OFF 0x00
#define MOTOTR_ON 0x01
#define MOTOR_INPUT_1  0x00
#define MOTOR_INPUT_2  0x01
/*    Macro Function Declarations Section    */
/*    Data Type Declarations Section    */
typedef struct
{
    pin_config_t _dc_motor[2];
}dc_motor_t;
/*    Functions Declarations Section    */
Std_ReturnType dc_motor_initilization(const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_move_right(const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_move_left(const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_stop(const dc_motor_t *dc_motor);

#endif	/* ECU_DC_MOTOR_H */

