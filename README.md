# QMK REVIUNG41 Keyboard + Hitbox keymapping
The SOCD Hitbox implementation was based on [QMK_HID_Gamepad_with_SOCD](https://github.com/brentaro/QMK_HID_Gamepad_with_SOCD/#qmk_hid_gamepad_with_socd)

# Layouts
Keyboard layers from the original reviung41 layout are set as the default layer with a couple of adjustments.

![keyboardfn](https://github.com/kh411d/qmk_reviung41_keymaps/assets/273012/c3449916-f1e0-426f-9909-ce6e591ad83f)

Usage:

- Hold the Space key and then press T for the **hitBox** layout
- Hold the Space key and then press G for the **Cross|Up** layout

Additional game layers,

**<ins>Note on Default SOCD behavior for ALL layouts</ins>:**
- **DPAD Behavior**
  - Up + Down = Up
  - Left + Right = Neutral
- **LS and RS behavior**
  - Up + Down = Up
  - Left + Right = Last Input Wins
---


![hitbox](https://github.com/kh411d/qmk_reviung41_keymaps/assets/273012/5a45c421-db0c-4c33-817f-82a2cd0b711e)

**hitBox style layout** 

Use the WIN/toggle key on the bottom left corner to go back to the keyboard mode

---

![crossup](https://github.com/kh411d/qmk_reviung41_keymaps/assets/273012/3f8a4793-aa4e-4519-9fdd-f7032e70be52)

**Cross|Up style layout** SOCD is Last Input Wins. 

Use the WIN/toggle key on the bottom left corner to go back to the keyboard mode

---

# Self Compile the HEX file 

[Setup your own local QMK environment](https://docs.qmk.fm/#/newbs_getting_started)

Copy the `hitbox/` directory to the keymaps directory of your cloned `qmk_firmware` repository,
```
- qmk_firmware
--- keyboards
------ reviung
--------- reviung41
------------- keymaps
---------------- ---COPY HERE--
``` 

Run this command under your `qmk_firmware` directory,
```
% cd qmk_firmware
% qmk compile -kb reviung/reviung41 -km hitbox
```
On compile succeed, the hex file should be created on your `qmk_firmware/reviung_reviung41_hitbox.hex` directory

# Flashing
[Download the hex file, reviung_reviung41_hitbox.hex.zip](https://github.com/kh411d/qmk_reviung41_keymaps/files/12393386/reviung_reviung41_hitbox.hex.zip) if you want to skip the compile process

Use [QMK toolbox to flash the generated hex file](https://docs.qmk.fm/#/newbs_flashing) for your MCU (e.g. promicro, seamicro, etc).
