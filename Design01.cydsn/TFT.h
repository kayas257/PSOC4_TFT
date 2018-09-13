/*
 * TFT.h
 *
 * 
 *  
 */ 


#ifndef TFT_H_
#define TFT_H_

#include <stdlib.h>
#include <project.h>	//   uint_t !
	
#define TFT_DATA_PORT PORTB
#define TFT_DATA_DIR DDRB
#define TFT_CTRL_PORT PORTA
#define TFT_CTRL_DIR DDRA

#define FONT_SPACE 10
#define FONT_X 16
#define FONT_Y 8
//Basic Colors
#define RED	 	0xf800

#define YELLOW	0xffe0
#define GREEN	0x07e0
#define BLUE	0x001f
#define CYAN	0x07ff
#define MAGENTA 0xF81F
#define BLACK	0x0000
#define WHITE	0xffff

//Other Colors   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
#define BRED		0xf810	
#define GRAY1		0x8410  
#define GRAY2		0x4208  
#define BLUE2    	0x051F

#define   NAVY   	0x000F
#define   DGREEN 	0x03E0
#define   DCYAN   	0x03EF
#define   MAROON  	0x7800
#define   PURPLE  	0x780F
#define   OLIVE   	0x7BE0
#define   GREY    	0xF7DE
#define   LGRAY  	0xC618
#define   DGRAY   	0x7BEF
#define   BROWN   	0xBC40 

#define MIN_X	0
#define MIN_Y	0

#define TFT_RDX	0
#define TFT_WRX	1
#define TFT_DCX	2
#define TFT_CSX	3

#define TFT_RDX_LO	{TFT_CTRL_PORT &=~(1 << TFT_RDX);}
#define TFT_RDX_HIGH	{TFT_CTRL_PORT |=(1 << TFT_RDX);}
	
#define TFT_WRX_LO	{TFT_CTRL_PORT &=~(1 << TFT_WRX);}
#define TFT_WRX_HIGH	{TFT_CTRL_PORT |=(1 << TFT_WRX);}
	
#define TFT_DCX_LO	{TFT_CTRL_PORT &=~(1 << TFT_DCX);}
#define TFT_DCX_HIGH	{TFT_CTRL_PORT |=(1 << TFT_DCX);}

#define TFT_CSX_LO	{TFT_CTRL_PORT &=~(1 << TFT_CSX);}
#define TFT_CSX_HIGH	{TFT_CTRL_PORT |=(1 << TFT_CSX);}
//****************************************************************************************
void TFT_SendCMD(uint8_t cmd);
void TFT_WriteData(uint8_t data);
void TFT_SendData(uint16_t data);
void TFT_Init(uint8_t orient);
void TFT_ClearScreen(void);
void TFT_FillScreen(uint16_t XL, uint16_t XR, uint16_t YU, uint16_t YD, uint16_t color);
void TFT_FillRectangle(uint16_t poX, uint16_t poY, uint16_t length, uint16_t width, uint16_t color);
void TFT_DrawHorizontalLine( uint16_t poX, uint16_t poY, uint16_t length,uint16_t color);
void TFT_DrawLine( uint16_t x0,uint16_t y0,uint16_t x1, uint16_t y1,uint16_t color);
void TFT_DrawVerticalLine( uint16_t poX, uint16_t poY, uint16_t length,uint16_t color);
void TFT_DrawRectangle(uint16_t poX, uint16_t poY, uint16_t length, uint16_t width,uint16_t color);
void TFT_DrawCircle(int poX, int poY, int r,uint16_t color);
void TFT_FillCircle(int poX, int poY, int r,uint16_t color);
void TFT_SetOrientation(uint8_t orient);
void TFT_DrawChar( uint8_t ascii, uint16_t poX, uint16_t poY,uint16_t size, uint16_t fgcolor);
void TFT_DrawString(char *string,uint16_t poX, uint16_t poY, uint16_t size,uint16_t fgcolor);
void TFT_SetPixel(uint16_t poX, uint16_t poY,uint16_t color);
//***************************************************************************************

void TFT_FillBitmap(uint16_t poX, uint16_t poY, uint16_t length, uint16_t width, unsigned short *Bitmap);
void TFT_Graf(uint16_t XL, uint16_t YU, uint16_t YD, char  Ydata , char last);
// void Read_SD_Pictute(uint16_t XL, uint16_t XR, uint16_t YU, uint16_t YD, unsigned short *FileName);
void TFT_GrafN(unsigned int Xi, unsigned int Yo, uint16_t height, uint8*  Ydata , uint8* last, uint16_t *colors, uint16_t Blcolor, uint8 Nch);
void TFT_DrawStringBl(char *string,uint16_t poX, uint16_t poY, uint16_t size,uint16_t fgcolor,uint16_t bgcolor);

#endif /* TFT_H_ */
