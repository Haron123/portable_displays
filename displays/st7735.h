#ifndef ST7735_H_
#define ST7735_H_

#include <stdint.h>
#include "display_controller.h"

/*
Definitions taken from
http://www.displayfuture.com/Display/datasheet/controller/ST7735.pdf
https://github.com/adafruit/Adafruit-ST7735-Library
http://w8bh.net/avr/AvrTFT.pdf

So Big Thanks to Marian Hrinko
*/

// Command definition
// -----------------------------------
#define DELAY                 0x80

#define NOP                   0x00
#define SWRESET               0x01
#define RDDID                 0x04
#define RDDST                 0x09

#define SLPIN                 0x10
#define SLPOUT                0x11
#define PTLON                 0x12
#define NORON                 0x13

#define INVOFF                0x20
#define INVON                 0x21
#define DISPOFF               0x28
#define DISPON                0x29
#define RAMRD                 0x2E
#define CASET                 0x2A
#define RASET                 0x2B
#define RAMWR                 0x2C

#define PTLAR                 0x30
#define MADCTL                0x36
#define COLMOD                0x3A

#define FRMCTR1               0xB1
#define FRMCTR2               0xB2
#define FRMCTR3               0xB3
#define INVCTR                0xB4
#define DISSET5               0xB6

#define PWCTR1                0xC0
#define PWCTR2                0xC1
#define PWCTR3                0xC2
#define PWCTR4                0xC3
#define PWCTR5                0xC4
#define VMCTR1                0xC5

#define RDID1                 0xDA
#define RDID2                 0xDB
#define RDID3                 0xDC
#define RDID4                 0xDD

#define GMCTRP1               0xE0
#define GMCTRN1               0xE1

#define PWCTR6                0xFC

// Colors
// -----------------------------------
#define BLACK                 0x0000
#define WHITE                 0xFFFF
#define RED                   0xF000

// AREA definition
// -----------------------------------
#define MAX_X                 161               // max columns / MV = 0 in MADCTL
#define MAX_Y                 130               // max rows / MV = 0 in MADCTL
#define SIZE_X                MAX_X - 1         // columns max counter
#define SIZE_Y                MAX_Y - 1         // rows max counter
#define CACHE_SIZE_MEM        (MAX_X * MAX_Y)   // whole pixels
#define CHARS_COLS_LEN        5                 // number of columns for chars
#define CHARS_ROWS_LEN        8                 // number of rows for chars

const uint8_t INIT_ST7735B[] =
{
  5, /* Num Initializers */
  0, 150, SWRESET,
  0, 200, SLPOUT,
  1,  10, COLMOD, 0x05,
  1,   0, MADCTL, 0xA0,
  0, 200, DISPON 
};

enum ST7735_FontSizes 
{
	// 1x high & 1x wide size
	X1 = 0x00,
	// 2x high & 1x wide size
	X2 = 0x80,
	// 2x high & 2x wider size
	// 0x0A is set because need to offset 5 position to right
	//      when draw the characters of string 
	X3 = 0x81
};

class ST7735
{
public:
	ST7735(DisplayController &controller): controller(controller) {}
	void init();
	void reset();
	void setWindow(uint8_t x0, uint8_t x1, uint8_t y0, uint8_t y1);
	void drawPixel(uint8_t x, uint8_t y, uint16_t color);
	void drawChar(char c, uint16_t color, ST7735_FontSizes size);
	void drawString(char *str, uint16_t color, ST7735_FontSizes size);
	void drawLine(uint8_t x0, uint8_t x1, uint8_t y0, uint8_t y1, uint16_t color);
	void drawRect(uint8_t x0, uint8_t x1, uint8_t y0, uint8_t y1, uint16_t color);
	void setPosition(uint8_t x, uint8_t y);
	void clear();


private:
	void sendCommand(uint8_t cmd);
	void sendData8(uint8_t data);
	void sendData16(uint16_t data);
	void sendColor565(uint16_t color, uint16_t count);
	void dispOn();
	void dispOff();
	bool checkBounds(uint8_t x0, uint8_t x1, uint8_t y0, uint8_t y1);

	DisplayController &controller;
};

#endif // ST7735_H_