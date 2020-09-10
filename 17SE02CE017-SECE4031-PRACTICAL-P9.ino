#17SE02CE017-DHRUV-GANDHI
include "Wire.h"
include "I2Cdev.h".
include "MPU6050.h"
include "Servo.h"
#17SE02CE017-DHRUV-GANDHI
MPUG050 mpu;
intl6_t ax, ay, az;
intl6_t gx, gy, gz;
Servo servo1;
Servo servo2:
#17SE02CE017-DHRUV-GANDHI
int vall:
int val2:
int prevVall:
int prevVal2:
#17SE02CE017-DHRUV-GANDHI
void setup()
{
  Wire.begin():
  Serial.begin(115200);
  Serial.println("Initialize MFU"):
  mpu.initialize();
  Serial.println(mpu.testConnection ()?"Connected" : "Connection Failed")
  servol.attach(5);
  servo2.attach(6);
  
}
#17SE02CE017-DHRUV-GANDHI
void loop()
{
  mpu.getMotione6(&ax,&ay,&az,&gx,&gy,&gz);
  vall=map(ax,-17000,17000, 0, 179);
  if (vall != prevVall)
  {
    servol.write(vall);
    prewall=vall:
  }
  val2=map(ay, -17000, 17000, 0, 179);
  if (val2 != prev Val2)
  {
	servo.write (val2);
    prevVal2=val2;
  }
  delay(5):
}
#17SE02CE017-DHRUV-GANDHI