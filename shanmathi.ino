const int in1a = 6;
const int in2a = 7;
const int in1b = 8;
const int in2b = 9;
const int enableA = 5;
const int enableB = 10;
const int echo = 13
const int trig = 12


void setup() {
  Serial.begin(9600);
  pinMode(in1a,OUTPUT);
  pinMode(in2a, OUTPUT);
  pinMode(in1b, OUTPUT);
  pinMode(in2b, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);

  Serial.begin(9600);
  while(!Serial)
  Serial.println("speed 0 to 255");
  
 }
 long EchoLocation()
 {
  digitalWrite(trig, LOW); //turn off the Trig pin incase it was on before
  delayMicroseconds(2); //a very short break

  digitalWrite(trig, HIGH); //turn on the Trig pin to send a sound wave
  delayMicroseconds(10); //a short break to let the operation happen
  digitalWrite(trig, LOW); //turn off the Trig pin to end the sound wave output

  long dur = pulseIn(echo, HIGH);
  long dis = 1.7*dur  // units cm/mm 3.4/2=1.7
  return dis

 }
 void Stop()
{
  digitalWrite(in1a,LOW);   //TO TURN OFF MOTOR A
  digitalWrite(in2a, LOW);

  digitalWrite(in1b,LOW);    //TO TURN OFF MOTOR B
  digitalWrite(in2b,LOW);

}

void forward()
{ if(Serial.available())
  int speed=Serial.parseInt();
  digitalWrite(in1a,HIGH);   //TO TURN ON MOTOR A
  digitalWrite(in2a, LOW);

  digitalWrite(in1b,HIGH);    //TO TURN ON MOTOR B
  digitalWrite(in2b,LOW);


  
  analogWrite(enableA,speed);   // MAX SPEED MOTOR A
  
  analogWrite(enableB,speed);    // MAX SPEED MOTOR B

  
 }
void tooclose()
{ digitalWrite(in1a,HIGH);   //TO TURN ON MOTOR A
  digitalWrite(in2a, LOW);

  digitalWrite(in1b,HIGH);    //TO TURN ON MOTOR B
  digitalWrite(in2b,LOW);

  analogWrite(enableA,speed);
  analogWrite(enableB,speed/2);  //to turn left average reduced speed on motor away from wall
}
void toofar()
{ digitalWrite(in1a,HIGH);   //TO TURN ON MOTOR A
  digitalWrite(in2a, LOW);

  digitalWrite(in1b,HIGH);    //TO TURN ON MOTOR B
  digitalWrite(in2b,LOW);

  analogWrite(enableA,speed/2);  //to turn left average reduced speed on the motor facing wall
  analogWrite(enableB,speed);  
}



void loop() {
  // put your main code here, to run repeatedly:

    if (EchoLocation()=10)
      { forward();
      }
    else if (EchoLocation()>10)
      { toofar();
      }
     else if (EchoLocation()<10)
      { tooclose();
      }

     

}
