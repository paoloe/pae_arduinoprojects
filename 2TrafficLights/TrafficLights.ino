//Traffic lights with pedestrian crossing 
//code below are the declaration of variables
int red = 0;  //trafficlight1
int amb = 0;  //trafficlight1
int gre = 0;  //trafficlight1
int x = 13;
int y = 12; 
int z = 11;
int red2 = 0; //trafficlight2
int amb2 = 0; //trafficlight2
int gre2 = 0; //trafficlight2
int a = 10;
int b = 9;
int c = 8;

// the setup function runs once when you press reset or power the board
void setup() {
    // initialize the LED's and button as an output.
    pinMode(x, OUTPUT); //red
    pinMode(y, OUTPUT); //amb
    pinMode(z, OUTPUT); //gre
    pinMode(a, OUTPUT); //red2
    pinMode(b, OUTPUT); //amb2
    pinMode(c, OUTPUT); //gre2
}
//First traffic light function
void TrafficLight1(int red, int amb, int gre) //parameters declared, named TrafficLights1
{ 
    if (red == 0) //if statement if value of red == 0
    {
        digitalWrite(x, LOW); //LED off 
        Serial.println(""); 
        Serial.print("L1 = OFF,"); //Serial monitor to print light off
    }
    if (red == 1) //if value == 1 
    {
        digitalWrite(x, HIGH); //LED on
        Serial.println("");
        Serial.print("L1 = ON,"); //Serial print ON
    }
    if (amb == 0) //if value of amb is 0
    {
        digitalWrite(y, LOW); //light off
        Serial.print("OFF,"); //print off
    }
    if (amb == 1) //if value is 1
    {
        digitalWrite(y, HIGH); //LED on
        Serial.print("ON,"); //print on
    } 
    if (gre == 0) //value of gre 0
    {
        digitalWrite(z, LOW); //LED off
        Serial.print("OFF"); //print off
    }
    if (gre == 1) //value 1
    {
        digitalWrite(z, HIGH); //LED on
        Serial.print("ON"); //print on
    }
}
//trafficlight2 function
void TrafficLight2(int red2, int amb2, int gre2) { //parameters declared 
    if (red2 == 0) //if red2 == 0
    {
        digitalWrite(a, LOW); //LED off
        Serial.println("");
        Serial.print("L2 = OFF,"); //print off
    }
    if (red2 == 1) //if value 1
    {
        digitalWrite(a, HIGH); //LED on
        Serial.println("");
        Serial.print("L2 = ON,"); //print on
    }
    if (amb2 == 0) //if amb 0
    {
        digitalWrite(b, LOW); //off
        Serial.print("OFF,"); //print off
    }
    if (amb2 == 1) //if 1 
    {
        digitalWrite(b, HIGH); //on
        Serial.print("ON,"); //print on
    }
    if (gre2 == 0) //if 0
    {
        digitalWrite(c, LOW);//off
        Serial.print("OFF"); //print off
    }
    if (gre2 == 1) //if 1
    {
        digitalWrite(c, HIGH); //on
        Serial.print("ON"); //print on
    }
}

// the loop function runs over and over again forever
void loop() 
{
    TrafficLight1(1, 0, 0);
    //again the code above means trafficlight1 = Red ON, Amb OFF, Gre OFF
    TrafficLight2(0, 0, 1);
    //trafficlight2 = Red OFF, Amb Off, Gre On
    delay(2000);
    TrafficLight1(1, 1, 0);
    TrafficLight2(0, 1, 0);
    delay(2000);
    TrafficLight1(0, 0, 1);
    TrafficLight2(1, 0, 0);
    delay(2000);
    TrafficLight1(0, 1, 0);
    TrafficLight2(1, 1, 0);
    delay(2000);
 }


