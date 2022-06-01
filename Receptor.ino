#include <RadioHead.h>
#include <string.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

void setup()
{
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}
void newl(char *b)
{
  int i;
  for(i=0;i<strlen(b);i++)
    if(b[i] == '\n')
     {
      b[i] = '\0';
      break;
     }
}
void convert(String ss, char *buf)
{
  buf[0] = '\0';
  char s[255];
  char* token;
  ss.toCharArray(s,255);
  token =  strtok(s, " ");
  while(token != NULL)
  {
    if(strcmp(token,".-") == 0)
      strcat(buf,"a");
    if(strcmp(token,"-...") == 0)
      strcat(buf,"b");
    if(strcmp(token,"-.-.") == 0)
      strcat(buf,"c");
    if(strcmp(token,"-..") == 0)
      strcat(buf,"d");
    if(strcmp(token,".") == 0)
      strcat(buf,"e");
    if(strcmp(token,"..-.") == 0)
      strcat(buf,"f");
    if(strcmp(token,"--.") == 0)
      strcat(buf,"g");
    if(strcmp(token,"....") == 0)
      strcat(buf,"h");
    if(strcmp(token,"..") == 0)
      strcat(buf,"i"); 
    if(strcmp(token,".---") == 0)
      strcat(buf,"j");
    if(strcmp(token,"-.-") == 0)
      strcat(buf,"k");
    if(strcmp(token,".-..") == 0)
      strcat(buf,"l");
    if(strcmp(token,"--") == 0)
      strcat(buf,"m");
    if(strcmp(token,"-.") == 0)
      strcat(buf,"n"); 
    if(strcmp(token,"---") == 0)
      strcat(buf,"o");
    if(strcmp(token,".--.") == 0)
      strcat(buf,"p");
    if(strcmp(token,"--.-") == 0)
      strcat(buf,"q");
    if(strcmp(token,".-.") == 0)
      strcat(buf,"r");
    if(strcmp(token,"...") == 0)
      strcat(buf,"s");
    if(strcmp(token,"-") == 0)
      strcat(buf,"t"); 
    if(strcmp(token,"..-") == 0)
      strcat(buf,"u");
    if(strcmp(token,"...-") == 0)
      strcat(buf,"v");
    if(strcmp(token,".--") == 0)
      strcat(buf,"w");
    if(strcmp(token,"-..-") == 0)
      strcat(buf,"x");
    if(strcmp(token,"-.--") == 0)
      strcat(buf,"y");
    if(strcmp(token,"--..") == 0)
      strcat(buf,"z");
    if(strcmp(token,".----") == 0)
      strcat(buf,"1");
    if(strcmp(token,"..---") == 0)
      strcat(buf,"2");
    if(strcmp(token,"...--") == 0)
      strcat(buf,"3"); 
    if(strcmp(token,"....-") == 0)
      strcat(buf,"4");
    if(strcmp(token,".....") == 0)
      strcat(buf,"5");
    if(strcmp(token,"-....") == 0)
      strcat(buf,"6");
    if(strcmp(token,"--...") == 0)
      strcat(buf,"7");
    if(strcmp(token,"---..") == 0)
      strcat(buf,"8");
    if(strcmp(token,"----.") == 0)
      strcat(buf,"9");
    if(strcmp(token,"-----") == 0)
      strcat(buf,"0");
    if(strcmp(token,"\t") == 0)
      strcat(buf," ");
      
    token = strtok(NULL, " ");
  }
    
}
void loop()
{
    String buff;
    uint8_t buf[255];
    buf[0] = '\0';
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
      newl((char*)buf);
      buff = String((char *)buf);
      convert(buff,(char *)buf);
      Serial.print("Message: ");
      Serial.println((char *)buf); 
   
    }
}
