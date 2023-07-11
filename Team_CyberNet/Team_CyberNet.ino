//define motor output pins
int motorLeftA = 8;
int motorLeftB = 9;
int motorRightA = 10;
int motorRightB = 12;
int motorLeftENA = 4;                                    // use any two pwm pin of arduino
int motorRightENB = 5;
char smuct;
int goti = 255; 

void setup() 
{  
pinMode(motorLeftA, OUTPUT);  // Digital Pin 8 as output
pinMode(motorLeftB, OUTPUT);  // Digital Pin 9 as output
pinMode(motorRightA, OUTPUT);  // Digital Pin 10 as output
pinMode(motorRightB, OUTPUT);  // Digital Pin 12 as output
Serial.begin(9600);
}

void forward(){
      digitalWrite(motorLeftA, HIGH);
      digitalWrite(motorLeftB, LOW);
      digitalWrite(motorRightA, HIGH);
      digitalWrite(motorRightB, LOW);
  }

 void backward(){
      digitalWrite(motorLeftA, LOW);
      digitalWrite(motorLeftB, HIGH);
      digitalWrite(motorRightA, LOW);
      digitalWrite(motorRightB, HIGH); 
      }

 void leftturn(){
    digitalWrite(motorLeftA, LOW);
    digitalWrite(motorLeftB, HIGH);//low (if you want to of left motor)
    digitalWrite(motorRightA, HIGH);
    digitalWrite(motorRightB, LOW);
  }

  void rightturn(){
    digitalWrite(motorLeftA, HIGH);
    digitalWrite(motorLeftB, LOW);
    digitalWrite(motorRightA, LOW);
    digitalWrite(motorRightB, HIGH); //LOW (if you want to of right motor)
    }
  void stopping(){
    digitalWrite(motorLeftA, LOW);
    digitalWrite(motorLeftB, LOW);
    digitalWrite(motorRightA, LOW);
    digitalWrite(motorRightB, LOW); 
    }
void loop()
{
  while (Serial.available() > 0)
  {
  smuct = Serial.read();
  Serial.println(smuct);
  }
  analogWrite(motorLeftENA , goti);
  analogWrite(motorRightENB, goti);
   
  if( smuct == 'F') // Forward Movement
    {
      forward();  
    }
  else if(smuct == 'B') // Backward Movement
    {
      backward();
    }
  
    else if(smuct == 'L') //Left Turn
    {
    leftturn();
    }
    else if(smuct == 'R') //Right Turn
    {
    rightturn();
    }
    
  else if(smuct == 'S') //Stop Bot
    {
    stopping();
    }

  if (smuct == '0')
  {
    goti = 0;
    stopping();
  }
  if (smuct == '1')
  {
    goti = 30;
  }
  if (smuct == '2')
  {
    goti = 60;
  }
  if (smuct == '3')
  {
    goti = 90;
  }
  if (smuct == '4')
  {
    goti = 120;
  }
  if (smuct == '5')
  {
    goti = 150;
  }
  if (smuct == '6')
  {
    goti = 180;
  }
  if (smuct == '7')
  {
    goti = 210;
  }
  if (smuct == '8')
  {
    goti = 240;
  }
  if (smuct == '9')
  {
    goti = 255;
  }

  /* Comment out of modification   
  else if(smuct == 'I') // FR
    {
    digitalWrite(motorLeftA, HIGH);
    digitalWrite(motorLeftB, LOW);
    digitalWrite(motorRightA, LOW);
    digitalWrite(motorRightB, LOW);
    }
  else if(smuct == 'J') //BR
    {
    digitalWrite(motorLeftA, LOW);
    digitalWrite(motorLeftB, HIGH);
    digitalWrite(motorRightA, LOW);
    digitalWrite(motorRightB, LOW);
    }
   else if(smuct == 'G') //FL
    {
    digitalWrite(motorLeftA, LOW);
    digitalWrite(motorLeftB, LOW);
    digitalWrite(motorRightA, HIGH);     
    digitalWrite(motorRightB, LOW);
    }
  else if(smuct == 'H') //BL
    {
    digitalWrite(motorLeftA, LOW);
    digitalWrite(motorLeftB, LOW);
    digitalWrite(motorRightA, LOW);
    digitalWrite(motorRightB, HIGH); 
    } */
}