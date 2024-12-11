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
	 * @brief Sends the Array of Size len on the Databus
	 * 
	 * @param data the array of bytes to send
	 * @param len the length of the data
	 */
	virtual void sendData(uint8_t *data, uint16_t len) = 0;

	/**
	 * @brief Sends 8 Bits over the Databus
	 * 
	 * @param data the byte to send
	 */
	virtual void sendData8(uint8_t data) = 0;

	/**
	 * @brief Sends 16 Bits over the Databus
	 * 
	 * @param data the 2 bytes to send
	 */
	virtual void sendData16(uint16_t data) = 0;

	/**
	 * @brief Writes from the Databus into the given array of Size len
	 * 
	 * @param data the array in which will be written
	 * @param len the amount of bytes to read
	 */
	virtual void receiveData(uint8_t *data, uint16_t len) = 0;

	/**
	 * @brief Reads 8 Bits from the Databus
	 * 
	 * @retval the byte thats been read from the databus
	 */
	virtual uint8_t receiveData8() = 0;

	/**
	 * @brief Reads 16 Bits from the Databus
	 * 
	 * @retval the 2 bytes that have been read from the databus
	 */
	virtual uint16_t receiveData16() = 0;
};

#endif // DATABUS_H_