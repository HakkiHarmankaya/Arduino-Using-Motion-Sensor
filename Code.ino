int hpin = 4; // Hareket sensörü pini.
int kpin = 3; // Kırmızı led.
int ypin = 2; // Yeşil led pin.
int hareket;
void setup() 
{
  pinMode(hpin, INPUT);
  pinMode(kpin, OUTPUT);
  pinMode(ypin, OUTPUT);
}

void loop() 
{
  hareket = digitalRead(hpin);
  if (hareket == 1)
    {
      digitalWrite(kpin, 1);
      digitalWrite(ypin, 0);
    }
    else
    {
      digitalWrite(kpin, 0);
      digitalWrite(ypin, 1);
    }
}
