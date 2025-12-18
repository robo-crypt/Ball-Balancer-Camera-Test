# 🎱 Ball Balancer – Camera-Based Control Test

This repository documents a **camera-based control test** for a 3-servo ball balancing platform.  
The current setup uses a **laptop camera** to detect a ball position in the camera frame and send that position to an Arduino, which tilts the platform accordingly.

At this stage, the ball is **not physically on the platform**. The purpose of this project is to validate the **computer vision pipeline and control-to-actuation response** before introducing full physical ball balancing.

---

## 🔁 Project Context & Development Stages
- **Phase 1:** Joystick-controlled platform (mechanical and kinematic validation)
- **Phase 2 (current):** Camera-based ball detection driving platform tilt (vision + control testing)
- **Phase 3 (planned):** Physical ball-on-platform stabilization using closed-loop PID control

This staged approach allows each subsystem to be validated independently.

---

## ✨ Key Features
- 3-servo parallel platform (120° spacing)
- Laptop camera for real-time ball detection
- Vision-based position data sent to Arduino
- Platform tilt proportional to detected ball position
- Modular architecture designed for future onboard camera integration

---

## 📷 Camera-Based Control Test (Current Setup)

In the current test configuration, a laptop camera is used as the vision sensor.  
Computer vision techniques detect the ball’s position within the camera frame, and the calculated position error is transmitted to the Arduino controller.

The Arduino then tilts the platform in a direction intended to counteract the detected ball position. This allows verification of the **end-to-end control pipeline**, even without the ball physically interacting with the platform.

This test focuses on validating:
- Ball detection accuracy using a non-dedicated camera
- Stability and repeatability of centroid estimation
- Communication between vision system and Arduino
- Platform response to vision-based position commands
- Correct direction and scaling of servo actuation

---

## 🧠 System Overview

**Control Flow (Current Test):**
1. Laptop camera captures a top-down image
2. OpenCV processes the image to detect the ball
3. Ball centroid \((x, y)\) is computed in image space
4. Position error relative to frame center is calculated
5. Position data is sent to the Arduino via serial communication
6. Arduino computes platform tilt based on the received position
7. Servos actuate the platform accordingly

---

## 👁️ Computer Vision Pipeline
- Image acquisition from laptop webcam
- Color thresholding / contour filtering
- Ball contour detection
- Centroid extraction for position estimation
- Scaling and normalization of position data
- Noise filtering for stable control input

---

## 🛠️ Tools & Technologies

### Hardware
- Laptop webcam (temporary vision sensor)
- Arduino (servo control)
- 3× servo motors
- Custom 3D-printed platform and linkages

### Software
- **OpenCV (Python/C++)** – ball detection and tracking
- **Arduino (C++)** – servo actuation based on vision input
- **SolidWorks** – mechanical design
- **Git/GitHub** – version control and documentation

---

## 📷 Demo

> _Laptop camera detects ball position and drives platform tilt (ball not yet on platform)._

```html
<img src="images/camera_control_test.jpg" width="600">
