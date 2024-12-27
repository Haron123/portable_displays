#include "atmega328p_spi.h"

void ATMega328pSPI::init()
{
	spi_init();
}

void ATMega328pSPI::writeData(uint8_t data)
{
	spi_writeRead(data);
}

uint8_t ATMega328pSPI::readData()
{
	return spi_writeRead(0xFF);
}