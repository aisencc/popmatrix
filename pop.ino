//////////////////////////////
//aisencc:: & Shawn Lauriat//
////////////////////////////
// xP cycling...

int width = 5;
int height = 5;
int x[]={
  3,4,5,6,7};
int y[]={
  8,9,10,11,12};

int xP;
int yP;
boolean xON[] = {
  false,false,false,false,false,false,false,false,false};
boolean yON[] = {
  false,false,false,false,false,false,false,false,false};
int HEADER = '|';

void setup(){
  Serial.begin(9600);
}

void loop() {
  for (int xPos = 0; xPos < width; xPos++) {
    for (int yPos = 0; yPos < height; yPos++) {
    //  Serial.print(xON[xPos] && yON[yPos] ? "1" : "0");
      if (xON[xPos] && yON[yPos]) {
        drawLines(xPos, yPos);
      }
    }
  //  Serial.println();
  }
//  Serial.println();
}

void drawLines(int xPos, int yPos){
  // Off!
  for(int i=0; i< width; i++){
      pinMode(x[i], INPUT);
  }
  for(int i=0; i< height; i++){
      pinMode(y[i], INPUT);
  }
  // Pick one on.
  for(int i=0; i< width; i++){
    if (xPos == i){ 
      pinMode(x[i], OUTPUT);
      digitalWrite(x[i], HIGH);
    } else {
      pinMode(x[i], INPUT);
    }
  }
  for(int i=0; i< height; i++){
    if (yPos == i){ 
      pinMode(y[i], OUTPUT);
      digitalWrite(y[i], LOW);
    } else {
      pinMode(y[i], INPUT);
    }
  }
  delay(100);
}

void serialEvent() {
  while (Serial.available()) {
    if (Serial.read() == HEADER) {
      flushSerial();
      xP = Serial.read() - 1;
      flushSerial();
      yP = Serial.read() - 1;
      Serial.print("read: ");
      Serial.print(xP);
      Serial.print(",");
      Serial.println(yP);
      if (xP > -1 && xP < width) {
        xON[xP] = !xON[xP];
      }
      if (yP > -1 && yP < height) {
        yON[yP] = !yON[yP];
      }
    } else {
      Serial.println("Read something other than header");
    }
  }
}

void flushSerial() {
  while (Serial.available() == 0);
}
