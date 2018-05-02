/*
 * adc.c
 *
 *  Created on: Apr 22, 2018
 *      Author: Rishi
 */
#include "adc.h"

void adc_init(void)
{
  ADC_Init_TypeDef ADCinit = ADC_INIT_DEFAULT;
  ADC_InitSingle_TypeDef singleInit = ADC_INITSINGLE_DEFAULT;

  /* Initializing the ADC */
  ADCinit.timebase = ADC_TimebaseCalc(0);
  ADCinit.prescale = ADC_PrescaleCalc(7000000, 0);
  ADC_Init(ADC0, &ADCinit);

  /* Initialize for single conversion */
  singleInit.reference = adcRefVEntropy;
  singleInit.diff = true;
  singleInit.posSel = adcPosSelVSS;
  singleInit.negSel = adcNegSelVSS;
  ADC_InitSingle(ADC0, &singleInit);

  /* Set VINATT to maximum value and clear FIFO */
  ADC0->SINGLECTRLX |= _ADC_SINGLECTRLX_VINATT_MASK;
  ADC0->SINGLEFIFOCLEAR = ADC_SINGLEFIFOCLEAR_SINGLEFIFOCLEAR;
}
