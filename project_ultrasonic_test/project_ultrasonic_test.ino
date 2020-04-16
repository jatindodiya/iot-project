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
int cm1 = 0;
int cm2 = 0;
void setup() {
 Serial.begin(9600);

}

void loop() {
  
            cm1 = 0.01723 * readUltrasonicDistance(7,8 );    //Read the distsnce of ultrasonic sensor 1 and 2
           cm2 = 0.01723 * readUltrasonicDistance(9, 10);     //  and display it on serial monitor
           Serial.print("\nultrasonic distance : \n");
           Serial.println(cm1);
           Serial.println(cm2);
           delay(2000);
}
