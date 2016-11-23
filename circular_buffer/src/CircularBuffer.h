/* Led Driver module header file */

#ifndef uint16_t
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
#endif

void LedDriverInit(uint16_t *PortAddress);

void LedDriverDeinit(void);

void LedDriverTurnLedOn(uint8_t Pin);

void LedDriverTurnLedOff(uint8_t Pin);
