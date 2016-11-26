/* Unit tests for the Light Scheduler module */

#include "unity.h"
#include "unity_fixture.h"

#include "LightScheduler.h"
#include "LightControllerSpy.h"
#include "FakeTimeService.h"

TEST_GROUP(LightScheduler);

TEST_SETUP(LightScheduler)
{

}

TEST_TEAR_DOWN(LightScheduler)
{

}

TEST(LightScheduler, NoChangeToLightsDuringInit)
{
	TEST_ASSERT_EQUAL_INT(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastID());
	TEST_ASSERT_EQUAL_INT(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, ScheduleOnEverydayNotTimeYet)
{
	//LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
	FakeTimeService_SetDay(MONDAY);
	FakeTimeService_SetTime(1199);
	LightScheduler_Wakeup();

	TEST_ASSERT_EQUAL_INT(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastID());
	TEST_ASSERT_EQUAL_INT(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

//TEST(LightScheduler, )
//{
//}

