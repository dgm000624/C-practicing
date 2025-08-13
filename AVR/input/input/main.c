/*
 * input.c
 *
 * Created: 2025-08-12 오후 2:09:14
 * Author : COMPUTER
 */ 

#include <avr/io.h>
#include <util/delay.h>

void switchs(int temp);
void switchs2(int temp);

unsigned int Font[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
	
int total;

int main(void)
{
    DDRE = 0xff;		//출력포트
	DDRG = 0x08;
	DDRD = 0x00;		//입력포트
	
	total = 0;
	
	int amt1 = 0; 
	int amt2 = 0; 
	int amt3 = 0; 
	int amt4 = 0; 
	
	int prev = 0;
	
	
    while (1) 
    {
		//PORTE = 0x00000000;
		
		int temp = PIND;
		
		if (prev != temp)
		{
			switchs2(temp);
		}
		
		
		
		int a = (total / 1000) % 10;
		int b = (total / 100) % 10;
		int c = (total / 10) % 10; 
		int d = total % 10;
		
		
		
		
		if ((a>=1)||(amt1==1))
		{
			DDRG = 0x01;
			switchs(a);
			amt1 = 1;
		}
		if ((b>=1)||(amt2==1))
		{
			DDRG = 0x02;
			switchs(b);
			amt2 = 1;
		}
		if ((c>=1)||(amt3==1))
		{
			DDRG = 0x04;
			switchs(c);
			amt3 = 1;
		}
		if ((d>=1)||(amt4==1))
		{
			DDRG = 0x08;
			switchs(d);
			amt4 = 1;
		}
		
		prev = temp;
    }
}

void switchs(int temp)
{
	
	switch(temp)
	{
		/*
		case 0x01: PORTE = ~Font[1];  break;
		case 0x02: PORTE = ~Font[2];  break;
		case 0x04: PORTE = ~Font[3];  break;
		case 0x08: PORTE = ~Font[4];  break;
		case 0x10: PORTE = ~Font[5];  break;
		case 0x20: PORTE = ~Font[6];  break;
		case 0x40: PORTE = ~Font[7];  break;
		case 0x80: total = 0; PORTE = ;  break;
		default : break;
		*/
		case 0: PORTE = ~Font[0]; _delay_ms(5); break;
		case 1: PORTE = ~Font[1]; _delay_ms(5); break;
		case 2: PORTE = ~Font[2]; _delay_ms(5); break;
		case 3: PORTE = ~Font[3]; _delay_ms(5); break;
		case 4: PORTE = ~Font[4]; _delay_ms(5); break;
		case 5: PORTE = ~Font[5]; _delay_ms(5); break;
		case 6: PORTE = ~Font[6]; _delay_ms(5); break;
		case 7: PORTE = ~Font[7]; _delay_ms(5);  break;
		case 8: PORTE = ~Font[8]; _delay_ms(5); break;
		case 9: PORTE = ~Font[9]; _delay_ms(5); break;
		
		default : break;
	}
	
}
void switchs2(int temp)
{
	switch(temp)
	{
		case 0x01: total += 1;  break;
		case 0x02: total += 2;  break;
		case 0x04: total += 3;  break;
		case 0x08: total += 4;  break;
		case 0x10: total += 5;  break;
		case 0x20: total += 6;  break;
		case 0x40: total += 7;  break;
		case 0x80: total = 0; PORTE = 0x00;  break;
		default : break;
	}
	
}