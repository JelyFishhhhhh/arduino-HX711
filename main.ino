#include <HX711.h>

const int DT_PIN = 6;
const int SCK_PIN = 5;

const int scale_factor = 443;
const double original=560;

HX711 scale;

void setup() {
  pinMode(13,OUTPUT);
  
  Serial.begin(9600);

  scale.begin(DT_PIN, SCK_PIN);

  scale.set_scale(scale_factor);
  scale.tare();

  Serial.println("returnZero"); 
  Serial.println(scale.get_units(5), 0);

  Serial.println("originalWeight");
  Serial.println(original);

  Serial.println("10 sec to setup");
  delay(10000);
  Serial.println("loop started.");
  Serial.println("==========");
}

double last,data;
int times=1;

void loop() {
  digitalWrite(13,HIGH);
  last=scale.get_units(10)*-1;
  if(last>=original){  
    Serial.println(times);
    Serial.println(last);
  }
  else{
    Serial.println(times);
    Serial.println(last);
    Serial.println("end.");
    delay(5000);
    exit(0);
  }
  
  digitalWrite(13,LOW);
  
  scale.power_down();
  delay(1000);
  //delay(3000);
  scale.power_up();

  times++;
}