/*
 * File:   ecu_character_lcd.c
 * Author: Mostafa
 *
 * Created on 06 , 2 ,  2024, 08:44 PM
 */

/* ----------------- Includes -----------------*/
#include "ecu_character_lcd.h"
/* ----------------- Functions Definitions -----------------*/
static Std_ReturnType lcd_4bit_send_enable_signal(const lcd_4bit_t *lcd);
static Std_ReturnType lcd_send_4bit_data(const lcd_4bit_t *lcd , uint8 data);
static Std_ReturnType lcd_4bit_set_cursor(const lcd_4bit_t *lcd , uint8 row , uint8 column);

static Std_ReturnType lcd_8bit_send_enable_signal(const lcd_8bit_t *lcd);
static Std_ReturnType lcd_8bit_set_cursor(const lcd_8bit_t *lcd , uint8 row , uint8 column);

/**
 * @brief Initializes the LCD module in 4-bit mode.
 * @param lcd Pointer to the LCD configuration.
 * @return Returns the status of the initialization (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType lcd_4bit_initialize(const lcd_4bit_t *lcd)
{
    Std_ReturnType ret = E_OK;
    uint8 counter =ZERO_INIT;
    if( NULL == lcd )
    {
        ret = E_NOT_OK;

    }
    else
    {
        ret = gpio_pin_initialize(&(lcd->lcd_rs));
        ret = gpio_pin_initialize(&(lcd->lcd_en));
        for( counter = 0 ; counter < 4 ; counter ++ )
        {
           ret = gpio_pin_initialize(&(lcd->lcd_data[counter])); 
        }
        __delay_ms(20);
        ret = lcd_4bit_send_command(lcd , LCD_8BIT_MODE_2LINE);
        __delay_ms(5);
        ret = lcd_4bit_send_command(lcd , LCD_8BIT_MODE_2LINE);
        __delay_us(120);
        ret = lcd_4bit_send_command(lcd , LCD_8BIT_MODE_2LINE);
        
        ret = lcd_4bit_send_command(lcd , LCD_CLEAR_DISPLAY);
        ret = lcd_4bit_send_command(lcd , LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd , LCD_ENTRY_MODE_AC_INCREMENT_SHIFT_OFF);
        ret = lcd_4bit_send_command(lcd , LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_4bit_send_command(lcd , LCD_4BIT_MODE_2LINE);
        ret = lcd_4bit_send_command(lcd , LCD_DDRAM_START_ADDRESS);
       
    }

    return ret ;

}
/**
 * @brief Sends a command to the LCD module in 4-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @param command Command to be sent to the LCD.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType lcd_4bit_send_command(const lcd_4bit_t *lcd, uint8 command)
{
    Std_ReturnType ret = E_OK;
    if( NULL == lcd )
    {
        ret = E_NOT_OK;

    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_LOW);
        ret = lcd_send_4bit_data( lcd , ( command >> 4) );
        ret = lcd_4bit_send_enable_signal(lcd);
        ret = lcd_send_4bit_data( lcd ,  command  );
        ret = lcd_4bit_send_enable_signal(lcd);
    }

    return ret ;

}
/**
 * @brief Sends a character to the LCD module in 4-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @param character data to be sent to the LCD.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType lcd_4bit_send_character(const lcd_4bit_t *lcd, uint8 character)
{
    Std_ReturnType ret = E_OK;
    if( NULL == lcd )
    {
        ret = E_NOT_OK;

    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_HIGH);
        ret = lcd_send_4bit_data( lcd , ( character >> 4) );
        ret = lcd_4bit_send_enable_signal(lcd);
        ret = lcd_send_4bit_data( lcd ,  character  );
        ret = lcd_4bit_send_enable_signal(lcd);
    }

    return ret ;
}
/**
 * @brief Sends a character to the LCD display at a specified position in 4-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @param row Row number where the character will be displayed.
 * @param column Column number where the character will be displayed.
 * @param character Character to be sent to the LCD.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType lcd_4bit_send_character_position(const lcd_4bit_t *lcd, uint8 row, uint8 column,uint8 character)
{
    Std_ReturnType ret = E_OK;
    if( NULL == lcd )
    {
        ret = E_NOT_OK;

    }
    else
    {
        switch(row)
        {
            case ROW1: ret = lcd_4bit_set_cursor(lcd , row , column); ret = lcd_4bit_send_character(lcd , character); break;
            case ROW2: ret = lcd_4bit_set_cursor(lcd , row , column); ret = lcd_4bit_send_character(lcd , character); break;
            case ROW3: ret = lcd_4bit_set_cursor(lcd , row , column); ret = lcd_4bit_send_character(lcd , character); break;
            case ROW4: ret = lcd_4bit_set_cursor(lcd , row , column); ret = lcd_4bit_send_character(lcd , character); break;
            default  : break;
        } 

    }

    return ret ;

}
/**
 * @brief Sends a string to the LCD display in 4-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @param str Pointer to the string to be sent.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */

Std_ReturnType lcd_4bit_send_string(const lcd_4bit_t *lcd, uint8 *str)
{
    Std_ReturnType ret = E_OK;
    if( (NULL == lcd) || (NULL == str) )
    {
        ret = E_NOT_OK;

    }
    else
    {
        while(*str)
        {
            ret = lcd_4bit_send_character(lcd , *(str++) );
        }

    }

    return ret ;
}
/**
 * @brief Sends a string to the LCD display starting from a specified position in 4-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @param row Row number where the string will start.
 * @param column Column number where the string will start.
 * @param str Pointer to the string to be sent.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType lcd_4bit_send_string_position(const lcd_4bit_t *lcd, uint8 row, uint8 column,uint8 *str)
{
    Std_ReturnType ret = E_OK;
    if( (NULL == lcd) || (NULL == str) )
    {
        ret = E_NOT_OK;

    }
    else
    {
        ret = lcd_4bit_set_cursor(lcd ,row , column );
        while(*str)
        {
            ret = lcd_4bit_send_character(lcd , *(str++) );
        }
    }

    return ret ;
}
/**
 * @brief Sends a custom character to the LCD display at a specified position in 4-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @param row Row number where the character will be displayed.
 * @param column Column number where the character will be displayed.
 * @param character Array containing the custom character data.
 * @param memory_position Memory position where the custom character will be stored in CGRAM
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType lcd_4bit_send_custom_character(const lcd_4bit_t *lcd ,uint8 row , uint8 column ,
                                              uint8 character[] , uint8 memory_position )
{
    Std_ReturnType ret = E_OK ;
    uint8 counter = ZERO_INIT ;
    if(  NULL == lcd  )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = lcd_4bit_send_command( lcd , (LCD_CGRAM_START_ADDRESS+8)*memory_position );
        for( counter = 0 ; counter < 8 ; counter ++ )
        {
            ret = lcd_4bit_send_character(lcd , character[counter]);    
        }
        ret = lcd_4bit_send_character_position(lcd ,row , column , memory_position);

    }
    return ret;
}

/**
 * @brief Initializes the LCD module in 8-bit mode.
 * @param lcd Pointer to the LCD configuration.
 * @return Returns the status of the initialization (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType lcd_8bit_initialize(const lcd_8bit_t *lcd)
{
    Std_ReturnType ret = E_OK;
    uint8 counter = ZERO_INIT;
    if( NULL == lcd )
    {
        ret = E_NOT_OK;

    }
    else
    {
        ret = gpio_pin_initialize(&(lcd->lcd_rs));
        ret = gpio_pin_initialize(&(lcd->lcd_en));
        for( counter = 0 ; counter < 8 ; counter ++ )
        {
           ret = gpio_pin_initialize(&(lcd->lcd_data[counter])); 
        }
        __delay_ms(20);
        ret = lcd_8bit_send_command(lcd , LCD_8BIT_MODE_2LINE);
        __delay_ms(5);
        ret = lcd_8bit_send_command(lcd , LCD_8BIT_MODE_2LINE);
        __delay_us(120);
        ret = lcd_8bit_send_command(lcd , LCD_8BIT_MODE_2LINE);
        
        ret = lcd_8bit_send_command(lcd , LCD_CLEAR_DISPLAY);
        ret = lcd_8bit_send_command(lcd ,LCD_RETURN_HOME);
        ret = lcd_8bit_send_command(lcd , LCD_ENTRY_MODE_AC_INCREMENT_SHIFT_OFF);
        ret = lcd_8bit_send_command(lcd , LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_8bit_send_command(lcd , LCD_8BIT_MODE_2LINE);
        ret = lcd_8bit_send_command(lcd , LCD_DDRAM_START_ADDRESS);
       

    }

    return ret ;


}

Std_ReturnType lcd_8bit_send_command(const lcd_8bit_t *lcd, uint8 command)
{
    Std_ReturnType ret = E_OK;
    uint8 counter = ZERO_INIT;
    if( NULL == lcd )
    {
        ret = E_NOT_OK;

    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_LOW);
        for( counter = 0 ; counter < 8 ; counter++ )
        {
            ret = gpio_pin_write_logic( &(lcd->lcd_data[counter]) ,(( command >> counter ) & (uint8)0x01 ) );
        }
        ret = lcd_8bit_send_enable_signal(lcd);
    }

    return ret ;

}
/**
 * @brief Sends a character to the LCD display in 8-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @param character Character to be sent to the LCD.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType lcd_8bit_send_character(const lcd_8bit_t *lcd, uint8 character)
{
    Std_ReturnType ret = E_OK;
    uint8 counter = ZERO_INIT;
    if( NULL == lcd )
    {
        ret = E_NOT_OK;

    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_HIGH);
        for( counter = 0 ; counter < 8 ; counter++ )
        {
            ret = gpio_pin_write_logic( &(lcd->lcd_data[counter]) ,(( character >> counter ) & (uint8)0x01 ) );
        }
        ret = lcd_8bit_send_enable_signal(lcd);
    }

    return ret ;

}
/**
 * @brief Sends a character to the LCD display at a specified position in 8-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @param row Row number where the character will be displayed.
 * @param column Column number where the character will be displayed.
 * @param character Character to be sent to the LCD.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType lcd_8bit_send_character_position(const lcd_8bit_t *lcd, uint8 row, uint8 column,uint8 character)
{
    Std_ReturnType ret = E_OK;
    if( NULL == lcd )
    {
        ret = E_NOT_OK;

    }
    else
    {
        switch(row)
        {
            case ROW1: ret = lcd_8bit_set_cursor(lcd , row , column); ret = lcd_8bit_send_character(lcd , character); break;
            case ROW2: ret = lcd_8bit_set_cursor(lcd , row , column); ret = lcd_8bit_send_character(lcd , character); break;
            case ROW3: ret = lcd_8bit_set_cursor(lcd , row , column); ret = lcd_8bit_send_character(lcd , character); break;
            case ROW4: ret = lcd_8bit_set_cursor(lcd , row , column); ret = lcd_8bit_send_character(lcd , character); break;
            default  : break;
        } 
    }

    return ret ;


}
/**
 * @brief Sends a string to the LCD display in 8-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @param str Pointer to the string to be sent.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType lcd_8bit_send_string(const lcd_8bit_t *lcd, uint8 *str)
{
    Std_ReturnType ret = E_OK;
    if( (NULL == lcd) || (NULL == str) )
    {
        ret = E_NOT_OK;

    }
    else
    {
        while(*str)
        {
            ret = lcd_8bit_send_character(lcd ,*(str++) );
        }
    }

    return ret ;

}
/**
 * @brief Sends a string to the LCD display starting from a specified position in 8-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @param row Row number where the string will start.
 * @param column Column number where the string will start.
 * @param str Pointer to the string to be sent.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType lcd_8bit_send_string_position(const lcd_8bit_t *lcd, uint8 row, uint8 column , uint8 *str)
{
    Std_ReturnType ret = E_OK;
    if( (NULL == lcd) || (NULL == str) )
    {
        ret = E_NOT_OK;

    }
    else
    { 
        ret = lcd_8bit_set_cursor(lcd , row , column );
        while(*str)
        {   
            ret = lcd_8bit_send_character(lcd , *(str++) );
        }
    }

    return ret ;

}
/**
 * @brief Sends a custom character to the LCD display at a specified position in 8-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @param row Row number where the character will be displayed.
 * @param column Column number where the character will be displayed.
 * @param character Array containing the custom character data.
 * @param memory_position Memory position where the custom character will be stored.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType lcd_8bit_send_custom_character(const lcd_8bit_t *lcd , uint8 row , uint8 column  ,
                                              uint8 character[] , uint8 memory_position )
{
    Std_ReturnType ret = E_OK ;
    uint8 counter = ZERO_INIT ;
    if(  NULL == lcd  )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = lcd_8bit_send_command( lcd , (LCD_CGRAM_START_ADDRESS+8)*memory_position );
        for( counter = 0 ; counter <= 8 ; counter ++ )
        {
            ret = lcd_8bit_send_character(lcd , character[counter]);    
        }
        ret = lcd_8bit_send_character_position(lcd ,row , column , memory_position);

    }
    return ret;
}

/**
 * @brief Converts a byte to a string .
 * @param number The byte to be converted to a string.
 * @param str Pointer to the array where the resulting string will be stored.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType convert_byte_to_string(uint8 number , uint8 *str)
{
    Std_ReturnType ret = E_OK;
    if( NULL == str )
    {
        ret = E_NOT_OK;
    }
    else
    {
        memset(str,'\0',4);
        sprintf(str,"%i",number);
    }
    return ret;
}
/**
 * @brief Converts a word to a string .
 * @param number The word to be converted to a string.
 * @param str Pointer to the array where the resulting string will be stored.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType convert_word_to_string(uint16 number , uint8 *str)
{
    Std_ReturnType ret = E_OK;
    if( NULL == str )
    {
        ret = E_NOT_OK;
    }
    else
    {
        memset(str,'\0',6);
        sprintf(str,"%i",number);
    }
    return ret;
    
}
/**
 * @brief Converts a Double word to a string .
 * @param number The Double word to be converted to a string.
 * @param str Pointer to the array where the resulting string will be stored.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
Std_ReturnType convert_uint32_to_string(uint32 number , uint8 *str)
{
    Std_ReturnType ret = E_OK;
    if( NULL == str )
    {
        ret = E_NOT_OK;
    }
    else
    {
        memset(str,'\0',11);
        sprintf(str,"%i",number);
    }
    return ret;
    
}
 /**
 * @brief Sends the enable signal to the LCD module in 4-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */                      
static Std_ReturnType lcd_4bit_send_enable_signal(const lcd_4bit_t *lcd)
{
    Std_ReturnType ret = E_OK;
    if( NULL == lcd )
    {
        ret = E_NOT_OK;

    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_LOW);
    }

    return ret ;

}
/**
 * @brief Sends the enable signal to the LCD module in 8-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
static Std_ReturnType lcd_8bit_send_enable_signal(const lcd_8bit_t *lcd)
{
    Std_ReturnType ret = E_OK;
    if( NULL == lcd )
    {
        ret = E_NOT_OK;

    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_LOW);
    }

    return ret ;

}
/**
 * @brief Sends 4-bit data to the LCD module.
 * @param lcd Pointer to the LCD structure.
 * @param data data to be sent.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
static Std_ReturnType lcd_send_4bit_data(const lcd_4bit_t *lcd , uint8 data)
{
    Std_ReturnType ret = E_OK;
    uint8 shifter =ZERO_INIT;
    if( NULL == lcd )
    {
        ret = E_NOT_OK;

    }
    else
    {
        for( shifter = 0 ; shifter < 4 ; shifter++ )
        {
            ret = gpio_pin_write_logic(&(lcd->lcd_data[shifter]), ( data >> shifter ) & (uint8)0x01);
        }
    }

    return ret ;

}
/**
 * @brief Sets the cursor position on the LCD display in 4-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @param row Row number where the cursor will be set.
 * @param column Column number where the cursor will be set.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
static Std_ReturnType lcd_4bit_set_cursor(const lcd_4bit_t *lcd , uint8 row , uint8 column)
{
    column--;
    Std_ReturnType ret = E_OK;  
    if( NULL == lcd )
    {
        ret = E_NOT_OK;

    }
    else
    {
        switch(row)
        {
            case ROW1: ret = lcd_4bit_send_command(lcd , (LCD_DDRAM_START_ADDRESS + column ) ) ; break;
            case ROW2: ret = lcd_4bit_send_command(lcd , (LCD_2ND_ROW_ADDRESS     + column ) ) ; break;
            case ROW3: ret = lcd_4bit_send_command(lcd , (LCD_3RD_ROW_ADDRESS     + column ) ) ; break;
            case ROW4: ret = lcd_4bit_send_command(lcd , (LCD_4TH_ROW_ADDRESS     + column ) ) ; break;
            default  :/*No Thing*/ ;
        }

    }

    return ret ;

}
/**
 * @brief Sets the cursor position on the LCD display in 8-bit mode.
 * @param lcd Pointer to the LCD structure.
 * @param row Row number where the cursor will be set.
 * @param column Column number where the cursor will be set.
 * @return Returns the status of the operation (E_OK if successful, E_NOT_OK otherwise).
 */
static Std_ReturnType lcd_8bit_set_cursor(const lcd_8bit_t *lcd , uint8 row , uint8 column)
{ 
    column--;
    Std_ReturnType ret = E_OK;  
    if( NULL == lcd )
    {
        ret = E_NOT_OK;

    }
    else
    {
        switch(row)
        {
            case ROW1: ret = lcd_8bit_send_command(lcd , (LCD_DDRAM_START_ADDRESS + column ) ) ; break;
            case ROW2: ret = lcd_8bit_send_command(lcd , (LCD_2ND_ROW_ADDRESS     + column ) ) ; break;
            case ROW3: ret = lcd_8bit_send_command(lcd , (LCD_3RD_ROW_ADDRESS     + column ) ) ; break;
            case ROW4: ret = lcd_8bit_send_command(lcd , (LCD_4TH_ROW_ADDRESS     + column ) ) ; break;
            default  :/*No Thing*/ ;
        }

    }

    return ret ;


}
