#include <Servo.h>
// definning object for servo motors
Servo entryservo;
Servo exitservo;
int pos = 0; 
int i = 0;

int cm1 = 0;     // Defining variable for ultrasonic distance
int cm2 = 0;
//Defining LED to arduino pins
int led[] = {A0,A1,A2,A3,A4,A5,4,11,13,12};  
int slot = 0;
// Entry IR and Exit IR pin define
int entry1 = 2;
int exit1 = 3;



//-------------------------------------------------------------------------------------------------------READ--ULTRASONIC---------
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);  
  delayMicroseconds(2);
 
  digitalWrite(triggerPin, HIGH);   // send the ultrasound 
  delayMicroseconds(10);              // wait for 10ms
  digitalWrite(triggerPin, LOW);     
  pinMode(echoPin, INPUT);
 
  return pulseIn(echoPin, HIGH);     //recive the ultrasound 
  
  /* calculation of formula: Distance = (Time x SpeedOfSound) / 2   
     2 is in the formula because the sound has to travel back and forth.
     First the sound travels away from the sensor,
     and then it bounces off of a surface and returns back.
     
     *******speed of sound is 240m/s***********
  */
}



//-------------------------------------------------------------------------------------------------------CHECK--TRAFFIC---------
void checktraffic(int dis1, int dis2)                         //this function is use for check traffic
{
   Serial.print(" we are in check trafffic  \n");
 
  if(dis1 >= 35 && dis2 >=35)                              // if no traffic then use forward path 
  {
    forward();
  }
  else if(slot == 3 && dis1 <= 19 && dis2 >=35)         // all the else if conditions will check for traffic and
  {                            //if satisfy the condition then it will go reverse
    reverse();
  }
  else if(slot == 2 && dis1 <= 11 && dis2 >= 35)
  {
    reverse();
  }
  else if(slot == 1 && dis1 <= 5 && dis2 >= 35)
  {
    reverse();
  }
  else if(slot == 4 && dis1 >= 35 && dis2 <= 5)
  {
    reverse();
  }
  else if(slot == 5 && dis1 >= 35 && dis2 <= 11)
  {
    reverse();
  }
  else if(slot == 6 && dis1 >= 35 && dis2 <= 19)
  {
    reverse();
  }
  else                        //By default it will go forwars path
  {
    forward();
  }
}


//----------------------------------------------------------------------------------------------------------TURNOFF------
 void turnoff()                                  //Turnoff all the LEDs
 {
    Serial.print(" we are in turnoff LED \n");
    for(int i = 0; i<=9;i++)
    {
      digitalWrite(led[i],HIGH);
    }
 }

//---------------------------------------------------------------------------------------------------------FORWARD-------
 
 void forward()                            // Forward path LED glow
 {
   servoentry();                           // open the Entry gate 
    Serial.print(" we are in FORWARD LED ");       
    if(slot >= 1 && slot <= 3)               // for slot 1,2,3
    {
      for(i= 0; i <= (slot) ; i ++)
      {
        digitalWrite(led[i],LOW);
      }
    }
    else if(slot >= 4 && slot <= 6)          // for slot 4,5,6
    {
      for(i= 5; i <= (slot+2) ; i ++)
      {
        digitalWrite(led[i],LOW);
      }
    }
    delay(10000);                           // wait 10second
    turnoff();                             // turnoff all LEDs
 }

 
//---------------------------------------------------------------------------------------------------------REVERSE------
 void reverse()                           // Reverse LEDs will glow
 {    
   servoentry();                          // open the Entry gate 
    Serial.print(" we are in REVERSE LED ");
   if(slot >= 1 && slot <= 3 )             // for slot 1,2,3
    {
     for(int i = 5 ; i <= 9 ; i++)
      {
        digitalWrite(led[i],LOW);
      }
     for(int j = 4; j >= slot ; j = j-1)
     {
       digitalWrite(led[j],LOW);
     }
   }
     if(slot >= 4 && slot <= 6)           // for slot 4,5,6
    {
      for(int i = 0; i <= 4 ; i++)
      {
        digitalWrite(led[i],LOW);
      }
      for(int j = 9; j >= (slot+2) ; j = j-1)
      {
        digitalWrite(led[j],LOW);
      }
    }
    delay(10000);                        // wait 10second
    turnoff();                           // turnoff all LEDs
    
 }


 
//--------------------------------------------------------------------------------------------------------SERVO-ENTRY--------
 void servoentry()                       // this function is to control the servo motor on entry gate
 {
   for (pos = 0; pos <= 180; pos += 1) {       // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    entryservo.write(pos);                     // tell servo to go to position in variable 'pos'
    delay(15);                                 // waits 15ms for the servo to reach the position
  }
   Serial.print("entry door open ");
   while(digitalRead(entry1)==0);           // wait till vehical to pass the gate 
  delay(2000); 
  for (pos = 180; pos >= 0; pos -= 1) {        // goes from 180 degrees to 0 degrees
    entryservo.write(pos);                     // tell servo to go to position in variable 'pos'
    delay(15);                                 // waits 15ms for the servo to reach the position
  }
 }

 
//--------------------------------------------------------------------------------------------------------SERVO-EXIT--------
 void servoexit()                          // this function will controll the servo motor in exit gate
{ 
   for (pos = 0; pos <= 180; pos += 1) 
   { 
       exitservo.write(pos);              
       delay(15);                     
   }
   Serial.print("exit door open ");
   while(digitalRead(exit1)==0);               // wait till vehical to pass the gate
   delay(2000); 
   for (pos = 180; pos >= 0; pos -= 1) 
   { 
        exitservo.write(pos);              
        delay(15);
   }
}
 
//-------------------------------------------------------------------------------------------------------SETUP---------
void setup()          //this is setup function 
{
  entryservo.attach(6);      // attach servo to PWM pin 6 and 5
  exitservo.attach(5);
  
  entryservo.write(0);      //setting both servo to initial position
  delay(100);
  exitservo.write(0);
  delay(100);
  
  pinMode(entry1,INPUT);       // defining entry gate IR sensor pin to input mode
  pinMode(exit1,INPUT);         //defining exit gate IR sensor pin to input mode 
   
   for(int i = 0; i <= 9; i++)    // for loop is for defining all the LEDs to OUTPUT nmode
    {
      pinMode(led[i],OUTPUT);
    } 
  
  Serial.begin(9600);            // setting baud rate for arduino
 
  Serial.print(" we are in setup \n");
  delay(1000);
  turnoff();                      // to ensure that we have all the LEDs tuen off before entering to loop
}




//--------------------------------------------------------------------------------------------------------LOOP--------
void loop()                         // this is loop function this will run contineously
{ 
 
  
 if(digitalRead(entry1) == 0)      //check for IR sensor on Entry gate if yes then move to next step 
                                   //else loop will comeback and check again 
 {
  
   /*
NOTE  : we are here using Serial monitor to enter the parking slot 
        but in final project we will use command from NODE MCU to check for parking slot 
        using serial communication
   */
    Serial.print("Enter the Slot number : \n");      // entert the slot number in serial monitor 
     if (Serial.available() > 0)                      // this will check weather serial monitor has any input ot not 
     {                                                 // if not then it will display the above sentance contineously
                                                       // if number is entered then it will move to next step
       
        slot = Serial.parseInt();                      // thsi will read the value and store it to "Slot" variable
       if (slot >= 1 && slot <= 6)                     //  check if entered slot is within 1-6 
        {
           Serial.print("  Parking 1  \n");             // if within 1-6 then parking 1 
           Serial.print("slot number is : ");
           Serial.print(slot);
           cm2 = 0.01723 * readUltrasonicDistance(7,8 );    //Read the distsnce of ultrasonic sensor 1 and 2
           cm1 = 0.01723 * readUltrasonicDistance(9, 10);     //  and display it on serial monitor
           Serial.print("\nultrasonic distance : \n");
           Serial.println(cm1);
           Serial.println(cm2);
           
           checktraffic(cm1,cm2);                           // this will call the check traffic function  
                                   // and pass the parameter of distance we get from ultrasonic sensor
          
        }
        else if(slot == 7)                                 // if entered number is 7 which is in parking 2 
        {
            Serial.print("  Parking 2  \n");                // slot 7 is numbered as 1 is parking 2 
            Serial.print("slot number is : 1 ");            // therefore it will display as slot 1
        }
        else if(slot > 7)                                  // else invelid
        { 
             Serial.print("  invelid option  \n");
        }
    
   } 
 }
 else if(digitalRead(exit1) == 0)    // check if Exit IR sensor is high or low 
 {
  servoexit();                      // if car the there then it will open exit gate using servoexit function  
  
 }

 
}
