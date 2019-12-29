#define M2On 3                  // Output of Motor Driver IC for contrlling first motor(On).
#define M1Off 4                  // Output of Motor Driver IC for contrlling first motor(Off).
#define M2On 5                  // Output of Motor Driver IC for contrlling Second motor(On).  
#define M2Off 6                  // Output of Motor Driver IC for contrlling Second motor(Off).

#define D0 10                   
#define D1 11                  // Output from DTMF reciever IC based on which Motor Driver IC is controlled.
#define D2 12
#define D3 13

void forward()
{
   digitalWrite(M2On, HIGH);  // Code for taking bot into forward direction.
   digitalWrite(M1Off, LOW);
   digitalWrite(M2On, HIGH);
   digitalWrite(M2Off, LOW);
}

void backward()
{
   digitalWrite(M2On, LOW);  // Code for taking bot into forward direction.
   digitalWrite(M1Off, HIGH);
   digitalWrite(M2On, LOW);
   digitalWrite(M2Off, HIGH); 
}

void left()
{
   digitalWrite(M2On, HIGH); // Code for taking bot into left direction.
   digitalWrite(M1Off, LOW);
   digitalWrite(M2On, LOW);
   digitalWrite(M2Off, LOW);
}

void right()
{
   digitalWrite(M2On, LOW); // Code for taking bot into Right direction.
   digitalWrite(M1Off, LOW);
   digitalWrite(M2On, HIGH);
   digitalWrite(M2Off, LOW);
}

void Stop()
{
   digitalWrite(M2On, LOW); // Code for stopping the bot.
   digitalWrite(M1Off, LOW);
   digitalWrite(M2On, LOW);
   digitalWrite(M2Off, LOW);
}

void setup() 
{
  pinMode(D0, INPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);

  pinMode(M2On, OUTPUT);
  pinMode(M1Off, OUTPUT);
  pinMode(M2On, OUTPUT);
  pinMode(M2Off, OUTPUT);
}

void loop() 
{

  int temp1=digitalRead(D0);
  int temp2=digitalRead(D1);
  int temp3=digitalRead(D2);
  int temp4=digitalRead(D3);
 
  if(temp1==0 && temp2==1 && temp3==0 && temp4==0)
  forward();

  else if(temp1==0 && temp2==0 && temp3==1 && temp4==0)
  left();

  else if(temp1==0 && temp2==1 && temp3==1 && temp4==0)
  right();

  else if(temp1==0 && temp2==0 && temp3==0 && temp4==1)
  backward();

   else if(temp1==1 && temp2==0 && temp3==1 && temp4==0)
  Stop();
}
