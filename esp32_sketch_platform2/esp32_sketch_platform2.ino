

#define M1_IN1  32
#define M1_IN2  33
#define M1_PWM  25

#define M2_IN1  26
#define M2_IN2  27
#define M2_PWM  14



void setup() {
  //  init motor driver
  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT);
  pinMode(M1_PWM, OUTPUT);

  m1Stop();
  m1Fwrd();

  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT);
  pinMode(M2_PWM, OUTPUT);

  m2Stop();
  m2Fwrd();
}


void
m1Fwrd()
{
  digitalWrite(M1_IN1, 0);
  digitalWrite(M1_IN2, 1);
}

void
m1Bwrd()
{
  digitalWrite(M1_IN1, 1);
  digitalWrite(M1_IN2, 0);
}

void
m1Speed(int pwm)
{
  analogWrite(M1_PWM, (pwm & 0xFF));
}

void
m1Stop()
{
  m1Speed(0);
}

void
m1Run(int pwm = 255)
{
  m1Speed(pwm);
}


void
m2Fwrd()
{
  digitalWrite(M2_IN1, 1);
  digitalWrite(M2_IN2, 0);
}

void
m2Bwrd()
{
  digitalWrite(M2_IN1, 0);
  digitalWrite(M2_IN2, 1);
}

void
m2Speed(int pwm)
{
  analogWrite(M2_PWM, (pwm & 0xFF));
}

void
m2Stop()
{
  m2Speed(0);
}

void
m2Run(int pwm = 255)
{
  m2Speed(pwm);
}

void loop() {

  /// forward ->
  m1Fwrd();
  m2Fwrd();
  m1Run(192);
  m2Run();

  delay(1000);

  m1Stop();
  m2Stop();

  /// backward <-
  m1Bwrd();
  m2Bwrd();
  m1Run();
  m2Run(192);

  delay(1000);

  m1Stop();
  m2Stop();
}
