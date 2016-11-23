/* Unit tests for the Led Driver module */

#include "unity.h"
#include "unity_fixture.h"

uint16_t virtualLeds = 0xffff;

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{
	LedDriverInit(&virtualLeds);
}

TEST_TEAR_DOWN(LedDriver)
{

}

TEST(LedDriver, LedsOffAfterInit)
{
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, Turn1stLedOn)
{
	LedDriverTurnLedOn(0);
	TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

TEST(LedDriver, Turn1stLedOff)
{
	LedDriverTurnLedOn(0);
	LedDriverTurnLedOff(0);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, TurnMultipleLedsOn)
{
	LedDriverTurnLedOn(8);
	LedDriverTurnLedOn(9);
	TEST_ASSERT_EQUAL_HEX16((1 << 8) | (1 << 9), virtualLeds);
}

TEST(LedDriver, TurnMultipleLedsOff)
{
	LedDriverTurnLedOff(8);
	LedDriverTurnLedOff(9);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, TurnAnyLedOff)
{
	LedDriverTurnLedOn(8);
	LedDriverTurnLedOn(9);
	LedDriverTurnLedOff(8);
	TEST_ASSERT_EQUAL_HEX16((1 << 9), virtualLeds);
}

TEST(LedDriver, TurnAllLedsOn)
{
	LedDriverTurnAllLedsOn();
	TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
}

TEST(LedDriver, TurnAllLedsOff)
{
	LedDriverTurnAllLedsOff();
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, UpperAndLowerBounds)
{
	LedDriverTurnLedOn(0);
	LedDriverTurnLedOn(15);
	TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLeds);
}

TEST(LedDriver, OutOfBoundsTurnOffSafety)
{
	LedDriverTurnAllLedsOff();
	LedDriverTurnLedOn(-1);
	LedDriverTurnLedOn(16);
	LedDriverTurnLedOn(1000);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, OutOfBoundsTurnOnSafety)
{
	LedDriverTurnAllLedsOn();
	LedDriverTurnLedOn(-1);
	LedDriverTurnLedOn(16);
	LedDriverTurnLedOn(1000);
	TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
}

TEST(LedDriver, OutOfBoundsTriggersRuntimeError)
{
	LedDriverTurnLedOn(100);
	TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds", \
			          RuntimeErrorStub_GetLastError());
	TEST_ASSERT_EQUAL(100, RuntimeErrorStub_GetLastParameter());
}

IGNORE_TEST(LedDriver, OutOfBoundsToDo)
{
	// Ignored test
}

TEST(LedDriver, IsLedOn)
{
	TEST_ASSERT_FALSE(LedDriverIsOn(11));
	LedDriverTurnLedOn(11);
	TEST_ASSERT_TRUE(LedDriverIsOn(11));
}

TEST(LedDriver, OutOfBoundsLedsAreOff)
{
	TEST_ASSERT_FALSE(LedDriverIsOn(20));
}

