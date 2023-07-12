/*
 * TFTLCD Temp & Humidity Graph with alarm
 * with DHT11
 * 
 * learnelectronics
 * 23 JUN 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 */
 
#include <Adafruit_GFX.h>                                       //graphix library for drawing
#include <Adafruit_TFTLCD.h>                                    //LCD library to drive screen
#include "MCUFRIEND_kbv.h"
#include "DHT.h"                                                //dht library
 
// #define LCD_CS A3                                               // Chip Select goes to Analog 3
// #define LCD_CD A2                                               // Command/Data goes to Analog 2
// #define LCD_WR A1                                               // LCD Write goes to Analog 1
// #define LCD_RD A0                                               // LCD Read goes to Analog 0
 
// #define LCD_RESET A4                                            //LCD reset to analog 4
#define DHTPIN A5                                               //DHT11 on digital 53 (Mega)
#define DHTTYPE DHT11                                           //define dht type (11,21,22)
 

#define BLACK   0x0000                                          //hex colors to english
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
 
// Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET); //create instance of LCD called tft
MCUFRIEND_kbv tft(A3, A2, A1, A0, A4);
DHT dht(DHTPIN, DHTTYPE);                                       //create instance of dht called dht
 
 
 

void setup(void) {
  Serial.begin(9600);                                           //serial comms for debug
  dht.begin();
  tft.reset();                                                  //reset the screen
  tft.begin(0x9486);
  tft.width();
  tft.height();                                            //start screen using chip identifier hex

  tft.setRotation(1);                                           //set rotation for wide screen
  tft.fillScreen(YELLOW);                                        //fill screen with black (ersatz clear)
  tft.setCursor(110,100);                                        //cursor to upper left
  tft.setTextSize(2);
  tft.setTextColor(RED);
  tft.print("Welcome\n");
  tft.setCursor(70,120);
  tft.print("To Our Project!");
  delay(2000);

  tft.fillScreen(TFT_OLIVE);                                        //fill screen with black (ersatz clear)
  tft.setCursor(75,100);                                        //cursor to upper left
  tft.setTextSize(4);
  tft.setTextColor(TFT_WHITE);
  tft.print("Dr.Tarek\n");
  delay(5000);

  tft.fillScreen(TFT_CYAN);                                        //fill screen with black (ersatz clear)
  tft.setCursor(80,10);                                        //cursor to upper left
  tft.setTextSize(2);
  tft.setTextColor(TFT_BLACK);
  tft.print("Project team:\n");
  tft.setCursor(50,40);
  tft.print("1-Antonious Emad\n");
  tft.setCursor(50,60);
  tft.print("2-Paula Ayman\n");
  tft.setCursor(50,80);
  tft.print("3-Paula Emad\n");
  tft.setCursor(50,100);
  tft.print("4-Michael Samy\n");
  delay(5000);



  // pinMode(26,OUTPUT);
 
}
 
void loop(void) {
  
      tft.fillScreen(BLACK);
      tft.setTextSize(1);
      tft.setTextColor(WHITE);

      tft.setCursor(0, 70);
      tft.print("100");

      tft.setCursor(0, 80);
      tft.print("90");
      
      tft.setCursor(0, 90);
      tft.print("80");
 
      tft.setCursor(0, 100);
      tft.print("70");
 
      tft.setCursor(0, 110);
      tft.print("60");
 
      tft.setCursor(0, 120);
      tft.print("50");
 
      tft.setCursor(0, 130);
      tft.print("40");
 
      tft.setCursor(0, 140);
      tft.print("30");
 
      tft.setCursor(0, 150);
      tft.print("20");

       tft.setCursor(0, 160);
      tft.print("10");   

       tft.setCursor(0, 170);
      tft.print("0");
 
      tft.drawLine(20, 170, 319, 170, WHITE);  
                            
      tft.setCursor(0, 0);
      tft.setTextSize(1);
      tft.setTextColor(YELLOW);
      tft.print("          DHT11 Temperature & Humidity Graph");
      tft.setCursor(190,220);
      tft.setTextSize(1);
      tft.print("Supervisor: Dr.Tarek");
 
  for(int j=20;j<320;j++){
  
      int t = dht.readTemperature();
          Serial.print("Temp: ");
          Serial.println(t);
      int h = dht.readHumidity(); 
          Serial.print("Humidity: ");
          Serial.println(h);
      //  if(h>80){
      //   digitalWrite(26,HIGH);
      //   delay(500);
      //   digitalWrite(26,LOW);
      //  }
 
      tft.setTextColor(WHITE);
      tft.setCursor(0, 190);
      tft.print("Temp:    ");
      tft.setTextColor(RED);tft.print(t);
      tft.print("C");
      tft.setCursor(0,200);
      tft.setTextColor(WHITE);tft.print("Humidty: ");
      tft.setTextColor(GREEN);tft.print(h);
      tft.print("%");
 
 
      tft.drawPixel(j-1, 170-t, RED);
      tft.drawPixel(j-1, 170-h, GREEN);
 
      delay(1000);
      tft.fillRect(0, 180, 150, 50, BLACK);
      
  }
      
}