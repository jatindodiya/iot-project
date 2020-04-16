#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] =  {
                            {'1','2','3','A'},
                            {'4','5','6','B'},
                            {'7','8','9','C'},
                            {'*','0','#','D'}
                         };
byte rowPins[ROWS] = {32,33,25,26}; 
byte colPins[COLS] = {27,14,12,13};
Keypad mykeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
Serial.begin(115200);
}

void loop() 
{

char keypressed = mykeypad.getKey();

if (keypressed != NO_KEY)

{

Serial.println(keypressed);

}

}
