#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(LedDriver)
{
	RUN_TEST_CASE(LedDriver, LedsOffAfterInit);
	RUN_TEST_CASE(LedDriver, Turn1stLedOn);
	RUN_TEST_CASE(LedDriver, Turn1stLedOff);
	RUN_TEST_CASE(LedDriver, TurnMultipleLedsOn);
	RUN_TEST_CASE(LedDriver, TurnMultipleLedsOff);
	RUN_TEST_CASE(LedDriver, TurnAnyLedOff);
	RUN_TEST_CASE(LedDriver, TurnAllLedsOn);
	RUN_TEST_CASE(LedDriver, TurnAllLedsOff);
	RUN_TEST_CASE(LedDriver, UpperAndLowerBounds);
	RUN_TEST_CASE(LedDriver, OutOfBoundsTurnOnSafety);
	RUN_TEST_CASE(LedDriver, OutOfBoundsTurnOffSafety);
	RUN_TEST_CASE(LedDriver, OutOfBoundsTriggersRuntimeError);
	RUN_TEST_CASE(LedDriver, OutOfBoundsToDo);
	RUN_TEST_CASE(LedDriver, IsLedOn);
	RUN_TEST_CASE(LedDriver, OutOfBoundsLedsAreOff);
}

