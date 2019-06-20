#include <Adafruit_Fingerprint.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include<Keypad.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(12, 13);

String password1 = "123456789011";
String password2 = "123456789012";
String password10 = "123456789110";
String password11 = "123456789111";
String password12 = "123456789112";

const byte ROWS = 4;
const byte COLS = 3;
int n = 0;

int flag1 = 0;
int flag2 = 0;
int flag10 = 0;
int flag11 = 0;
int flag12 = 0;



//**pushbutton**//
int buttonPin1 = 9;   // choose the input pin (for a pushbutton)
int buttonPin2 = 10;
int val1 = 0;     // variable for reading the pin status
int val2 = 0;
int j = 0;
int k = 0;
//**keypad**//
String keys = "";
char keypressed;
char keyMap[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {8, 7, 6, 5};
byte colPins[COLS] = {4, 3, 2};

Keypad myKeypad = Keypad(makeKeymap(keyMap), rowPins, colPins, ROWS, COLS );
LiquidCrystal_I2C lcd(0x3F, 16, 2);
Servo myservo;
int getFingerprintIDez();
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()
{
  Serial.begin(9600);
  myservo.attach(11);       //declare servo as input
  pinMode(buttonPin1, INPUT);    // declare pushbutton as input
  pinMode(buttonPin2, INPUT);    // declare pushbutton as input
  lcd.backlight();
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("Enter Your ");
  lcd.setCursor(0, 1);
  lcd.print("ADHAAR Number :-");
  myservo.write(180);

  //**fingerptint scanner**//
  Serial.begin(9600);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");

  // set the data rate for the sensor serial port
  finger.begin(57600);

  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) {
      delay(1);
    }
  }

  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
}
void loop()
{
  char keypressed = myKeypad.getKey();

  if (keypressed)
  {
    if (n >= 12)
    {
      n++;
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ADHAAR NUMBER :-");
      lcd.setCursor(0, 1);
      keys += keypressed;
      n = n + 1;
      //Serial.println(keys);
      lcd.print(keys);

    }
  }
  if (keypressed == '*')
  {
    if (keys == password1)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("PlaceYourThumb");
      lcd.setCursor(0, 1);
      lcd.print("On Scanner");
      vote();
    }
    else if (keys == password2)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("PlaceYourThumb");
      lcd.setCursor(0, 1);
      lcd.print("On Scanner");
      vote();
    }
    else if (keys == password10)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("PlaceYourThumb");
      lcd.setCursor(0, 1);
      lcd.print("On Scanner");
      vote();
    }
    else if (keys == password11)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("PlaceYourThumb");
      lcd.setCursor(0, 1);
      lcd.print("On Scanner");
      vote();
    }
    else if (keys == password12)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("PlaceYourThumb");
      lcd.setCursor(0, 1);
      lcd.print("On Scanner");
      vote();
    }
    
    else
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("WRONG ADHAAR");
      //lcd.setCursor(2, 1);
      //lcd.print("ADHAAR");
    }
  }
  if (keypressed == '#')
  {
    keys = "";
    n = 0;

    keypressed = "";
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ADHAAR NUMBER :-");
  }

}

/*void pushbutton()
  {
  delay(5000);
  val = digitalRead(buttonPin);  // read input value

  if (val == HIGH )         // check if the input is HIGH (button released)
  {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You have voted");
    lcd.setCursor(0, 3);
    lcd.print("for BJP");
    delay(3000);
    lcd.clear();
  }
  }*/


void vote()
{
  delay(5000);
  if (getFingerprintIDez() >= 0)
  {

    doorOpen();
    delay(7000);
    doorClose();
  }
}

void doorOpen()
{

  if (finger.fingerID == 4 && keys == password1)
  {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("VOTE NOW");
    lcd.setCursor(2, 1);
    lcd.print("ANIRBAN");
    myservo.write(0);
    delay(3000);

    pushbutton();
    flag1 = 4;

  }
  if (finger.fingerID == 6 && keys == password2)
  {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("VOTE NOW");
    lcd.setCursor(2, 1);
    lcd.print("SNEHANJAN");
    myservo.write(0);
    delay(3000);

    pushbutton();

    flag2 = 6;

  }
  if (finger.fingerID == 10 && keys == password10)
  {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("VOTE NOW");
    lcd.setCursor(2, 1);
    lcd.print("TR SIR");
    myservo.write(0);
    delay(3000);

    pushbutton();

    flag10 = 10;

  }
  if (finger.fingerID == 11 && keys == password11)
  {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("VOTE NOW");
    lcd.setCursor(2, 1);
    lcd.print("SPS SIR");
    myservo.write(0);
    delay(3000);

    pushbutton();

    flag11 = 11;


  }
  if (finger.fingerID == 12 && keys == password12)
  {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("VOTE NOW");
    lcd.setCursor(2, 1);
    lcd.print("RC SIR");
    myservo.write(180);
    delay(3000);

    pushbutton();

    flag12 = 12;


  }
  
}

void pushbutton()
{
  delay(2000);
  val1 = digitalRead(buttonPin1);  // read 1st input value
  val2 = digitalRead(buttonPin2); // read 2nd input value
  if (flag1 == 4 && finger.fingerID == 4)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You have already");
    lcd.setCursor(0, 1);
    lcd.print("voted");
    Serial.print("Anirban has already voted!");
  }
  else if (flag2 == 6 && finger.fingerID == 6)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You have already");
    lcd.setCursor(0, 1);
    lcd.print("voted");
    Serial.print("Snehanjan has already voted!");
  }
  else if (flag10 == 10 && finger.fingerID == 10)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You have already");
    lcd.setCursor(0, 1);
    lcd.print("voted");
    Serial.print("TR SIR has already voted!");
  }
  else if (flag11 == 11 && finger.fingerID == 11)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You have already");
    lcd.setCursor(0, 1);
    lcd.print("voted");
    Serial.print("SPS SIR has already voted!");
  }
  else if (flag12 == 12 && finger.fingerID == 12)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You have already");
    lcd.setCursor(0, 1);
    lcd.print("voted");
    Serial.print("RC SIR has already voted!");
  }
  

  else
  {
    if (val1 == 1)            // check if the input is HIGH (button released)
    {
      //digitalWrite(ledPin, LOW);// turn LED OFF
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You have voted");
      lcd.setCursor(0, 3);
      lcd.print("for BJP");
      j = j + 1;
      Serial.print("Votes for BJP  "); Serial.println(j);
      delay(3000);
      lcd.clear();
    }
    if (val2 == HIGH)    // check if the input is HIGH (button released)
    {
      //digitalWrite(ledPin, LOW);// turn LED OFF
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You have voted");
      lcd.setCursor(0, 3);
      lcd.print("for CONGRESS");
      k++;
      Serial.print("Votes for CONGRESS  "); Serial.println(k);
      delay(3000);
      lcd.clear();
    }
    else
    {
      //digitalWrite(ledPin, HIGH);  // turn LED ON

    }
  }
}

void doorClose()
{
  myservo.write(180);
  keys = "";
  n = 0;
  keypressed = "";
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Your ");
  lcd.setCursor(0, 1);
  lcd.print("ADHAAR Number :-");
}


uint8_t getFingerprintID()
{
  uint8_t p = finger.getImage();
  switch (p)
  {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p)
  {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK)
  {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
}
