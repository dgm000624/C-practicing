/*
 * Fnd2.c
 *
 * Created: 2025-08-12 오전 10:39:39
 * Author : COMPUTER
 */ 

#include <avr/io.h>
#include <util/delay.h>

unsigned int Font[16] = {0xFF, 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86};
unsigned int Font2[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

int main(void)
{
	DDRB = 0xff;
	DDRG = 0xff;
	PORTG = 0x02;
	
	int idx = 0;
    int admit1 = 0;
	int admit2 = 0;
	int admit3 = 0;
	
	int rep1 = 0;
	int rep2 = 0;
	int rep3 = 0;
    while (1) 
    {
		/*
		PORTB = ~Font[idx];
		_delay_ms(500); 
		idx++;
		if (idx == 16)
		{ idx = 0;
		}*/
		/*
		PORTG = 0x0E;
		PORTB = ~Font[3];
		_delay_ms(5);
		PORTG = 0x0D;
		PORTB = ~Font[1];
		_delay_ms(5);
		PORTG = 0x0B;
		PORTB = ~Font[3];
		_delay_ms(5);
		PORTG = 0x07;
		PORTB = ~Font[6];
		_delay_ms(5);
		*/
		/*
		PORTG = 0x0E;
		PORTB = ~Font[idx];
		_delay_ms(5);
		idx++;
		if (idx == 16)
		{	idx = 0;
			admit1++;
		
		}
		if (admit1 > 0)
		{	
			PORTG = 0x0D;
			PORTB = ~Font[admit1];
			_delay_ms(5);
			if (admit1 == 16)
			{
				admit2++;
				admit1 =0;
			}
		}
		if (admit2 > 0)
		{
			PORTG = 0x0B;
			PORTB = ~Font[admit2];
			_delay_ms(5);
			if (admit2 == 16)
			{
				admit3++;
				admit2 =0;
			}
		}
		if (admit3 > 0)
		{
			PORTG = 0x07;
			PORTB = ~Font[admit3];
			_delay_ms(5);
			if (admit3 == 16)
			{
				admit3 =0;
			}
		}
		*/
		/*
		PORTG = 0x07;
		PORTB = ~Font2[idx];
		_delay_ms(5);
		idx++;
		if (idx == 10)
		{	idx = 0;
			admit1++;
			
		}
		if ((admit1 > 0) || (rep1 ==1))
		{
			rep1 = 1;
			PORTG = 0x0B;
			PORTB = ~Font2[admit1];
			_delay_ms(5);
			if (admit1 == 10)
			{
				admit2++;
				admit1 =0;
			}
		}
		if ((admit2 > 0) || (rep2 ==1))
		{
			rep2 = 1;
			PORTG = 0x0D;
			PORTB = ~Font2[admit2];
			_delay_ms(5);
			if (admit2 == 10)
			{
				admit3++;
				admit2 =0;
			}
		}
		if ((admit3 > 0) || (rep3 ==1))
		{
			rep3 = 1;
			PORTG = 0x0E;
			PORTB = ~Font2[admit3];
			_delay_ms(5);
			if (admit3 == 10)
			{
				admit3 =0;
			}
		}
		*/
		
		
		
		
    }
}

