const int SW1 = 2;

bool led_state = 0;

bool sw_state_now = 0;
bool sw_state_old = 0;

void setup() {

  pinMode(SW1, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, led_state);

  Serial.begin(9600);
}

void loop() {

  if(digitalRead(SW1) != sw_state_old){
    delay(10);
    sw_state_now = digitalRead(SW1);
  }

  if(sw_state_now != sw_state_old){
    led_state = sw_state_now;
    Serial.println(led_state);
  }
  sw_state_old = sw_state_now;


  digitalWrite(LED_BUILTIN, led_state);

}
