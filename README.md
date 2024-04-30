# Subaru Legacy Engine Emulator Control

## Overview
This Arduino project is designed to control a diesel car engine emulator after swapping the engine with an STI petrol engine in a Subaru Legacy. It uses an Arduino board, a LiquidCrystal display, and buttons to simulate different engine speeds and conditions, helping to test and fine-tune the engine control unit (ECU).

## Hardware Requirements
- Arduino Uno or Nano board
- LiquidCrystal display (16x2 LCD)
- Pushbuttons (5x)
- Breadboard and connecting wires

## Software Dependencies
- [LiquidCrystal library](https://www.arduino.cc/en/Reference/LiquidCrystal): Used for managing the LCD display.

## Installation
1. **Arduino IDE Setup**:
   - Download and install the Arduino IDE from [Arduino's official site](https://www.arduino.cc/en/software).

2. **Library Installation**:
   - Open the Arduino IDE, navigate to `Sketch` > `Include Library` > `Manage Libraries...`
   - Search for `LiquidCrystal` and install it.

3. **Hardware Setup**:
   - Connect the LCD display to the Arduino:
     - `RS` pin to digital pin 8
     - `Enable` pin to digital pin 9
     - `D4` to digital pin 4
     - `D5` to digital pin 5
     - `D6` to digital pin 6
     - `D7` to digital pin 7
   - Connect each button to an analog pin and the other side to ground.

4. **Wiring the Control Mechanism**:
   - Connect `pinLewy` and `pinPrawy` to the corresponding digital pins for left and right control signals (pin 7 and pin 6 respectively).

## Configuration
- Modify the `opoznienie` variable in the code to adjust the delay in ms between encoder states, which affects the response speed of the engine emulation.

## Usage
- Power on the Arduino.
- Use the buttons connected to the analog pin to control the engine speed:
  - **RIGHT**: Increase RPM significantly
  - **LEFT**: Decrease RPM significantly
  - **UP**: Increment RPM
  - **DOWN**: Decrement RPM
  - **SELECT**: Reserved for future features

The LCD will display the current engine cycle count, which corresponds to the simulated RPM value.

## Function Descriptions
- `read_LCD_buttons()`: Reads the analog values from the buttons and determines which button is pressed.
- `czyscNumerek()`: Clears the RPM display on the LCD.
- `obrotyUP(int ile)`: Increases the engine RPM by a specified increment.
- `obrotyDOWN(int ile)`: Decreases the engine RPM by a specified decrement.

## Testing Code Details

The "tester" source code introduces several enhancements and operational features to fine-tune the control of the engine emulator:

### Initial RPM Setup
Upon system initialization, the `setup()` function now sets the emulator to start at a predefined RPM to simulate engine conditions immediately after ignition. For example:
- `obrotyUP(350);` sets the emulator to simulate around 2000 RPM, providing a realistic start-up scenario for testing.

### Enhanced RPM Control
The loop function (`loop()`) has been enriched with refined control over the emulator's RPM, offering more granular adjustment:
- **Right Button**: Increase RPM by 10 units.
- **Left Button**: Decrease RPM by 10 units.
- **Up Button**: Incrementally increase RPM by 1 unit.
- **Down Button**: Decrementally decrease RPM by 1 unit.
- **Select Button**: Reserved for future functionalities like engine condition presets or diagnostic modes.

### Clearing Display
The function `czyscNumerek()` is used to clear the RPM value displayed on the LCD before updating it. This ensures that the display is always clear and readable, avoiding any ghosting of previous numbers.

### RPM Adjustment Mechanism
Two functions, `obrotyUP(int ile)` and `obrotyDOWN(int ile)`, are responsible for simulating the increase and decrease in RPM. These functions manage the digital output to pins controlling the emulator's operational state, replicating the fine adjustments needed for RPM:
- Each call to `obrotyUP()` or `obrotyDOWN()` adjusts the emulator's state through a sequence of digital pin settings that mimic the electrical impulses required for changing engine speed.

### Button Debouncing
To enhance the reliability of button inputs, a locking mechanism (`blokada`) is implemented to prevent multiple readings of a single button press. This mechanism is reset only when no button is pressed (`btnNONE`), ensuring that each button action is deliberate and singular.

## Implementation Considerations
- Ensure that the analog pin used for reading button inputs is free from noise and correctly calibrated to the resistance values of your specific button setup.
- Adjust the `opoznienie` delay setting in the functions `obrotyUP()` and `obrotyDOWN()` to fine-tune how rapidly the emulator responds to control inputs, which can vary based on your specific hardware configuration.


## Contributing
Contributions to this project are welcome. Please fork the repository, make your changes, and submit a pull request with a clear explanation of your improvements or fixes.

## License
This project is released under the MIT License. Please see the LICENSE file in the repository for more details.
