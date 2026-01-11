# 🎯 Computer-Vision Ball Balancer

This is a **vision-based autonomous version** of the ball balancer.  
A **laptop camera** is used in this phase to **validate the computer vision system and control loop** before moving to the final embedded camera hardware.

---

### 🎥 Vision-Based Control Test

This video demonstrates the ball balancer operating using **real-time camera feedback** from a laptop webcam.  
The camera tracks the ball position and the controller adjusts the servos in real time to keep the ball centered.

https://github.com/user-attachments/assets/05046abd-455c-4f7d-9ce4-ba65d60c6b68

---

## ✨ Features
- Real-time ball tracking using computer vision  
- Closed-loop feedback control for autonomous stabilization  
- 3-servo platform with synchronized motion  
- Laptop camera used for rapid vision testing  
- SolidWorks CAD models of the platform and linkages  

---

## 🛠️ Tools & Technologies
- **SolidWorks** – CAD modeling and design  
- **Laptop camera** – vision input for testing  
- **OpenCV (Python/C++)** – ball detection and tracking  
- **Arduino IDE (C++)** – servo control  
- **Git/GitHub** – version control and documentation  

---

## 🚀 Next Steps
- Move vision processing to **ESP32-CAM**  
- Implement **PID control** for smoother stabilization  
- Improve **tracking accuracy and latency**  
- Refine CAD models for smoother and more reliable operation  
