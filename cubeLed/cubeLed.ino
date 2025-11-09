#include <SPI.h>

const int latchPin = 10;
const int layerPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

uint8_t cube[8][8];

void setup() {
  pinMode(latchPin, OUTPUT);
  
  for(int i = 0; i < 8; i++) {
    pinMode(layerPins[i], OUTPUT);
    digitalWrite(layerPins[i], LOW);
  }
  
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  renderCube();
}

void loop() {
  // clearCube();
  // delay(100);
  fillCube();
  wait(1);
  clearCube();
  apagadoTotal();
  wait(1);
  capaCapa();
  wait(1);
  //clearCube();
  //apagadoTotal();
  altNalt();
  //delay(1000);
  wait(5);
  // inv();
  // wait(2);
}

void renderCube() {
  for(uint8_t i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      digitalWrite(layerPins[j], LOW);
    }
    
    digitalWrite(latchPin, LOW);
    for(uint8_t j = 0; j < 8; j++) {
      SPI.transfer(cube[i][j]);
    }
    digitalWrite(latchPin, HIGH);
    
    digitalWrite(layerPins[i], HIGH);
    delayMicroseconds(1000);
  }
}

void inv(){
  clearCube();
  for(int i=0; i < 8; i++){
    cube[0][i] = 0xB1;
  }
}

void capaCapa(){
  for(int capa = 0; capa < 8; capa++){
    digitalWrite(layerPins[capa], HIGH);
    for (int j = 0; j < 8; j++){
      cube[capa][j] = 0xFF;
      delay(20);
    }
    digitalWrite(layerPins[capa], LOW);
    delay(25);
  }
  for(int capa = 8; capa > 0; capa--){
    digitalWrite(layerPins[capa], HIGH);
    for (int j = 8; j > 0; j--){
      cube[capa][j] = 0xFF;
      delay(20);
    }
    digitalWrite(layerPins[capa], LOW);
    delay(20);
  }
}

void altNalt(){
  for(uint8_t i = 0; i < 8; i++) {
    digitalWrite(layerPins[i], HIGH);
    for(uint8_t j = 0; j < 8; j++) {
      cube[1][j] = 0xFF;
      delay(20);
    }
    digitalWrite(layerPins[i], LOW);
  }
  clearCube();
  wait(1);
  for(uint8_t i = 0; i < 8; i++) {
    digitalWrite(layerPins[i], HIGH);
    for(uint8_t j = 0; j < 8; j++) {
      cube[1][j] = 0x1;
      delay(20);
    }
  }
  /*
  for(uint8_t i = 0; i < 8; i++) {
    for(uint8_t j = 0; j < 8; j++) {
      cube[i][j] = 0xAA;
    }
  }
  
  wait(1);
  //learCube();
  //apagadoTotal();
  for(uint8_t i = 0; i < 8; i++) {
    for(uint8_t j = 0; j < 8; j++) {
      cube[i][j] = 0x00;
    }
  }
  
  wait(2);
  for(uint8_t i = 0; i < 8; i++) {
    for(uint8_t j = 0; j < 8; j++) {
      cube[i][j] = 0xAA;
    }
  }
  */
  
}

void fillCube() {
  for(uint8_t i = 0; i < 8; i++) {
    for(uint8_t j = 0; j < 8; j++) {
      cube[i][j] = 0xFF;
    }
  }
}

void setVoxel(int x, int y, int z){
    if(x < 8 && y < 8 && z < 8) {
    cube[y][z] |= (0x01 << x);
  }
}

void clearCube() {
  for(uint8_t i = 0; i < 8; i++) {
    for(uint8_t j = 0; j < 8; j++) {
      cube[i][j] = 0x00;
    }
  }
}

void apagadoTotal() {
  
  for(int i = 0; i < 8; i++) {
    digitalWrite(layerPins[i], LOW);
  }
  
  
  digitalWrite(latchPin, LOW);
  for(int i = 0; i < 8; i++) {
    SPI.transfer(0x00);
  }
  digitalWrite(latchPin, HIGH);
}

void wait(int t){
  unsigned long start = millis();
  while(millis() - start < t * 1000) {
    renderCube();
  }
}