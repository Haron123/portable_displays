#ifndef ATMEGA328P_DISPLAY_CONTROLLER_H_
#define ATMEGA328P_DISPLAY_CONTROLLER_H_

#include <avr/io.h>
#include "display_controller.h"
#include "system_time.h"
#include <util/delay.h>

class ATMega328pDisplayController: public DisplayController
{
public:
	/**
	 * @brief sets up the Object with the given Ports and Pins
	 * 
	 * @param reset_ddr Data Direction Register Address for the Reset pin
	 * @param reset_port Control Port Register Address for the Reset pin
	 * @param reset_pin_num Pin Number of the Reset pin (Not the already Shifted value)
	 * @param dc_ddr Data Direction Register Address for the Data/Command pin
	 * @param dc_port Control Port Register Address for the Data/Command pin
	 * @param dc_pin_num Pin Number of the Data/Command pin (Not the already Shifted value)
	 */
	ATMega328pDisplayController(DataBus &data_bus, volatile uint8_t *reset_ddr, volatile uint8_t *reset_port, uint8_t reset_pin_num,
	volatile uint8_t *dc_ddr, volatile uint8_t *dc_port, uint8_t dc_pin_num);

	void init() override;
	void delayMs(uint16_t ms) override;
	void assertReset() override;
	void releaseReset() override;
	void assertDC() override;
	void releaseDC() override;
	void setBrightness(uint8_t brightness) override;

private:
	volatile uint8_t *reset_ddr;
	volatile uint8_t *reset_port;
	uint8_t reset_pin_num;

	volatile uint8_t *dc_ddr;
	volatile uint8_t *dc_port;
	uint8_t dc_pin_num;
};

#endif // ATMEGA328P_DISPLAY_CONTROLLER_H_