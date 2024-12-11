#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include <stdint.h>
#include "databus.h"

class SpiInterface: public DataBus
{
public:
	/**
	 * @brief Blocking Operation. Initializes the SPI Peripheral making it ready
	 * to read and write
	 */
	virtual void init() = 0;

	/**
	 * @brief Blocking Operation. Writes a single Byte while reading a single Byte
	 * 
	 * @param data the byte that will be written on the spi peripheral
	 * 
	 * @retval the data which was read from the spi peripheral
	 */
	virtual uint8_t writeRead(uint8_t data) = 0;

	void sendData(uint8_t *data, uint16_t len) override
	{
		for(uint16_t i = 0; i < len; i++)
		{
			writeRead(data[i]);
		}
	}

	void sendData8(uint8_t data) override
	{
		writeRead(data);
	}

	void sendData16(uint16_t data) override
	{
		writeRead((data >> 8) & 0xFF);
		writeRead(data & 0xFF);
	}

	void receiveData(uint8_t *data, uint16_t len) override
	{
		for(uint16_t i = 0; i < len; i++)
		{
			data[i] = writeRead(0x00);
		}
	}

	uint8_t receiveData8() override
	{
		return writeRead(0x00);
	}

	uint16_t receiveData16() override
	{
		uint16_t result = writeRead(0x00) << 8;
		result |= writeRead(0x00);
		
		return result;
	}

};

#endif // SPI_INTERFACE_H_