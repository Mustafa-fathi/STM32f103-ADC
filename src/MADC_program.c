#include "MADC_interface.h"
#include "MADC_private.h"
#include "../../HLCD/include/LSTD_TYPES.h"



volatile u16 analog_data =0;
volatile u16 counter=0;
void MADC_init(void)
{
	ADC1->ADC_CR2|=(1<<0);  /*enable ADC*/
	
	/*according to data sheet you should make a delay to stablize the ADC */
	for (u8 i=0 ; i<20 ; i++)
	{

		asm("nop");
	}

	ADC1->ADC_CR2 &=~(1<<11);  /* right alignment of data*/

	ADC1 ->ADC_CR1 |=(1<<5);  /*enable interrupt for End Of Conversion for regular channel*/

	ADC1->ADC_CR2|=(1<<2); /*enable CAlibration*/
	
	while((ADC1->ADC_CR2 & (1<<2)) != 0) ;  /*wait until CAlibration completed*/
	

	/*select the length which is 1 conversion 'we have only one channel '  */
    ADC1 ->ADC_SQR1 &=~(1<<20);
    ADC1 ->ADC_SQR1 &=~(1<<21);
    ADC1 ->ADC_SQR1 &=~(1<<22);
    ADC1 ->ADC_SQR1 &=~(1<<23);


   //  the selected channel is channel 1
    ADC1 ->ADC_SQR3 |=(1<<0);
    ADC1 ->ADC_SQR3 &=~(1<<1);
    ADC1 ->ADC_SQR3 &=~(1<<2);
    ADC1 ->ADC_SQR3 &=~(1<<3);
    ADC1 ->ADC_SQR3 &=~(1<<4);

	/*select 1.5 cycles to sample every sample*/
	ADC1->ADC_SMPR2 &=~(1<<0);
	ADC1->ADC_SMPR2 &=~(1<<1);
	ADC1->ADC_SMPR2 &=~(1<<2);
	
	//ADC1->ADC_CR2 |=(1<<23);  /*enable temperature sensor */
	
	/*Start conversion of regular channels  by making software as a trigger */
//	ADC1->ADC_CR2 |=(1<<17);
//	ADC1->ADC_CR2 |=(1<<18);
//	ADC1->ADC_CR2 |=(1<<19);
//
	
	
	
	
	
	ADC1->ADC_CR2 |=(1<<1); /*continous converstion */
	
	
	
//	ADC1->ADC_CR2 |=(1<<22); /*Start conversion of regular channels*/
	
	
}


void ADC1_2_IRQHandler(void)
{


		//check if the End of conversion is completed
		if (ADC1->ADC_SR & (1<<1))
		{
			analog_data = ADC1->ADC_DR ;
		//	ADC1->ADC_SR &=~(1<<1);
		//	ADC1->ADC_CR2 |=(1<<22); /*Start conversion of regular channels*/

		}

		else
		{
			//counter--;
			//conversion not happened
		}


		counter++;
	//MADC1_callback();


}

//take care if there is an interrupt fired after firing ADC_handeler callback will jump to garbage location
// so itis recomendded to make call_back function before initialization in main()

void set_callback(void (*ptr) (void))
{

 MADC1_callback = ptr;

}



u16 MADC1_getdata(void)
{

	return analog_data;
}
