int input1Motor1 = 2;
int input2Motor1 = 3;
int input1Motor2 = 4;
int input2Motor2 = 5;
int LEFTirsensor1 =A1;
int RIGHTirsensor2 = A0;
int threshold = 500;




void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor1pinvalue = analogRead(LEFTirsensor1);
  int sensor2pinvalue = analogRead(RIGHTirsensor2);

 if( sensor1pinvalue > threshold && sensor2pinvalue > threshold ){
 stopMotors();
 }

 else if( sensor1pinvalue > threshold && sensor2pinvalue < threshold ){
  leftTurn();
 }

 else if(sensor1pinvalue < threshold && sensor2pinvalue < threshold){
  moveForward();
 }

 else if(sensor1pinvalue < threshold && sensor2pinvalue > threshold){
  rightTurn();
 }
}

 void stopMotors(){
  digitalWrite(input1Motor1,LOW);
  digitalWrite(input2Motor1,LOW);
  digitalWrite(input1Motor2,LOW);
  digitalWrite(input2Motor2,LOW);
}

void leftTurn(){
  digitalWrite(input1Motor1,LOW);
  digitalWrite(input2Motor1,HIGH);
  digitalWrite(input1Motor2,HIGH);
  digitalWrite(input2Motor2,LOW);
}

void rightTurn(){
  digitalWrite(input1Motor1,HIGH);
  digitalWrite(input2Motor1,LOW);
  digitalWrite(input1Motor2,LOW);
  digitalWrite(input2Motor2,HIGH);
}

void moveForward(){
  digitalWrite(input1Motor1,LOW);
  digitalWrite(input2Motor1,HIGH);
  digitalWrite(input1Motor2,LOW);
  digitalWrite(input2Motor2,HIGH);
}


