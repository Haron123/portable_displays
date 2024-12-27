#include "st7735.h"

/* Public */
void ST7735::init()
{
	controller.init();
	reset();

	uint16_t at_command = 0;
	uint8_t num_commands = INIT_ST7735B[at_command++];

	for(uint8_t i = 0; i < num_commands; i++)
	{
		uint8_t num_args = INIT_ST7735B[at_command++];
		uint8_t delay_time = INIT_ST7735B[at_command++];
		uint8_t cmd = INIT_ST7735B[at_command++];

		sendCommand(cmd);

		for(uint8_t i = 0; i < num_args; i++)
		{
			sendData8(INIT_ST7735B[at_command++]);
		}

		controller.delayMs(delay_time);
	}
}

void ST7735::reset()
{
	controller.releaseReset();
	controller.delayMs(200);
	controller.assertReset();
	controller.delayMs(200);
	controller.releaseReset();
}

void ST7735::setWindow(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1)
{
	if(!checkBounds(x0, x1, y0, y1))
	{
		return;
	}

	sendCommand(CASET);
	sendData16(0x0000 | x0);
	sendData16(0x0000 | x1-1);
	sendCommand(RASET);
	sendData16(0x0000 | y0);
	sendData16(0x0000 | y1-1);
}

void ST7735::drawPixel(uint16_t x, uint16_t y, uint16_t color)
{
	setWindow(x, x, y, y);
	sendColor565(color, 1);
}

void ST7735::drawChar(char c, uint16_t color, ST7735_FontSizes size)
{

}

void ST7735::drawString(char *str, uint16_t color, ST7735_FontSizes size)
{

}

void ST7735::drawLine(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1, uint16_t color)
{
	setWindow(x0, x1, y0, y1);

	uint16_t length = x1 - x0;
	uint16_t height = y1 - y0;

	uint16_t y_per_x = height / length;
	uint16_t x_per_y = length / height;

	if(y_per_x)
	{
		for(uint16_t x = 0; x < length; x++)
		{
			drawPixel(x, (x * y_per_x), color);
		}
	}
	else if(x_per_y)
	{
		for(uint16_t y = 0; y < length; y++)
		{
			drawPixel(y, (y * x_per_y), color);
		}	
	}
}

void ST7735::drawRect(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1, uint16_t color)
{
	setWindow(x0, x1, y0, y1);
	uint16_t num_pixels = (x1 - x0) * (y1 - y0);
	sendColor565(color, num_pixels);
}

void ST7735::setPosition(uint16_t x, uint16_t y)
{

}

void ST7735::clear()
{
	setWindow(0, SIZE_X, 0, SIZE_Y);
	sendColor565(WHITE, CACHE_SIZE_MEM);
}

/* Private */
void ST7735::sendCommand(uint8_t cmd)
{
	controller.assertDC();
	controller.data_bus.sendData8(cmd);
}

void ST7735::sendData8(uint8_t data)
{
	controller.releaseDC();
	controller.data_bus.sendData8(data);
}

void ST7735::sendData16(uint16_t data)
{
	controller.releaseDC();
	controller.data_bus.sendData16(data);
}

void ST7735::sendColor565(uint16_t color, uint16_t count)
{
	sendCommand(RAMWR);

	for(uint16_t i = 0; i < count; i++)
	{
		sendData16(color);
	}
}

void ST7735::dispOn()
{
	sendCommand(DISPON);
}

void ST7735::dispOff()
{
	sendCommand(DISPOFF);
}

bool ST7735::checkBounds(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1)
{
	if ((x0 > x1) || (x1 > SIZE_X) || (y0 > y1) || (y1 > SIZE_Y)) 
	{
		return false;
	}

	return true;
}