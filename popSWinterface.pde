//////////////////////////////
//aisencc:: & Shawn Lauriat//
////////////////////////////

import processing.serial.*;

// The serial port:
Serial myPort;

public static final char HEADER = '|';
int x;
int y;
int dotsize;
int combined;


int matrix= 400;
boolean on = false;


void setup(){
  size(matrix, matrix);
  background(0);
    smooth();
  stroke(100,0,100);
  dotsize= matrix/10;
  
  
// I know that the first port in the serial list on my mac
// is always my  Keyspan adaptor, so I open Serial.list()[0].
// Open whatever port is the one you're using.
myPort = new Serial(this, "/dev/tty.usbmodemfd121", 9600);

// Send a capital A out the serial port  
}


void draw(){

  for(int x=1; x< 6; x++){
    for(int y=1; y< 6; y++){
      // Set the color based on the x and y and whether the mouse is pressed
      if (floor(mouseX/( width /5))* width/5 + dotsize == (x-1)*width/5 +dotsize && floor(mouseY/( height /5))* height/5 +dotsize == (y-1)*height/5 +dotsize && on==true){
          fill(255,0,0);
          println(x + "," + y);
          ellipse((x-1)*width/5 + dotsize, (y-1)*height/5 +dotsize, dotsize , dotsize);
         // combined=( (x << 4)+y);
//         combined=(x*10 + y);
         myPort.write(HEADER);
         myPort.write(x);
         myPort.write(y);
         delay(1000);
//         myPort.write('-');
//          myPort.write( combined +"00000-");

          // Call the function to draw a dot here on your tongue. This uses x and y
        } else {

//          println("not pressed");
        }

    }
  }
}

void mousePressed(){
  on= true;
}

void mouseReleased(){
  on= false;
}
void mouseDragged(){
   background(0);
}

void serialEvent(Serial p) {
  String inString = myPort.readStringUntil('\n');
  if (inString != null) {
    println(inString);
  }
}

//void keypressed(){
//if(value == "b"){ 
//  background(0);
//}
//}
