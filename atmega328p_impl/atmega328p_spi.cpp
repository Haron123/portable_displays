#include "atmega328p_spi.h"

void ATMega328pSPI::init()
{
	spi_init();
}

uint8_t ATMega328pSPI::writeRead(uint8_t data)
{
	return spi_writeRead(data);
}