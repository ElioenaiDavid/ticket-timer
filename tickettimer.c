#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "tikect.h"
//int espera(int f,int s);

int k=0,n=0,c=0;

int func[10];
int main(void) {
	 tikectinit();
	/* global enable IRQs */
	LCD_init();

	while(1){
		erase();
		Write("uno ");
		if(func[1]){Write("dos ");}
		if(func[2]){Write("tres ");}

		func[2]=espera(5);
		func[1]=espera(10);
			delayMs(20);}
}


