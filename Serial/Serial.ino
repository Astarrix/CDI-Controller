#include <CustomSoftwareSerial.h>

#define RxPIN 4
#define TxPIN 2  // not used but have to set so it doesnt throw errors
#define EnablePIN 7
#define UsesDeadSwitch false
#define UsesSensitivityPot false

//data bits
bool button_1;
bool button_2;
byte XMovement = 0;
byte YMovement = 0;

CustomSoftwareSerial RCSerial(RxPIN, TxPIN, true); // using inverse logic

void setup() {
  Serial.begin(9600);
  RCSerial.begin(1200, CSERIAL_7N2);  // set to 7 data bits, 0 Parity Bits, 2 stop bits and at 1200 baud

  pinMode(EnablePIN, OUTPUT);  // enables sending and recieving data, no reason really not to tie it to high
  digitalWrite(EnablePIN, LOW); // this just makes sure its on and enabled correctly
  delay(1);
  digitalWrite(EnablePIN, HIGH);
}

void loop() {
  bool hasPrinted = true;
  char buffer[3];  // place to store
  while (RCSerial.available() > 0) {
    RCSerial.readBytes(buffer, 3);

    if (buffer[0] & 127) {
      button_1 = 32 & buffer[0];
      button_2 = 16 & buffer[0];
      YMovement = ((buffer[0]) << 4) + ((buffer[2]) << 0);
      XMovement = ((buffer[0]) << 6) + ((buffer[1]) << 0);
      hasPrinted = false;
    }
  }

  if (!hasPrinted) {
    Serial.print("Button 1: " + String(button_1) + "\n");
    Serial.print("Button 2: " + String(button_2) + "\n");
    Serial.print("isUp: ------------------- " + String(YMovement) + "\n");
    Serial.print("isRight: " + String(XMovement) + "\n");
    Serial.print("\n");
  }
}

/* DATA FORMAT FROM RC
        64 32  16  8  4  2  1 
Byte 0: 1  bt1 bt2 Y7 Y6 X7 X6
Byte 1: 0  X5  X4  X3 X2 X1 X0
Byte 2: 0  Y5  Y4  Y3 Y2 Y1 Y0
*/