#ifndef MADC_private_h
#define MADC_private_h

typedef struct{
	
volatile u32 ADC_SR;
volatile u32 ADC_CR1;
volatile u32 ADC_CR2;	 
volatile u32 ADC_SMPR1;
volatile u32 ADC_SMPR2;
volatile u32 ADC_JOFR1;
volatile u32 ADC_JOFR2;
volatile u32 ADC_JOFR3;
volatile u32 ADC_JOFR4;
volatile u32 ADC_HTR;
volatile u32 ADC_LTR;
volatile u32 ADC_SQR1;
volatile u32 ADC_SQR2;
volatile u32 ADC_SQR3;
volatile u32 ADC_JSQR;
volatile u32 ADC_JDR1;
volatile u32 ADC_JDR2;
volatile u32 ADC_JDR3;
volatile u32 ADC_JDR4;
volatile u32 ADC_DR;

	
}MADC_type;


#define ADC1 ((volatile MADC_type*) 0x40012400 )
#define ADC2 ((volatile MADC_type*) 0x40012800 )
#define ADC3 ((volatile MADC_type*) 0x40013C00 )







#endif