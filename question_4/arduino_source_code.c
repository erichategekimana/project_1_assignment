// Pin Definitions
const int TRIG_PIN = 9;
const int ECHO_PIN = 8;
const int BUZZER_PIN = 10;
const int GREEN_LED = 11;
const int RED_LED = 12;

// Threshold for parking occupancy in centimeters
const float OCCUPANCY_THRESHOLD_CM = 50.0;

void setup() {
  // Initialize Serial Monitor for debugging and verification
  Serial.begin(9600);

  // Configure Pin Modes
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Initial State: Turn all outputs OFF
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  noTone(BUZZER_PIN);
}

// Function to measure distance in centimeters using HC-SR04
float read_ultrasonic_distance_cm() {
  // Ensure trigger pin is low
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send a 10-microsecond HIGH pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure pulse duration on ECHO pin in microseconds
  long duration_us = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout

  // If no echo received within timeout, consider it out of range
  if (duration_us == 0) {
    return 400.0; 
  }

  // Distance = (duration * speed_of_sound) / 2
  float distance_cm = (duration_us * 0.0343) / 2.0;
  return distance_cm;
}

// Function to update actuators based on space occupancy
void update_indicators(bool is_occupied) {
  if (is_occupied) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    tone(BUZZER_PIN, 1000);
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);  
    noTone(BUZZER_PIN);             
  }
}

void loop() {
  float distance = read_ultrasonic_distance_cm();

  // Evaluate occupancy condition
  bool is_occupied = (distance <= OCCUPANCY_THRESHOLD_CM);

  // Apply output decisions
  update_indicators(is_occupied);

  // Output to Serial Monitor for live test recording
  Serial.print("Detected Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Status: ");
  if (is_occupied) {
    Serial.println("OCCUPIED [Red ON, Green OFF, Buzzer ON]");
  } else {
    Serial.println("AVAILABLE [Green ON, Red OFF, Buzzer OFF]");
  }

  delay(200); // Sampling rate of 5 Hz
}