const int switchPin = A0;
const int motorPin = 9;
int switchState = 0;
int switchVal;
const int switchValLow = 520;
const int switchValHigh = 1023;
void setup() {
  pinMode(motorPin,OUTPUT);
  pinMode(switchPin,INPUT);
  Serial.begin(9600); // This serial comms just helps you see what ranges are being read 
                      // from your variable resistance and the respective DC motor speed 
}

void loop() {
  // put your main code here, to run repeatedly:
  switchVal = analogRead(switchPin); // This is where your potentiometer needs to be connected in series to
  Serial.print("Current power rating: "); // Power may not be most accurate term, but you get the idea
  Serial.print(switchVal);
  
  // The following two if statements guarantee the switch value never falls below or above a certain range, 
  // which just smooths out the map function below. You may need to adjust these based on your resistor values.
  if (switchVal<switchValLow){
    switchVal = switchValLow; 
  }
  if (switchVal>switchValHigh){
    switchVal = switchValHigh;
  }
  
  int wheelSpeed = map(switchVal,switchValLow,switchValHigh,0,100); // Map, as mentioned in the video, sets your 
                                                                    // input analog reading into a proportional response
                                                                    // between a desired low and high point, see '0' and '100'
                                                                    
  analogWrite(9,wheelSpeed); // The mapped analogRead from swtichPin is then sent out through the Arduino's pin 9 with PWM control
                             // The pulse width is determined by the wheelSpeed variable.
}
