#include "em_device.h"
#include "em_adc.h"
#include "em_cmu.h"

#define VINATT(ATT_FACTOR) ATT_FACTOR << _ADC_SINGLECTRLX_VINATT_SHIFT
#define VREFATT(ATT_FACTOR)ATT_FACTOR << _ADC_SINGLECTRLX_VREFATT_SHIFT

void InitADCforSupplyMeasurement()
{
  
  ADC_Init_TypeDef ADC_Defaults =ADC_INIT_DEFAULT;
  
  ADC_InitSingle_TypeDef init =ADC_INITSINGLE_DEFAULT ;
  init.negSel = adcNegSelVSS;
  init.posSel = adcPosSelAVDD;
  init.reference = adcRef5V ;

  /* Enable clock for ADC0 */
  CMU_ClockEnable(cmuClock_ADC0, true);

  /*start with defaults */
  ADC_Init(ADC0,&ADC_Defaults);
  
  ADC_InitSingle(ADC0, &init);

  ADC0->SINGLECTRLX = VINATT(12) | VREFATT(6);

   /*start  the conversion*/
 // ADC_Start(ADC0,adcStartSingle );
}
/*
   check to see if conversion is complete
*/
static inline bool ADC_SingleDataValid()
{
  return ADC0->STATUS & ADC_STATUS_SINGLEDV;
}

/*
  read ADC value  

   VFS = 2�VREF�VREFATTF/VINATTF, where
   VREF is selected in the VREFSEL bitfield, and
   VREFATTF (VREF attenuation factor) = (VREFATT+6)/24 when VREFATT is less than 13, and (VREFATT-3)/12 when VREFATT is
   greater than or equal to 13, and
   VINATTF (VIN attenuation factor) = VINATT/12, illegal settings: 0,1,2
   VREFATTF = (6+6)/24 = 0.5
   VINATTF = 12/12
   VFS = 2*5.0*0.5 = 5.0
   1.221 mV/step


*/
#define microvoltsPerStep 1221// 1322
int16_t readSupplyVoltage()
{
   unsigned int raw=0;
   unsigned int supplyVoltagemV=0;


   /* wait for conversion to complete.*/
   while((ADC_IntGet(ADC0) & ADC_IF_SINGLE) != ADC_IF_SINGLE) {
   }

   if(ADC_SingleDataValid())
   {
     raw =  ADC_DataSingleGet(ADC0);

     supplyVoltagemV = raw*microvoltsPerStep/1000UL;
     return supplyVoltagemV;
   }
   
   return -1;
   
}
