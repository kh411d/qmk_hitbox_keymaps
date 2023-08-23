# QMK Hitbox layout
Add additional joystick layers to the default layout.

You can use anyboard keymap as you base template, [anyboard/keymaps/hitbox](https://github.com/kh411d/qmk_reviung41_keymaps/tree/master/anyboard/keymaps/hitbox) take Reviung41 layout below as example

# REVIUNG41 Hitbox layout
## Layouts
Keyboard layers from the original reviung41 layout are set as the default layer with a couple of adjustments, e.g. RGB removal.

![keyboardfn](https://github.com/kh411d/qmk_reviung41_keymaps/assets/273012/c3449916-f1e0-426f-9909-ce6e591ad83f)

Usage:

- Hold the Space key and then press T for the **DPAD** mode
- Hold the Space key and then press G for the virtual **Stick** mode
- The keyboard should be detected as a controller, you may test on any online browser gamepad tester, PC, OSX, consoles, etc.


Joystick layers,

- **17** buttons and a single left stick mode
- Common SOCD, 
    - Up + Down = Up
    - Left + Right = Neutral
---


![dpad_mode](https://github.com/kh411d/qmk_reviung41_keymaps/assets/273012/5a45c421-db0c-4c33-817f-82a2cd0b711e)

**DPAD mode** 

Use the WIN/toggle key on the bottom left corner to go back to the keyboard mode

---

![stick_mode](https://github.com/kh411d/qmk_reviung41_keymaps/assets/273012/025e2b2f-cc6d-48e5-adbc-7d5d05d86bd2)

**Stick mode** 

Use the WIN/toggle key on the bottom left corner to go back to the keyboard mode

---

## Self Compile the firmware file 

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

## Flashing

Download the hex file [reviung_reviung41_hitbox.hex.zip](https://github.com/kh411d/qmk_reviung41_keymaps/files/12410985/reviung_reviung41_hitbox.hex.zip) to skip the compile process

Use [QMK toolbox to flash the generated hex file](https://docs.qmk.fm/#/newbs_flashing) for your MCU (e.g. promicro, seamicro, etc).
