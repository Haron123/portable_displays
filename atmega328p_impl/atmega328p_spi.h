#ifndef ATMEGA328P_SPI_H_
#define ATMEGA328P_SPI_H_

#include "databus.h"
#include "spi.h"

class ATMega328pSPI: public DataBus
{
public:
	void init() override;
	void writeData(uint8_t data) override;
	uint8_t readData() override;
};

#endif // ATMEGA328P_SPI_H_