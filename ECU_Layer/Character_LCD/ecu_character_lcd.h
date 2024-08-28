/* 
 * File:   ecu_character_lcd.h
 * Author: Mostafa
 *
 * Created on 06 , 2 ,  2024, 08:43 PM
 */

#ifndef ECU_CHARACTER_LCD_H
#define	ECU_CHARACTER_LCD_H

/* ----------------- Includes -----------------*/

#include "ecu_character_lcd_cfg.h"
#include "../../MCAL_Layer/GPIO/Hal_GPIO.h"
#include "string.h"
#include <stdio.h>
/* ----------------- Macro Declarations -----------------*/
#define _XTAL_FREQ  8000000
#define LCD_CLEAR_DISPLAY                          0x01
#define LCD_RETURN_HOME                            0x02
#define LCD_ENTRY_MODE_AC_DECREMENT_SHIFT_OFF      0x04
#define LCD_ENTRY_MODE_AC_DECREMENT_SHIFT_ON       0x05
#define LCD_ENTRY_MODE_AC_INCREMENT_SHIFT_OFF      0x06
#define LCD_ENTRY_MODE_AC_INCREMENT_SHIFT_ON       0x07
#define LCD_DISPLAY_OFF_CURSOR_OFF                 0x08
#define LCD_MOVE_CURSOR_SHIFT_LEFT                 0x10
#define LCD_MOVE_CURSOR_SHIFT_RIGHT                0x14
#define LCD_DISPLAY_SHIFT_LEFT                     0x18
#define LCD_DISPLAY_SHIFT_RIGHT                    0x1c
#define LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF    0x0c
#define LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON     0x0d
#define LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF     0x0e
#define LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON      0x0f

#define LCD_4BIT_MODE_2LINE                        0x28
#define LCD_8BIT_MODE_2LINE                        0x38

#define LCD_CGRAM_START_ADDRESS                    0x40
#define LCD_DDRAM_START_ADDRESS                    0x80

#define ROW1  0x01
#define ROW2  0x02
#define ROW3  0x03
#define ROW4  0x04
#define LCD_2ND_ROW_ADDRESS                       0XC0
#define LCD_3RD_ROW_ADDRESS                       0X94
#define LCD_4TH_ROW_ADDRESS                       0XD4

/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/

typedef struct 
{
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[4];

}lcd_4bit_t;

typedef struct 
{
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[8];

}lcd_8bit_t;

/* ----------------- Functions Declarations -----------------*/

Std_ReturnType lcd_4bit_initialize(const lcd_4bit_t *lcd);
Std_ReturnType lcd_4bit_send_command(const lcd_4bit_t *lcd , uint8 command);
Std_ReturnType lcd_4bit_send_character(const lcd_4bit_t *lcd , uint8 character);
Std_ReturnType lcd_4bit_send_character_position(const lcd_4bit_t *lcd , uint8 row , uint8 column ,uint8 character);
Std_ReturnType lcd_4bit_send_string(const lcd_4bit_t *lcd , uint8 *str);
Std_ReturnType lcd_4bit_send_string_position(const lcd_4bit_t *lcd , uint8 row , uint8 column ,uint8 *str);
Std_ReturnType lcd_4bit_send_custom_character(const lcd_4bit_t *lcd ,uint8 row , uint8 column ,
                                              uint8 character[] , uint8 memory_position );

Std_ReturnType lcd_8bit_initialize(const lcd_8bit_t *lcd);
Std_ReturnType lcd_8bit_send_command(const lcd_8bit_t *lcd , uint8 command);
Std_ReturnType lcd_8bit_send_character(const lcd_8bit_t *lcd , uint8 character);
Std_ReturnType lcd_8bit_send_character_position(const lcd_8bit_t *lcd , uint8 row , uint8 column ,uint8 character);
Std_ReturnType lcd_8bit_send_string(const lcd_8bit_t *lcd , uint8 *str);
Std_ReturnType lcd_8bit_send_string_position(const lcd_8bit_t *lcd , uint8 row , uint8 column ,uint8 *str);
Std_ReturnType lcd_8bit_send_custom_character(const lcd_8bit_t *lcd , uint8 row , uint8 column  ,
                                              uint8 character[] , uint8 memory_position );

Std_ReturnType convert_byte_to_string(uint8 number , uint8 *str);
Std_ReturnType convert_word_to_string(uint16 number , uint8 *str);
Std_ReturnType convert_uint32_to_string(uint32 number , uint8 *str);
                       

#endif	/* ECU_CHARACTER_LCD_H */

