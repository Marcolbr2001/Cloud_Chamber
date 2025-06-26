 //Versione 1.0.1
#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>   // Hardware-specific library
//https://github.com/prenticedavid/MCUFRIEND_kbv/blob/master/MCUFRIEND_kbv.cpp
//https://www.hackster.io/electropeak/ultimate-beginner-s-guide-to-run-tft-lcd-displays-by-arduino-081006
//#include <SWIFT.h>
#include <SPI.h>
#include <Wire.h>
#include "math.h"
#include <stdint.h>
#include <EEPROM.h>

MCUFRIEND_kbv tft;


////////////////////////////// TEMPERATURA //////////////////////
#include <OneWire.h>
#include <DallasTemperature.h>

#define SENSOR1_BUS_PIN 24
#define SENSOR2_BUS_PIN 26
#define SENSOR3_BUS_PIN 28

#define SENSOR4_BUS_PIN 32
#define SENSOR5_BUS_PIN 34

OneWire oneWire1(SENSOR1_BUS_PIN); //Creiamo istanza OneWire per utilizzare il canale di comunicazione
DallasTemperature sensor1(&oneWire1); //Passiamo il canale di comunicazione alla libreria della Dallas
OneWire oneWire2(SENSOR2_BUS_PIN); //Creiamo istanza OneWire per utilizzare il canale di comunicazione
DallasTemperature sensor2(&oneWire2); //Passiamo il canale di comunicazione alla libreria della Dallas
OneWire oneWire3(SENSOR3_BUS_PIN); //Creiamo istanza OneWire per utilizzare il canale di comunicazione
DallasTemperature sensor3(&oneWire3); //Passiamo il canale di comunicazione alla libreria della Dallas

OneWire ds(SENSOR4_BUS_PIN); //Creiamo istanza OneWire per utilizzare il canale di comunicazione
//DallasTemperature sensor4(&oneWire4); //Passiamo il canale di comunicazione alla libreria della Dallas
OneWire ds1(SENSOR5_BUS_PIN); //Creiamo istanza OneWire per utilizzare il canale di comunicazione
//DallasTemperature sensor5(&oneWire5); //Passiamo il canale di comunicazione alla libreria della Dallas
//////////////////////////////////////////////////////



//Font
#include <FreeDefaultFonts.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>


//immagini schermi
#include "images.c"


/* some RGB color definitions */
#define Black           0x0000      /*   0,   0,   0 */
#define Navy            0x000F      /*   0,   0, 128 */
#define DarkGreen       0x03E0      /*   0, 128,   0 */
#define DarkCyan        0x03EF      /*   0, 128, 128 */
#define Maroon          0x7800      /* 128,   0,   0 */
#define Purple          0x780F      /* 128,   0, 128 */
#define Olive           0x7BE0      /* 128, 128,   0 */
#define LightGrey       0xC618      /* 192, 192, 192 */
#define DarkGrey        0x7BEF      /* 128, 128, 128 */
#define Blue            0x001F      /*   0,   0, 255 */
#define Green           0x07E0      /*   0, 255,   0 */
#define Cyan            0x07FF      /*   0, 255, 255 */
#define Red             0xF800      /* 255,   0,   0 */
#define Magenta         0xF81F      /* 255,   0, 255 */
#define Yellow          0xFFE0      /* 255, 255,   0 */
#define White           0xFFFF      /* 255, 255, 255 */
#define Orange          0xFD20      /* 255, 165,   0 */
#define GreenYellow     0xAFE5      /* 173, 255,  47 */
#define Pink            0xF81F

//color for main menu
int coloraria=tft.color565(218,234,236), colorramner=tft.color565(0,0,0), colorpelt=tft.color565(230,230,230), colorram=tft.color565(232,146,15), coloracq=tft.color565(103,248,255),colorpeloff=tft.color565(255,87,87);


//Touchscreen
#include <TouchScreen.h>
//definition of touchscreen object
const int XP=9,YP=A2,XM=A3,YM=8;
const int TS_LEFT=70,TS_RT=960,TS_TOP=120,TS_BOT=920;
#define MINPRESSURE 10
#define MAXPRESSURE 1000
TouchScreen ts=TouchScreen(XP,YP,XM,YM,300);
uint16_t xpos, ypos;  //screen coordinates


//variabili per definzione e orientamento dello schermo
uint16_t ID;
uint8_t Orientation = 1;


//costanti e vettore per la funzione Loading
#define PI 3.1415926535897932384626433832795
int col[8];
int colorLineValGraf=LightGrey;


//Variabili per la temperatura acqua
int val_ott_ac=20, errac=15;
float Temp1=10, Temp2=50;
const int mintemp=10, maxtemp=50;
#define CTA 30//definisco la cardinalità del vettore per il grafico della temperatura dell'acqua
float graficoTA[CTA];
int colorTermA1=Blue, colorTermA2=Blue, colorGrafA=Blue,colorGrafAOtt=Green;
int numciclipreimmTA=2;//definisco il numero di rilevazioni prima di inserire il dato nel grafico
int X0TA=220,Y0TA=270, lungGrafTA=240, altGrafTA=240;//valori inziali e altezze del grafico
float digitalReadAcqua1Prec=val_ott_ac,digitalReadAcqua2Prec=val_ott_ac;


//Variabili temperatura rame
int val_ott_rn=-10, val_ott_r1=10, val_ott_r2=30;
int errrn=10,errr1=10,errr2=10;
float Tempr1,Tempr2,TemprN,Temp;
const int mintempr=-20, maxtempr=80;
#define CTR 45//definisco la cardinalità del vettore per il grafico della temperatura del rame
float grafico1[CTR],grafico2[CTR],graficoN[CTR];//array per i grafici
int colorTermR1=Blue, colorTermR2=Blue, colorGrafTT1=Blue, colorGrafTT2=Red,colorGrafTTN=Purple;
int numciclipreimmTR=1;//definisco il numero di rilevazioni prima di inserire il dato nel grafico
int X0TR=160,Y0TR=230, lungGrafTR=300, altGrafTR=180;//valori inziali e altezze del grafico
int XCTR1=70,YCTR1=230;//x ed y dei centri dei termometri del rame
int RETR1=30,RITR1=22,HTR1=110;//Valori di raggi e altezze dei disegni dei termomtri

//Variabili grafico totale
int X0TT=50,Y0TT=260, lungGrafTT=400, altGrafTT=180;//valori inziali e altezze del grafico


//VAraibili alcol
const int AOUTpin = A6;//pin analogico A0
//const int DOUTpin =33;//pin digitale D33
//int limit;
float value;
float val_ott=83;
float erassol=10;
#define CA 30//definisco la cardinalità del vettore per il grafico dell'alcol
float graficoAl[CA];
int colorSfondoDisAl=LightGrey, colorminvalott=Blue, colorvalott=Green, colormaggvalott=Red, colorvalottLine=Pink, colorvalottgafLine=Green, colorGrafAl=Red,colorCenterA=White;
int numciclipreimmA=1;//definisco il numero di rilevazioni prima di inserire il dato nel grafico
int lungGrafA=200,altGrafA=260;
int X0A=260, Y0A=275;
int CccAX=125,CccAY=180,ReccA=100,RiccA=80;

//controllo accensione peltier
bool pelt1acc=false,pelt2acc=false,pelt3acc=false,pelt4acc=false,peltonaacc=false,Electricfield=true,led=true;

//controllo valori al di fuori
bool alcprec=false, rnprec=false,r1prec=false,r2prec=false,acprec=false;

bool posmenu=true;

//variabili per sensori
float digitalReadAlcol;
float digitalReadRameNero;
float digitalReadRame1;
float digitalReadRame2;
float digitalReadAcqua1;
float digitalReadAcqua2;
bool digitalR1,digitalR2,digitalRN;

bool funzr1=false,funzr2=false,funzrn=false;

//contatori per i grafici
int contAl=0, contvAl=0;
int contTA=0, contvTA=0;
int contR=0, contvR=0;
float epsilon=0.5;//variabile per spessore grafico cartesiano

//contatore per i valori al di fuori della norma
int numer=0,numerprec=0;
bool disegnocasetta=false;
int senser=0,senserprec=0;;

//variabili per pressioni touchscreen
int Menu=0;
bool Back=false;


int relay1 = 31;   // PIN a cui è connesso il relay ad Arduino
int relayPeltier1 = 33;   // PIN a cui è connesso il relay ad Arduino
int relayPeltier2 = 35;   // PIN a cui è connesso il relay ad Arduino
int relayPeltier3 = 37;   // PIN a cui è connesso il relay ad Arduino
int relayPeltier4 = 41;   // PIN a cui è connesso il relay ad Arduino

int relayin3 = 43;   // PIN a cui è connesso il relay ad Arduino
int relayin2 = 45;   // PIN a cui è connesso il relay ad Arduino
int relayin1 = 47;   // PIN a cui è connesso il relay ad Arduino
int relaypiccoloin2 = 51;   // PIN a cui è connesso il relay ad Arduino
int relaypiccoloin1 = 53;   // PIN a cui è connesso il relay ad Arduino




float getTemp1(){
  //returns the temperature from one DS18B20 in DEG Celsius
 
  byte data[12];
  byte addr[8];
 
  if ( !ds.search(addr)) {
      //no more sensors on chain, reset search
      ds.reset_search();
      return -1000;
  }
 
  if ( OneWire::crc8( addr, 7) != addr[7]) {
      //Serial.println("CRC is not valid!");
      return -1000;
  }
 
  if ( addr[0] != 0x10 && addr[0] != 0x28) {
      //Serial.print("Device is not recognized");
      return -1000;
  }
 
  ds.reset();
  ds.select(addr);
  ds.write(0x44,1); // start conversion, with parasite power on at the end
 
  byte present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE); // Read Scratchpad
 
  for (int i = 0; i < 9; i++) { // we need 9 bytes
    data[i] = ds.read();
  }
 
  ds.reset_search();
 
  byte MSB = data[1];
  byte LSB = data[0];
 
  float tempRead = ((MSB << 8) | LSB); //using two's compliment
  float TemperatureSum = tempRead / 16;
 
  return TemperatureSum;
 
}
float getTemp2(){
  //returns the temperature from one DS18B20 in DEG Celsius
 
  byte data[12];
  byte addr[8];
 
  if ( !ds1.search(addr)) {
      //no more sensors on chain, reset search
      ds1.reset_search();
      return -1000;
  }
 
  if ( OneWire::crc8( addr, 7) != addr[7]) {
      //Serial.println("CRC is not valid!");
      return -1000;
  }
 
  if ( addr[0] != 0x10 && addr[0] != 0x28) {
      //Serial.print("Device is not recognized");
      return -1000;
  }
 
  ds1.reset();
  ds1.select(addr);
  ds1.write(0x44,1); // start conversion, with parasite power on at the end
 
  byte present = ds1.reset();
  ds1.select(addr);    
  ds1.write(0xBE); // Read Scratchpad
 
  for (int i = 0; i < 9; i++) { // we need 9 bytes
    data[i] = ds1.read();
  }
 
  ds1.reset_search();
 
  byte MSB = data[1];
  byte LSB = data[0];
 
  float tempRead = ((MSB << 8) | LSB); //using two's compliment
  float TemperatureSum = tempRead / 16;
 
  return TemperatureSum;
 
}
void setup() {
  /////////// Inizializzazione seriale sensori/////////////////
  Serial.begin(9600);
  sensor1.begin(); //Sensore Temp
  sensor2.begin(); 
  sensor3.begin(); 


  /////////////////////////////////////////////////////
  
  tft.reset();
  ID = tft.readID();
  tft.begin(ID);

  col[0] = tft.color565(155, 0, 50);
  col[1] = tft.color565(170, 30, 80);
  col[2] = tft.color565(195, 60, 110);
  col[3] = tft.color565(215, 90, 140);
  col[4] = tft.color565(230, 120, 170);
  col[5] = tft.color565(250, 150, 200);
  col[6] = tft.color565(255, 180, 220);
  col[7] = tft.color565(255, 210, 240);

//  pinMode(DOUTpin, INPUT); //DOUT input

  pinMode(relay1, OUTPUT);      // Imposta l'uscita del PIN
  pinMode(relayPeltier1, OUTPUT);      // Imposta l'uscita del PIN
  pinMode(relayPeltier2, OUTPUT);      // Imposta l'uscita del PIN
  pinMode(relayPeltier3, OUTPUT);      // Imposta l'uscita del PIN
  pinMode(relayPeltier4, OUTPUT);      // Imposta l'uscita del PIN
  pinMode(relayin3, OUTPUT);
  pinMode(relayin2, OUTPUT);
  pinMode(relayin1, OUTPUT);
  pinMode(relaypiccoloin2, OUTPUT);
  pinMode(relaypiccoloin1, OUTPUT);

  digitalWrite(relay1,HIGH);
  digitalWrite(relayPeltier1, HIGH);
  digitalWrite(relayPeltier2, HIGH);
  digitalWrite(relayPeltier3, HIGH);
  digitalWrite(relayPeltier4, LOW);
  digitalWrite(relayin3, HIGH);
  digitalWrite(relayin2, LOW);
  digitalWrite(relayin1, HIGH);

  
  tft.setFont(&FreeSans12pt7b);
  tft.setRotation(Orientation);
  tft.setTextSize(4);
  tft.setCursor(0,70);
  tft.print("CAMERA A NEBBIA");

  /*for (int i=0;i<=400;i++)
  {
    tft.fillRect(40,300,i,10,White);
  }*/
  delay(500);

  
  
  drawMainMenu();
  
  
}

void loop() {
  randomSeed(millis());

  

  
  ///MAPPATURA TOUCHESCRREEN
  touchmap();

  //////// FUNZIONE per contollo dei valori e inserimento nel grafico
  control();
  touchmap();

  switch(Menu)
  {
    case(1)://alcol
      Menu=0;
      percentualealcol();
      break;
    case(2)://piastra nera 
      Menu=0;
      temperaturaramenero();
      break;
    case(3):
      Menu=0;
      if(pelt1acc)
      {
        tft.fillRect(36.8,100,89.6,41.6,colorpeloff);
        pelt1acc=false;
        tft.setCursor(66,113);
        tft.setTextColor(Black);
        tft.print("OFF");
        digitalWrite(relayPeltier1, HIGH); //accendi rele
      }
      else
      {
        if(peltonaacc){
        tft.fillRect(36.8,100,89.6,41.6,colorpelt); 
        pelt1acc=true;
        tft.setCursor(70,113);
        tft.setTextColor(Green);
        tft.print("ON"); 
        digitalWrite(relayPeltier1, LOW); //accendi rele
        }else{}
      }
      break;
    case(4):
      Menu=0;
      if(pelt2acc)
      {
        tft.fillRect(142.4,100,89.6,41.6,colorpeloff);
        pelt2acc=false;
        tft.setCursor(171.6,113);
        tft.setTextColor(Black);
        tft.print("OFF");
        digitalWrite(relayPeltier2, HIGH); //accendi rele

      }
      else
      {
        if(peltonaacc){
        tft.fillRect(142.4,100,89.6,41.6,colorpelt); 
        pelt2acc=true; 
        tft.setCursor(175.6,113);
        tft.setTextColor(Green);
        tft.print("ON");
        digitalWrite(relayPeltier2, LOW); //accendi rele
        }else{}
      }
      break;
    case(5):
      Menu=0;
      if(pelt3acc)
      {
        tft.fillRect(248,100,89.6,41.6,colorpeloff);
        pelt3acc=false;
        tft.setCursor(277.2,113);
        tft.setTextColor(Black);
        tft.print("OFF");
        digitalWrite(relayPeltier3, HIGH); //accendi rele
      }
      else
      {
        if(peltonaacc){
        tft.fillRect(248,100,89.6,41.6,colorpelt);
        pelt3acc=true; 
        tft.setCursor(281.2,113);
        tft.setTextColor(Green);
        tft.print("ON");
        digitalWrite(relayPeltier3, LOW); //accendi rele
        }else{}
        
      }
      break;
    case(6):
      Menu=0;
      if(pelt4acc)
      {
        tft.fillRect(353.6,100,89.6,41.6,colorpeloff);
        pelt4acc=false;
        tft.setCursor(382.8,113);
        tft.setTextColor(Black);
        tft.print("OFF");
        digitalWrite(relayPeltier4, LOW); //accendi rele
        
      }
      else
      {
        if(peltonaacc){
        tft.fillRect(353.6,100,89.6,41.6,colorpelt);
        pelt4acc=true; 
        tft.setCursor(386.8,113);
        tft.setTextColor(Green);
        tft.print("ON");
        digitalWrite(relayPeltier4, HIGH); //accendi rele
        }else{}
      }
      break;
    case(7):
      Menu=0;
      temperaturarame1();
      break;
    case(8):
      Menu=0;
      if(peltonaacc)
      {
        tft.fillRect(104,182,272,49.2,colorpeloff); 
        peltonaacc=false;
        tft.setCursor(223,198.8);
        tft.setTextColor(Black);
        tft.print("OFF");
        digitalWrite(relay1, HIGH);    // spengo relè

      }
      else
      {
        tft.fillRect(104,182,272,49.2,colorpelt); 
        peltonaacc=true; 
        tft.setCursor(227,198.8);
        tft.setTextColor(Green);
        tft.print("ON");
        digitalWrite(relay1, LOW); //accendi rele
      }
      break;
    case(9):
      Menu=0;
      temperaturarame2();
      break;
    case(10):
      Menu=0;
      temperaturacqua();
      break;
    case(11):
      Menu=0;
      Temp_gen();
      break;
    case(12):
      Menu=0;
      tft.fillRect(40,10,150,45,coloraria);
        tft.fillRect(290,10,150,45,coloraria);
        Electricfield= !Electricfield;
        if(Electricfield)
        {
          tft.drawBitmap(40,10,uparrowimg,30,45,Black);
          tft.drawBitmap(100,10,uparrowimg,30,45,Black);
          tft.drawBitmap(160,10,uparrowimg,30,45,Black);
          tft.drawBitmap(290,10,uparrowimg,30,45,Black);
          tft.drawBitmap(350,10,uparrowimg,30,45,Black);
          tft.drawBitmap(410,10,uparrowimg,30,45,Black);
          digitalWrite(relaypiccoloin1, HIGH); //accendi rele
          digitalWrite(relaypiccoloin2, LOW); //accendi rele
        }
        else
        {
          tft.drawBitmap(40,10,downarrowimg,30,45,Black);
          tft.drawBitmap(100,10,downarrowimg,30,45,Black);
          tft.drawBitmap(160,10,downarrowimg,30,45,Black);
          tft.drawBitmap(290,10,downarrowimg,30,45,Black);
          tft.drawBitmap(350,10,downarrowimg,30,45,Black);
          tft.drawBitmap(410,10,downarrowimg,30,45,Black);
          digitalWrite(relaypiccoloin1, LOW); //accendi rele
          digitalWrite(relaypiccoloin2, HIGH); //accendi rele
        }
        
        break;
     case(13):
        Menu=0;
        if(led)
        {
          digitalWrite(relayin1,LOW);
          tft.fillRect(373,183,47,47,White);
          tft.drawBitmap(373,183,lampoff,47,47,Black);
          led=false;
        }        
        else
        {
          digitalWrite(relayin1,HIGH);
          tft.fillRect(373,183,47,47,White);
          tft.drawBitmap(373,183,lampon,47,47,Black);
          led=true;
        }
        break;
     default:
        break;
  }
  ///////////////////////////////////////////////////////////////////////////////////AGGIORNAMENTO VALORI

  //aria
  touchmap();
  tft.fillRect(198,25,60,20,coloraria);
  touchmap();
  tft.setTextSize(2);
  touchmap();
  if(digitalReadAlcol>val_ott+erassol||digitalReadAlcol<val_ott-erassol)
  {
    touchmap();
    tft.setTextColor(Red);
    touchmap();
    if(!alcprec)
    {
      touchmap();
      tft.setCursor(260,25);
      touchmap();
      tft.print("%");
      touchmap();
    }
    touchmap();
    alcprec=true;
    touchmap();
  }
  else
  {
    touchmap();
    tft.setTextColor(Black);
    touchmap();
    if(alcprec)
    {
      touchmap();
      tft.setCursor(260,25);
      touchmap();
      tft.print("%");
      touchmap();
      
    }
    touchmap();
    alcprec=false;
    touchmap();
  }
  touchmap();

  touchmap();
  tft.setCursor(199,25);
  touchmap();
  if(digitalReadAlcol<99)
  {
    touchmap();
    tft.print(" ");
    touchmap();
  }   
  if(digitalReadAlcol<10)
  {
    touchmap();
    tft.print(" ");
    touchmap(); 
  }
  touchmap();   
  tft.print(digitalReadAlcol,1);
  touchmap();
  
  
  //rame nero
  touchmap();
  tft.fillRect(198,72,72,20,colorramner);
  touchmap();
  tft.setTextSize(2);
  touchmap();
  if(digitalRN)
  {
    touchmap();
    tft.fillRect(198,74,110,20,colorramner);
    touchmap();
    tft.setTextColor(Red);
    touchmap();
    tft.setCursor(210,74);
    touchmap();
    tft.print("ERROR");
    touchmap();
    funzrn=true;
    touchmap();
  }
  else
  {
    if(funzrn)
    {
      tft.fillRect(198,72,90,20,colorramner);
      touchmap();
      funzrn=false;
      touchmap();
      if(rnprec)
      {
        touchmap();
        tft.setTextColor(Red);
        touchmap();
      }
      else
      {
        touchmap();
        tft.setTextColor(White);
        touchmap();
      }  
      touchmap();    
      tft.setCursor(210,74.9);
      touchmap();
      tft.print((char)167);
      touchmap();
      tft.print("C");
      touchmap();
    }
    if(digitalReadRameNero>val_ott_rn+errrn||digitalReadRameNero<val_ott_rn-errrn)
    {
      touchmap();
      tft.setTextColor(Red);
      touchmap();
      if(!rnprec)
      {
        touchmap();
        tft.setCursor(273,75);
        touchmap();
        tft.print((char)167);
        touchmap();
        tft.print("C");
        touchmap();
      }
      touchmap();
      rnprec=true;
      touchmap();
    }
    else
    {
      touchmap();
      tft.setTextColor(White);
      touchmap();
      if(rnprec)
      {
        touchmap();
        tft.setCursor(273,75);
        touchmap();
        tft.print((char)167);
        touchmap();
        tft.print("C");
        touchmap();
      }
      touchmap();
      rnprec=false;
      touchmap();
    }

    touchmap();
    tft.setCursor(200,75);
    touchmap();
    if(digitalReadRameNero>-10)
    {
      touchmap();
      tft.print(" ");
      touchmap();
    }
    if(digitalReadRameNero>=0&&digitalReadRameNero<10)
    {
      touchmap();
      tft.print(" ");
      touchmap();
    }
    touchmap();
    tft.print(digitalReadRameNero);
    touchmap();
  }
  



  //rame 1
  touchmap();
  tft.fillRect(198,154,72,20,colorram);
  touchmap();
  tft.setTextSize(2);
  touchmap();
  if(digitalR1)
  {
    touchmap();
    tft.fillRect(198,154,110,20,colorram);
    touchmap();
    tft.setTextColor(Red);
    touchmap();
    tft.setCursor(210,154);
    touchmap();
    tft.print("ERROR");
    touchmap();
    funzr1=true;
    touchmap();
  }
  else
  {
    if(funzr1)
    {
      touchmap();
      tft.fillRect(198,154,90,20,colorram);
      touchmap();
      funzr1=false;
      touchmap();
      if(r1prec)
      {
        touchmap();
        tft.setTextColor(Red);
        touchmap();
      }   
      else
      {
        touchmap();
        tft.setTextColor(White);
        touchmap();
      }
      touchmap();  
      tft.setCursor(273,154.9);
      touchmap();
      tft.print((char)167);
      touchmap();
      tft.print("C");
      touchmap();
    }
    if(digitalReadRame1>val_ott_r1+errr1||digitalReadRame1<val_ott_r1-errr1)
    {
      touchmap();
      tft.setTextColor(Red);
      touchmap();
      if(!r1prec)
      {
        touchmap();
        tft.setCursor(273,154.9);
        touchmap();
        tft.print((char)167);
        touchmap();
        tft.print("C");
        touchmap(); 
      }
      touchmap();
      r1prec=true;
      touchmap();
    }
    else
    {
      touchmap();
      tft.setTextColor(White);
      touchmap();
      if(r1prec)
      {
        touchmap();
        tft.setCursor(273,154.9);
        touchmap();
        tft.print((char)167);
        touchmap();
        tft.print("C");
        touchmap();
      }
      touchmap();
      r1prec=false;
      touchmap();
    }
    touchmap();
    tft.setCursor(200,154.9);
    touchmap();
    if(digitalReadRame1>-10)
    {
      touchmap();
      tft.print(" ");
      touchmap();
    }
    if(digitalReadRame1>=0&&digitalReadRame1<10)
    {
      touchmap();
      tft.print(" ");
      touchmap();
    }
    touchmap();
    tft.print(digitalReadRame1);
    touchmap();
  }
  
   
  

  //rame 2
  touchmap();
  tft.fillRect(198,242,72,20,colorram);
  touchmap();
  tft.setTextSize(2);
  touchmap();
  if(digitalR2)
  {
    touchmap();
    tft.fillRect(198,242,110,20,colorram);
    touchmap();
    tft.setTextColor(Red);
    touchmap();
    tft.setCursor(210,242);
    touchmap();
    tft.print("ERROR");
    touchmap();
    funzr2=true;
    touchmap();
  }
  else
  {
    if(funzr2)
    {
      touchmap();
      tft.fillRect(198,242,90,20,colorram);
      touchmap();
      funzr2=false;
      touchmap();
      if(r2prec)
      {
        touchmap();
        tft.setTextColor(Red);
        touchmap();
      } 
      else
      {
        touchmap();
        tft.setTextColor(White);
        touchmap();
      }
      touchmap();  
      tft.setCursor(273,242);
      touchmap();
      tft.print((char)167);
      touchmap();
      tft.print("C");
      touchmap();
    }
    if(digitalReadRame2>val_ott_r2+errr2||digitalReadRame2<val_ott_r2-errr2)
    {
      touchmap();
      tft.setTextColor(Red);
      touchmap();
      if(!r2prec)
      {
        touchmap();
        tft.setCursor(273,242);
        touchmap();
        tft.print((char)167);
        touchmap();
        tft.print("C");
        touchmap();
      }
      touchmap();
      r2prec=true;
      touchmap();
    }
    else
    {
      touchmap();
      tft.setTextColor(White);
      touchmap();
      if(r2prec)
      {
        touchmap();
        tft.setCursor(273,242);
        touchmap();
        tft.print((char)167);
        touchmap();
        tft.print("C");
        touchmap();
      }
      touchmap();
      r2prec=false;
      touchmap();
    }
    touchmap();
    tft.setCursor(200,242);
    touchmap();
    if(digitalReadRame2>-10)
    {
      touchmap();
      tft.print(" ");
      touchmap();
    }   
    if(digitalReadRame2>=0&&digitalReadRame2<10)
    {
      touchmap();
      tft.print(" ");
      touchmap();
    }
    touchmap();
    tft.print(digitalReadRame2);
    touchmap();
  }
  

  
  

  //acqua
  touchmap();
  tft.fillRect(198,288,72,20,coloracq);
  touchmap();
  tft.setTextSize(2);
  touchmap();
  if(((digitalReadAcqua1+digitalReadAcqua2)/2.0)>val_ott_ac+errac||((digitalReadAcqua1+digitalReadAcqua2)/2.0)<val_ott_ac-errac)
  {
    touchmap();
    tft.setTextColor(Red);
    touchmap();
    if(!acprec)
    {
      touchmap();
      tft.setCursor(273,288);
      touchmap();
      tft.print((char)167);
      touchmap();
      tft.print("C");
      touchmap();
    }
    touchmap();
    acprec=true;
    touchmap();
  }
  else
  {
    touchmap();
    tft.setTextColor(Black);
    touchmap();
    if(acprec)
    {
      touchmap();
      tft.setCursor(273,288);
      touchmap();
      tft.print((char)167);
      touchmap();
      tft.print("C");
      touchmap();
    }
    touchmap();
    acprec=false;
    touchmap();
  }
  touchmap();
  tft.setCursor(200,288);
  touchmap();
  tft.print(" ");
  touchmap();
  if(((digitalReadAcqua1+digitalReadAcqua2)/2.0)<10.0)
  {
    touchmap();
    tft.print(" ");
    touchmap();
  }
  touchmap();  
  tft.print((digitalReadAcqua1+digitalReadAcqua2)/2.0);
  touchmap();


  


  
}
