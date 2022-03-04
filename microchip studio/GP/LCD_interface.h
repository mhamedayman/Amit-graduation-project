#ifndef		LCD_INTERFACE_H
#define		LCD_INTERFACE_H

#define		LCD_CONTROL_PORT		PORTD
#define		LCD_RS					PIN0
#define		LCD_RW					PIN1
#define		LCD_EN					PIN2

#define		LCD_DATA_PORT			PORTC

#define		LCD_MODE				8

void	LCD_voidInit8bit(void);
void	LCD_voidWriteChar8bit(u8 Data);
void	LCD_voidSendCMD8bit(u8 CMD);
	
void	LCD_voidInit4bit(void);
void	LCD_voidWriteChar4bit(u8 Data);
void	LCD_voidSendCMD4bit(u8 CMD);
void	LCD_voidWriteString(u8 * string);
void	LCD_voidGotoXY(u8 Line , u8 Col);
void	LCD_voidWriteu8Num(u32 Num);

#endif

