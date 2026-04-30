/*
  Driver Drowsiness Alert System
  
*/

// ===============================
// Pin Definitions
// ===============================
const int IR_SENSOR_PIN = 3;   // IR sensor input pin
const int BUZZER_PIN = 8;      // Buzzer output pin

// Motor Driver Pins
const int MOTOR_IN1 = 9;
const int MOTOR_IN2 = 10;
const int MOTOR_IN3 = 11;
const int MOTOR_IN4 = 12;

// ===============================
// Timing Variables (in milliseconds)
// ===============================
const unsigned long STAGE1_TIME = 2000;   // 2 sec warning
const unsigned long STAGE2_TIME = 4000;   // 4 sec stronger warning
const unsigned long STOP_TIME   = 7000;   // 7 sec motor stop

// ===============================
// Global Variables
// ===============================
unsigned long eyesClosedStartTime = 0;  // Stores when eyes first closed
bool eyesWereClosed = false;            // Tracks previous eye state

// ===============================
// Setup Function
// ===============================
void setup() {

  // Sensor and buzzer configuration
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Motor pin configuration
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_IN3, OUTPUT);
  pinMode(MOTOR_IN4, OUTPUT);

  // Start motors initially
  startMotors();
}

// ===============================
// Main Loop Function
// ===============================
void loop() {

  // Read IR sensor state
  bool eyesClosed = digitalRead(IR_SENSOR_PIN);

  // If eyes are closed
  if (eyesClosed == HIGH) {

    // First time eyes closed
    if (!eyesWereClosed) {
      eyesClosedStartTime = millis();  // Record start time
      eyesWereClosed = true;
    }

    // Calculate duration of eye closure
    unsigned long t = millis() - eyesClosedStartTime;

    // ---------------------------
    // Stage 1: Mild Warning
    // ---------------------------
    if (t >= STAGE1_TIME && t < STAGE2_TIME) {
      tone(BUZZER_PIN, 1000, 200);  // 1000 Hz beep for 200 ms
      maintainMotors();             // Keep vehicle running
    }

    // ---------------------------
    // Stage 2: Strong Warning
    // ---------------------------
    else if (t >= STAGE2_TIME && t < STOP_TIME) {
      tone(BUZZER_PIN, 2000, 300);  // Stronger warning
      maintainMotors();
    }

    // ---------------------------
    // Stage 3: Emergency Stop
    // ---------------------------
    else if (t >= STOP_TIME) {
      tone(BUZZER_PIN, 4000);       // Continuous alarm
      stopMotors();                 // Stop vehicle
    }

  }

  // ==========================
  // If eyes are open
  // ==========================
  else {
    eyesWereClosed = false;   // Reset closure tracking
    noTone(BUZZER_PIN);       // Stop buzzer
    startMotors();            // Restart motors
  }

  // Small delay for stable readings
  delay(50);
}

// ===============================
// MOTOR FUNCTIONS
// ===============================

// Start motors (vehicle moving)
void startMotors() {
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);

  digitalWrite(MOTOR_IN3, HIGH);
  digitalWrite(MOTOR_IN4, LOW);
}

// Maintain normal movement
void maintainMotors() {
  startMotors();
}

// Stop motors completely
void stopMotors() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);

  digitalWrite(MOTOR_IN3, LOW);
  digitalWrite(MOTOR_IN4, LOW);
}
