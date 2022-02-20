
 #define Pin2  2 // Optocopler
 #define PWMA  9 
 #define AIN2  8 
 #define AIN1  7
 #define STBY  6  

 int Speed = 200 ;
 int Duration = 3000 ;
 volatile int counter = 0 ; // 20/rev

 void setup() {
  Serial.begin(9600); 
  pinMode(Pin2, INPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT); 
  digitalWrite(STBY, HIGH); 
  attachInterrupt(0, interruptFunction, CHANGE);  
    
  analogWrite(PWMA, Speed) ;
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
 }

 void loop() {

  delay(Duration) ;
  Serial.println(counter) ;
  counter = 0 ;
 }

  void interruptFunction() 
  {   counter++ ;  } 
  
