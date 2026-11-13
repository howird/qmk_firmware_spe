# Instructions

## Flashing

1. Clone this repo locally: https://github.com/howird/qmk_firmware_spe

2. `keymap.c` in this directory holds the keymap; `config.h` holds the tap-hold settings.

3. Connect the dongle. From the repo root, enter the build environment and flash:

   ```sh
   nix-shell
   make centromere:howird:avrdude
   ```

   When prompted to reset, press (or double-tap) the dongle's reset button.
   Opening the bootloader port needs QMK's udev rules
   (`hardware.keyboard.qmk.enable = true;` on NixOS); without them, run
   `sudo -E env "PATH=$PATH" make centromere:howird:avrdude` inside `nix-shell`.

## Editing

`framework.json` is the layout as a QMK Configurator export (https://config.qmk.fm/).
After changing it, update `keymaps[][]` in `keymap.c` by hand (or from
`qmk json2c framework.json`), keeping the custom `VOX` key, which the JSON
can't express (it is `KC_NO` there).
