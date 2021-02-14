const int SW1 = 2;

bool led_state = 0;

bool sw_state = 0;

void setup() {

  pinMode(SW1, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, led_state);
}

void loop() {

  sw_state = digitalRead(SW1);

  led_state = sw_state;

  digitalWrite(LED_BUILTIN, led_state);

}
