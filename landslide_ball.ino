#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//Declare constants
LiquidCrystal_I2C lcd(0x27,20,4);
const int buttonPin=22;
const int ir1=A0;
const int ir2=A1;
const int ir3=A2;
const int ir4=A3;
const int ir5=A4;
const int ir6=A5;
const int scorelvl1=500;
const int scorelvl2=1500;
const int scorelvl3=2500;

//Declare variables
int game_time = 0;
int score = 0;
int highscore = 0;
int button,levelcounter;
int sensor1 = 0;
int sensor2 = 0;
int sensor3 = 0;
int sensor4 = 0;
int sensor5 = 0;
int sensor6 = 0;
int threshold = 400; //threshold di sensor IR
void setup() {
Serial.begin(9600);
lcd.init();
lcd.begin(20,4);
lcd.backlight(); //menyalakan lcd backlight
lcd.clear();
lcd.home();

  //7segment / LED matrix pin disini
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(14,OUTPUT);
pinMode(15,OUTPUT);
pinMode(16,OUTPUT);
pinMode(17,OUTPUT);
pinMode(18,OUTPUT);

//untuk input IR Sensor dan Start Button
pinMode(ir1,INPUT);
pinMode(buttonPin,INPUT);
 Serial.println("Welcome to Landslide Ball Game");
 sensor1 = analogRead(ir1);
    sensor2 = analogRead(ir2);
    sensor3 = analogRead(ir3);
    sensor4 = analogRead(ir4);
    sensor5 = analogRead(ir5);
    sensor6 = analogRead(ir6);
   Serial.println(sensor1);
   Serial.println(sensor2);
   Serial.println(sensor3);
   Serial.println(sensor4);
   Serial.println(sensor5);
   Serial.println(sensor6);
}

void loop() {
  // put your main code here, to run repeatedly:
 button = digitalRead(buttonPin);
 if(button == HIGH){
  Serial.println("HALO");
  game_start();
  
 }
 
 if(button == LOW){
  //DISPLAY AWAL IDLE
  Serial.println("BELOM");
  lcd.setCursor(5,0);
  lcd.print("Welcome to");
  //delay(500);
  lcd.setCursor(1,1);
  lcd.print("LANDSLIDE BALLGAME");
  lcd.setCursor(4,3);
  lcd.print("");
  delay(5000);
 game_start();
  //IDLE STATE , menyalakan hiasan lampu

  
 }

}
// level = buat mulai level aja
// game_start = buat mulai game awal2
void game_start()
{
  score = 0;
  //Serial.println("START THE GAME!");
  lcd.clear();
  lcd.setCursor(2,1);
  lcd.print("START THE GAME!");
  delay(2000);

  level1();
  if(score < scorelvl1){
    lcd.clear();
    lcd.setCursor(5,1);
    lcd.print("GAME OVER");
   // Serial.println("GAME OVER");
    delay(2000);
  }
    else{
      lcd.clear();
     lcd.setCursor(6,1);
    lcd.print("FINISH!");
    delay(2000);
    lcd.setCursor(1,2);
    lcd.print("GO TO NEXT STAGE!!");
     // Serial.println("GO TO NEXT STAGE!!");
      delay(2000);
      level1();
        if(score < scorelvl2){
          lcd.clear();
    lcd.setCursor(5,1);
    lcd.print("GAME OVER");
   // Serial.println("GAME OVER");
    delay(2000);
  }
    else{
     lcd.clear();
     lcd.setCursor(6,1);
    lcd.print("FINISH!");
    delay(2000);
    lcd.setCursor(1,2);
    lcd.print("GO TO NEXT STAGE!!");
     // Serial.println("GO TO NEXT STAGE!!");
      delay(2000);
      level1();
       if(score < scorelvl3){
        lcd.clear();
    lcd.setCursor(5,1);
    lcd.print("GAME OVER");
  // Serial.println("GAME OVER");
    delay(2000);
  }
    else{
      lcd.clear();
     lcd.setCursor(6,1);
    lcd.print("FINISH!");
    delay(2000);
    lcd.setCursor(1,2);
    lcd.print("GO TO NEXT STAGE!!");
     // Serial.println("GO TO NEXT STAGE!!");
      delay(2000);
      level1();
         if(score < highscore ){
          lcd.clear();
    lcd.setCursor(5,1);
    lcd.print("GOOD GAME");
    lcd.setCursor(5,2);
    lcd.print("THANK YOU");
   // Serial.println("GOOD GAME THANK YOU");
    delay(2000);
  }
    else{
      highscore = score;
      lcd.setCursor(3,0);
    lcd.print("YOU SET A NEW");
    lcd.setCursor(5,1);
    lcd.print("HIGH SCORE");
      Serial.println("YOU SET A NEW HIGHSCORE!\n");
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,3);
      lcd.print("HIGH SCORE:");lcd.print(highscore);
      //Serial.println("YOUR HIGH SCORE : ");
      delay(2000);
      //Serial.println(highscore);
      delay(2000);
      score = 0;
      
    }
    }
    }
    }
  return;
}

void level1(){
  game_time = 40;
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("GET READY!");
  //Serial.println("GET READY!");
  delay(2000);
  lcd.clear();
  lcd.setCursor(9,1);
  lcd.print("3!");
 //Serial.println("3");
  delay(1000);
  lcd.clear();
  lcd.setCursor(9,2);
  lcd.print("2!");
  //Serial.println("2");
  delay(1000);
  lcd.clear();
  lcd.setCursor(9,3);
  lcd.print("1!");
  //Serial.println("1");
  delay(1000);
  lcd.clear();
  lcd.setCursor(8,1);
  lcd.print("GO!!");
  //Serial.println("START LEVEL 1");
  //i=0;
  delay(500);
  lcd.clear();
  for (game_time = 40;game_time >= 0;game_time--){
    for (int y=0; y<=24; y++){
   checksensor();
    //delay(10);
  lcd.setCursor(6,1);
  lcd.print("TIME: ");
  if(game_time>9){
  lcd.print(game_time);
  } else{
    lcd.setCursor(12,1);
    lcd.print("0");
    lcd.setCursor(13,1);
    lcd.print(game_time);
  }
  Serial.println("Time : ");
    Serial.println(game_time);
    Serial.println("\n");
      delay(10);
    }
    /*{
        checksensor();
        delay (10);
        Serial.print("time: ");
        Serial.print(timer);
        Serial.print("\n");
        pixels.setPixelColor(i, pixels.Color(r,g,b)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
        i++;
        delay(10);
        
      }*/
    
  }
  return;

}
void level2(){
    Serial.println("GET READY!");
  delay(2000);
  Serial.println("3");
  delay(1000);
  Serial.println("2");
  delay(1000);
  Serial.println("1");
  delay(1000);
  Serial.println("START LEVEL 2");
  game_time = 40;
  //i=0;
  for (game_time = 40;game_time >= 0;game_time--){
    for (int y=0; y<=24; y++){
   checksensor();
   delay(10);
    Serial.println("Time : ");
    Serial.println(game_time);
    Serial.println("\n");
      delay(10);
    }
    /*{
        checksensor();
        delay (10);
        Serial.print("time: ");
        Serial.print(timer);
        Serial.print("\n");
        pixels.setPixelColor(i, pixels.Color(r,g,b)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
        i++;
        delay(10);
        
      }*/
  
    
  }
  return;

}
void level3(){
  game_time = 40;
    Serial.println("GET READY!");
  delay(2000);
  Serial.println("3");
  delay(1000);
  Serial.println("2");
  delay(1000);
  Serial.println("1");
  delay(1000);
  Serial.println("START LEVEL 1");
  //i=0;
  for (game_time = 40;game_time >= 0;game_time--){
    for (int y=0; y<=24; y++){
   checksensor();
   delay(10);
    Serial.println("Time : ");
    Serial.println(game_time);
    Serial.println("\n");
      delay(10);
    }
    /*{
        checksensor();
        delay (10);
        Serial.print("time: ");
        Serial.print(timer);
        Serial.print("\n");
        pixels.setPixelColor(i, pixels.Color(r,g,b)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
        i++;
        delay(10);
        
      }*/
   
  }
  return;
}
  void level4(){
  game_time = 40;
    Serial.println("GET READY!");
  delay(2000);
  Serial.println("3");
  delay(1000);
  Serial.println("2");
  delay(1000);
  Serial.println("1");
  delay(1000);
  Serial.println("START LEVEL 4");
  //i=0;
  for (game_time = 40;game_time >= 0;game_time--){
    for (int y=0; y<=24; y++){
   checksensor();
    delay(10);
    Serial.println("Time : ");
    Serial.println(game_time);
    Serial.println("\n");
      delay(10);
    }
  
    
  }
  return;

}

void checksensor(){//SESUAIKAN TAMBAHAN POIN DENGAN TINGKAT KESUSAHAN MEMASUKAN BOLA KE SENSOR
    sensor1 = analogRead(ir1);
    sensor2 = analogRead(ir2);
    sensor3 = analogRead(ir3);
    sensor4 = analogRead(ir4);
    sensor5 = analogRead(ir5);
    sensor6 = analogRead(ir6);
  
 // if (sensor2 < threshold){
   //   score = score + 20; //
   // }
    /*Serial.print(sensor5);/*
    if (sensor3 < threshold){
      score = score + 30; //
    }
    if (sensor4 < threshold){
      score = score + 40; //
    }
    if (sensor5 < threshold){
      score = score + 50; //
    }
    if (sensor6 < threshold){
      score = score + 60; //
    }*/
      /*if (sensor1 < threshold){
        score = score + 300;
        lcd.setCursor(5,2);
        lcd.print("SCORE: ");lcd.print(score);
        Serial.print("Score: ");
        Serial.print(score);
        Serial.print("\n");
        Serial.print(sensor1);
        delay(500);
        
      } /*else if (sensor2 < threshold){
        score = score + 150;
        lcd.setCursor(5,2);
        lcd.print("SCORE: ");lcd.print(score);
        Serial.print("Score: ");
        Serial.print(score);
        Serial.print("\n");
        Serial.print(sensor2);
        delay(10);*/
      
        if (sensor3 < threshold){
        score = score + 250;
        lcd.setCursor(5,2);
        lcd.print("SCORE: ");lcd.print(score);
        Serial.print("Score: ");
        Serial.print(score);
        Serial.print("\n");
        Serial.print(sensor3);
        delay(10);
        
      }else if (sensor4 < threshold){
        score = score + 100;
        lcd.setCursor(5,2);
        lcd.print("SCORE: ");lcd.print(score);
        Serial.print("Score: ");
        Serial.print(score);
        Serial.print("\n");
        Serial.print(sensor4);
        delay(500);
        
      }else if (sensor5 < threshold){
        score = score + 200;
        lcd.setCursor(5,2);
        lcd.print("SCORE: ");lcd.print(score);
        Serial.print("Score: ");
        Serial.print(score);
        Serial.print("\n");
        Serial.print(sensor5);
        delay(10);
        
      }
      else if (sensor6 < threshold){
        score = score + 500;
        lcd.setCursor(5,2);
        lcd.print("SCORE: ");lcd.print(score);
        Serial.print("Score: ");
        Serial.print(score);
        Serial.print("\n");
        Serial.print(sensor6);
        delay(10);
        
      }
      else if(score > 20000){
        score = 200;
      }
      else{
        delay(10);
        lcd.setCursor(5,2);
        lcd.print("SCORE: ");lcd.print(score);
        Serial.print("score: ");
        Serial.print(score);
        Serial.print("\n");
        Serial.print(sensor1);
        
        }
    }
