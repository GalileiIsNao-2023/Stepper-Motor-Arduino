/************************************************************************/
/*LE FUNZIONI SONO        evshield.bank_a.motorRunDegrees                                                     
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

************************************************************************/
/*
 * For beginners tutorial (and user guide) visit:
 * http://www.openelectrons.com/docs/viewdoc/25
 */

#include <Wire.h>
#include <EVShield.h>
#include <EVShieldAGS.h>
#include <EVs_EV3Color.h>
#include <EVs_NXTLight.h>
// setup for this example:
// attach EV3 Color Sensor to Port BAS1
// Open the Serial terminal to view results.
EVs_NXTLight    light1;
EVShield     evshield(0x34,0x36); //  Create shield object
//EVs_EV3Color myColor; //  Create our sensor for use in this program
//int led_a=2,led_b=3,led_c=4,led_d=5;
//bool spia=false;
int tempo = 5000;
void setup()
{
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
    Serial.begin(9600);       // start serial for output
    
    // initialize the shield i2c interface.
    
    evshield.init( SH_HardwareI2C );

    Serial.println ("--------------------------------------");
    Serial.println ("Starting EV3 Color Sensor Color Detection Test program");
    Serial.println ("--------------------------------------");

    //  initialize the sensor, and tell where it is connected.
 
 evshield.bank_a.motorReset();
 evshield.bank_b.motorReset();
 evshield.bank_a.motorRunDegrees(SH_Motor_1, 
                     SH_Direction_Forward, 
                     SH_Speed_Medium,
                     90, 
                     SH_Completion_Dont_Wait,
                     SH_Next_Action_BrakeHold);  
        evshield.bank_a.motorRunDegrees(SH_Motor_2, 
                     SH_Direction_Forward, 
                     SH_Speed_Medium,
                     90, 
                     SH_Completion_Dont_Wait,
                     SH_Next_Action_BrakeHold);   
   evshield.bank_b.motorRunDegrees(SH_Motor_1, 
                     SH_Direction_Forward, 
                     SH_Speed_Medium,
                    90, 
                     SH_Completion_Dont_Wait,
                     SH_Next_Action_BrakeHold); 

    evshield.bank_b.motorRunDegrees(SH_Motor_2, 
                     SH_Direction_Forward, 
                     SH_Speed_Medium,
                     90, 
                     SH_Completion_Dont_Wait,
                     SH_Next_Action_BrakeHold); 
  
}

void loop()
{

         
        
       Serial.println ("PORTE CHIUSE");
       
if((digitalRead(2) == 0) && (digitalRead(3) == 1) && (digitalRead(4) == LOW) && (digitalRead(5) == LOW))
{
 int y= evshield.bank_b.motorRunDegrees(SH_Motor_1, 
                     SH_Direction_Reverse, 
                     50,
                     90, 
                     SH_Completion_Dont_Wait,
                     SH_Next_Action_BrakeHold); 
                     delay(tempo);
                      Serial.println( y);

  evshield.bank_b.motorRunDegrees(SH_Motor_1, 
                     SH_Direction_Forward, 
                     SH_Speed_Medium,
                     90, 
                     SH_Completion_Dont_Wait,
                     SH_Next_Action_BrakeHold); 
                      delay(tempo);
}
                      evshield.bank_a.motorReset();
if((digitalRead(2) == 0) && (digitalRead(3) == 0) && (digitalRead(4) == LOW) && (digitalRead(5) == 1))
{
 int y= evshield.bank_b.motorRunDegrees(SH_Motor_2, 
                     SH_Direction_Reverse, 
                     50,
                     90, 
                     SH_Completion_Dont_Wait,
                     SH_Next_Action_BrakeHold); 
                     delay(tempo);
                      Serial.println( y);

  evshield.bank_b.motorRunDegrees(SH_Motor_2, 
                     SH_Direction_Forward, 
                     SH_Speed_Medium,
                     90, 
                     SH_Completion_Dont_Wait,
                     SH_Next_Action_BrakeHold); 
                      delay(tempo);
}
  if ((digitalRead(2) == HIGH) && (digitalRead(3) == LOW) && (digitalRead(4) == LOW) && (digitalRead(5) == LOW))      //apertura motore 1
    {
      Serial.println ("Motore 1 in apertura");
 int y= evshield.bank_a.motorRunDegrees(SH_Motor_1, 
                     SH_Direction_Reverse, 
                     50,
                     90, 
                     SH_Completion_Dont_Wait,
                     SH_Next_Action_BrakeHold); 
                     delay(tempo);
                      Serial.println( y);

  evshield.bank_a.motorRunDegrees(SH_Motor_1, 
                     SH_Direction_Forward, 
                     SH_Speed_Medium,
                     90, 
                     SH_Completion_Dont_Wait,
                     SH_Next_Action_BrakeHold); 
                      delay(tempo);
                      evshield.bank_a.motorReset();
        }



    if ((digitalRead(2)== LOW)  && (digitalRead(3) == 0) && (digitalRead(4) == 1) && (digitalRead(5) == LOW))    //apertura motore 2
    {
      Serial.println ("Motore 2 in apertura");
 int y= evshield.bank_a.motorRunDegrees(SH_Motor_2, 
                     SH_Direction_Reverse, 
                     50,
                     90, 
                     SH_Completion_Dont_Wait,
                     SH_Next_Action_BrakeHold); 
                     delay(tempo);
                      Serial.println( y);

  evshield.bank_a.motorRunDegrees(SH_Motor_2, 
                     SH_Direction_Forward, 
                     SH_Speed_Medium,
                     90, 
                     SH_Completion_Dont_Wait,
                     SH_Next_Action_BrakeHold); 
                      delay(tempo);
                      evshield.bank_a.motorReset();
        }


    


     
    

    delay(100);
}
