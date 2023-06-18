#include <WiFi.h>
#include <WiFiClientSecure.h>

// Replace with your network credentials
const char *ssid = "Realme 8s 5G";
const char *password = "123456789";

// Replace with your Discord bot token
const char *bot_token = "MTA5NDIxMzc3MzI1NjAzMjI3Ng.GC7BuD.AAccj2YW2c6L5Q32x5-JO5w-EHkON_XrhAjJQQ";

// Replace with your Discord channel ID
const char *channel_id = "1094217495528886322";

// Replace with your Discord server hostname
const char *discord_hostname = "discord.com";

// Set the pin number for the button
const int button_pin = 27;

// Initialize button state
int button_state = HIGH;
int last_button_state = HIGH;

// Create a WiFi client to connect to Discord
WiFiClientSecure client;

void setup()
{
    // Initialize serial communication
    Serial.begin(9600);

    // Connect to Wi-Fi network
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    // Configure button pin
    pinMode(button_pin, INPUT_PULLUP);

    // Connect to Discord
    client.setInsecure();
    if (!client.connect(discord_hostname, 443))
    {
        Serial.println("Connection to Discord failed");
    }
    else
    {
        Serial.println("Connected to Discord");

        // Send hello world message to server
        String message = "{\"content\":\"Connected to Wifi, Bot is up and running now!\"}";
        String request = String("POST /api/channels/") + channel_id + "/messages HTTP/1.1\r\n" +
                         "Host: " + discord_hostname + "\r\n" +
                         "Authorization: Bot " + bot_token + "\r\n" +
                         "Content-Type: application/json\r\n" +
                         "Content-Length: " + String(message.length()) + "\r\n" +
                         "Connection: alive\r\n\r\n" +
                         message;
        client.print(request);
        Serial.println("Sent message to Discord");
    }
}

void loop()
{
    // Get current button state
    button_state = digitalRead(button_pin);

    if (button_state != last_button_state)
    {
        // If button state has changed, send message to Discord
        String message;
        if (button_state == LOW)
        {
            message = "{\"content\":\"Lab is Closed\"}";
            Serial.println("Lab is Closed");
            last_button_state = LOW;
        }
        else
        {
            message = "{\"content\":\"Lab is Open\"}";
            Serial.println("Lab is Open");
            last_button_state = HIGH;
        }

        String request = String("POST /api/channels/") + channel_id + "/messages HTTP/1.1\r\n" +
                         "Host: " + discord_hostname + "\r\n" +
                         "Authorization: Bot " + bot_token + "\r\n" +
                         "Content-Type: application/json\r\n" +
                         "Content-Length: " + String(message.length()) + "\r\n" +
                         "Connection: alive\r\n\r\n" +
                         message;

        if (!client.connected() && !client.connect(discord_hostname, 443))
        {
            Serial.println("Connection to Discord failed");
            return;
        }

        client.print(request);
        Serial.println("Sent message to Discord");
    }

    // Wait for a short time before checking button again
    delay(100);
}
