/* Light Scheduler module header file */

#ifndef uint16_t
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef unsigned char bool;
#endif


void LightScheduler_Wakeup (void);
void LightScheduler_ScheduleTurnOn (void);
void LightScheduler_RemoveSchedule (void);
