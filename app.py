import serial
import pyautogui
import time

# --- CHANGE THIS TO YOUR ESP32 PORT ---
# Example: "COM3" on Windows or "/dev/ttyUSB0" on Linux
PORT = "COM13"
BAUD_RATE = 115200

# --- Connect to ESP32 Serial ---
ser = serial.Serial(PORT, BAUD_RATE, timeout=1)
time.sleep(2)  # wait for ESP32 to initialize

print("✅ Connected to ESP32 joystick")
print("🎮 Ready to play Subway Surfers!")

# --- Main Loop ---
while True:
    line = ser.readline().decode().strip()
    if not line:
        continue

    print(f"Received: {line}")

    # --- Map joystick directions to keyboard keys ---
    if line == "LEFT":
        pyautogui.press("left")
    elif line == "RIGHT":
        pyautogui.press("right")
    elif line == "UP" or line == "JUMP":
        pyautogui.press("up")
    elif line == "DOWN":
        pyautogui.press("down")

    # Small delay to prevent spam
    time.sleep(0.15)
