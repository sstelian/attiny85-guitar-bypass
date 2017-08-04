boolean ef = LOW, cb = LOW, lb = LOW;

void setup() {
  DDRB = 0b10001;
  PORTB = 0b1001;
  delay(250);
  PORTB = 0b1000;
  delay(250);
  PORTB = 0b1001;
  delay(250);
  PORTB = 0b1000;
  delay(250);
  PORTB = 0b1001;
  
}

void loop() {
  cb = debounce(lb);
  if (lb == LOW && cb == HIGH)
     ef = !ef;
  lb = cb;
  digitalWrite(4,ef);
}

boolean debounce(boolean last)
{
 boolean current = digitalRead(3);
 if (last != current) {
   delay(20);
   current = digitalRead(3);
 }
 return current;
}
