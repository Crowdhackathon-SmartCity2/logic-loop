int mq3_analogPin = A1; // connected to the output pin of MQ3

 const int buttonPin = 13;     // the number of the pushbutton pin

  int buttonState = 0;         // variable for reading the pushbutton status

// Define Pins
    int redPin= 3;
    int greenPin = 5;
    int bluePin = 6;


Servo myservo;

void setup(){
Serial.begin(9600); // open serial at 9600 bps

   pinMode(buttonPin, INPUT);
   myservo.attach(9);
   myservo.write(90); 
   
   pinMode(redPin, OUTPUT);
   pinMode(greenPin, OUTPUT);
   pinMode(bluePin, OUTPUT);
}

int redValue;
int greenValue;
int blueValue;


void loop()
{
// give ample warmup time for readings to stabilize
   buttonState = digitalRead(buttonPin);

   myservo.write(90); 
   
   setColor(0, 255, 255);
         delay(1000);


float mq3_value = analogRead(mq3_analogPin);

Serial.println(mq3_value);

if (buttonState == HIGH) {

int highvalue = 0;

for (int i=0;i<10;i++) {
  
  float mq3_value = analogRead(mq3_analogPin);
    Serial.println(highvalue);
  
if (mq3_value > highvalue)
{
  highvalue = mq3_value;
}
  delay(500);

}

if (highvalue < 370) {
 
  Serial.println("< 0,25 mg/L safe to drive");
  setColor(0, 0, 255);
   myservo.write(180);

}


if (highvalue > 371 && highvalue < 550) {
 
  Serial.println("0,25 - 0,4 mg/L not safe to drive. Call taxi?");
    setColor(255, 0, 0);


}

if (highvalue > 551 && highvalue < 1000) {
 
  Serial.println("> 0,4 mg/L Very unsafe to drive. Call taxi?");
  setColor(255, 0, 0);

}
Serial.println(highvalue);

delay(5000); //Just here to slow down the output.


}
delay(100); //Just here to slow down the output.
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
