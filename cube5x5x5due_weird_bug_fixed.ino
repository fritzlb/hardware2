byte ledpins[25];
byte layerpins[5];

unsigned long millisold = 0;
void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);

ledpins[0]=5;
ledpins[1]=7;
ledpins[2]=6;
ledpins[3]=3;
ledpins[4]=4;

ledpins[5]=37;
ledpins[6]=25;
ledpins[7]=23;
ledpins[8]=31;
ledpins[9]=29;

ledpins[10]=38;
ledpins[11]=36;
ledpins[12]=42;
ledpins[13]=40;
ledpins[14]=39;

ledpins[15]=41;
ledpins[16]=35;
ledpins[17]=27;
ledpins[18]=33;
ledpins[19]=34;

ledpins[20]=26;
ledpins[21]=28;
ledpins[22]=32;
ledpins[23]=24;
ledpins[24]=30;

layerpins[0]=12;
layerpins[1]=10;
layerpins[2]=9;
layerpins[3]=11;
layerpins[4]=8;

for (int i = 0; i < 25; i++) {
  pinMode(ledpins[i], OUTPUT);
}
for (int i = 0; i < 5; i++) {
  pinMode(layerpins[i], OUTPUT);
}

}

byte leds[5][25];

int mode = 0;
int step = 0;
void loop() {
  if (mode > 29) {
    mode = 0;
  }
  for (byte i = 0; i < 5; i++) {
    digitalWrite(layerpins[i], HIGH);
      for (byte j = 0; j < 25; j++) {
        digitalWrite(ledpins[j], leds[i][j]);
      }
      delayMicroseconds(600);
      for (byte j = 0; j < 25; j++) {
        digitalWrite(ledpins[j], 0);
      }
    digitalWrite(layerpins[i], LOW);
  }
  
  if (mode == 0) {
    if (millis() - millisold > 100) {
      if (step < 125) {
        for (byte i = 0; i < 25; i++) {
          leds[0][i] = 0;
          leds[1][i] = 0;
          leds[2][i] = 0;
          leds[3][i] = 0;
          leds[4][i] = 0;
        }
        leds[int(step/25)][step%25] = 1;
      }

      step++;
      if (step > 125) {
        step = 0;
        mode++;
      }
      millisold = millis();
    }
  }

  if (mode == 1 || mode == 2 || mode == 3 || mode == 4 || mode == 5) {
    if (millis() - millisold > 150) {
      Serial.println("hor");
      Serial.println(mode);
      Serial.println(step);
      if (step == 0) {
        for (byte i = 0; i < 25; i++) {
          leds[0][i] = 1;
          leds[1][i] = 0;
          leds[2][i] = 0;
          leds[3][i] = 0;
          leds[4][i] = 0;
        }
      }
      else if (step == 1) {
        for (byte i = 0; i < 25; i++) {
          leds[0][i] = 0;
          leds[1][i] = 1;
          leds[2][i] = 0;
          leds[3][i] = 0;
          leds[4][i] = 0;
        }
      }
      else if (step == 2) {
        for (byte i = 0; i < 25; i++) {
          leds[0][i] = 0;
          leds[1][i] = 0;
          leds[2][i] = 1;
          leds[3][i] = 0;
          leds[4][i] = 0;
        }
      }
      else if (step == 3) {
        for (byte i = 0; i < 25; i++) {
          leds[0][i] = 0;
          leds[1][i] = 0;
          leds[2][i] = 0;
          leds[3][i] = 1;
          leds[4][i] = 0;
        }
      }
      else if (step == 4) {
        for (byte i = 0; i < 25; i++) {
          leds[0][i] = 0;
          leds[1][i] = 0;
          leds[2][i] = 0;
          leds[3][i] = 0;
          leds[4][i] = 1;
        }
      }
      else if (step == 5) {
        for (byte i = 0; i < 25; i++) {
          leds[0][i] = 0;
          leds[1][i] = 0;
          leds[2][i] = 0;
          leds[3][i] = 1;
          leds[4][i] = 0;
        }
      }
      else if (step == 6) {
        for (byte i = 0; i < 25; i++) {
          leds[0][i] = 0;
          leds[1][i] = 0;
          leds[2][i] = 1;
          leds[3][i] = 0;
          leds[4][i] = 0;
        }
      }
      else if (step == 7) {
        for (byte i = 0; i < 25; i++) {
          leds[0][i] = 0;
          leds[1][i] = 1;
          leds[2][i] = 0;
          leds[3][i] = 0;
          leds[4][i] = 0;
        }
      }

      step++;
      if (step > 7) {
        step = 0;
        mode++;
      }
      millisold = millis();
    }
  }

  if (mode > 5 && mode < 30) { 
    if (millis() - millisold > 150) {
      Serial.println("vert");
      Serial.println(mode);
      Serial.println(step);
      allOff();
      Serial.print("nach alloff: ");
      Serial.println(mode);


      byte fuenfmultp[5]; //the mcu hates multiplication for whatever reason... probably ram.
      fuenfmultp[0] = 0;
      fuenfmultp[1] = 5;
      fuenfmultp[2] = 10;
      fuenfmultp[3] = 15;
      fuenfmultp[4] = 20;

      for (byte k = 0; k < 5; k++) {
        byte stepsnow = fuenfmultp[step]+k;
        leds[0][stepsnow] = 1;
        leds[1][stepsnow] = 1;
        leds[2][stepsnow] = 1;
        leds[3][stepsnow] = 1;
        leds[4][stepsnow] = 1;
        Serial.print("loop");
        Serial.print(k);
        Serial.println(mode);
      }
        Serial.print("mode now ");
        Serial.println(mode);
      step++;
      if (step > 5) {
        Serial.print("old mode ");
        Serial.println(mode);
        step = 0;
        mode++;
        allOff();
        Serial.print("new mode");
        Serial.println(mode);
      }
      millisold = millis();
    }
  }
  
}
void allOff() {
  for (byte i = 0; i < 5; i++) {
    for (byte j = 0; j < 25; j++) {
      leds[i][j] = 0;
    }
  }
}
