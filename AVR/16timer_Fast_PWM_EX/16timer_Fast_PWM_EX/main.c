/*
 * 16timer_Fast_PWM_EX.c
 *
 * Created: 2025-08-20 오전 9:24:03
 * Author : COMPUTER
 */ 

#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define MAX_Duty 65535
unsigned int Duty = 65535;

ISR(INT0_vect){
	Duty = MAX_Duty/5;
}

ISR(INT1_vect){
	Duty = 2*MAX_Duty/5;
}

ISR(INT2_vect){
	Duty = 3*MAX_Duty/5;
}

ISR(INT3_vect){
	Duty = 4*MAX_Duty/5;
}

ISR(INT4_vect){
	Duty = MAX_Duty;
}



int main(void)
{
	DDRD = 0x00;
	DDRE = 0x00;
	DDRA = 0xff;
	ASSR = 0;
	TIMSK = 0x00;
	TCCR1A = (1<<COM1A1) | (1<<WGM11);
	TCCR1B = (1 << WGM13) | (1<<WGM12) | ( 1<<CS11);
	ICR1 = MAX_Duty;

	EICRA = ((1<<ISC01) | (1<<ISC00) | (1<<ISC11) | (1<<ISC10) | (1<<ISC21) | (1<<ISC20) | (1<<ISC31) | (1<<ISC30));
	EICRB = ((1<<ISC41) | (1<<ISC40));
	
	EIMSK = (1 << INT0) | (1 << INT1) | (1 << INT2) | (1 << INT3) | (1 << INT4);
	
	
	
	sei();
	PORTA = 0xff;
	
    while (1) 
    {
		_delay_ms(100);
		ICR1 = Duty;
    }
}

