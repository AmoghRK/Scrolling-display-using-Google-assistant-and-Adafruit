#include <Wire.h>
#include <TimerOne.h>
#include"SPI.h"
#include <ledP10.h>

LedP10 myled;
void(*resetFunc)(void) = 0;
char msg[32];
//char oldMsg[32];
int i = 0;

void setup() {
  Wire.begin(8);                /* join i2c bus with address 8 */
  Wire.onReceive(receiveEvent); /* register receive event */
   myled.init(3,4,8,9 ,4);
  //Wire.onRequest(requestEvent); /* register request event */
  Serial.begin(9600);           /* start serial for debug */
}
void loop() {
  if (strlen(msg) > 0) // strcmp(msg, oldMsg) == 0)
  {
    Serial.println(msg);
    myled.showmsg_single_scroll(msg,5,3,0);
    //strcpy(oldMsg, msg);
    Wire.endTransmission();
    //Serial.print(oldMsg);

    //while(1);
    for (int i = 0; i < 2; i++)
    
    {
      delay(1000);
    }
   resetFunc();
  }
 // else
 // {
    // resetFunc();
    //Serial.println("Reading");
  //}
  //delay(1000);
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (0 < Wire.available()) {
    char c = Wire.read();      /* receive byte as a character */
    msg[i] = c;
    i++;

    //Serial.print(c);           /* print the character */
  }
  //Serial.print(msg);
  //Serial.println();             /* to newline */
}

// function that executes whenever data is requested from master
//void requestEvent() {
//Wire.write("Hello NodeMCU");  /*send string on request */
//}
