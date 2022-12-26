/*
 * File:   main.c
 * Author: Phil Glazzard
 * MPLABX IDE v6.00
 * XC8 v2.36
 * Optimisations 0
 *
 * Created on 11 December 2022, 18:23
 * 
 * * *                  16f1459
 *                  ---------
 *   +5 Volts    1 |Vdd      | 20 0 Volts
    DOWN BUTTON  2 |RA5   RA0| 19   
 *    UP BUTTON  3 |RA4   RA1| 18   
      MCLR       4 |RA3      | 17  
 *               5 |RC5   RC0| 16 
 *               6 |RC4   RC1| 15  
 *               7 |RC3   RC2| 14  
 *               8 |RC6   RB4| 13  SDA
  DIAGNOSTIC LED 9 |RC7   RB5| 12  ENT BUTTON
 *    TX        10 |RB7   RB6| 11  SCL
 *                  ---------
 * 
 */


#include <xc.h>
#include "config.h"
#include "constants.h"
#include "configOsc.h"
#include "configPins.h"
#include "configSPI.h"
#include "configEUSART.h"
#include "configBaud.h"
#include "configPCD8544.h"
#include "clearPCD8544.h"
#include "setAddress.h"
#include "writeCommand.h"
#include "writeData.h"
#include "select0To47.h"

void main(void) 
{
    int8_t angle;
    uint8_t col = 0;
    int8_t row = 0;
    pageToRow ypixel;

    uint8_t radius;
   
    configOsc();
    configPins();
    configSPI();
    configEUSART();
    configBaud();
    printf("hello Phil\n");
    configPCD8544();
    __delay_ms(1000);
   clearPCD8544();
   
   /*for(angle = 0; angle <=45; angle++)
   {
        for(radius = 0; radius <50; radius = radius + 1)
        {
            col = 42 + (radius * sineLookUp[angle]);
            row = -10 + (radius * cosineLookUp[angle]);
            if(row<0)
                continue;
       
       
            //col = col*cos(theta) - row*sin(theta);
            //row = col*cos(theta) + row*sin(theta);
            select0To47(row, &ypixel);
            writeCommand(0x22); //horizontal addressing
            setAddress(col,ypixel.page);
            writeData(ypixel.byte);
        }
 __delay_ms(200);
   clearPCD8544();  
    *  }*/
   
   for(col = 0; col < 84; col++)
   {
       //for(page = 0; page < 6; page++)
       //{
           writeCommand(0x20); //horizontal addressing
           writeData(quad_Bitmap[col]);
       //}
   }
   setAddress(0,1);    // col, page
   for(col = 84; col < 168; col++)
   {
       //for(page = 0; page < 6; page++)
       //{
           writeCommand(0x20); //horizontal addressing
           writeData(quad_Bitmap[col]);
       //}
   }
    setAddress(0,2);    // col, page
   for(col = 168; col < 255; col++)
   {
       //for(page = 0; page < 6; page++)
       //{
           writeCommand(0x20); //horizontal addressing
           writeData(quad_Bitmap[col]);
       //}
   }
    while(1)
    {
      /*  LATCbits.LATC4 = HI;
        __delay_ms(500);
        LATCbits.LATC4 = LO;
        __delay_ms(500);*/
        
    }
    
}
