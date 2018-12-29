#include <SPI.h>
#include <RFID.h>
#include <Keypad.h>
#include "noteFreqs.h"

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN,RST_PIN);

int led = 7;
int power = 8; 
int serNum[5];
int cards[][5] = {
  {214,252,119,65,28}
  
};

bool access = false;

int speakerOut = 8;

int DEBUG = 0;

char incomingByte = 0;

const byte numRows= 4;
const byte numCols= 4;

byte colPins[numRows] = {14,15,16,17}; //Rows 0 to 3
byte rowPins[numCols]= {7,6,5,4}; //Columns 0 to 3

char keymap[numRows][numCols]= { 
  {'1', '2', '3', 'A'},
  
  {'4', '5', '6', 'B'},
  
  {'7', '8', '9', 'C'},
  
  {'*', '0', '#', 'D'} 
};

Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

// Setup RFID
void setup(){
    Serial.begin(9600);
    SPI.begin();
    rfid.init();   
}

char password[5];
char newPass[5];
int cnt = 0;
int nCnt = 0;
char entry[5];

void btPassword(){
        incomingByte = Serial.read();
       newPass[nCnt] = lookupAscii(incomingByte);
       nCnt++;
       
       if(nCnt == 4){
         
         password[0] = newPass[0];
         password[1] = newPass[1];
         password[2] = newPass[2];
         password[3] = newPass[3];
         
         note(C5,S);
         note(C5,S);
         note(C5,E);
         note(E5,E);
         note(D5,E);
         note(C5,Q);
         
         
         nCnt = 0;
       }
      // say what you got:
      Serial.print("I received: ");
      Serial.println(lookupAscii(incomingByte));
      Serial.println(password);
}

void btMusic(){
       incomingByte = Serial.read();
       newPass[nCnt] = lookupAscii(incomingByte);
       nCnt++;
       
       if(nCnt == 2){
         note(getNote(newPass),Q);       
         nCnt = 0;
       }
      // say what you got:
      Serial.print("I received: ");
      Serial.println(lookupAscii(incomingByte));
      Serial.println(password);
}
// :Loop and Listen for RFID  
void loop(){
    //WATCH THE SERIAL INPUT
    if (Serial.available() > 0) {
      // read the incoming byte:
//      btPassword();
      // read notes and play them
      btMusic();
    }
  
    // KEY PAD ENTRY
    char keypressed = myKeypad.getKey();
    if (keypressed != NO_KEY)
    {
      Serial.print(keypressed);
      entry[cnt] = keypressed;
      cnt++;
      if(cnt == 4){
        cnt = 0;
        for(int i = 0; i < 4; i++){ 
          if(entry[i] == password[i]){
              if(i == 3){
                  victory();
                  Serial.print("\nSuccess");
              }
          }else{
            buzz();
            Serial.print("ERROR!");
            break;
          }
        }  
      }
    }
    // RFID Card Reader
    if(rfid.isCard()){
        if(rfid.readCardSerial()){
            Serial.print(rfid.serNum[0]);
            Serial.print(" ");
            Serial.print(rfid.serNum[1]);
            Serial.print(" ");
            Serial.print(rfid.serNum[2]);
            Serial.print(" ");
            Serial.print(rfid.serNum[3]);
            Serial.print(" ");
            Serial.print(rfid.serNum[4]);
            Serial.println("");
            
            for(int x = 0; x < sizeof(cards); x++){
              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
                  if(rfid.serNum[i] != cards[x][i]) {
                      access = false;
                      break;
                  } else {
                      access = true;
                  }
              }
              if(access) break;
            }  
        }
  
       if(access){
          Serial.println("Welcome!");
          victory();
           
      } else {
          Serial.println("Not allowed!"); 
          kingdom();         
       }        
    }
    rfid.halt();
}




