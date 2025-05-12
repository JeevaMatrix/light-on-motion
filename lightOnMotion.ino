#define RELAY1 26
#define PIR_PIN 14

unsigned long lastMotionTime = 0;
const unsigned long lightTimeout = 10000;

void setup(){
  Serial.begin(115200);
  pinMode(RELAY1, OUTPUT);
  pinMode(PIR_PIN, INPUT);

  digitalWrite(RELAY1, HIGH); //as 2ch relay is active low
}
void loop(){
  int motion = digitalRead(PIR_PIN);

  if(motion == HIGH){
    digitalWrite(RELAY1, LOW); //as active low relay
    lastMotionTime = millis();

  }
  if(digitalRead(RELAY1) == LOW && (millis()-lastMotionTime > lightTimeout)){
    digitalWrite(RELAY1, HIGH);
    Serial.println("No motion for 10sec - Turn OFF light");
  }
  delay(100);
}