/* Led Driver Module implementation file */

#include "LedDriver.h"
#include "RuntimeError.h"

static uint16_t *LedPortAddress = 0;
static uint16_t LedPortImage = 0;

static void setLedImageBit(uint8_t Bit)
{
	LedPortImage |= (1 << Bit);
}

static void clearLedImageBit(uint8_t Bit)
{
	LedPortImage &= ~(1 << Bit);
}

static bool IsLedOutOfBounds (uint8_t Pin)
{
	return ((Pin < 0) || (Pin >= LED_PORT_SIZE));
}

static void updateHardware(void)
{
	*LedPortAddress = LedPortImage;
}

void LedDriverInit (uint16_t *PortAddress)
{
	LedPortAddress = PortAddress;
	LedPortImage = ALL_LEDS_OFF;
	updateHardware();
}

void LedDriverDeinit (void)
{
	LedPortImage = ALL_LEDS_OFF;
	updateHardware();
}

void LedDriverTurnLedOn (uint8_t Pin)
{
	if (IsLedOutOfBounds(Pin))	
	{
		RUNTIME_ERROR("LED Driver: out-of-bounds", Pin);
	}
	else
	{
		setLedImageBit(Pin);
		updateHardware();
	}
}

void LedDriverTurnLedOff (uint8_t Pin)
{
	if (IsLedOutOfBounds(Pin))
	{
		RUNTIME_ERROR("LED Driver: out-of-bounds", Pin);
	}
	else
	{
		clearLedImageBit(Pin);
		updateHardware();
	}
}

void LedDriverTurnAllLedsOff (void)
{
	LedPortImage = ALL_LEDS_OFF;
	updateHardware();
}

void LedDriverTurnAllLedsOn (void)
{
	LedPortImage = ALL_LEDS_ON;
	updateHardware();
}

bool LedDriverIsOn(uint8_t Pin)
{
	if (IsLedOutOfBounds(Pin))
	{
		return 0;
	}
	else
	{
		return (LedPortImage & (Pin));
	}
}

