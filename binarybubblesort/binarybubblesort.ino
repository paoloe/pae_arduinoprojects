/**
 * Author : Paolo Espiritu
 * Edited : 13/02/20
 **/

int * ptr;        //declaration of pointer for array
int myArray[50];  //declaration of array as 50
int n = 50;       //int used as element counter in sort loop
int temp = 0;     //used to switch in loop

int l1 = 13;
int l2 = 12;
int l3 = 11;  //led no.3
int l4 = 10;  //led no.4
int l5 = 9;   //led no.5
int l6 = 8;
int l7 = 7;
int l8 = 6;

int incomingByte; //variable for serial button

String lowestBinArray[8];   // way tested to create LED outptut & translate lowest number in array to binary
String highestBinArray[8];  // way tested to create LED outptut & translate highest number in array to binary
//String lowestBinary;

void setup() {

  pinMode(l1, OUTPUT); //declaration of 8 LED's as outputs 
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(l6, OUTPUT);
  pinMode(l7, OUTPUT);
  pinMode(l8, OUTPUT);

  // put your setup code here, to run once:
  Serial.begin(9600); //declaration of serial declaration of serial to be able to print

}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
  }
  if (incomingByte == 's') {
    for (int b = 0; b < 50; b++) //loop to create and fill the array with random numbers
    {
      myArray[b] = random(0, 255); //ranging from 0 - 255
    }

    for (int i = 0; i < n; i++) //first loop to go through each element in the array
    {
      for (int j = 1; j < (n - i); j++) //second loop in charge of the switch
      {
        if (myArray[j - 1] > myArray[j]) // change to > for ASCENDING ORDER. // if position a is greater than b switch
        {
          temp = myArray[j - 1];
          myArray[j - 1] = myArray[j];
          myArray[j] = temp;
        }
      }
    }

    for (int a = 0; a < 50; a++) //loop used to print the whole array using a pointer
    {
      //int *ptr;
      ptr = & myArray[a]; //declaration of pointer as the sorted array
      Serial.print( * ptr); //pointer to the Array
      Serial.print(" "); //used to make array clearer
    }

    //Serial.print(*ptr);

    Serial.println();

    int lowest = myArray[0]; //declaration of the lowest number of the array as an int
    int highest = myArray[49]; //declaration of the highest number of the array as an int
    //int lowestBinary;

    for (int b = 7; b >= 0; b--) { //a loop used to print the whole binary using bitRead function
      String lowestBinary = String(bitRead(lowest, b));
      //Serial.print(lowestBinary);
      for (int i = 0; i < 8; i++) {
        if (lowestBinary.charAt(i) == '0') { /*Serial.print("0");*/
          lowestBinArray[i] = '0';
          Serial.print(lowestBinArray[i]);
        }
        if (lowestBinary.charAt(i) == '1') { /*Serial.print("1");*/
          lowestBinArray[i] = '1';
          Serial.print(lowestBinArray[i]);
        }
      }

    }

    Serial.println();
    
    for (int b = 7; b >= 0; b--) { //loop used again to attempt to print the whole binary
      //Serial.print(bitRead(highest, c));
      String highestBin = String(bitRead(highest, b)); //conversion of int to a String
            for (int i = 0; i < 8; i++) {
        if (highestBin.charAt(i) == '0') { /*Serial.print("0");*/
          highestBinArray[i] = '0';
          Serial.print(highestBinArray[i]);
        }
        if (highestBin.charAt(i) == '1') { /*Serial.print("1");*/
          highestBinArray[i] = '1';
          Serial.print(highestBinArray[i]);
        }
      }


    }
    
    Serial.println();
    int f0 = bitRead(lowest, 0); //conversion of lowest number to binary (8th position in binary)
    if (f0 == 1) { //if variable == 1 
      digitalWrite(l1, HIGH); //turn on first LED
    }

    int f1 = bitRead(lowest, 1); //conversion of lowest number to binary (7th position in binary)
    if (f1 == 1) { //if variable == 1
      digitalWrite(l2, HIGH); //turn on LED
    }

    int f2 = bitRead(lowest, 2); //conversion of lowest number to binary (6th position in binary)
    if (f2 == 1) { //if variable == 1
      digitalWrite(l3, HIGH);
    }

    int f3 = bitRead(lowest, 3); //5th position in binary
    if (f3 == 1) { //if variable == 1
      digitalWrite(l4, HIGH); //turn on LED
    }

    int f4 = bitRead(lowest, 4); //4th
    if (f4 == 1) { //if variable == 1
      digitalWrite(l5, HIGH); //turn on LED
    }

    int f5 = bitRead(lowest, 5); //3rd
    if (f5 == 1) { //if variable == 1
      digitalWrite(l6, HIGH); //turn on LED
    }

    int f6 = bitRead(lowest, 6); //2nd
    if (f6 == 1) { //if variable == 1
      digitalWrite(l7, HIGH); //turn on LED
    }

    int f7 = bitRead(lowest, 7); //1st
    if (f7 == 1) { //if variable == 1
      digitalWrite(l8, HIGH); //turn on LED
    }
    delay(5000);

    for(int i = 1; i <= 8; i++){
      String led = 'l' + i;
      digitalWrite(led, LOW);
    }

    int i0 = bitRead(highest, 0); //conversion of binary of highest int (again starting from 8th position of binary) 
    if (i0 == 1) { //if variable == 1 
      digitalWrite(l1, HIGH); //turn on LED
    }

    int i1 = bitRead(highest, 1);
    if (i1 == 1) { //if variable == 1 
      digitalWrite(l2, HIGH); //turn on LED
    }

    int i2 = bitRead(highest, 2);
    if (i2 == 1) { //if variable == 1 
      digitalWrite(l3, HIGH); //turn on LED
    }

    int i3 = bitRead(highest, 3);
    if (i3 == 1) { //if variable == 1 
      digitalWrite(l4, HIGH); //turn on LED
    }

    int i4 = bitRead(highest, 4);
    if (i4 == 1) { //if variable == 1 
      digitalWrite(l5, HIGH); //turn on LED
    }

    int i5 = bitRead(highest, 5);
    if (i5 == 1) { //if variable == 1 
      digitalWrite(l6, HIGH); //turn on LED
    }

    int i6 = bitRead(highest, 6);
    if (i6 == 1) { //if variable == 1 
      digitalWrite(l7, HIGH); //turn on LED
    }

    int i7 = bitRead(highest, 7);
    if (i7 == 1) { //if variable == 1 
      digitalWrite(l8, HIGH); //turn on LED
    }
    delay(5000);

    for(int i = 1; i <= 8; i++){
      String led = 'l' + i;
      digitalWrite(led, LOW);
    }
  }
}
