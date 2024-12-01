# Soccer Bots ⚽🤖  

Welcome to the **Soccer Bots** project! This hobby project combines my passion for hardware and software to create a fun and interactive robotic soccer game where two players can compete using custom-built robots.  

## 📖 Overview  

The Soccer Bots are built using **ESP8266 boards** and communicate wirelessly using the **ESP-NOW protocol**. The system comprises two main components:  

1. **Transmitter Bot**  
   - Equipped with an **MPU6050 gyroscope sensor** to capture position and orientation.  
   - Sends precise commands to the receiver bot for motion control.  

2. **Receiver Bot**  
   - Processes the transmitted commands from the sender.  
   - Uses an **L298N motor driver** to control motors and enable smooth robot movement.  

This project blends real-time data communication, motor control, and robotics to create a fun gaming experience!  

## 🚀 Features  

- **Real-Time Communication**: Uses ESP-NOW for fast and reliable data transfer between the transmitter and receiver.  
- **Gyroscope Integration**: The MPU6050 sensor enables accurate position and orientation detection.  
- **Motor Control**: Smooth and responsive movement with the L298N motor driver.  
- **Interactive Gameplay**: Designed for a two-player soccer game with robots.  

## 🛠️ Hardware Components  

- **ESP8266 Boards** (2x): One for the transmitter and one for the receiver.  
- **MPU6050 Gyroscope Sensor**: For capturing motion and orientation data.  
- **L298N Motor Driver**: To control the motors of the receiver bot.  
- **Motors**: For movement of the receiver bot.  
- **Battery Pack**: Powering both bots.  

## 🧑‍💻 Software Components  

- **ESP-NOW Protocol**: For efficient wireless communication between the bots.  
- **Arduino IDE**: Used for programming the ESP8266 boards.  

## ⚙️ How It Works  

1. The transmitter bot reads data from the MPU6050 gyroscope sensor.  
2. The sensor data is processed to determine the bot's orientation and position.  
3. The transmitter sends this data wirelessly to the receiver bot using ESP-NOW.  
4. The receiver bot processes the commands and controls the motors using the L298N driver.  

## 🏗️ Building the Bots  

### Transmitter Setup  
1. Connect the MPU6050 to the ESP8266 board.  
2. Power the transmitter with a battery pack.  
3. Upload the transmitter code to the ESP8266.  

### Receiver Setup  
1. Connect the ESP8266 to the L298N motor driver.  
2. Wire the motors to the L298N for movement control.  
3. Upload the receiver code to the ESP8266.  

## 🎮 Gameplay  

- Use the transmitter bot to control the receiver bot's movements.  
- Two players can compete by setting up their own robots and creating a soccer field!  

## 📹 Demo Video  

Check out the bots in action here: [Insert Video Link]  

## 🌟 Future Enhancements  

- Adding more sensors for collision detection and advanced control.  
- Improving motor performance for smoother gameplay.  
- Developing an app or remote control for easier user interaction.  

## 🛠️ Tools Used  

- **Arduino IDE**  
- **ESP-NOW Protocol**  
- **Hardware Prototyping Tools**  

## 🤝 Contributing  

Have an idea or suggestion? Feel free to open an issue or submit a pull request. Collaboration is always welcome!  

## 📝 License  

This project is licensed under the MIT License.  

## 💬 Contact  

For any questions or feedback, reach out to me on:  
- **LinkedIn**: [Ashish Rohila](https://in.linkedin.com/in/ashish-rohilla-3200011ba)  
- **GitHub**: [Ashish Rohila](https://github.com/ashurohilla)  

---  

**Let’s bring the game to life with tech and fun!** 🎉  
