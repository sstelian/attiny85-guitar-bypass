#define BUTTON_PIN     3
#define RELAY_PIN      4
#define STATUS_LED_PIN 0

boolean bypassDisabled = LOW, currentButtonState = LOW, lastButtonState = LOW;

void setup() {
  //pin mode setup
  pinMode(STATUS_LED_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, 1);
  //blink status led on startup
  for (byte i = 1; i <= 5; i++)
  {
    digitalWrite(STATUS_LED_PIN, (i % 2));
    delay(250);
  }
}

void loop() {
  //debounce button
  currentButtonState = debounce(lastButtonState);
  //toggle bypass on each button press
  if (lastButtonState == LOW && currentButtonState == HIGH)
     bypassDisabled = !bypassDisabled;
  lastButtonState = currentButtonState;
  digitalWrite(RELAY_PIN, bypassDisabled);
}

//button debouncing function
boolean debounce(boolean last)
{
 boolean current = digitalRead(BUTTON_PIN);
 if (last != current) {
   delay(20);
   current = digitalRead(BUTTON_PIN);
 }
 return current;
}
