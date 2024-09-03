# Instructions

## Flashing

1. Clone this repo locally: https://github.com/howird/qmk_firmware_spe

2. In the keyboards/centromere/keymaps/howird directory is the 'keymap.c' containing the keymap

3. Connect your dongle to your computer. Navigate back to the qmk_firmware_spe directory, and run the following command in your terminal: `sudo make centromere:howird:avrdude`. When prompted to reset, press the reset button on your dongle. This should flash your dongle.

## Editing

1. Go to https://config.qmk.fm/ to create your edit the keymaps (`.json` files in this dir). From there download the json of the keymap you want to flash.

2/ Run qmk json2c path/to/keymap.json. Copy the generated c code and the `keymaps[][]` var in your keymap.c file with this code to update the keymap. Now you can re-flash.