#include "BluetoothSerial.h"

BluetoothSerial ESP_BT; //Object for Bluetooth

String incoming;
int LED_BUILTIN = 2;

void setup() {
  Serial.begin(115200); //Start Serial monitor in 115200
  ESP_BT.begin("ESP32_cd"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");

  pinMode (LED_BUILTIN, OUTPUT);//Specify that LED pin is output
}

void loop() {

  if (ESP_BT.available()) //Check if we receive anything from Bluetooth
  {
    char A = ESP_BT.read();
    if (A != '/n') {
      incoming += String(A);
    }
    Serial.println(incoming);

    if (incoming == "on")
    {
      digitalWrite(LED_BUILTIN, HIGH);
      ESP_BT.println("LED turned ON");
      incoming = "";
    }

    if (incoming == "off")
    {
      digitalWrite(LED_BUILTIN, LOW);
      ESP_BT.println("LED turned OFF");
      incoming = "";

    }
  }
  delay(20);
}
