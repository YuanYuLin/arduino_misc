
//===============================================================================
//  Constants
//===============================================================================
// Here we have a bunch of constants that will become clearer when we look at the
// readNesController() function. Basically, we will use these contents to clear
// a bit. These are chosen according to the table above.
const int A_BUTTON         = 0;
const int B_BUTTON         = 1;
const int SELECT_BUTTON    = 2;
const int START_BUTTON     = 3;
const int UP_BUTTON        = 4;
const int DOWN_BUTTON      = 5;
const int LEFT_BUTTON      = 6;
const int RIGHT_BUTTON     = 7;

const int DELAY_INPUT      = 100;
//===============================================================================
//  Variables
//===============================================================================
byte nesRegister  = 0;    // We will use this to hold current button states

//===============================================================================
//  Pin Declarations
//===============================================================================
//Inputs:
int nesData       = 4;    // The data pin for the NES controller
//Outputs:
int nesClock      = 2;    // The clock pin for the NES controller
int nesLatch      = 3;    // The latch pin for the NES controllerj

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
 // Initialize serial port speed for the serial terminal
  Serial.begin(9600);
  
  // Set appropriate pins to inputs
  pinMode(nesData, INPUT);
  
  // Set appropriate pins to outputs
  pinMode(nesClock, OUTPUT);
  pinMode(nesLatch, OUTPUT);
  
  // Set initial states
  digitalWrite(nesClock, LOW);
  digitalWrite(nesLatch, LOW);
}

// the loop function runs over and over again forever
void loop() {
  nesRegister = readNesController();

  delay(DELAY_INPUT);

  if (bitRead(nesRegister, A_BUTTON) == 0)
  {
    Serial.println("A");
    Serial.println(nesRegister);
  }
    
  if (bitRead(nesRegister, B_BUTTON) == 0)
  {
    Serial.println("B");
    Serial.println(nesRegister); 
  }
    
  if (bitRead(nesRegister, START_BUTTON) == 0)
  {
    Serial.println("START");
    Serial.println(nesRegister);
  }
    
  if (bitRead(nesRegister, SELECT_BUTTON) == 0)
  {
    Serial.println("SELECT");
    Serial.println(nesRegister);
  }
  
  if (bitRead(nesRegister, UP_BUTTON) == 0)
  {
    Serial.println("UP");
    Serial.println(nesRegister);
  }
  
  if (bitRead(nesRegister, DOWN_BUTTON) == 0)
  {
    Serial.println("DOWN");
    Serial.println(nesRegister);
  }
  
  if (bitRead(nesRegister, LEFT_BUTTON) == 0)
  {
    Serial.println("LEFT");  
    Serial.println(nesRegister);
  }
  
  if (bitRead(nesRegister, RIGHT_BUTTON) == 0)
  {
    Serial.println("RIGHT");
    Serial.println(nesRegister);
  }
}

byte readNesController() 
{  
  // Pre-load a variable with all 1's which assumes all buttons are not
  // pressed. But while we cycle through the bits, if we detect a LOW, which is
  // a 0, we clear that bit. In the end, we find all the buttons states at once.
  int tempData = 255;
    
  // Quickly pulse the nesLatch pin so that the register grab what it see on
  // its parallel data pins.
  digitalWrite(nesLatch, HIGH);
  digitalWrite(nesLatch, LOW);
 
  // Upon latching, the first bit is available to look at, which is the state
  // of the A button. We see if it is low, and if it is, we clear out variable's
  // first bit to indicate this is so.
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, A_BUTTON);
    
  // Clock the next bit which is the B button and determine its state just like
  // we did above.
  digitalWrite(nesClock, HIGH);
  digitalWrite(nesClock, LOW);
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, B_BUTTON);
  
  // Now do this for the rest of them!
  
  // Select button
  digitalWrite(nesClock, HIGH);
  digitalWrite(nesClock, LOW);
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, SELECT_BUTTON);

  // Start button
  digitalWrite(nesClock, HIGH);
  digitalWrite(nesClock, LOW);
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, START_BUTTON);

  // Up button
  digitalWrite(nesClock, HIGH);
  digitalWrite(nesClock, LOW);
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, UP_BUTTON);
    
  // Down button
  digitalWrite(nesClock, HIGH);
  digitalWrite(nesClock, LOW);
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, DOWN_BUTTON);

  // Left button
  digitalWrite(nesClock, HIGH);
  digitalWrite(nesClock, LOW);
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, LEFT_BUTTON);  
    
  // Right button
  digitalWrite(nesClock, HIGH);
  digitalWrite(nesClock, LOW);
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, RIGHT_BUTTON);
    
  // After all of this, we now have our variable all bundled up
  // with all of the NES button states.*/
  return tempData;
}
