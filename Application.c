/* 
 * File:   Application.c
 * Author: Moustafa Mohammed
 *
 * Created on 29 , 11 , 2023, 01:13 ?
 */

/*    Includes Section    */
#include "Application.h"
/*    Data Type Declarations Section    */
Std_ReturnType ret=E_OK;
/*pin_config_t pin0=
{
    .port=PORTD_INDEX,
    .pin=GPIO_PIN0,
    .direction=GPIO_OUTPUT,
    .logic=GPIO_LOW
};
led_t led1=
{
    .pin=GPIO_PIN0,
    .port=PORTA_INDEX,
    .status=LED_OFF
};
led_t led2=
{
    .pin=GPIO_PIN1,
    .port=PORTA_INDEX,
    .status=LED_OFF
};
led_t led3=
{
    .pin=GPIO_PIN2,
    .port=PORTA_INDEX,
    .status=LED_OFF
};
led_t led4=
{
    .pin=GPIO_PIN3,
    .port=PORTA_INDEX,
    .status=LED_OFF
};
button_t btn_active_low={
.button_logic=BUTTON_ACTIVE_LOW,
.button_status=BUTTON_RELEASED,
.button_pin.direction=GPIO_INPUT,
.button_pin.logic=GPIO_LOW,
.button_pin.pin=GPIO_PIN0,
.button_pin.port=PORTD_INDEX
};

button_t btn_active_high={
.button_logic=BUTTON_ACTIVE_HIGH,
.button_status=BUTTON_RELEASED,
.button_pin.direction=GPIO_INPUT,
.button_pin.logic=GPIO_LOW,
.button_pin.pin=GPIO_PIN1,
.button_pin.port=PORTD_INDEX
};

relay_t relay1={
.relay_pin=GPIO_PIN0,
.relay_port=PORTC_INDEX,
.relay_status=RELAY_OFF};
relay_t relay2={
.relay_pin=GPIO_PIN1,
.relay_port=PORTC_INDEX,
.relay_status=RELAY_OFF};

dc_motor_t dc_motor1=
{
    ._dc_motor[MOTOR_INPUT_1].port = PORTC_INDEX,
    ._dc_motor[MOTOR_INPUT_1].pin  = GPIO_PIN0,
    ._dc_motor[MOTOR_INPUT_1].direction= GPIO_OUTPUT,
    ._dc_motor[MOTOR_INPUT_1].logic= MOTOR_OFF,
    ._dc_motor[MOTOR_INPUT_2].port = PORTC_INDEX,
    ._dc_motor[MOTOR_INPUT_2].pin  = GPIO_PIN1,
    ._dc_motor[MOTOR_INPUT_2].direction= GPIO_OUTPUT,
    ._dc_motor[MOTOR_INPUT_2].logic= MOTOR_OFF
};
dc_motor_t dc_motor2=
{
    ._dc_motor[MOTOR_INPUT_1].port = PORTC_INDEX,
    ._dc_motor[MOTOR_INPUT_1].pin  = GPIO_PIN2,
    ._dc_motor[MOTOR_INPUT_1].direction= GPIO_OUTPUT,
    ._dc_motor[MOTOR_INPUT_1].logic= MOTOR_OFF,
    ._dc_motor[MOTOR_INPUT_2].port = PORTC_INDEX,
    ._dc_motor[MOTOR_INPUT_2].pin  = GPIO_PIN3,
    ._dc_motor[MOTOR_INPUT_2].direction= GPIO_OUTPUT,
    ._dc_motor[MOTOR_INPUT_2].logic= MOTOR_OFF
};
       
uint8 seven_seg_anode[10]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
uint8 seven_seg_cathode[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};

uint8 seconds=50,minutes=59,hours=23;

        uint8 number =0;
        uint32 counter =0;
        pin_config_t ENABLE1={.port=PORTD_INDEX,.pin=GPIO_PIN0,.direction=GPIO_OUTPUT,.logic=GPIO_LOW};
        pin_config_t ENABLE2={.port=PORTD_INDEX,.pin=GPIO_PIN1,.direction=GPIO_OUTPUT,.logic=GPIO_LOW};
        seven_segment_t seven_segment1={
        .seven_segment_pin[SEGMENT_PINA].port=PORTC_INDEX,
        .seven_segment_pin[SEGMENT_PINA].pin=GPIO_PIN0,
        .seven_segment_pin[SEGMENT_PINA].direction=GPIO_OUTPUT,
        .seven_segment_pin[SEGMENT_PINA].logic=GPIO_LOW,
        .seven_segment_pin[SEGMENT_PINB].port=PORTC_INDEX,
        .seven_segment_pin[SEGMENT_PINB].pin=GPIO_PIN1,
        .seven_segment_pin[SEGMENT_PINB].direction=GPIO_OUTPUT,
        .seven_segment_pin[SEGMENT_PINB].logic=GPIO_LOW,
        .seven_segment_pin[SEGMENT_PINC].port=PORTC_INDEX,
        .seven_segment_pin[SEGMENT_PINC].pin=GPIO_PIN2,
        .seven_segment_pin[SEGMENT_PINC].direction=GPIO_OUTPUT,
        .seven_segment_pin[SEGMENT_PINC].logic=GPIO_LOW,
        .seven_segment_pin[SEGMENT_PIND].port=PORTC_INDEX,
        .seven_segment_pin[SEGMENT_PIND].pin=GPIO_PIN3,
        .seven_segment_pin[SEGMENT_PIND].direction=GPIO_OUTPUT,
        .seven_segment_pin[SEGMENT_PIND].logic=GPIO_LOW,
        .seven_segment_type=SEVEN_SEGMENT_COMMON_ANODE
       };
     */   
   keypad_t keypad1={
   .keypad_rows_pins[0].port=PORTD_INDEX,
   .keypad_rows_pins[0].pin=GPIO_PIN0,
   .keypad_rows_pins[0].direction=GPIO_OUTPUT,
   .keypad_rows_pins[0].logic=GPIO_LOW,
   .keypad_rows_pins[1].port=PORTD_INDEX,
   .keypad_rows_pins[1].pin=GPIO_PIN1,
   .keypad_rows_pins[1].direction=GPIO_OUTPUT,
   .keypad_rows_pins[1].logic=GPIO_LOW,
   .keypad_rows_pins[2].port=PORTD_INDEX,
   .keypad_rows_pins[2].pin=GPIO_PIN2,
   .keypad_rows_pins[2].direction=GPIO_OUTPUT,
   .keypad_rows_pins[2].logic=GPIO_LOW,
   .keypad_rows_pins[3].port=PORTD_INDEX,
   .keypad_rows_pins[3].pin=GPIO_PIN3,
   .keypad_rows_pins[3].direction=GPIO_OUTPUT,
   .keypad_rows_pins[3].logic=GPIO_LOW,
   .keypad_columns_pins[0].port=PORTD_INDEX,
   .keypad_columns_pins[0].pin=GPIO_PIN4,
   .keypad_columns_pins[0].direction=GPIO_INPUT,
   .keypad_columns_pins[0].logic=GPIO_LOW,
   .keypad_columns_pins[1].port=PORTD_INDEX,
   .keypad_columns_pins[1].pin=GPIO_PIN5,
   .keypad_columns_pins[1].direction=GPIO_INPUT,
   .keypad_columns_pins[1].logic=GPIO_LOW,
   .keypad_columns_pins[2].port=PORTD_INDEX,
   .keypad_columns_pins[2].pin=GPIO_PIN6,
   .keypad_columns_pins[2].direction=GPIO_INPUT,
   .keypad_columns_pins[2].logic=GPIO_LOW,
   .keypad_columns_pins[3].port=PORTD_INDEX,
   .keypad_columns_pins[3].pin=GPIO_PIN7,
   .keypad_columns_pins[3].direction=GPIO_INPUT,
   .keypad_columns_pins[3].logic=GPIO_LOW
   };     
   uint8 value=ZERO_INIT;
   lcd_4bit_t lcd1 ={.lcd_rs.port=PORTC_INDEX,
                     .lcd_rs.pin=GPIO_PIN0,
                     .lcd_rs.direction= GPIO_OUTPUT,
   .lcd_rs.logic=GPIO_LOW,
   .lcd_en.port=PORTC_INDEX,
   .lcd_en.pin=GPIO_PIN1,
   .lcd_en.direction= GPIO_OUTPUT,
   .lcd_en.logic=GPIO_LOW,
   .lcd_data[0].port=PORTC_INDEX,
   .lcd_data[0].pin=GPIO_PIN2,
   .lcd_data[0].direction= GPIO_OUTPUT,
   .lcd_data[0].logic=GPIO_LOW,
   .lcd_data[1].port=PORTC_INDEX,
   .lcd_data[1].pin=GPIO_PIN3,
   .lcd_data[1].direction= GPIO_OUTPUT,
   .lcd_data[1].logic=GPIO_LOW,
   .lcd_data[2].port=PORTC_INDEX,
   .lcd_data[2].pin=GPIO_PIN4,
   .lcd_data[2].direction= GPIO_OUTPUT,
   .lcd_data[2].logic=GPIO_LOW,
   .lcd_data[3].port=PORTC_INDEX,
   .lcd_data[3].pin=GPIO_PIN5,
   .lcd_data[3].direction= GPIO_OUTPUT,
   .lcd_data[3].logic=GPIO_LOW,
   
   };

     lcd_8bit_t lcd2 ={
         .lcd_rs.port=PORTC_INDEX,
         .lcd_rs.pin=GPIO_PIN6,
         .lcd_rs.direction= GPIO_OUTPUT,
   .lcd_rs.logic=GPIO_LOW,
   .lcd_en.port=PORTC_INDEX,
   .lcd_en.pin=GPIO_PIN7,
   .lcd_en.direction= GPIO_OUTPUT,
   .lcd_en.logic=GPIO_LOW,
   .lcd_data[0].port=PORTD_INDEX,
   .lcd_data[0].pin=GPIO_PIN0,
   .lcd_data[0].direction= GPIO_OUTPUT,
   .lcd_data[0].logic=GPIO_LOW,
   .lcd_data[1].port=PORTD_INDEX,
   .lcd_data[1].pin=GPIO_PIN1,
   .lcd_data[1].direction= GPIO_OUTPUT,
   .lcd_data[1].logic=GPIO_LOW,
   .lcd_data[2].port=PORTD_INDEX,
   .lcd_data[2].pin=GPIO_PIN2,
   .lcd_data[2].direction= GPIO_OUTPUT,
   .lcd_data[2].logic=GPIO_LOW,
   .lcd_data[3].port=PORTD_INDEX,
   .lcd_data[3].pin=GPIO_PIN3,
   .lcd_data[3].direction= GPIO_OUTPUT,
   .lcd_data[3].logic=GPIO_LOW,
   .lcd_data[4].port=PORTD_INDEX,
   .lcd_data[4].pin=GPIO_PIN4,
   .lcd_data[4].direction= GPIO_OUTPUT,
   .lcd_data[4].logic=GPIO_LOW,
   .lcd_data[5].port=PORTD_INDEX,
   .lcd_data[5].pin=GPIO_PIN5,
   .lcd_data[5].direction= GPIO_OUTPUT,
   .lcd_data[5].logic=GPIO_LOW,
   .lcd_data[6].port=PORTD_INDEX,
   .lcd_data[6].pin=GPIO_PIN6,
   .lcd_data[6].direction= GPIO_OUTPUT,
   .lcd_data[6].logic=GPIO_LOW,
   .lcd_data[7].port=PORTD_INDEX,
   .lcd_data[7].pin=GPIO_PIN7,
   .lcd_data[7].direction= GPIO_OUTPUT,
   .lcd_data[7].logic=GPIO_LOW,
   
   };
 uint8 customChar[] = {
  0x1F,
  0x15,
  0x15,
  0x1F,
  0x15,
  0x15,
  0x1F,
  0x00};
 uint8 counter =ZERO_INIT;
 uint8 counter_text[4];
 int main() 
{
     application_initialize();
     ret = lcd_4bit_send_string_position(&lcd1,2,6,"Calculator");
     __delay_ms(500);
      ret = lcd_4bit_send_command(&lcd1,LCD_CLEAR_DISPLAY);
     while(1)
    {
      ret = keypad_get_value_pressed(&keypad1,&value);
      ret = lcd_4bit_send_character(&lcd1,value);
      ret = lcd_4bit_send_string_pos(&lcd1,value); 
    }
    return (EXIT_SUCCESS);
}
void application_initialize(void)
{
    ret = lcd_4bit_initialize(&lcd1);
    ret = keypad_initilize(&keypad1);

}

