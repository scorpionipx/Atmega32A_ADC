/*
 * Atmega32A_ADC.c
 *
 * Created: 18-Oct-17 10:07:11 AM
 * Author : uidq6025
 */ 

#include "global.h"
#include <avr/io.h>
#include <util/delay.h>
#include "adc_driver.h"
#include "hx1230.h"
#include "hx_8x6_characters.h"

void display_title(void);
void display_menu(void);

int main(void)
{
	_delay_ms(50);
    ADC_init();
	
	_delay_ms(50);
	init_hx1230_control();
	
	_delay_ms(250);
	hx_fill_screen();
	_delay_ms(500);
	hx_clear_screen();
	display_title();
	display_menu();
	
	uint8_t adc_channel = 0;
	uint16_t adc_value = 0;
	
    while (1) 
    {
		_delay_ms(1000);
		adc_value = ADC_get_value(adc_channel);
		
		hx_set_coordinates((adc_channel / 4) * HX_MAX_COL / 2 + 18, (adc_channel % 4) + 3);
		hx_write_char(HX_character['0']);
		
		adc_channel ++;
		adc_channel %= 8;
    }
}






void display_title(void)
{
	
	hx_set_coordinates(0, 0);
	
	for(char i=0; i<15; i++)
	{
		hx_send_data(0);
	}
	
	hx_write_char(HX_character['S']);
	hx_write_char(HX_character['c']);
	hx_write_char(HX_character['o']);
	hx_write_char(HX_character['r']);
	hx_write_char(HX_character['p']);
	hx_write_char(HX_character['i']);
	hx_write_char(HX_character['o']);
	hx_write_char(HX_character['n']);
	hx_write_char(HX_character['I']);
	hx_write_char(HX_character['P']);
	hx_write_char(HX_character['X']);
	
	hx_set_coordinates(0, 1);
	
	for(char i=0; i<10; i++)
	{
		hx_send_data(0);
	}

	hx_write_char(HX_character['A']);
	hx_write_char(HX_character['t']);
	hx_write_char(HX_character['m']);
	hx_write_char(HX_character['e']);
	hx_write_char(HX_character['g']);
	hx_write_char(HX_character['a']);
	hx_write_char(HX_character['3']);
	hx_write_char(HX_character['2']);
	hx_write_char(HX_character['A']);
	hx_write_char(HX_character[' ']);
	hx_write_char(HX_character['A']);
	hx_write_char(HX_character['D']);
	hx_write_char(HX_character['C']);
}

void display_menu(void)
{
	hx_set_coordinates(0, 3);
	
	hx_write_char(HX_character['A']);
	hx_write_char(HX_character['1']);
	
	hx_set_coordinates(0, 4);
	
	hx_write_char(HX_character['A']);
	hx_write_char(HX_character['2']);
	
	hx_set_coordinates(0, 5);
	
	hx_write_char(HX_character['A']);
	hx_write_char(HX_character['3']);
	
	hx_set_coordinates(0, 6);
	
	hx_write_char(HX_character['A']);
	hx_write_char(HX_character['4']);
	
	hx_set_coordinates(HX_MAX_COL / 2, 3);
	
	hx_write_char(HX_character['A']);
	hx_write_char(HX_character['5']);
	
	hx_set_coordinates(HX_MAX_COL / 2, 4);
	
	hx_write_char(HX_character['A']);
	hx_write_char(HX_character['6']);
	
	hx_set_coordinates(HX_MAX_COL / 2, 5);
	
	hx_write_char(HX_character['A']);
	hx_write_char(HX_character['7']);
	
	hx_set_coordinates(HX_MAX_COL / 2, 6);
	
	hx_write_char(HX_character['A']);
	hx_write_char(HX_character['8']);
}