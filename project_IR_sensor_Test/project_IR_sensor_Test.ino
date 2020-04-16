
int a[6] = {39,34,36,15,22,23};
int state = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
for(int i=0; i<6;i++)
{
  pinMode(a[i],INPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
    for(int i=0; i<6;i++)
    {
      state = digitalRead(a[i]);
      Serial.print("IR status ");
      Serial.print(i+1);
      Serial.print(" = ");
      Serial.print(state);
      Serial.print(" \n");
      delay(2000);
    }
}
