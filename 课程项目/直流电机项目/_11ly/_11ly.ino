//

int outputPin = 5;
int inputPin = 4;
int cmdPin = 3;
int pinI1 = 8; //定义I1接口
int pinI2 = 9; //定义I2接口
int speedpin1 = 11; //定义EA(PWM调速)接口
int pinI3 = 6; //定义I3接口
int pinI4 = 7; //定义I4接口
int speedpin2 = 10; //定义EB(PWM调速)接口
char receivedata[10];
int i = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(outputPin, OUTPUT);
  pinMode(inputPin, INPUT);
  pinMode(pinI1, OUTPUT);
  pinMode(pinI2, OUTPUT);
  pinMode(speedpin1, OUTPUT);
  pinMode(pinI3, OUTPUT);
  pinMode(pinI4, OUTPUT);
  pinMode(speedpin2, OUTPUT);
  pinMode(cmdPin, INPUT);

  receivedata[1] = '0';
  receivedata[2] = '0';
  receivedata[3] = '0';
  receivedata[4] = '0';
  receivedata[5] = '0';
  receivedata[6] = '0';

}

void loop()
{
  while (Serial.available() > 0)
  {
    receivedata[i] = Serial.read();
    //Serial.println(receivedata[i]);
    i++;
    if (receivedata[7] == ':')
    {
      i = 0;
      break;
    }
    delay(10);
  }
  int m;
  int n;
  m = (receivedata[1] - '0') * 100 + (receivedata[2] - '0') * 10 + receivedata[3] - '0';
  n = (receivedata[4] - '0') * 100 + (receivedata[5] - '0') * 10 + receivedata[6] - '0';
  Serial.println(m);
  Serial.println(n);

  rightSpeed(m);
  leftSpeed(n);
  delay(2000);
}
void rightSpeed(int speed_r)
{
  analogWrite(speedpin1, speed_r); //输入模拟值进行设定速度
  digitalWrite(pinI1, HIGH); //使直流电机（左）顺时针转
  digitalWrite(pinI2, LOW);
}

void leftSpeed(int speed_l)
{
  analogWrite(speedpin2, speed_l); //输入模拟值进行设定速度
  digitalWrite(pinI3, LOW); //使直流电机（）顺时针转
  digitalWrite(pinI4, HIGH);
}

