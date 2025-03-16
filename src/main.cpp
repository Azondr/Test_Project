//Aziz Önder
//THE PONG GAME

#include <Arduino.h>

void switchLED(int r, int c, bool ON);
void clearDisplay();
void drawPaddle(int pos);
void moveBall();
void refreshDisplay();

#define JOY_X A4 // X-Achse des Joysticks
#define JOY_Y A5 // Y-Achse des Joysticks

#define R0 5 // pin for row 0
#define R1 A1 // pin for row 1
#define R2 13 
#define R3 2
#define R4 6
#define R5 12
#define R6 7
#define R7 10
#define C0 A0 // pin for column 0
#define C1 8 // pin for column 1
#define C2 9 
#define C3 4
#define C4 11
#define C5 3
#define C6 A2
#define C7 A3

int row[] = {R0, R1, R2, R3, R4, R5, R6, R7};
int column[] = {C0, C1, C2, C3, C4, C5, C6, C7};

int paddlePos = 3; // Startposition des Schlägers
int ballX = 3, ballY = 3; // Startposition des Balls
int ballDirX = 1, ballDirY = 1; // Bewegungsrichtung des Balls

bool ledMatrix[8][8] = {false};

void setup() {
  pinMode(JOY_X, INPUT);
  pinMode(JOY_Y, INPUT);
  
  for (int i = 0; i < 8; i++) {
    pinMode(row[i], OUTPUT);
    digitalWrite(row[i], HIGH);
  }
  for (int i = 0; i < 8; i++) {
    pinMode(column[i], OUTPUT);
    digitalWrite(column[i], LOW);
  }
  clearDisplay();
}

void loop() {
  int joyValue = analogRead(JOY_X);
  if (joyValue < 400 && paddlePos > 0) paddlePos--; // Links bewegen
  if (joyValue > 600 && paddlePos < 5) paddlePos++; // Rechts bewegen 
  
  clearDisplay();
  drawPaddle(paddlePos);
  moveBall();
  refreshDisplay();
  delay(100); // Geschwindigkeit anpassen
}

void clearDisplay() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      ledMatrix[i][j] = false;
    }
  }
}

void switchLED(int r, int c, bool ON) {
  ledMatrix[r][c] = ON;
}

void drawPaddle(int pos) {
  switchLED(7, pos, true);
  switchLED(7, pos + 1, true);
}

void moveBall() {
  switchLED(ballY, ballX, true);
  
  ballX += ballDirX;
  ballY += ballDirY;
  
  if (ballX <= 0 || ballX >= 7) ballDirX = -ballDirX;
  if (ballY <= 0) ballDirY = -ballDirY;
  if (ballY == 6 && (ballX == paddlePos || ballX == paddlePos + 1)) ballDirY = -ballDirY; 
  
  if (ballY >= 7) {
    ballX = 3;
    ballY = 3;
    ballDirX = 1;
    ballDirY = 1;
  }
}

void refreshDisplay() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(row[i], HIGH);
    for (int j = 0; j < 8; j++) {
      digitalWrite(column[j], ledMatrix[i][j] ? LOW : HIGH);
    }
    digitalWrite(row[i], LOW);
    delay(2); 
  }
}
