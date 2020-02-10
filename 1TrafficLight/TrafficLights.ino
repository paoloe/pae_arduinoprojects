/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/
 int red = 13; //Declaration of variables for different ports
 int amb = 12;
 int gre = 11;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(red, OUTPUT); //Declaration of the variables as outputs
  pinMode(amb, OUTPUT);
  pinMode(gre, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(red, HIGH);  //red on
  //delay(2000);              //delay         
  digitalWrite(amb, HIGH);  //amb on
  //delay(1000);              //delay  
  digitalWrite(red, LOW);   // red off   
  digitalWrite(amb, LOW);   // amb off   
  //delay(500);               //delay         
  digitalWrite(gre, HIGH);  // green on
  //delay(2000);              //delay         
  digitalWrite(gre, LOW);   // green off
  digitalWrite(amb, HIGH);  // amb on
  //delay(1000);              //delay         
  digitalWrite(amb, LOW);   // amb off
}
