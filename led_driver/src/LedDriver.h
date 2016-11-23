/* Led Driver module header file */

#ifndef uint16_t
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef unsigned char bool;
#endif

#define LED_PORT_SIZE 16u
#define ALL_LEDS_ON   0xFFFFu
#define ALL_LEDS_OFF  0x0u

void LedDriverInit(uint16_t *PortAddress);

void LedDriverDeinit(void);

void LedDriverTurnLedOn(uint8_t Pin);

void LedDriverTurnLedOff(uint8_t Pin);

void LedDriverTurnAllLedsOn(void);

void LedDriverTurnAllLedsOff(void);

bool LedDriverIsLedOn(uint8_t Pin);
