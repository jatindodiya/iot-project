#include <WiFi.h>
#include <FirebaseESP32.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

#define FIREBASE_HOST "parking-tech-88362.firebaseio.com"
#define FIREBASE_AUTH "YxEJ1FoylOOimZsjfwSBEFiJe3QXaPx46nDli1qQ"
#define WIFI_SSID "Ghanshyam1"
#define WIFI_PASSWORD "ghanuiloveu1"
  
FirebaseData firebaseData;

String spmessage = "";

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
Keypad mykeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );   //char keypressed = mykeypad.getKey();

int ir[6] = {39,34,36,15,22,23};              // IR sensor pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//void parkingdataupload()
//{
//    
//}
void messageupload()
{
    if(Firebase.setString(firebaseData, "/message", spmessage))                   
    {
        Serial.println("Set int data success");
    }
    else
    {
        Serial.print("Error in setString, ");
        Serial.println(firebaseData.errorReason());
    }
}

void setup()                                                              //   ----------set up-----------
{
    for(int i=0; i<6;i++)
    {
        pinMode(ir[i],INPUT);
    }
    Serial.begin(115200);
    lcd.begin(16, 2);
//    lcd.setCursor(0, 0);
//    jatin = "welcom";
//    lcd.print(jatin);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                  
    while (WiFi.status() != WL_CONNECTED){  
        Serial.print(".");
        delay(300);
        }
    spmessage = "connected";
    messageupload();
    delay(5000);
    Serial.println("Connected with IP: ");
    Serial.println(WiFi.localIP());
  
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);                       //auto connect wifi if connection lost
}
void loop()
{
    char keypressed = mykeypad.getKey();
    int tmp = mykeypad.getKey();
    spmessage = keypressed;
    messageupload();
}
