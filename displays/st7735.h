#ifndef ST7735_H_
#define ST7735_H_

#include <stdint.h>
#include "display_controller.h"
#include "portable_display.h"

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

const uint8_t fontsize_values[] =
{
	0x00, /* X1 */
	0x80, /* X2 */
	0x81, /* X3 */
};
#define MAX_FONTSIZE sizeof(fontsize_values)

class ST7735: public PortableDisplay
{
public:
	ST7735(DisplayController &controller): controller(controller) {}
	void init() override;
	void reset() override;
	void drawPixel(uint16_t x, uint16_t y, uint16_t color = BLACK) override;
	void drawLine(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1, uint16_t color = BLACK) override;
	void drawRect(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1, uint16_t color = BLACK) override;
	void drawImg(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1, uint8_t *img) override;
	void setPosition(uint16_t x, uint16_t y) override;
	void drawChar(char c, uint8_t size, uint16_t color = BLACK) override;
	void drawString(char *str, uint8_t size, uint16_t color = BLACK) override;
	void clear() override;
	void on() override;
	void off() override;

private:
	void setWindow(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1);
	void sendCommand(uint8_t cmd);
	void sendData8(uint8_t data);
	void sendData16(uint16_t data);
	void sendData16Burst(uint16_t data, uint16_t count);
	void sendColor565(uint16_t color, uint16_t count);
	bool checkBounds(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1);

	DisplayController &controller;
};

#endif // ST7735_H_