#ifndef ATMEGA328P_SPI_H_
#define ATMEGA328P_SPI_H_

#include "spi_interface.h"
#include "spi.h"

class ATMega328pSPI: public SpiInterface
{
public:
	void init() override;
	uint8_t writeRead(uint8_t data) override;
};

#endif // ATMEGA328P_SPI_H_