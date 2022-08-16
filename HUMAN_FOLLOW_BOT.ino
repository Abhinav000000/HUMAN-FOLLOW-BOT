int p1=4;
int p2=5;
int p3=6;
int p4=7;
int LIR = 8;
int RIR = 9;
int BIR = 10;
bool L_IR;
bool R_IR;
bool B_IR;
#define echo 11
#define trig 12
int con= 0;
float  duration; // time taken by the pulse to return back
float  distance; // oneway distance travelled by the pulse

void setup(){
  pinMode(p1,OUTPUT);
  pinMode(p2,OUTPUT);
  pinMode(p3,OUTPUT);
  pinMode(p4,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(LIR,INPUT);
  pinMode(RIR,INPUT);
  pinMode(BIR,INPUT);
  
  Serial.begin(9600);
}
void loop(){
  digitalWrite(13,HIGH);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
    
  distance = duration * 0.01723;

  L_IR = digitalRead(LIR);
  R_IR = digitalRead(RIR);
  B_IR = digitalRead(BIR);
  
  if(distance >= 5 && distance <= 50)  
    if(L_IR==1 && R_IR==1){
      digitalWrite(p1,LOW);
      digitalWrite(p2,HIGH);
      digitalWrite(p4,HIGH);
      digitalWrite(p3,LOW);}

    else if(L_IR==1 && R_IR==0){
      digitalWrite(p1,HIGH);
      digitalWrite(p2,LOW);
      digitalWrite(p4,HIGH);
      digitalWrite(p3,LOW);}

    else if(L_IR==0 && R_IR==1){
      digitalWrite(p1,LOW);
      digitalWrite(p2,HIGH);
      digitalWrite(p4,LOW);
      digitalWrite(p3,HIGH);}

    else{
      digitalWrite(p1,LOW);
      digitalWrite(p2,LOW);
      digitalWrite(p3,LOW);
      digitalWrite(p4,LOW);}
      
  if(B_IR == 1){
    digitalWrite(p2,LOW);
    digitalWrite(p1,HIGH);
    digitalWrite(p3,HIGH);
    digitalWrite(p4,LOW);}
  
  else{
      digitalWrite(p1,LOW);
      digitalWrite(p2,LOW);
      digitalWrite(p3,LOW);
      digitalWrite(p4,LOW);}}
