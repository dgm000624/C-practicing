// /*
//  * AD_Convert.c
//  *
//  * Created: 2025-08-20 오전 11:23:52
//  * Author : COMPUTER
//  */ 
// 
// #define F_CPU 16000000L
// #include <avr/io.h>
// #include <util/delay.h>
// 
// unsigned char Font[18] = {0x3F, 0X06, 0X5B, 0X4F,
// 	0X66, 0X6D, 0X7C, 0X07,
// 	0X7F, 0X67, 0X77, 0X7C,
// 	0X39, 0X5E, 0X79, 0X71,
// 0X08, 0X80};
// 
// void Segment(int);
// unsigned int adc_data = 0;
// 
// void Segment ( int N )
// {
// 	int i;
// 	unsigned char N1000, N100, N10, N1;
// 	int Buff;
// 	N1000 = N / 1000; // 세그먼트에서 사용하는 천의 자리를 추출
// 	Buff = N % 1000;
// 	N100 = Buff / 100; // 세그먼트에서 사용하는 백의자리 추출
// 	Buff = Buff % 100;
// 	N10 = Buff / 10; // 세그먼트에서 사용하는 십의 자리 추출
// 	N1 = Buff % 10; // 세그먼트에서 사용하는 일의 자리 추출
// 	for( i = 0; i < 30; i++ ) {
// 		PORTC = 0x0e; // 왼쪽 첫 번째 세그먼트 ON
// 		PORTA = Font[N1000]; // 천의 자리 숫자를 출력해 준다
// 		_delay_ms(1);
// 		PORTC = 0x0d; // 왼쪽 두 번째 세그먼트 ON
// 		PORTA = Font[N100]; // 백의 자리 숫자를 출력해 준다
// 		_delay_ms(1);
// 		PORTC = 0x0b; // 왼쪽 세 번째 세그먼트 ON
// 		PORTA = Font[N10]; // 십의 자리 숫자를 출력해 준다
// 		_delay_ms(1);
// 		PORTC = 0x07; // 왼쪽 네 번째 세그먼트 ON
// 		PORTA = Font[N1]; // 일의 자리 숫자를 출력해 준다
// 		_delay_ms(1);
// 	}
// }
// 
// unsigned int read_adc(void)
// {
// 	ADCSRA|=0x40; 
// 	
// 	while(1){
// 		if((ADCSRA&0x10)!=0) break;
// 	}
// 	return ADC;
// }
// 
// int main(void)
// {
//     DDRA = 0xff;
// 	DDRC = 0x0f;
// 	PORTA = 0xff;
// 	PORTC = 0x0f;
// 	
// 	DDRF = 0x00;
// 	ADMUX = 0x00;
// 	ADCSRA = 0x83;
// 	_delay_us(10);
//     while (1) 
//     {
// 		adc_data = read_adc();
// 		Segment(adc_data);
//     }
// }
// 
