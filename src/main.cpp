//Aziz Önder
//I LOVE ESY
//22.03.2025

#include <Arduino.h>

void switchLED(int r, int c, bool ON);
void clearDisplay();

#define R0 5 
#define R1 A1 
#define R2 13 
#define R3 2
#define R4 6
#define R5 12
#define R6 7
#define R7 10
#define C0 A0 
#define C1 8
#define C2 9 
#define C3 4
#define C4 11
#define C5 3
#define C6 A2
#define C7 A3


int R[] = {5,A1,13,2,6,12,7,10};  
int C[] = {A0,8,9,4,11,3,A2,A3}; 


  
unsigned char I[8][8] =      //Das "I"
{  
  0,0,0,1,1,0,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,1,1,0,0,0,  
};  

unsigned char Herz[8][8] =     //Das Herz  
{  
  0,0,0,0,0,0,0,0,  
  0,1,1,0,0,1,1,0,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  0,1,1,1,1,1,1,0,  
  0,0,1,1,1,1,0,0,  
  0,0,0,1,1,0,0,0,  
};  

unsigned char E[8][8] =      //Das "E"
{  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,0,0,0,0,0,0,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,0,0,0,0,0,0,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
};  

unsigned char S[8][8] =      //Das "S"
{  
  0,0,0,1,1,0,0,0,  
  0,0,1,0,0,1,0,0,  
  0,0,1,0,0,0,0,0,  
  0,0,0,1,0,0,0,0,  
  0,0,0,0,1,0,0,0,  
  0,0,0,0,0,1,0,0,  
  0,0,1,0,0,1,0,0,  
  0,0,0,1,1,0,0,0,  
};  

unsigned char Y[8][8] =      //Das "Y"
{  
  1,1,0,0,0,0,1,1,  
  0,1,1,0,0,1,1,0,  
  0,0,1,1,1,1,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,1,1,0,0,0,  
};  
void Clear()                 //Alle LEDS ausschalten
{  
  for(int i = 0;i<8;i++)  
  {  
    digitalWrite(R[i],LOW);  
    digitalWrite(C[i],HIGH);  
  }  
}

void Display(unsigned char dat[8][8])    
{  
  for(int c = 0; c<8;c++)  
  {  
    digitalWrite(C[c],LOW);             //Die Spalten werden ausgeschalten
   
    for(int r = 0;r<8;r++)  
    {  
      digitalWrite(R[r],dat[r][c]);     //Das Muster wird auf die Reihe "übertragen"
    }  
    delay(1);  
    Clear();  //Alle LEDS auschalten
  }  
}  
void setup()  
{  
   
  for(int i = 0;i<8;i++)  
  
  {  
  //Alle Pins als OUTPUT definieren

    pinMode(R[i],OUTPUT);  
    pinMode(C[i],OUTPUT);  
  }  
}  
  
void loop()  
{  
  for(int i = 0 ; i < 150 ; i++)         //Definiert wie lange der jeweilige Buchstabe angezeigt wird
  {     
    Display(I);                 //Das I anzeigen
  }
  for(int i = 0 ; i < 150 ; i++)        //Definiert wie lange der jeweilige Buchstabe angezeigt wird
  {  
    Display(Herz);                   //Das Herz anzeigen
  }  
  for(int i = 0 ; i < 150 ; i++)         //Definiert wie lange der jeweilige Buchstabe angezeigt wird
  {     
    Display(E);                 //Das E anzeigen
  } 
  for(int i = 0 ; i < 150 ; i++)         //Definiert wie lange der jeweilige Buchstabe angezeigt wird
  {     
    Display(S);                 //Das S anzeigen
  }  
  for(int i = 0 ; i < 150 ; i++)         //Definiert wie lange der jeweilige Buchstabe angezeigt wird
  {     
    Display(Y);                 //Das Y anzeigen
  }  
}  
  

  
