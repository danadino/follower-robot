#define IRSR 11   // IR RIGHT SENSOR
#define IRSL 12   // IR LEFT SENSOR
#define MP 70   // MOTOR SPEED

// RIGHT MOTOR
int ERM=6;  /* ENABLE RIGHT MOTOR , ENA */
int RMP1=7;   /* FORWORD PIN , RIGHT MOTOR PIN1 , IN1 */
int RMP2=8;  /* BACKWORD PIN , RIGHT MOTOR PIN2 , IN2 */

// LEFT MOTOR
int ELM=5;  /* ENABLE LEFT MOTOR , ENB */
int LMP1=9;   /* BACKWORD PIN , LEFT MOTOR PIN1 , IN3 */
int LMP2=10; /* FORWORD PIN , LEFT MOTOR PIN2 , IN4 */

void setup()
{

pinMode(ERM,OUTPUT);
pinMode(RMP1,OUTPUT);
pinMode(RMP2,OUTPUT);

pinMode(ELM,OUTPUT);
pinMode(LMP1,OUTPUT);
pinMode(LMP2,OUTPUT);

pinMode(IRSR,INPUT);
pinMode(IRSL,INPUT);

}


void loop()
{

int IRSR_V = digitalRead(IRSR); // IRSR_V = IR RIGHT SENSOR VALUE
int IRSL_V = digitalRead(IRSL); // IRSL_V = IR LEFT SENSOR VALUE

// GO STRAIGHT
if (IRSL_V == LOW && IRSR_V == LOW)
{
RotateMotor(-MP,MP);
}
// TURN LEFT
else if (IRSL_V == HIGH && IRSR_V == LOW )
{
RotateMotor(MP,MP);
}
// TURN RIGHT
else if (IRSL_V == LOW && IRSR_V == HIGH )
{
RotateMotor(-MP,-MP);
}
// STOP
else
{
RotateMotor(0, 0);
}
}


void RotateMotor(int LMS,int RMS)  /*LMS = LEFT MOTOR SPEED , RMS = RIGHT MOTOR SPEED */
{

if(LMS<0) // -MP
{
digitalWrite(LMP1,LOW); // BACKWORD PIN
digitalWrite(LMP2,HIGH); // FORWORD PIN
}
else if(LMS>0) // MP
{
digitalWrite(LMP1,HIGH); // BACKWORD PIN
digitalWrite(LMP2,LOW); // FORWORD PIN
}
else
{
digitalWrite(LMP1,LOW); // BACKWORD PIN
digitalWrite(LMP2,LOW); // FORWORD PIN
}

if(RMS<0) // -MP
{
digitalWrite(RMP1,LOW); // FORWORD PIN
digitalWrite(RMP2,HIGH); // BACKWORD PIN
}
else if(RMS>0) // MP
{
digitalWrite(RMP1,HIGH); // FORWORD PIN
digitalWrite(RMP2,LOW); // BACKWORD PIN
}
else
{
digitalWrite(RMP1,LOW); // FORWORD PIN
digitalWrite(RMP2,LOW); // BACKWORD PIN
}
analogWrite(ELM,MP);
analogWrite(ERM,MP);
}
