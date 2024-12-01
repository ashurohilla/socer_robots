#include <Wire.h>
#include <MPU6050.h>
#include <ESP8266WiFi.h>
#include <espnow.h>

// Create an MPU6050 object
MPU6050 mpu;
uint8_t broadcastAddress[] = {0xE0, 0x98, 0x06, 0x91, 0x76, 0x1D}; // Replace with the MAC address of the receiver

enum Command {
  STOP = 0,
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};

// Define the threshold value
const int16_t threshold = 6000;  // Adjust this value based on your needs

void onSent(uint8_t *macAddr, uint8_t sendStatus) {
  Serial.print("Last Packet Send Status: ");
  Serial.println(sendStatus == 0 ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize I2C communication
  Wire.begin(D2, D1);  // Specify the SDA and SCL pins
  
  // Initialize the MPU6050
  Serial.println("Initializing MPU6050...");
  mpu.initialize();

  // Check if the connection is successful
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connected successfully!");
  } else {
    Serial.println("MPU6050 connection failed. Check your wiring.");
    while (1);
  }

  WiFi.mode(WIFI_STA);
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(onSent);
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

Command getMovementCommand(int16_t ax, int16_t ay, int16_t az, int16_t gx, int16_t gy, int16_t gz) {
  int Threshold = 6000; // Accelerometer threshold

  if (ax > Threshold) {
    return LEFT;
  } else if (ax < -Threshold) {
    return RIGHT;
  } else if (ay > Threshold) {
    return FORWARD;
  } else if (ay < -Threshold) {
    return BACKWARD;
  } else {
    return STOP;
  }
}
void loop() {
  // Variables to store the accelerometer and gyroscope data
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  // Read the raw data from the MPU6050
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);


  Command movementCommand = getMovementCommand(ax, ay, az, gx, gy, gz);
esp_now_send(broadcastAddress, (uint8_t *)&movementCommand, sizeof(movementCommand));


  // Print the accelerometer data for debugging
  // Serial.print("Accel X: "); Serial.print(ax);
  // Serial.print(" | Accel Y: "); Serial.print(ay);
  // Serial.print(" | Accel Z: "); Serial.println(az);

  // Delay for a short period before the next loop
  delay(20);
}
