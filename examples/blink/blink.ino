#define BUILTIN_LED 13

auto led_value = HIGH;

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {
  digitalWrite(BUILTIN_LED, led_value);
  led_value = !led_value;
  delay(500);
}
