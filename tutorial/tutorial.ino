#define LED_PIN 13U

const unsigned int PULSE_INTERVAL_SECONDS = 1;
unsigned long LAST_PULSE_TIME = 0;
bool LED_STATE = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
}

void loop() {
  if (millis() - LAST_PULSE_TIME > PULSE_INTERVAL_SECONDS * 1000)
  {
    
    Serial.println("toggling");
    LED_STATE = !LED_STATE;
    Serial.println(LED_STATE);
    LAST_PULSE_TIME = millis();
  }
  digitalWrite(LED_PIN, LED_STATE);

}
