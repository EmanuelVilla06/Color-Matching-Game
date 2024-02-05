// C++ code
//
void setup()
{
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  
  randomSeed(analogRead(A0));
}

int j,i,k,h,d,a,e;
int colorindex = -1;
int colorfound = 0;
int matchnum = 0;
int x = 0;
int y = 0;
int colors[] = {8, 9, 10};
int leds[6];
int ledsPos[] = {0, 1, 2, 3, 4, 5};
int colorsChosen[3];
int colorx[6];

void playerInput(int a){
  if (ledsPos[a] == 0 || ledsPos[a] == 1) {
    digitalWrite(colors[0],1);
    delay(1000);
    digitalWrite(colors[0],0);
  }
  if (ledsPos[a] == 2 || ledsPos[a] == 3) {
    digitalWrite(colors[1],1);
    delay(1000);
    digitalWrite(colors[1],0);
  }
  if (ledsPos[a] == 4 || ledsPos[a] == 5) {
    digitalWrite(colors[2],1);
    delay(1000);
    digitalWrite(colors[2],0);
  }
}

void loop() { 
  
  if (digitalRead(A2) == 1) {
    
    e = 1;
    //shuffles colors array
    const int questionCountColors = sizeof colors / sizeof colors[0];
    for (int j = 0; j < questionCountColors; j++) {
      long x = random(0, questionCountColors);
      int tempC = colors[x];
      colors[x] = colors[j];
      colors[j] = tempC;
    }
    
    colorx[0] = colors[0];
    colorx[1] = colors[0];
    colorx[2] = colors[1];
    colorx[3] = colors[1];
    colorx[4] = colors[2];
    colorx[5] = colors[2];
    
    //shuffles leds array
    const int questionCountLeds = sizeof ledsPos / sizeof ledsPos[0];
    for (int i = 0; i < questionCountLeds; i++) {
      long n = random(0, questionCountLeds);
      int tempL = ledsPos[n];
      ledsPos[n] = ledsPos[i];
      ledsPos[i] = tempL;
    }
    
    leds[ledsPos[0]] = 2;
    leds[ledsPos[1]] = 3;
    leds[ledsPos[2]] = 4;
    leds[ledsPos[3]] = 5;
    leds[ledsPos[4]] = 6;
    leds[ledsPos[5]] = 7;
    
    for (int k = 0; k < 200; k++){
      
      //shows first pair
      digitalWrite(leds[0],0);
      digitalWrite(leds[1],1);
      digitalWrite(leds[2],1);
      digitalWrite(leds[3],1);
      digitalWrite(leds[4],1);
      digitalWrite(leds[5],1);
      
      if (colors[0] == 8 || colors[0] == 9 || colors[0] == 10){
        digitalWrite(colors[0],1);
        delay(2);
      }
      digitalWrite(8,0);
      digitalWrite(9,0);
      digitalWrite(10,0);
  
      digitalWrite(leds[0],1);
      digitalWrite(leds[1],0);
      digitalWrite(leds[2],1);
      digitalWrite(leds[3],1);
      digitalWrite(leds[4],1);
      digitalWrite(leds[5],1);
      digitalWrite(colors[0],1);
  
      if (colors[0] == 8 || colors[0] == 9 || colors[0] == 10){
        digitalWrite(colors[0],1);
        delay(2);
      }
      digitalWrite(8,0);
      digitalWrite(9,0);
      digitalWrite(10,0);
  
      //shows second pair
      digitalWrite(leds[0],1);
      digitalWrite(leds[1],1);
      digitalWrite(leds[2],0);
      digitalWrite(leds[3],1);
      digitalWrite(leds[4],1);
      digitalWrite(leds[5],1);
  
      if (colors[1] == 8 || colors[1] == 9 || colors[1] == 10){
        digitalWrite(colors[1],1);
        delay(2);
      }
      digitalWrite(8,0);
      digitalWrite(9,0);
      digitalWrite(10,0);
  
      digitalWrite(leds[0],1);
      digitalWrite(leds[1],1);
      digitalWrite(leds[2],1);
      digitalWrite(leds[3],0);
      digitalWrite(leds[4],1);
      digitalWrite(leds[5],1);
      digitalWrite(colors[1],1);
  
      if (colors[1] == 8 || colors[1] == 9 || colors[1] == 10){
        digitalWrite(colors[1],1);
        delay(2);
      }
      digitalWrite(8,0);
      digitalWrite(9,0);
      digitalWrite(10,0);
  
      //shows third pair
      digitalWrite(leds[0],1);
      digitalWrite(leds[1],1);
      digitalWrite(leds[2],1);
      digitalWrite(leds[3],1);
      digitalWrite(leds[4],0);
      digitalWrite(leds[5],1);
      digitalWrite(colors[2],1);
  
      if (colors[2] == 8 || colors[2] == 9 || colors[2] == 10){
        digitalWrite(colors[2],1);
        delay(2);
      }
      digitalWrite(8,0);
      digitalWrite(9,0);
      digitalWrite(10,0);
  
      digitalWrite(leds[0],1);
      digitalWrite(leds[1],1);
      digitalWrite(leds[2],1);
      digitalWrite(leds[3],1);
      digitalWrite(leds[4],1);
      digitalWrite(leds[5],0);
      digitalWrite(colors[2],1);
      
      if (colors[2] == 8 || colors[2] == 9 || colors[2] == 10){
        digitalWrite(colors[2],1);
        delay(2);
      }
      digitalWrite(8,0);
      digitalWrite(9,0);
      digitalWrite(10,0);
    }
  }
  
  //player's input 
  if (digitalRead(13) == 1) {
    
    digitalWrite(7,0);
    digitalWrite(6,1);
    digitalWrite(5,1);
    digitalWrite(4,1);
    digitalWrite(3,1);
    digitalWrite(2,1);
    
    playerInput(5);
    colorindex = 5;
  }
  
  if (digitalRead(12) == 1) {
    
    digitalWrite(7,1);
    digitalWrite(6,0);
    digitalWrite(5,1);
    digitalWrite(4,1);
    digitalWrite(3,1);
    digitalWrite(2,1);
    
    playerInput(4);
    colorindex = 4;
  }
  
  if (digitalRead(11) == 1) {
    
    digitalWrite(7,1);
    digitalWrite(6,1);
    digitalWrite(5,0);
    digitalWrite(4,1);
    digitalWrite(3,1);
    digitalWrite(2,1);
  
    playerInput(3);
    colorindex = 3;
  }
  
  if (digitalRead(A3) == 1) {
    
    digitalWrite(7,1);
    digitalWrite(6,1);
    digitalWrite(5,1);
    digitalWrite(4,0);
    digitalWrite(3,1);
    digitalWrite(2,1);
  
    playerInput(2);
    colorindex = 2;
  }
  
  if (digitalRead(A4) == 1) {
    
    digitalWrite(7,1);
    digitalWrite(6,1);
    digitalWrite(5,1);
    digitalWrite(4,1);
    digitalWrite(3,0);
    digitalWrite(2,1);
  
    playerInput(1);
    colorindex = 1;
  }
  
  if (digitalRead(A5) == 1) {
    
    digitalWrite(7,1);
    digitalWrite(6,1);
    digitalWrite(5,1);
    digitalWrite(4,1);
    digitalWrite(3,1);
    digitalWrite(2,0);
  
    playerInput(0);
    colorindex = 0;
  }
    
  if (e == 1) {
    
    digitalWrite(7,0);
    digitalWrite(6,0);
    digitalWrite(5,0);
    digitalWrite(4,0);
    digitalWrite(3,0);
    digitalWrite(2,0);
    
    if (colorindex != -1) {
      if (x == 0){
        y = colorx[ledsPos[colorindex]];
        x++;
      } 
      else {
        if (colorx[ledsPos[colorindex]] == y){
          for (int i = 0; i <= matchnum; i++){
            if (y == colorsChosen[0] || y == colorsChosen[1] || y == colorsChosen[2] ) {
               colorfound = 1;
            }
          }
          if (colorfound == 0) {
            colorsChosen[matchnum] = y;
            matchnum++;
            x = 0;
            y = 0; 
          }
        } 
        else {
          //game lost signal
          for (int i = 0; i < 8; i++){
            digitalWrite(8,1);
            delay(350);
            digitalWrite(8,0); 
            delay(350);
          }
          exit(0);
        }
      }
      colorindex = -1;
    }
    //game won signal
    if (matchnum == 3){ 
      for (int i = 0; i < 8; i++){
        digitalWrite(10,1);
        delay(350);
        digitalWrite(10,0); 
        delay(350);
      }
      matchnum = 0;
      exit(0);
    }
  }
}
