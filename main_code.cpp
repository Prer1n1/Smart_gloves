#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char sent[100];
int ind = 0;
const int flexPin1 = A0;
const int flexPin2 = A1;
const int flexPin3 = A2;
const int flexPin4 = A3;
int buttonPin = 9;
int v1;
int v2;
int v3;
int v4;
String str = “”;
boolean obtained = false;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}


void loop() {
    v1 = analogRead(flexPin1);
    v2 = analogRead(flexPin2);
    v3 = analogRead(flexPin3);
    v4 = analogRead(flexPin4);

    Serial.println(v1);
    Serial.println(v2);
    Serial.println(v3);
    Serial.println(v4);
    Serial.println(“  “);
    Serial.println(“  “);
    Serial.println(“  “);

    if (v1 > 890) {
      str.concat(“00”);
    }
    if (v2 > 890) {
      str.concat(“01”);
    }
    if (v3 > 890) {
      str.concat(“10”);
    }
    if (v4 > 890) {
      str.concat(“11”);
    }

    Serial.println(str);

    if (str.length() == 8) {
       int ascii = getBinVal(str);

      if (ascii == 4) {
        obtained = true;
      } else {
        if (!obtained) {
          char c = getCharVal(ascii);
          //Serial.println(“Decoded character: “);
          Serial.println(c);

          sent[ind] = c;
          ind++;
          sent[ind] = ‘\0’; 
          
          lcd.clear();
          lcd.print(sent);



          delay(1000);  

          lcd.clear();
          lcd.print(sent);
        }
      }

       str = “”;
    }

    if (obtained) {
      //lcd.clear();
      Serial.print(“Received sentence: “);
      Serial.println(sent);

      delay(5000); 

      lcd.clear();
      obtained = false;
      ind = 0;
    }

    delay(1500);
  }
  
int getBinVal(String str) {
  int bin = 0;
  int j = 0;
  int con = 0;
  int finalv = 0;
  for (int I = str.length() – 1; I >= 0; i--) {
    if (str.charAt(i) == ‘1’) {
      bin = 1;
    } else {
      bin = 0;
    }
    con = (int)(bin * (pow(2, j)) + 0.5);
    finalv = finalv + con;
    j++;
  }
  return finalv;
}


char getCharVal(int ascii) {
  char mych = char(ascii);
  return mych;
}
