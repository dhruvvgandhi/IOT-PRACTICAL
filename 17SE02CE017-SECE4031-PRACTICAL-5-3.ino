char data = 0;                
void setup() 
{
Serial.begin(9600);        
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);        
}
void loop()
{
if(Serial.available() > 0)  
{
data = Serial.read();      
Serial.print(data);        
Serial.print("\n");        
if(data == 'a')             
digitalWrite(8, HIGH);  
else if(data == 'b')     
digitalWrite(8, LOW); 

  if(data == 'c')             
digitalWrite(9, HIGH);  
else if(data == 'd')     
digitalWrite(9, LOW);

if(data == 'e')             
digitalWrite(10, HIGH);  
else if(data == 'f')     
digitalWrite(10, LOW);

if(data == 'g')             
digitalWrite(11, HIGH);  
else if(data == 'h')     
digitalWrite(11, LOW);
}                            

}