/*
 * servo.c
 *
 *  Created on: 27 oct. 2019
 *      Author: David
 */
#include <MKL25Z4.H>
#include "tikect.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define	RS	1
#define	RW	2
#define	EN	4
int second,i;


void LCD_init(void)
{
	SIM->SCGC5 |= 0x1000;
	PORTD->PCR[0] = 0x100;
	PORTD->PCR[1] = 0x100;
	PORTD->PCR[2] = 0x100;
	PORTD->PCR[4] = 0x100;
	PORTD->PCR[5] = 0x100;
	PORTD->PCR[6] = 0x100;
	PORTD->PCR[7] = 0x100;
	PTD->PDDR = 0xF7;
	delayMs(30);
	LCD_nibble_write(0x30, 0);
	delayMs(10);
	LCD_nibble_write(0x30, 0);
	delayMs(1);
	LCD_nibble_write(0x30, 0);
	delayMs(1);
	LCD_nibble_write(0x20, 0);
	delayMs(1);
	LCD_command(0x28);
	LCD_command(0x06);
	LCD_command(0x01);
	LCD_command(0x0F);
}
void LCD_nibble_write(unsigned char data, unsigned char control)
{
	data &= 0xF0;
	control &= 0x0F;
	PTD->PDOR = data | control;
	PTD->PDOR = data | control | EN;
	delayMs(0);
	PTD->PDOR = data;
	PTD->PDOR = 0;
}
void LCD_data(unsigned char data)
{
	LCD_nibble_write(data & 0xF0, RS);
	LCD_nibble_write(data << 4, RS);
	delayMs(1);
}
void LCD_command(unsigned char command)
{
	LCD_nibble_write(command & 0xF0, 0);
	LCD_nibble_write(command << 4, 0);
	if (command < 4)
		delayMs(4);
	else
		delayMs(1);
}
void delayUs(int n)
{
	int i; int j;
	for(i = 0 ; i < n; i++) {
		for(j = 0; j < 3; j++);
	}
}
void delayMs(int n) {
	int i;
	int j;
	for(i = 0 ; i < n; i++)
		for(j = 0 ; j < 3500; j++) {
		}
}

void Write(char c[32])
{
	int i=0;
	for(i=0;c[i] !='\0'; i++)
	{
		LCD_data(c[i]);
	}
}

void erase(void){
	LCD_command(1);
}
void line1(void){
	LCD_command(0x80);
}
void line2(void){
	LCD_command(0xC0);
}
void cusoron(void){
	LCD_command(0x0E);
}
void cursoroff(void){
	LCD_command(0x0C);
}
void lefall(int p){
	for(int i=0;i<p;i++){
	LCD_command(0x18);
}
}
void rigthall(int p){
	for(int i=0;i<p;i++){
	LCD_command(0x1C);
}
}
void coordinate(int x,int y){
if(y==1){ line1();
for(int i=0;i<x;i++){
	LCD_command(0x14);
}

}else if(y==2){
	line2();

for(int i=0;i<x;i++){
	LCD_command(0x14);
}

}

}


/*
 * lcd.c
 *
 *  Created on: 2 nov. 2019
 *      Author: David
 */



void timer_init (void){
	SIM->SOPT2 |= 0x01000000; /* use MCGFLLCLK as timer counter clock */
	SIM->SCGC6 |= 0x01000000; /* enable clock to TPM0 */
	TPM0->SC = 0; /* disable timer while configuring */
	TPM0->SC = 0x07; /* prescaler /128 */
	TPM0->MOD = 0xFFFFFF; /* max modulo value *///41940000/16-1
	TPM0->SC |= 0x80; /* clear TOF */
	TPM0->SC |= 0x40; /* enable timeout interrupt */
	TPM0->SC |= 0x08; /* enable timer */
	NVIC->ISER[0] |= 0x00020000; /* enable IRQ17 (bit 17 of ISER[0]) */
}

void TPM0_IRQHandler(void) {

	i++;
	if (i==2){
	second++;
	i=0;
	}


	TPM0->SC |= 0x80; /* clear TOF */
}
int espera(int s){



		if(second>s){
			return 1;


}else{return 0;}
}

void tikectinit(void){
	__disable_irq();
		timer_init();
		__enable_irq();

}


