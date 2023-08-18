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

![hitBox](https://github.com/kh411d/qmk_reviung41_keymaps/assets/273012/b517b916-4dbf-40d5-ba5c-ff381264ae61)

**hitBox style layout** 
Hold the Space key and then press T, use Left Shift to go back to the keyboard mode

---

![crossup](https://github.com/kh411d/qmk_reviung41_keymaps/assets/273012/1570da23-237e-44e4-b26a-fdf54337945a)

**Cross|Up style layout** SOCD is Last Input Wins. 
Hold the Space key and then press G, use Left Shift to go back to the keyboard mode

---

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

Make sure your [QMK environment is already setup](https://docs.qmk.fm/#/newbs_getting_started)
run command under your `qmk_firmware` directory,
```
% cd qmk_firmware
% qmk compile -kb reviung/reviung41 -km hitbox
```
Hex file should be created on your qmk_firmware directory

# Flashing
[Download the hex file, reviung_reviung41_hitbox.hex.zip](https://github.com/kh411d/qmk_reviung41_keymaps/files/12381690/reviung_reviung41_hitbox.hex.zip) if you want to skip the compile process

Use [QMK toolbox to flash the generated hex file](https://docs.qmk.fm/#/newbs_flashing) for your MCU (e.g. promicro).
