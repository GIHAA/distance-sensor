
#define TRIGGER 5
#define ECHO    4
#define mindis 20 //add minumum distance here
#define led_pin 7 //add pin num for led or relay here

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(B, OUTPUT);
}
 
void loop() {
 
  // disatance calculator
  long duration, distance;
 
  
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1; // final distance in cm
  
  Serial.print(distance);
  Serial.println("Centimeter:");
  delay(1000);
  
  if ( distance > mindis){
    
    digitalWrite(led_pin , HIGH);
    
    //add what you want to do when minimum distance is reached
  }
}
