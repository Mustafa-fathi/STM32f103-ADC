#ifndef MADC_interface_h
#define MADC_interface_h


void MADC_init(void);



u16 MADC_startADConversion(void);

u16 MADC1_getdata(void);

void (* MADC1_callback)(void);
void set_callback(void (*ptr) (void));

#endif
