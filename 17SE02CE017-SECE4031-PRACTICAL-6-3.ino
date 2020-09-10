#include <ESP8266WiFi.h>
const char* ssid = "DHRUV";
const char* password = "A@a12345#54321";

// Set web server port number to 80
WiFiServer server(80);

String header;

// Auxiliar variables to store the current output state
String output1State = "off";
String output2State = "off";
String output3State = "off";
String output4State = "off";
String output5State = "off";


// Assign output variables to GPIO pins
const int output1 = 5;
const int output2 = 2;
const int output3 = 3;
const int output4 = 4;
const int output5 = 5;

Serial.begin(115200);

// Initialize the output variables as outputs
pinMode(output1, OUTPUT);
pinMode(output2, OUTPUT);
pinMode(output3, OUTPUT);
pinMode(output4, OUTPUT);
pinMode(output5, OUTPUT);

// Set outputs to LOW
digitalWrite(output1, LOW);
digitalWrite(output2, LOW);
digitalWrite(output3, LOW);
digitalWrite(output4, LOW);
digitalWrite(output5, LOW);

// Connect to Wi-Fi network with SSID and password
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
}
// Print local IP address and start web server
Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
server.begin();

// Listen for incoming clients
WiFiClient client = server.available(); 

if (client) { // If a new client connects,
Serial.println("New Client."); // print a message out in the serial port
String currentLine = ""; // make a String to hold incoming data from the client
while (client.connected()) { // loop while the client's connected
if (client.available()) { // if there's bytes to read from the client,
	char c = client.read(); // read a byte, then
  	Serial.write(c); // print it out the serial monitor
  	header += c;
if (c == '\n') { // if the byte is a newline character
   // if the current line is blank, you got two newline characters in a row.
   // that's the end of the client HTTP request, so send a response:
if (currentLine.length() == 0) {
    // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
    // and a content-type so the client knows what's coming, then a blank line:
client.println("HTTP/1.1 200 OK");
client.println("Content-type:text/html");
client.println("Connection: close");
client.println();

// turns the GPIOs on and off
if (header.indexOf("GET /1/on") >= 0) {
  Serial.println("GPIO 1 on");
  output1State = "on";
  digitalWrite(output1, HIGH);
} 
  else if (header.indexOf("GET /1/off") >= 0) {
  Serial.println("GPIO 1 off");
  output1State = "off";
  digitalWrite(output1, LOW);
} 
  else if (header.indexOf("GET /2/on") >= 0) {
  Serial.println("GPIO 2 on");
  output2State = "on";
  digitalWrite(output2, HIGH);
} 
  else if (header.indexOf("GET /2/off") >= 0) {
  Serial.println("GPIO 2 off");
  output2State = "off";
  digitalWrite(output2, LOW);
}
  else if (header.indexOf("GET /3/on") >= 0) {
  Serial.println("GPIO 3 on");
  output3State = "on";
  digitalWrite(output2, HIGH);
} else if (header.indexOf("GET /3/off") >= 0) {
  Serial.println("GPIO 3 off");
  output3State = "off";
  digitalWrite(output3, LOW);
}
  else if (header.indexOf("GET /4/on") >= 0) {
  Serial.println("GPIO 4 on");
  output4State = "on";
  digitalWrite(output4, HIGH);
} else if (header.indexOf("GET /4/off") >= 0) {
  Serial.println("GPIO 4 off");
  output4State = "off";
  digitalWrite(output4, LOW);
}
  else if (header.indexOf("GET /5/on") >= 0) {
  Serial.println("GPIO 5 on");
  output5State = "on";
  digitalWrite(output5, HIGH);
} else if (header.indexOf("GET /5/off") >= 0) {
  Serial.println("GPIO 5 off");
  output5State = "off";
  digitalWrite(output5, LOW);
}



