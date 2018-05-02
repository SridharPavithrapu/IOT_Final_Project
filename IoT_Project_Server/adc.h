#include <stdint.h>
#define TICKS_PER_SECOND    32768
#define ADC_READ            2
#define BATTERY_READ_INTERVAL  1*TICKS_PER_SECOND
#define REPEATING 0           /* */

void InitADCforSupplyMeasurement();
int16_t readSupplyVoltage();
