const int switchPin = A0;
const int motorPin = 9;
int switchState = 0;
int switchVal;
const int switchValLow = 520;
const int switchValHigh = 1023;
void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin,OUTPUT);
  pinMode(switchPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchVal = analogRead(switchPin);
  Serial.print("Current power rating: ");
  Serial.print(switchVal);
  if (switchVal<switchValLow){
    switchVal = switchValLow;
  }
  if (switchVal>switchValHigh){
    switchVal = switchValHigh;
  }
  int wheelSpeed = map(switchVal,switchValLow,switchValHigh,0,100);
  analogWrite(9,wheelSpeed);
}
