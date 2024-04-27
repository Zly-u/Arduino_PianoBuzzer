
#define PIN_C     2
#define PIN_C_sh  3
#define PIN_D     4
#define PIN_D_sh  5
#define PIN_E     6
#define PIN_F     7

#define PIN_G     8
#define PIN_G_sh  9
#define PIN_A     10
#define PIN_A_sh  11
#define PIN_B     12

#define PIN_SPEAKER 13               

void setup() {
  Serial.begin(9600);

  pinMode(PIN_C,    INPUT_PULLUP);
  pinMode(PIN_C_sh, INPUT_PULLUP);
  pinMode(PIN_D,    INPUT_PULLUP);
  pinMode(PIN_D_sh, INPUT_PULLUP);
  pinMode(PIN_E,    INPUT_PULLUP);
  pinMode(PIN_F,    INPUT_PULLUP);
  pinMode(PIN_G,    INPUT_PULLUP);
  pinMode(PIN_G_sh, INPUT_PULLUP);
  pinMode(PIN_A,    INPUT_PULLUP);
  pinMode(PIN_A_sh, INPUT_PULLUP);
  pinMode(PIN_B,    INPUT_PULLUP);

  pinMode(PIN_SPEAKER, OUTPUT);
}

int note = -1;

#define LOW_HIGH -12*1
#define MAX_HIGH 12*3
void loop() {
  note = -1;
  
  // for(int pin = PIN_C; pin <= PIN_B; ++pin){
  //   if (digitalRead(pin) == HIGH){
  //     Serial.println(pin);
  //     note = pin - PIN_C;
  //     break;
  //   }
  // }

  note = -1;
  if (digitalRead(PIN_C) == LOW){
    Serial.println("Note C");
    note = PIN_C - PIN_C;
  }
  if (digitalRead(PIN_D) == LOW){
    Serial.println("Note D");
    note = PIN_D - PIN_C;
  }
  if (digitalRead(PIN_E) == LOW){
    Serial.println("Note E");
    note = PIN_E - PIN_C;
  }
  if (digitalRead(PIN_F) == LOW){
    Serial.println("Note F");
    note = PIN_F - PIN_C;
  }

  // if (digitalRead(PIN_C_sh) == HIGH){
  //   note = PIN_C_sh;
  // }

  if (note >= 0){
    tone(PIN_SPEAKER, 440.0 * pow(2.0, (note - 9 + 1)/12.0));
  } else {
    noTone(PIN_SPEAKER);
    Serial.print("\n\n\n\n\n\n\n\n\n\n");
  }
}
