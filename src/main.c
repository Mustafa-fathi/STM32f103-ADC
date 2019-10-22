/*
 * main.c
 *
 *  Created on: Nov 13, 2018
 *      Author: Hampota
 *
 *      we will use ADC channel 0
 */


#include "MADC_interface.h"
#include "../../HLCD/include/LSTD_TYPES.h"
#include "../../HLCD/include/MDIO_interface.h"
#include "../../HLCD/include/MRCC_interface.h"

volatile u16 data;
/*to know the Vin = (ADC_data * Vref) / precision'
 * let Vref =3.3 - 0 =3.3
 * let ADC_data=12-bit
 * so precision = 2612 =4095
 *
 *  */
f32 vin=0;
f32 Vref=3.3;
void main(void)
{

	MRCC_Initialize();
	MRCC_EnableClock(BUS_ABP2,PERIPHERAL_ADC1);
	MRCC_EnableClock(BUS_ABP2,PERIPHERAL_GPIOA);
	MRCC_EnableClock(BUS_ABP2 , PERIPHERAL_AFIO );

	MDIO_Initialize();

	MNVK_EnableInt(18); //enable NVIC interrupt for ADC1 & ADC2
	MADC_init();

	MDIO_SetPinValue(MDIO_PORTA,2,MDIO_HIGH);


	 data = MADC1_getdata();
	      vin = (data * Vref )/ 4095;

	      if (vin>0 && vin < 1.5)
	      {
	    	  MDIO_SetPinValue(MDIO_PORTA,2,MDIO_LOW);
	      }

	      else
	      {

	    	  MDIO_SetPinValue(MDIO_PORTA,2,MDIO_HIGH);
	      }


	while(1)
	{



	}



}





