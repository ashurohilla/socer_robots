#include <ESP8266WiFi.h>
#include <espnow.h>

// Define the commands (must match the sender's enum)
enum Command {
  STOP = 0,
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};

Command receivedCommand;

// Define motor control pins
const int IN1 = D5;  // Input 1 for motor A
const int IN2 = D6;  // Input 2 for motor A
const int IN3 = D3;  // Input 1 for motor B
const int IN4 = D4;  // Input 2 for motor B

void setupMotors() {
  // Set all motor control pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Initialize motors to stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void moveForward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW);  // Stop left motor
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); // Right motor forward
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH); // Left motor forward
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  // Stop right motor
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void onReceive(uint8_t *mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&receivedCommand, incomingData, sizeof(receivedCommand));
  
  // Act based on the received command
  switch (receivedCommand) {
    case STOP:
      Serial.println("Received Command: STOP");
      stopMotors();
      break;
    case FORWARD:
      Serial.println("Received Command: FORWARD");
      moveForward();
      break;
    case BACKWARD:
      Serial.println("Received Command: BACKWARD");
      moveBackward();
      break;
    case RIGHT:
      Serial.println("Received Command: LEFT");
      turnLeft();
      break;
    case LEFT:
      Serial.println("Received Command: RIGHT");
      turnRight();
      break;
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  setupMotors();  // Initialize motor pins
  
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(onReceive);
}

void loop() {
  // The car control logic is handled in the onReceive callback function
}
