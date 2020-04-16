#include <WiFi.h>
#include <FirebaseESP32.h>

//-------------------------------------------------------------------------------1. Change the following info from firebase

#define FIREBASE_HOST "parking-tech-88362.firebaseio.com"
#define FIREBASE_AUTH "YxEJ1FoylOOimZsjfwSBEFiJe3QXaPx46nDli1qQ"
#define WIFI_SSID "Ghanshyam"
#define WIFI_PASSWORD "ghanuwifi1"


//-------------------------------------------------------------------2. Define FirebaseESP32 data object for data sending and receiving
FirebaseData firebaseData;

int fireStatus = 0;                                                     // led status received from firebase
int led = 2;  
//============================================================================================================================================================================
void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(115200);
//----------------------------------------------------------THIS PART IS FOR WIFI ------------------------------------
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                  
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();


//--------------------------------------------------------------------------------------------------------------------------

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

//--------------------------------------------------------------------------------------------------------------------------

  
  //4. Enable auto reconnect the WiFi when connection lost
  Firebase.reconnectWiFi(true);
//----------------------------------------------------------------------


  //5. Try to set int data to Firebase
  //The set function returns bool for the status of operation
  //firebaseData requires for sending the data
 
  
  if(Firebase.setInt(firebaseData, "/ledStatus", 1))                   //--------------------THis is send data-----------------             
  {
    //Success
     Serial.println("Set int data success");

  }else{
    //Failed?, get the error reason from firebaseData

    Serial.print("Error in setInt, ");
    Serial.println(firebaseData.errorReason());
  }


  //6. Try to get int data from Firebase
  //The get function returns bool for the status of operation
  //firebaseData requires for receiving the data
  
  if(Firebase.getInt(firebaseData, "/ledStatus"))                 //---------------------this will recieve data------------------
  {
    //Success
    Serial.print("Get int data success, int = ");
    Serial.println(firebaseData.intData());

  }else{
    //Failed?, get the error reason from firebaseData

    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  }

  /*
  In case where you want to set other data types i.e. bool, float, double and String, you can use setBool, setFloat, setDouble and setString.
  If you want to get data which you known its type at specific node, use getInt, getBool, getFloat, getDouble, getString.
  If you don't know the data type at specific node, use get and check its type.
  The following shows how to get the variant data
  */

/* if(Firebase.get(firebaseData, "/ledstatus"))
  {
    //Success
    Serial.print("Get variant data success, type = ");
    Serial.println(firebaseData.dataType());

    if(firebaseData.dataType() == "int"){
      Serial.print("data = ");
      Serial.println(firebaseData.intData());
    }else if(firebaseData.dataType() == "bool"){
      if(firebaseData.boolData())
        Serial.println("data = true");
      else
        Serial.println("data = false");
    }

  }else{
    //Failed?, get the error reason from firebaseData

    Serial.print("Error in get, ");
    Serial.println(firebaseData.errorReason());
  }
*/
  /*
  If you want to get the data in realtime instead of using get, see the stream examples.
  If you want to work with JSON, see the FirebaseJson, jsonObject and jsonArray examples.
  If you have questions or found the bugs, feel free to open the issue here https://github.com/mobizt/Firebase-ESP32
  */




}

void loop()
{

   if(Firebase.getInt(firebaseData, "/ledStatus"))                 //---------------------this will recieve data------------------
  {
    //Success
    Serial.print("Get int data success, int = ");
    Serial.println(firebaseData.intData());
    fireStatus = firebaseData.intData(); 
    
    if (fireStatus == 1) 
    {                                                          // compare the input of led status received from firebase
       Serial.println("Led Turned ON");                         
       digitalWrite(led, HIGH);                                                         // make external led ON
    } 
    else if (fireStatus == 0) 
    {                                                  // compare the input of led status received from firebase
       Serial.println("Led Turned OFF");
       digitalWrite(led, LOW);                                                         // make external led OFF
    }
    else 
    {
       Serial.println("Wrong Credential! Please send ON/OFF");
    }

  }
  else
  {
    //Failed?, get the error reason from firebaseData

    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  }
   
}
