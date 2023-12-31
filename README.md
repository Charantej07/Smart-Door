# 🚪 Smart Door Bot

The Smart Door Bot is an IoT project that provides real-time door status updates to a Discord channel using a microcontroller connected to a button sensor.

## 🛠️ Setup

### 📋 Requirements

- Arduino board (ESP32/ESP8266)
- WiFi connection details (`ssid` and `password`)
- Discord bot token (`bot_token`)
- Discord channel ID (`channel_id`)

### 🛠️ Configuration

1. Connect the Arduino board and upload the provided `.ino` file.
2. Replace placeholders in the code with your specific details:
   - `ssid`: Your WiFi network name
   - `password`: Your WiFi password
   - `bot_token`: Your Discord bot token
   - `channel_id`: Your Discord channel ID

## 🚀 Usage

1. Power on the Arduino board after setup.
2. Upon startup, the board connects to the WiFi network and Discord.
3. Use the button to simulate door open/close events:
   - Pressing the button (`LOW` state) sends a Discord message indicating the door is closed.
   - Releasing the button (`HIGH` state) sends a Discord message indicating the door is open.
4. Check the Discord channel for real-time updates on the door's status.

## 💻 Code Overview

- Establishes a secure WiFi connection and connects to Discord on startup.
- Continuously monitors the button state to detect changes.
- Sends corresponding door status messages to the configured Discord channel.

## ⚙️ Requirements

- Arduino IDE
- Libraries:
  - `WiFi.h`
  - `WiFiClientSecure.h`

## ⚡ Circuit

- Connect the button to a pin on the Arduino board (`button_pin`).
- Ensure proper grounding and power connections for the button.

## 🤝 Contributing

Contributions to enhance or extend the functionality of this project are welcomed! Fork this repository, make changes, and create pull requests.

## 📄 License

This project is licensed under the [MIT License](LICENSE.md).
