
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  1;      // the number of the LED pin
int LEDstate =0;
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button
int buttonPushCounter = 0;   // counter for the number of button presses

void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT);   
  currentButtonState = digitalRead(buttonPin);
}

void loop(){
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(buttonPin); // read new state

  if(lastButtonState == HIGH && currentButtonState == LOW) 
  {
    LEDstate = !LEDstate; //toggle LED when SW is pressed
    digitalWrite(ledPin, LEDstate); 

    while(digitalRead(buttonPin)==LOW&&LEDstate==HIGH)
    {
      buttonPushCounter++; //SW has hold press
      delay(50);
    }
  }
  if (digitalRead(buttonPin)== HIGH && buttonPushCounter >= 60) //check SW has been long press
  {     
    LEDstate = 0;
    buttonPushCounter = 0;
    digitalWrite(ledPin, LEDstate); // Turn LED off
  }
}


