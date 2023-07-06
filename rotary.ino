#define CLK 19
#define DT 18
#define SW 5

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDIR = "";
unsigned long lastButtonPress = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("Ready...");

  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);

//  digitalWrite(CLK, HIGH);
//  digitalWrite(DT, HIGH);
//  digitalWrite(SW, HIGH);

  lastStateCLK = digitalRead(CLK);
}

void loop() {
  // put your main code here, to run repeatedly:

  currentStateCLK = digitalRead(CLK);

  if (currentStateCLK != lastStateCLK && currentStateCLK == 1) {

    if (digitalRead(DT) == currentStateCLK) {
      counter--;
      currentDIR = "Berlawanan Putar Jarum Jam";
    }
    else {
      counter++;
      currentDIR = "Searah Putar Jarum Jam";
    }

    Serial.print(currentDIR);
    Serial.print(" | ");
    Serial.println(counter);
    
  }

  lastStateCLK = currentStateCLK;

  int btnState = digitalRead(SW);

  if (btnState == LOW) {
    if (millis() - lastButtonPress > 50) {
      Serial.println("Button Di Tekan..");
    }

    lastButtonPress = millis();
  }

  delay(1);
}
