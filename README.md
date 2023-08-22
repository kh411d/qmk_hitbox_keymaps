# QMK REVIUNG41 Hitbox layout
Add additional joystick layers to the default reviung41 keyboard layout.
# Layouts
Keyboard layers from the original reviung41 layout are set as the default layer with a couple of adjustments, e.g. RGB removal.

![keyboardfn](https://github.com/kh411d/qmk_reviung41_keymaps/assets/273012/c3449916-f1e0-426f-9909-ce6e591ad83f)

Usage:

- Hold the Space key and then press T for the **DPAD** mode
- Hold the Space key and then press G for the virtual **Stick** mode


Joystick layers,

- **17** buttons and a single left stick mode
- Common SOCD, 
    - Up + Down = Up
    - Left + Right = Neutral
---


![hitbox](https://github.com/kh411d/qmk_reviung41_keymaps/assets/273012/5a45c421-db0c-4c33-817f-82a2cd0b711e)

**DPAD mode** 

Use the WIN/toggle key on the bottom left corner to go back to the keyboard mode

---

![g3233](https://github.com/kh411d/qmk_reviung41_keymaps/assets/273012/2375f10f-ca2d-4784-813c-d7297b7d29b8)

**Stick mode** 

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

Download the hex file [reviung_reviung41_hitbox.hex.zip](https://github.com/kh411d/qmk_reviung41_keymaps/files/12394843/reviung_reviung41_hitbox.hex.zip) to skip the compile process

Use [QMK toolbox to flash the generated hex file](https://docs.qmk.fm/#/newbs_flashing) for your MCU (e.g. promicro, seamicro, etc).
