#define F_CPU    16000000UL

#include		"Bit_Math.h"
#include		"Std_Types.h"
#include		"DIO_interface.h"
#include		"ADC_interface.h"
#include		"LCD_interface.h"

#include		<util/delay.h>



int main(void)
{
	/*				lcd port			*/
DIO_voidSetPortDirection(PORTC,0xFF);
DIO_voidSetPortDirection(PORTD,0x00);
DIO_voidSetPinDirection(PORTD,PIN0,OUTPUT);
DIO_voidSetPinDirection(PORTD,PIN1,OUTPUT);
DIO_voidSetPinDirection(PORTD,PIN2,OUTPUT);

	/*				adc port			*/
DIO_voidSetPinDirection(PORTA,PIN0,INPUT);
DIO_voidSetPinDirection(PORTA,PIN1,INPUT);
DIO_voidSetPinDirection(PORTA,PIN2,INPUT);
DIO_voidSetPinDirection(PORTA,PIN3,INPUT);
DIO_voidSetPinDirection(PORTA,PIN4,INPUT);




LCD_voidInit8bit();
ADC_voidInit();
ADC_voidEnable();


u16 x[5]={0,0,0,0,0};
    while (1) 
    {
		for (u8 i=0; i<5;i++)
		{
			ADC_voidSetChannel(i);
			x[i]=ADC_u16ReadValue();
		}
		
			
		if ((x[0]>512)&&(x[1]>512)&&(x[2]>512)&&(x[3]>512)&&(x[4]>512))
		{
			LCD_voidSendCMD8bit(0x80);
			LCD_voidWriteString((u8*) "Hello");
		}
		else if((x[0]>512)&&(x[1]<512)&&(x[2]<512)&&(x[3]<512)&&(x[4]<512))
		{
			LCD_voidSendCMD8bit(0x80);
			LCD_voidWriteString((u8*) "Good Job");

		}
		else if((x[0]<512)&&(x[1]>512)&&(x[2]<512)&&(x[3]<512)&&(x[4]>512))
		{
			LCD_voidSendCMD8bit(0x80);
			LCD_voidWriteString((u8*) "Amazing");
		
		}
		else if((x[0]>512)&&(x[1]>512)&&(x[2]<512)&&(x[3]<512)&&(x[4]>512))
		{
			LCD_voidSendCMD8bit(0x80);
			LCD_voidWriteString((u8*) "I Love You");
			
		}
		else if((x[0]<512)&&(x[1]>512)&&(x[2]<512)&&(x[3]<512)&&(x[4]<512))
		{
			LCD_voidSendCMD8bit(0x80);
			LCD_voidWriteString((u8*) "You");
			
		}
		else if((x[0]<512)&&(x[1]>512)&&(x[2]>512)&&(x[3]<512)&&(x[4]<512))
		{
			LCD_voidSendCMD8bit(0x80);
			LCD_voidWriteString((u8*) "Peace");
			
		}
		else if((x[0]>512)&&(x[1]<512)&&(x[2]<512)&&(x[3]<512)&&(x[4]>512))
		{
			LCD_voidSendCMD8bit(0x80);
			LCD_voidWriteString((u8*) "Phone");
			
		}
		else if((x[0]<512)&&(x[1]<512)&&(x[2]>512)&&(x[3]>512)&&(x[4]>512))
		{
			LCD_voidSendCMD8bit(0x80);
			LCD_voidWriteString((u8*) "I'm Good");
			
		}
		else
		{
		_delay_ms(50);
		LCD_voidSendCMD8bit(0x1);

		}
		
    }
}
	//LCD_voidWriteu8Num(X);
	//_delay_ms(20);
	//LCD_voidSendCMD8bit(0x1);
	//_delay_ms(20);
	
	
	
	//LCD_voidWriteu8Num(x1);
	//_delay_ms(20);
	//LCD_voidSendCMD8bit(0x1);
	//LCD_voidWriteu8Num(x2);
	//_delay_ms(20);
	//LCD_voidSendCMD8bit(0x1);
	//LCD_voidWriteu8Num(x3);
	//_delay_ms(20);
	//LCD_voidSendCMD8bit(0x1);
	//LCD_voidWriteu8Num(x4);
	//_delay_ms(20);
	//LCD_voidSendCMD8bit(0x1);
	
	
	
	
	
//LCD_voidWriteu8Num(x[0]);
//_delay_ms(20);
//LCD_voidSendCMD8bit(0x1);
//LCD_voidWriteu8Num(x[1]);
//_delay_ms(20);
//LCD_voidSendCMD8bit(0x1);
//LCD_voidWriteu8Num(x[2]);
//_delay_ms(20);
//LCD_voidSendCMD8bit(0x1);
//LCD_voidWriteu8Num(x[3]);
//_delay_ms(20);
//LCD_voidSendCMD8bit(0x1);



	//ADC_voidSetChannel(PIN0);
	//x1=ADC_u16ReadValue();
	//ADC_voidSetChannel(PIN1);
	//x2=ADC_u16ReadValue();
	//ADC_voidSetChannel(PIN2);
	//x3=ADC_u16ReadValue();
	//ADC_voidSetChannel(PIN3);
	//x4=ADC_u16ReadValue();