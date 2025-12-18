#include <Servo.h>
#include <math.h>

Servo servo1, servo2, servo3;

float dx = 0;
float dy = 0;
String inputString = "";

// Arm lengths in cm
const float L1 = 5.0;  // Lower arm
const float L2 = 7.0;  // Upper arm

// Tilt scaling factors
const float ALPHA_MULTIPLIER = 1.5;
const float BETA_MULTIPLIER  = 1.5;

// Platform tilt angles (deg)
float alpha = 0;
float beta = 0;

// Convert degrees to radians
float degToRad(float deg) {
  return deg * PI / 180.0;
}

// Inverse kinematics calculation
float calculateZ(float x, float y, float alphaDeg, float betaDeg) {
  float alphaRad = degToRad(alphaDeg);
  float betaRad  = degToRad(betaDeg);
  return x * tan(alphaRad) + y * tan(betaRad);
}

// Convert vertical displacement to servo angle
float zToServoAngle(float z) {
  float ratio = constrain(z / L1, -1.0, 1.0); // prevent NaN
  float angleRad = asin(ratio);
  return angleRad * 180.0 / PI;
}

// ✅ Floating-point map function (GLOBAL, not inside loop)
float fmap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  Serial.begin(9600);

  servo1.write(150);
  servo2.write(150);
  servo3.write(150);
}

void loop() {
  if (Serial.available()) {
    inputString = Serial.readStringUntil('\n');
    int commaIndex = inputString.indexOf(',');
    if (commaIndex > 0) {
      String dxStr = inputString.substring(0, commaIndex);
      String dyStr = inputString.substring(commaIndex + 1);

      dx = dxStr.toInt();
      dy = dyStr.toInt();
    }

    // ✅ Use fmap instead of map()
    alpha = fmap(dx, -320.0, 320.0, -11.0, 11.0) * ALPHA_MULTIPLIER;
    beta  = fmap(dy, -240.0, 240.0, -11.0, 11.0) * BETA_MULTIPLIER;

    // Servo platform positions (radius 9.5 cm, 120° apart)
    float x1 = 0,     y1 = 9.5;
    float x2 = -8.22, y2 = -4.75;
    float x3 =  8.22, y3 = -4.75;

    // Calculate Z displacement
    float z1 = calculateZ(x1, y1, alpha, beta);
    float z2 = calculateZ(x2, y2, alpha, beta);
    float z3 = calculateZ(x3, y3, alpha, beta);

    // Convert Z to servo angles
    float a1 = 150 + zToServoAngle(z1);
    float a2 = 150 + zToServoAngle(z2);
    float a3 = 150 + zToServoAngle(z3);

    // Clamp
    a1 = constrain(a1, 0, 180);
    a2 = constrain(a2, 0, 180);
    a3 = constrain(a3, 0, 180);

    // Move servos
    servo1.write(a1);
    servo2.write(a2);
    servo3.write(a3);

    // Debug output
    Serial.print("alpha=");
    Serial.print(alpha, 2); // print with 2 decimal places
    Serial.print(" beta=");
    Serial.println(beta, 2);
  }
}
