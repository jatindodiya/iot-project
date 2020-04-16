int led[] = {A0,A1,A2,A3,A4,A5,4,11,13,12};
void setup() 
{
 
    for(int i = 0; i <= 9; i++)    
    {
      pinMode(led[i],OUTPUT);
    } 
}

void loop() 
{
      for(int i = 0; i <= 9 ; i++)
      {
        digitalWrite(led[i],LOW);
        delay(1000);
      }
      for(int i = 0; i <= 9 ; i++)
      {
        digitalWrite(led[i],HIGH);
        delay(1000);
      }
}
