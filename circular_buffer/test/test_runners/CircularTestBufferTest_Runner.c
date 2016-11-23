#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(LedDriver)
{
	RUN_TEST_CASE(LedDriver, LedsOffAfterInit);
	RUN_TEST_CASE(LedDriver, Turn1stLedOn);
	RUN_TEST_CASE(LedDriver, Turn1stLedOff);
}

