


#ifndef    _LCD_INTERFACE_H_
#define   _LCD_INTERFACE_H_


#define PortA  		0
#define PortB 	 	1
#define PortC	 	2
#define PortD  		3

#define OUTPUT 		1
#define INPUT   	0

#define HIGH   		1
#define LOW      	0

#define     CLR_LCD                                         0x01
#define 	RETURN_HOME										0x02

#define 	DECREMENT_CURSOR_TO_LEFT						0x04
#define 	INCREMENT_CURSOR_TO_RIGHT						0x06

#define 	SHIFT_DISPLAY_TO_RIGHT							0x05
#define 	SHIFT_DISPLAY_TO_LEFT							0x07


#define 	DISPLAY_OFF_CURSOR_OFF							0x08
#define 	DISPLAY_OFF_CURSOR_ON							0x0A
#define 	DISPLAY_ON_CURSOR_OFF							0x0C
#define 	DISPLAY_ON_CURSOR_BLINK							0x0E


#define 	SHIFT_CURSOR_POSITION_TO_LEFT					0x10
#define 	SHIFT_CURSOR_POSITION_TO_RIGHT					0x14

#define 	SHIFT_ENTRIE_DISPLAY_TO_LEFT					0x18
#define 	SHIFT_ENTRIE_DISPLAY_TO_RIGHT					0x1C

#define 	FORCE_CURSOR_START_FIRST_LINE					0x80
#define 	FORCE_CURSOR_START_SECOND_LINE					0xC0


void LCD_VidSendData(uint8_t copy_U8Data);
void LCD_VidSendCommand(uint8_t copy_U8Command);
void LCD_VidInit(void);
void LCD_VidSendString(uint8_t *copy_U8String);
void LCD_GoToXY(uint8_t copy_U8X,uint8_t copy_U8Y);
void LCD_VidLatch(uint8_t copy_U8Data);
//void LCD_VidSendSpecialNumber(u32 copy_U32Number);
void LCD_VidDraw(uint8_t copy_U8Pattern[], uint8_t copy_U8Size);
//void LCD_enuSendSpecialNumber(u32 Copy_u32Number);
//void LCD_VidSendSpecialNumber(u32 Copy_U32Number);
void LCD_VidSendNum (uint32_t Copy_U32Num);
void LCD_WriteNumber(sint16_t num);

#endif
