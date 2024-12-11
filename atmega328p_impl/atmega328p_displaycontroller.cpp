#include "atmega328p_displaycontroller.h"

ATMega328pDisplayController::ATMega328pDisplayController(DataBus &data_bus, volatile uint8_t *reset_ddr, volatile uint8_t *reset_port, uint8_t reset_pin_num, 
volatile uint8_t *dc_ddr, volatile uint8_t *dc_port, uint8_t dc_pin_num): 
/* Call Parent Class Constructor */
DisplayController(data_bus),
/* Set Pin Variables */
reset_ddr(reset_ddr), reset_port(reset_port), reset_pin_num(reset_pin_num),
dc_ddr(dc_ddr), dc_port(dc_port), dc_pin_num(dc_pin_num)
{

}

void ATMega328pDisplayController::init()
{
	/* Set to Outputs */
	*reset_ddr |= (1 << reset_pin_num);
	*dc_ddr |= (1 << dc_pin_num);

	data_bus.init();
}

void ATMega328pDisplayController::delayMs(uint16_t ms)
{
	delay_ms(ms);
}

void ATMega328pDisplayController::assertReset()
{
	*reset_port &= ~(1 << reset_pin_num); 
}

void ATMega328pDisplayController::releaseReset()
{
	*reset_port |= (1 << reset_pin_num); 
}

void ATMega328pDisplayController::assertDC()
{
	*dc_port &= ~(1 << dc_pin_num); 
}

void ATMega328pDisplayController::releaseDC()
{
	*dc_port |= (1 << dc_pin_num); 
}

void ATMega328pDisplayController::setBrightness(uint8_t brightness)
{
}
