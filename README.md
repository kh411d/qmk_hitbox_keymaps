# QMK REVIUNG41 Keyboard + Hitbox keymapping
The SOCD Hitbox implementation was based on [QMK_HID_Gamepad_with_SOCD](https://github.com/brentaro/QMK_HID_Gamepad_with_SOCD/#qmk_hid_gamepad_with_socd)

# Layouts
Default layers from original keyboard layout is included with some modification and adjustment.

Additional hitbox layers,

**<ins>Note on Default SOCD behavior for ALL layouts</ins>:**
- **DPAD Behavior**
  - Up + Down = Up
  - Left + Right = Neutral
- **LS and RS behavior**
  - Up + Down = Up
  - Left + Right = Last Input Wins
---

![hitbox]()

**hitBox style layout** 
Hold the Space key and then press T, use Left Shift to go back to the keyboard mode

---

![crossup]()

**Cross|Up style layout** SOCD is Last Input Wins. 
Hold the Space key and then press G, use Left Shift to go back to the keyboard mode

---


# Download already generated hex file


# Self Compile the HEX file 
Copy the `hitbox/` directory to keymaps directory of your cloned `qmk_firmware` repository,
```
- qmk_firmware
--- keyboards
------ reviung
--------- reviung41
------------- keymaps
---------------- hitbox
``` 

Make sure your ![QMK environment is already setup](https://docs.qmk.fm/#/newbs_getting_started)
run command under your `qmk_firmware` directory,
```
% cd qmk_firmware
% qmk compile -kb reviung/reviung41 -km hitbox
```
Hex file should be created on your qmk_firmware directory

Use ![QMK toolbox](https://github.com/qmk/qmk_toolbox) ![to flash the generated hex file](https://docs.qmk.fm/#/newbs_flashing) for your MCU (e.g. promicro).