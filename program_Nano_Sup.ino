//NJarpa
//Arduino&Lbview with 2 DS18

#include <OneWire.h>
#include <DallasTemperature.h>

//Umidade
#include <dht.h>

//umidade
#define dht_dpin   A0
dht DHT1;

//acionamentos
#define Led1  3
#define Led2  4
#define Led3  5
#define Led4  6
#define Led5  7
#define Led6  8
#define Led7  9
#define Led8  10
#define Led9  11
#define Led10 12
#define Led11 A1
#define Led12 A2
#define Led13 A3
#define Led14 A4

int var = 0;

 
// Data to Arduino pin 2
#define ONE_WIRE_BUS 2
 

OneWire oneWire(ONE_WIRE_BUS);
 
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void botaoLig();
void botaoDesl();
 
void setup(void)
{
  Serial.begin(9600);
  
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  pinMode(Led6, OUTPUT);
  pinMode(Led7, OUTPUT);
  pinMode(Led8, OUTPUT);
  pinMode(Led9, OUTPUT);
  pinMode(Led10, OUTPUT);
  pinMode(Led11, OUTPUT);
  pinMode(Led12, OUTPUT);
  pinMode(Led13, OUTPUT);
  pinMode(Led14, OUTPUT);

  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, HIGH);
  digitalWrite(Led4, HIGH);
  digitalWrite(Led5, HIGH);
  digitalWrite(Led6, HIGH);
  digitalWrite(Led7, HIGH);
  digitalWrite(Led8, HIGH);
  digitalWrite(Led9, HIGH);
  digitalWrite(Led10, HIGH);
  digitalWrite(Led11, HIGH);
  digitalWrite(Led12, HIGH);
  digitalWrite(Led13, HIGH);
  digitalWrite(Led14, HIGH);

  // Start up the library
  sensors.begin();

}
 
 
void loop(void)
{

   while (Serial.available() > 0) 
   {
      var = Serial.read();
      if(var == 'a'){digitalWrite(Led1, LOW);}
      if(var == 'b'){digitalWrite(Led1, HIGH);}
      
      if(var == 'c'){digitalWrite(Led2, LOW);}
      if(var == 'd'){digitalWrite(Led2, HIGH);}
      
      if(var == 'e'){digitalWrite(Led3, LOW);}
      if(var == 'f'){digitalWrite(Led3, HIGH);} 
      
      if(var == 'g'){digitalWrite(Led4, LOW);}
      if(var == 'h'){digitalWrite(Led4, HIGH);}
      
      if(var == 'i'){digitalWrite(Led5, LOW);}
      if(var == 'j'){digitalWrite(Led5, HIGH);}
      
      if(var == 'k'){digitalWrite(Led6, LOW);}
      if(var == 'l'){digitalWrite(Led6, HIGH);}
      
      if(var == 'm'){digitalWrite(Led7, LOW);}
      if(var == 'n'){digitalWrite(Led7, HIGH);}
      
      if(var == 'o'){digitalWrite(Led8, LOW);}
      if(var == 'p'){digitalWrite(Led8, HIGH);}

      if(var == 'q'){digitalWrite(Led9, LOW);}
      if(var == 'r'){digitalWrite(Led9, HIGH);}

      if(var == 's'){digitalWrite(Led10, LOW);}
      if(var == 't'){digitalWrite(Led10, HIGH);}

      if(var == 'u'){digitalWrite(Led11, LOW);}
      if(var == 'v'){digitalWrite(Led11, HIGH);}

      if(var == 'w'){digitalWrite(Led12, LOW);}
      if(var == 'y'){digitalWrite(Led12, HIGH);}

      if(var == 'x'){digitalWrite(Led13, LOW);}
      if(var == 'z'){digitalWrite(Led13, HIGH);}

      if(var == '1'){digitalWrite(Led14, LOW);}
      if(var == '2'){digitalWrite(Led14, HIGH);}
        
   }
   
  DHT1.read22(dht_dpin);
  DHT1.humidity; 
  sensors.requestTemperatures(); // Send the command to get temperatures
  String sensor1 = String(sensors.getTempCByIndex(0),DEC);
  String sensor2 = String(sensors.getTempCByIndex(1),DEC);
  String sensor3 = String(sensors.getTempCByIndex(2),DEC);
  String sensor4 = String(DHT1.humidity);
 
  String temp1 = String("A" + sensor1);
  String temp2 = String("B" + sensor2);
  String temp3 = String("C" + sensor3);
  String umid1 = String("H" + sensor4);
 
  Serial.println(temp1); 
  Serial.println(temp2); 
  Serial.println(temp3); 
  Serial.println(umid1);


}



