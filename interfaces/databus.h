#ifndef DATABUS_H_
#define DATABUS_H_

#include <stdint.h>

class DataBus
{
public:

	/**
	 * @brief initializes the Databus
	 */
	virtual void init() = 0;

	/**
	 * @brief Blocking Operation which retrieves one byte from the databus
	 * 
	 * @retval the byte which has been read from the databus 
	 */
	virtual uint8_t readData() = 0;

	/**
	 * @brief Blocking Operation which sends one byte to the databus
	 * 
	 * @param data the byte which should be written
	 */
	virtual void writeData(uint8_t data) = 0;

	/**
	 * @brief Sends the Array of Size len on the Databus
	 * 
	 * @param data the array of bytes to send
	 * @param len the length of the data
	 */
	void sendData(uint8_t *data, uint16_t len)
	{
		for(uint16_t i = 0; i < len; i++)
		{
			writeData(data[i]);
		}
	}

	/**
	 * @brief Sends 8 Bits over the Databus
	 * 
	 * @param data the byte to send
	 */
	void sendData8(uint8_t data)
	{
		writeData(data);
	}

	/**
	 * @brief Sends 16 Bits over the Databus, High Byte goes first
	 * 
	 * @param data the 2 bytes to send
	 */
	void sendData16(uint16_t data)
	{
		writeData((data >> 8) & 0xFF);
		writeData(data & 0xFF);
	}

	/**
	 * @brief Writes from the Databus into the given array of Size len
	 * 
	 * @param data the array in which will be written
	 * @param len the amount of bytes to read
	 */
	void receiveData(uint8_t *data, uint16_t len)
	{
		for(uint16_t i = 0; i < len; i++)
		{
			data[i] = readData();
		}
	}

	/**
	 * @brief Reads 8 Bits from the Databus
	 * 
	 * @retval the byte thats been read from the databus
	 */
	uint8_t receiveData8()
	{
		return readData();
	}

	/**
	 * @brief Reads 16 Bits from the Databus, High Byte is read first
	 * 
	 * @retval the 2 bytes that have been read from the databus
	 */
	uint16_t receiveData16()
	{
		uint16_t result = 0;

		result = readData() << 8;
		result |= readData();

		return result;
	}
};

#endif // DATABUS_H_