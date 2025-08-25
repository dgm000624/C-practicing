/*
 * steping_motor_1and2.c
 *
 * Created: 2025-08-21 오전 10:10:58
 * Author : COMPUTER
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned char Step[8] = {0x09, 0x08, 0x0c, 0x04, 0x06, 0x02, 0x03, 0x01};
	
int mod = 0;

ISR(INT0_vect)
{
	
}

int main(void)
{
    DDRD = 0x0f;
	int t = 0;
    while (1) 
    {
		if(mod == 0){
			for(int i = 0 ; i < 24 ; i++)
			{
				PORTD = Step[t];
				t +=1;
				if(t>7) t=0;
				_delay_ms(10);
			}
		}
		else if(mod ==1)
		{
			
		}
		_delay_ms(1000);
    }
}

