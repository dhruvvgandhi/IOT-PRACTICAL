int value=0;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2,INPUT);
}

void loop()
{
  value=digitalRead(2);
  if(value==HIGH)
  {
  digitalWrite(13,HIGH);
  }
  else
  {
  digitalWrite(13,LOW);
  }
}