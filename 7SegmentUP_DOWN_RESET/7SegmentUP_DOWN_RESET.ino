//Pengaturan hardware Seven Segment pins
int A = 2;
int B = 3;
int C = 4;
int D = 6;
int DP = 5;
int E = 7;
int F = 8;
int G = 9;

//pemberian status untuk push buttons pins, push buttons states, dan counter
int switchUpPin = 13;
int switchDownPin = 12;
int resetPin = 11;
int counter = 0;
int buttonUpState = 0;
int lastButtonUpState = 0;
int buttonDownState = 0;
int lastButtonDownState = 0;
int resetButtonState = 0;
int lastResetButtonState = 0;
void setup() 
{
  Serial.begin(9600);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);

  digitalWrite(DP, HIGH);

  pinMode(switchUpPin, INPUT_PULLUP);
  pinMode(switchDownPin, INPUT_PULLUP);
  pinMode(resetPin, INPUT_PULLUP);
}

void loop() 
{
  //mulai dengan menggunakan push button
  buttonUpState = digitalRead(switchUpPin);
  buttonDownState = digitalRead(switchDownPin);
  resetButtonState = digitalRead(resetPin);

  //Membaca push button status yang di tekan
  //melakukan proses untuk button yang di tekan
  if (buttonUpState != lastButtonUpState) 
  {
    if (buttonUpState == LOW) 
    {
      if (counter == 9)
      {
        counter = -1;
      }
      counter++;
      Serial.println(counter);
      changeNumber(counter);
      delay(300);
    }
    else
    {
      Serial.println("OFF");
    }
    delay(50);
  }

  if (buttonDownState != lastButtonDownState)
  {
    if (buttonDownState == LOW)
    {
      if (counter == 0)
      {
        counter = 10;
      }
      counter--;
      Serial.println(counter);
      changeNumber(counter);
      delay(300);
    }
    else
    {
      Serial.println("OFF");
    }
    delay(50);
  }

  if (resetButtonState != lastResetButtonState)
  {
    if (resetButtonState == LOW)
    {
      counter = 0;
      Serial.println(counter);
      changeNumber(counter);
      delay(300);
    }
    else
    {
      Serial.println("OFF");
    }
    delay(50);
  }

  lastButtonUpState = buttonUpState;
  lastButtonDownState = buttonDownState;
  lastResetButtonState = resetButtonState;
  changeNumber(counter);
}

//tampilan led seven segment ketika aktif.
void changeNumber(int buttonPress)
{
  switch (buttonPress)
  {
    //number 0
    case 0:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;
    //number 1
    case 1:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    //number 2
    case 2:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      break;
    //number 3
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      break;
    //number 4
    case 4:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    //number 5
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    //number 6
    case 6:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    //number 7
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    //number 8
    case 8:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    //number 9
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
  }
}
