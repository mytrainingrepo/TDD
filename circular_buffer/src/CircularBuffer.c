/* Led Driver Module implementation file */

#include "LedDriver.h"

static uint16_t *LedPort = 0;

void LedDriverInit (uint16_t *PortAddress)
{
	LedPort = PortAddress;
	*LedPort = 0;
}

void LedDriverDeinit (void)
{
	// nop
}

void LedDriverTurnLedOn (uint8_t Pin)
{
	*LedPort = (1 << Pin);
}

void LedDriverTurnLedOff (uint8_t Pin)
{
	*LedPort = (0 << Pin);
}

