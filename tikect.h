/*
 * tikect.h
 *
 *  Created on: 2 nov. 2019
 *      Author: David
 */

#ifndef TIKECT_H_
#define TIKECT_H_


void LCD_init(void);
void LCD_nibble_write(unsigned char data, unsigned char control);
void LCD_data(unsigned char data);
void LCD_command(unsigned char command);
void delayUs(int n);
void delayMs(int n);
void Write(char c[32]);
void tikectinit(void);
void erase(void);
void line1(void);
void line2(void);
void cusoron(void);
void cursoroff(void);
void lefall(int p);
void rigthall(int p);
void coordinate(int x,int y);
int espera(int s);
void timer_init (void);

#endif /* TIKECT_H_ */
