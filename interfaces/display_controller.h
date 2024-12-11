#ifndef DISPLAY_CONTROLLER_H_
#define DISPLAY_CONTROLLER_H_

#include "databus.h"

class DisplayController
{
public:	
	DisplayController(DataBus &data_bus): data_bus(data_bus) {}

	DataBus &data_bus;

	/**
	 * @brief Initializes the Display Controller
	 */
	virtual void init() = 0;

	/**
	 * @brief Blocking Delay for x MS
	 * 
	 * @param ms the amount of milliseconds to block
	 */
	virtual void delayMs(uint16_t ms) = 0;

	/**
	 * @brief Asserts the Reset Signal to the Display
	 */
	virtual void assertReset() = 0;

	/**
	 * @brief Releases the Reset Signal to the Display
	 */
	virtual void releaseReset() = 0;

	/**
	 * @brief Asserts the Data/Command Signal to the Display
	 */
	virtual void assertDC() = 0;

	/**
	 * @brief Releases the Data/Command Signal to the Display
	 */
	virtual void releaseDC() = 0;

	/**
	 * @brief Set the Brightness of the Display from 0-255
	 * 
	 * @param brightness a value from 0-255 where 0 is backlight off and 255 is backlight fully on
	 * the values in between have to PWM the Backlight, theres no brightness specification for the values
	 * between 0 and 255
	 */
	virtual void setBrightness(uint8_t brightness) = 0;
};

#endif // DISPLAY_CONTROLLER_H_