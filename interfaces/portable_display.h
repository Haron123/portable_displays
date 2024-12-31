#ifndef PORTABLE_DISPLAY_H_
#define PORTABLE_DISPLAY_H_

#include <stdint.h>

// Standard Colors
// -----------------------------------
#define BLACK                 0x0000
#define WHITE                 0xFFFF
#define RED                   0xF000
#define PURPLE				  0xF00F

class PortableDisplay
{
public:
	virtual void init() = 0;
	virtual void reset() = 0;
	virtual void drawPixel(uint16_t x, uint16_t y, uint16_t color = BLACK) = 0;
	virtual void drawLine(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1, uint16_t color = BLACK) = 0;
	virtual void drawRect(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1, uint16_t color = BLACK) = 0;
	virtual void drawImg(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1, uint8_t *img) = 0;
	virtual void setPosition(uint16_t x, uint16_t y) = 0;
	virtual void drawChar(char c, uint8_t size = 0, uint16_t color = BLACK) = 0;
	virtual void drawString(char *str, uint8_t size = 0, uint16_t color = BLACK) = 0;
	virtual void clear() = 0;
	virtual void on() = 0;
	virtual void off() = 0;
};

#endif // PORTABLE_DISPLAY_H_