# QMK Hitbox Keymaps
The visual below uses the Reviung41 layout as an example, but it could easily adjust to any keyboard. Take a look at [_template_/keymaps/hitbox](https://github.com/kh411d/qmk_hitbox_keymaps/tree/master/_template_/keymaps/hitbox) for 10x4 base template

## Keyboard Layer

Using the Default layers from Reviung41 with a couple of mods,

![g1850](https://github.com/kh411d/qmk_hitbox_keymaps/assets/273012/cada7e39-0ff9-41e4-b1d9-3ddcf7dbccf8)

Usage:

- Hold [SPACE] then press [S] = **Left Stick** mode 
- Hold [SPACE] then press [D] = **DPAD** mode
- Switching between Left stick and DPAD mode you need to go back to the keyboard layer and choose again.

## Joystick Layers
Additional joystick layers to the default layers
### Directional Layers

- Consist with 2 directional modes
    - Left stick 
    - DPAD
---

![g2010](https://github.com/kh411d/qmk_hitbox_keymaps/assets/273012/cf2e9171-2b90-4df3-a574-135a6b69ac32)

**DPAD mode** 

- Press [WIN] (bottom left corner) = Go back to keyboard layer
- Hold [Command] (bottom right corner) for the SOCD mode switcher, see SOCD layers below

---

![g1986](https://github.com/kh411d/qmk_hitbox_keymaps/assets/273012/bda3bc81-1769-418f-aabf-89e6a4febf36)

**Stick mode** 

- Press [WIN] (bottom left corner) = Go back to keyboard layer
- Hold [Command] (bottom right corner) for the SOCD mode switcher, see SOCD layers below

---

### SOCD Layers

Support 3 kinds of SOCD: 

Standard SOCD is the default every time you choose a directional layer the first time.

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

![g2485](https://github.com/kh411d/qmk_hitbox_keymaps/assets/273012/9ca74484-a679-4d4e-b948-ca9b67d53788)

- Hold [Command] then press [X] = Standard SOCD
- Hold [Command] then press [O] = True neutral SOCD
- Hold [Command] then press [R2] = Last input priority SOCD

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
