
#define VRX_PIN 34
#define VRY_PIN 35
#define SW_PIN 32

#define DEADZONE 400  // tolerance range around center

int centerX = 2048;  // change if your center value is different
int centerY = 2048;  // change if your center value is different

String lastDirection = "";

void setup() {
  Serial.begin(115200);
  pinMode(SW_PIN, INPUT_PULLUP);
  Serial.println("Joystick Direction Test Started");
}

void loop() {
  int xValue = analogRead(VRX_PIN);
  int yValue = analogRead(VRY_PIN);
  bool buttonPressed = (digitalRead(SW_PIN) == LOW);

  String direction = "CENTER";

  // Determine direction based on deadzone
  if (xValue < (centerX - DEADZONE)) {
    direction = "LEFT";
  } else if (xValue > (centerX + DEADZONE)) {
    direction = "RIGHT";
  } else if (yValue < (centerY - DEADZONE)) {
    direction = "UP";
  } else if (yValue > (centerY + DEADZONE)) {
    direction = "DOWN";
  }

  if (buttonPressed) {
    direction = "JUMP";
  }

  // Print only when direction changes
  if (direction != lastDirection) {
    if (direction != "CENTER") {
      Serial.println(direction);
    }
    lastDirection = direction;
  }

  delay(100);
}
