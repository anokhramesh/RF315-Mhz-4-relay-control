//In this Project We will controll 4 relays Remotely with the Help of Radio Frequency module (Rf 315 mhz)and its Remote control

// initializing pin numbers:
const int buttonPin1 = 2;   // Connect D3 pin of RF Module to Arduino Pin#2
const int Relay_1 = 12;    // Pin 12 will go High when pressed RF remote button-C
const int buttonPin2 = 3;  // Connect D2 pin of RF Module to Arduino Pin#3
const int Relay_2 = 11;    // Pin 11 will go High when pressed RF remote button-A
const int buttonPin3 = 4;  // Connect D1 pin of RF Module to Arduino Pin#4
const int Relay_3 = 10;   // Pin 10 will go High when pressed RF remote button-D
const int buttonPin4 = 5; // Connect D0 pin of RF Module to Arduino Pin#5
const int Relay_4 = 9;    //Pin 9 will go High when pressed RF remote button-B
// Variables will change:
int RelayState1 = HIGH;       // the current state of the output pin-12
int buttonState1;             // the current reading from the input pin-2
int lastButtonState1 = LOW;   // the previous reading from the input pin-2
int RelayState2 = HIGH;       // the current state of the output pin-11
int buttonState2;             // the current reading from the input pin-3
int lastButtonState2 = LOW;   // the previous reading from the input pin-3
int RelayState3 = HIGH;       // the current state of the output pin-10
int buttonState3;             // the current reading from the input pin-4
int lastButtonState3 = LOW;   // the previous reading from the input pin-4
int RelayState4 = HIGH;       // the current state of the output pin-9
int buttonState4;             // the previous reading from the input pin-9
int lastButtonState4 = LOW;   // the previous reading from the input pin-5


// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers
long lastDebounceTime2 = 0;  // the last time the output pin was toggled
long debounceDelay2 = 50; // the debounce time; increase if the output flickers
long lastDebounceTime3 = 0;
long debounceDelay3 = 50;
long lastDebounceTime4 = 0;
long debounceDelay4 = 50;

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(Relay_1, OUTPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(Relay_2, OUTPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(Relay_3, OUTPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(Relay_4, OUTPUT);


  // set initial Relay state
  digitalWrite(Relay_1, RelayState1);
  digitalWrite(Relay_2, RelayState2);
  digitalWrite(Relay_3, RelayState3);
  digitalWrite(Relay_4, RelayState4);

}

void loop() {
  // read the state of the switch into a local variable:
  int reading1 = digitalRead(buttonPin1);
  int reading2 = digitalRead(buttonPin2);
  int reading3 = digitalRead(buttonPin3);
  int reading4 = digitalRead(buttonPin4);



  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading1 != lastButtonState1) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if (reading2 != lastButtonState2) {
    // reset the debouncing timer
    lastDebounceTime2 = millis();
  }
  if (reading3 != lastButtonState3) {
    // reset the debouncing timer
    lastDebounceTime3 = millis();
  }
  if (reading4 != lastButtonState4) {
    // reset the debouncing timer
    lastDebounceTime4 = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if ((millis() - lastDebounceTime2) > debounceDelay2) {
      if ((millis() - lastDebounceTime3) > debounceDelay3) {
        if ((millis() - lastDebounceTime4) > debounceDelay4) {

          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state:

          // if the button state has changed:
          if (reading1 != buttonState1) {
            buttonState1 = reading1;

            // only toggle the Relay if the new button state is HIGH
            if (buttonState1 == HIGH) {
              RelayState1 = !RelayState1;
            }
          }
        }
        if (reading2 != buttonState2) {
          buttonState2 = reading2;

          // only toggle the Relay if the new button state is HIGH
          if (buttonState2 == HIGH) {
            RelayState2 = !RelayState2;
          }
        }
      }

      if (reading3 != buttonState3) {
        buttonState3 = reading3;

        // only toggle the Relay if the new button state is HIGH
        if (buttonState3 == HIGH) {
          RelayState3 = !RelayState3;
        }
      }
    }

    if (reading4 != buttonState4) {
      buttonState4 = reading4;

      // only toggle the Relay if the new button state is HIGH
      if (buttonState4 == HIGH) {
        RelayState4 = !RelayState4;
      }
    }
  }


  // set the Relay Status:
  digitalWrite(Relay_1, RelayState1);
  digitalWrite(Relay_2, RelayState2);
  digitalWrite(Relay_3, RelayState3);
  digitalWrite(Relay_4, RelayState4);


  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState1 = reading1;
  lastButtonState2 = reading2;
  lastButtonState3 = reading3;
  lastButtonState4 = reading4;


}
