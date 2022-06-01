#include <RadioHead.h>
#include <string.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

void setup()
{
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}
void convert(String s, char *d)
{
  
  int i;
    for(i=0;i<s.length();i++)
  {
    switch(s.charAt(i)){
        case 'a': strcat(d,".- ");
          break;
        case 'b': strcat(d,"-... ");
          break;
        case 'c': strcat(d,"-.-. ");
          break;
        case 'd': strcat(d,"-.. ");
          break;
        case 'e': strcat(d,". ");
          break;
        case 'f': strcat(d,"..-. ");
          break;
        case 'g': strcat(d,"--. ");
          break;
        case 'h': strcat(d,".... ");
          break;
        case 'i': strcat(d,".. ");
          break;
        case 'j': strcat(d,".--- ");
          break;
        case 'k': strcat(d,"-.- ");
          break;
        case 'l': strcat(d,".-.. ");
          break;
        case 'm': strcat(d,"-- ");
          break;
        case 'n': strcat(d,"-. ");
          break;
        case 'o': strcat(d,"--- ");
          break;
        case 'p': strcat(d,".--. ");
          break;
        case 'q': strcat(d,"--.- ");
          break;
        case 'r': strcat(d,".-. ");
          break;
        case 's': strcat(d,"... ");
          break;
        case 't': strcat(d,"- ");
          break;
        case 'u': strcat(d,"..- ");
          break;
        case 'v': strcat(d,"...- ");
          break;
        case 'w': strcat(d,".-- ");
          break;
        case 'x': strcat(d,"-..- ");
          break;
        case 'y': strcat(d,"-.-- ");
          break;
        case 'z': strcat(d,"--.. ");
          break;
        case '1': strcat(d,".---- ");
          break;
        case '2': strcat(d,"..--- ");
          break;
        case '3': strcat(d,"...-- ");
          break;
        case '4': strcat(d,"....- ");
          break;
        case '5': strcat(d,"..... ");
          break;
        case '6': strcat(d,"-.... ");
          break;
        case '7': strcat(d,"--... ");
          break;
        case '8': strcat(d,"---.. ");
          break;
        case '9': strcat(d,"----. ");
          break;
        case '0': strcat(d,"----- ");
          break;
        case '\0': break;
        case '\n': strcat(d,"\n");
        default: strcat(d,"\t ");
          break;
      }
  }
}
void loop()
{
   if(Serial.available() > 0)
   { String mesaj;
    int i;
    char msg[255];
    mesaj=Serial.readString();
    Serial.println(mesaj);
    convert(mesaj,msg);
    //mesaj.toCharArray(msg,255);
    Serial.println(msg);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
   }
   /*while(Serial.available() > 0){
    char t = Serial.read();
  }*/
}
/*
void loop()
{
  if(Serial.available() > 0)
  {
    char msg_1 = Serial.read();
    const char msg = msg_1;   
    driver.send((uint8_t )&msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
    
  }
  
}*/
