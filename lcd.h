/* 
 * File:   lcd.h
 * Author: Ajit Jadhav
 *
 * Created on 14 March, 2016, 6:51 PM
 */

#ifndef LCD_H
#define	LCD_H

void lcdcmd(unsigned char);
void lcddata(unsigned char);
void lcdinit();
void lcdstring(unsigned char*);

#endif	/* LCD_H */

