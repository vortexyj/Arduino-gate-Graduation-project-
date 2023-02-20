//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <Servo.h>
Servo servo;



// Set these to run example.
#define FIREBASE_HOST "karta-app-6bfd9-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "OCs2wWj0Cjr4Bdh7Z6mUM5nHyKnw60YWVpnwdPJ4"
#define WIFI_SSID "iPhone"
#define WIFI_PASSWORD "gehad2000"


void setup() {
  servo.attach(2); //D4
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.println(" i am in firebase's ass ");
  
}

int n = 0; 
void loop() {
  
      Serial.print( " -  i am in loop ... (");
  // set value
  // Firebase.setFloat("number", 42.0);
  // handle error
  // if (Firebase.failed()) {
  //     Serial.print("setting /number failed:");
  //     Serial.println(Firebase.error());  
  //     return;
  // }
  // delay(1000);
  
  // update value
  // Firebase.setFloat("number", 43.0);
  // handle error
  // if (Firebase.failed()) {
  //     Serial.print("setting /number failed:");
  //     Serial.println(Firebase.error());  
  //     return;
  // }
  // delay(1000);

  // get value 
  // Serial.print("number: ");
  // Serial.println(Firebase.getFloat("number"));
  // delay(1000);

  // remove value
  // Firebase.remove("number");
  // delay(1000);
  Serial.println(Firebase.getFloat("/Gate/status"));
 if (Firebase.failed()) {  
      Serial.print("setting /number failed:");  
      Serial.println(Firebase.error());    
      return;  
  }    
    if (Firebase.getInt("/Gate/status") == 0) {

      Firebase.setString("/Gate/message", "Gate Closed");
      //n++;
      Serial.println(" i am in closed )");
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      //delay(100);   

      servo.write(0);
      delay(2000);

    } else  {
      
      Serial.println(" i am in opend)");
      Firebase.setString("/Gate/message", "Gate Opened");
     // n++;
      digitalWrite(LED_BUILTIN, LOW);
      delay(1000);
      servo.write(90);
      delay(1000);
    }
    // if (n == 1) {

    //   Firebase.setString("/Gate/message", "Gate Closed");
    //   //n++;
    //   Serial.println(" i am in closed )");
    //   digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    //   delay(1000);                       // wait for a second
    //   digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    //   //delay(100);   

    //   servo.write(0);
    //   delay(2000);
    //   n=0;

    // } else {
      
    //   Serial.println(" i am in opend)");
    //   Firebase.setString("/Gate/message", "Gate Opened");
    //  // n++;
    //   digitalWrite(LED_BUILTIN, LOW);
    //   delay(1000);
    //   servo.write(90);
    //   delay(1000);
    //   n=1;
    // }
    // servo.write(90);


  // set string value
  
  // handle error
  // if (Firebase.failed()) {
  //     Serial.print("setting /message failed:");
  //     Serial.println(Firebase.error());  
  //     return;
  // }
  // delay(1000);
  
  // // set bool value
  // Firebase.setBool("truth", false);
  // // handle error
  // if (Firebase.failed()) {
  //     Serial.print("setting /truth failed:");
  //     Serial.println(Firebase.error());  
  //     return;
  // }
  // delay(1000);

  // append a new value to /logs
  // String name = Firebase.pushInt("logs", n++);
  // // handle error
  // if (Firebase.failed()) {
  //     Serial.print("pushing /logs failed:");
  //     Serial.println(Firebase.error());  
  //     return;
  // }
  // Serial.print("pushed: /logs/");
  // Serial.println(name);
  // delay(1000);
}
