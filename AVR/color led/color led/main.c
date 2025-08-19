/*
 * color led.c
 *
 * Created: 2025-08-19 오후 1:47:30
 * Author : COMPUTER
 */ 

#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>

unsigned RGB_Table[5][3] = {
	{163, 191, 64},		// Green Yellow
	{255, 69, 0},		// Orange Red
	{34, 139, 34},		// Forest Green
	{135, 206, 235},	// Sky Blue
	{128, 0, 128},		// Purple
};

int main(void)
{
   
    while (1) 
    {
    }
}

