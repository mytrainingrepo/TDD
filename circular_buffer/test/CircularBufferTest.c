/* Unit tests for the Led Driver module */

#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(CircularBuffer);

TEST_SETUP(CircularBuffer)
{
	CircularBuffer_Init();
}

TEST_TEAR_DOWN(CircularBuffer)
{

}

TEST(CircularBuffer, CircularBuffer_Init)
{
	uint16_t virtualLeds = 0xffff;
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(CircularBuffer)
{
	LedDriverTurnLedOn(0);
	TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

TEST(CircularBuffer)
{
	LedDriverTurnLedOn(0);
	LedDriverTurnLedOff(0);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}
