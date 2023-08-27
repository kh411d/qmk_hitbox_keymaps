# QMK Hitbox Keymaps
The visual below is using the Reviung41 layout as example, but it could easily adjust to any keyboards. Take a look at [_template_/keymaps/hitbox](https://github.com/kh411d/qmk_hitbox_keymaps/tree/master/_template_/keymaps/hitbox) for 10x4 base template

## Keyboard Layer

Using the Default layers from Reviung41 with couple of mods,

![keyboardfn](https://github.com/kh411d/qmk_reviung41_keymaps/assets/273012/c3449916-f1e0-426f-9909-ce6e591ad83f)

Usage:

- Hold the Space key and then press S for Directional layer with **Left Stick** mode active
- Hold the Space key and then press D for Directional layer with **DPAD** mode
- Switching between Stick and DPAD modes You need to go back to keyboard layout

## Joystick Layers
Additional joystick layers to the default layers
### Directional Layers

- Consist with 2 directional modes
    - Left stick 
    - DPAD
---


![dpad_mode](https://github.com/kh411d/qmk_reviung41_keymaps/assets/273012/5a45c421-db0c-4c33-817f-82a2cd0b711e)

**DPAD mode** 

- Use the WIN/toggle key reset and go back to the keyboard mode
- Use the Command/toggle key to switch SOCD mode

---

![stick_mode](https://github.com/kh411d/qmk_reviung41_keymaps/assets/273012/025e2b2f-cc6d-48e5-adbc-7d5d05d86bd2)

**Stick mode** 

- Use the WIN/toggle key on the bottom left corner to go back to the keyboard mod
- Use the Command/toggle key to switch SOCD mode

---

### SOCD Layers

Support 3 kinds of SOCD: 

- Standard SOCD, 
    - Up + Down = Up
    - Left + Right = Neutral
- True Neutral SOCD,
    - Up + Down = Neutral
    - Left + Right = Neutral
- Last Input Priority SOCD,
    - Up + Down = Down
    - Down + Up = Up
    - Left + Right = Right 
    - Right + Left = Left

While on Directional Layer,

- Hold command and then X for Standard SOCD
- Hold command and then O for True neutral SOCD
- Hold command and then L2 for Last input priority SOCD

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
