# QMK Hitbox Keymaps
The visual below uses the Reviung41 layout as an example, but it could easily adjust to any keyboard. Take a look at [10x4 Ortho base template](https://github.com/kh411d/qmk_hitbox_keymaps/blob/master/_template/keymaps/hitbox/keymap.c) 

## Keyboard Layer

Using the Default layers from Reviung41 with a couple of mods,

![g1850](https://github.com/kh411d/qmk_hitbox_keymaps/assets/273012/cada7e39-0ff9-41e4-b1d9-3ddcf7dbccf8)

![g34789](https://github.com/kh411d/qmk_hitbox_keymaps/assets/273012/4fd9c380-a4ed-4864-8ccd-1e0ebf3d0fd0)


## Joystick Layers
Additional joystick layers to the default layers

**DPAD mode** 

![g14448](https://github.com/kh411d/qmk_hitbox_keymaps/assets/273012/9ab6351f-8867-424b-b5ad-c9dd27f2c48c)

---
**Stick mode** 

![g14652](https://github.com/kh411d/qmk_hitbox_keymaps/assets/273012/ab56707d-6b13-447e-a077-a523a99826c9)

---
**Usage**

![g14068](https://github.com/kh411d/qmk_hitbox_keymaps/assets/273012/cd11de50-23cf-4bf8-81e5-c7d973509d7a)



### SOCD Modes

[What is SOCD?](https://www.hitboxarcade.com/blogs/support/what-is-socd)

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

Use [QMK toolbox to flash the newly created hex file](https://docs.qmk.fm/#/newbs_flashing) for your MCU (e.g. promicro, seamicro, etc).
