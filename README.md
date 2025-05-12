# Motion-Based Smart Light using ESP32, PIR Sensor, and Relay

This project turns on a light automatically when **motion is detected in the dark**, using an **ESP32**, a **PIR sensor**, and an **LDR** (Light Dependent Resistor). It controls an **AC bulb** via a **relay module** for real-world automation.

---

## 🔧 Components Used

| Component           | Quantity | Description                                 |
|---------------------|----------|---------------------------------------------|
| ESP32 Dev Board     | 1        | Main microcontroller                         |
| PIR Motion Sensor   | 1        | Detects human movement                       |
| LDR + Resistor      | 1        | Senses light level (resistor: ~10kΩ)         |
| 5V 2-Channel Relay  | 1        | Switches AC load                             |
| AC Bulb + Holder    | 1        | The load controlled by relay                 |
| Breadboard + Wires  | 1 set    | For connections                              |

---

## 🧠 How It Works

1. **PIR Sensor** detects motion.
2. **LDR** checks ambient light level.
3. If **motion is detected AND it is dark**, the **relay turns ON**.
4. If no motion or bright light, the **relay stays OFF**.

---

## ⚡ Circuit Connections

### PIR Sensor
| PIR Pin | ESP32 Pin |
|---------|-----------|
| VCC     | 5V        |
| GND     | GND       |
| OUT     | GPIO 14   |

### LDR Circuit
Connect LDR between **3.3V and A0 (GPIO 34)**  
10k Resistor from A0 to GND → voltage divider

### Relay Module
| Relay Pin | ESP32 Pin |
|-----------|-----------|
| IN1       | GPIO 26   |
| VCC       | 5V        |
| GND       | GND       |

> ⚠️ Be cautious when working with AC. Ensure proper insulation and safety.

---

## 🧾 Code Summary

- Reads LDR value and PIR state.
- If LDR value < threshold **AND** PIR detects motion → turn relay ON.
- Otherwise, relay OFF.
