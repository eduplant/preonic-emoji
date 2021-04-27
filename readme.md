# OLKB Preonic - Emoji Edition

This keyboard firmware implements macros for every key of a 5x12 grid layout of
OLKB Preonic rev3. The keyboard implements no standard keycodes.

## Building New Firmware

1. Follow the [QMK documentation](https://docs.qmk.fm) in order to set up a
   current build environment. At the time of writing, the first four sections of
the Tutorial should be enough to cover what's necessary for the platform you're
using.

1. This keymap requires the existing `preonic` source files. You should be able
   to find it under `qmk_firmware/keyboards/preonic` or the equivalent inside
the build environment. Clone this repository into the `keymaps` subfolder.

1. With the many keymaps omitted for space, the folder structure of `preonic`
should now look something like this: 

```
├── config.h
├── info.json
├── keymaps
│   ├── default...
│   ├── ...
│   └── discord-emoji
│       ├── config.h
│       ├── keymap.c
│       ├── readme.md
│       └── rules.mk
├── preonic.c
├── preonic.h
├── readme.md
├── rev1
│   ├── config.h
│   ├── rev1.c
│   ├── rev1.h
│   └── rules.mk
├── rev2
│   ├── config.h
│   ├── rev2.c
│   ├── rev2.h
│   └── rules.mk
└── rev3
    ├── config.h
    ├── info.json
    ├── rev3.c
    ├── rev3.h
    └── rules.mk
```

1. The QMK documentation has the rest of the steps starting from [Build Your
   Firmware](https://docs.qmk.fm/#/newbs_building_firmware?id=build-your-firmware)
and continuing through [Flashing
Firmware](https://docs.qmk.fm/#/newbs_flashing?id=flashing-your-keyboard). For
the Preonic, there is convenient access to the reset button on the underside of
the case to put the device in DFU mode for flashing.

## Swapping Keys

To swap emojis, you need to change three values:

1. The custom keycode name
1. The keymap keycode reference
1. The text of the discord emoji

### Keycode Name

The custom keycodes are defined in an `enum` called `discord_keycodes` in
`keymap.c`. It looks something like this:

```
enum discord_keycodes {
	EMOJI_PEPECRY = SAFE_RANGE,
	EMOJI_PEPEDAB,
	EMOJI_PEPEBLANKET,
	EMOJI_PEPESERENITY,
	EMOJI_PEPEHMM,
	EMOJI_PEPESIMP,
	EMOJI_PEPECLAP,
	...
	EMOJI_THONKSPIN,
	EMOJI_TEETH
};
```

In C, `enum`s map convient labels to numbers. In this case, the numbering starts
from the number `SAFE_RANGE` (provided via a C preprocessor macro in QMK) and
counts upwards.

For the sake of organization, rename the key you want to substitute with an
appropriate enum name like `EMOJI_FOOBAR`. It could really be called mostly
anything, it just has to be referenced correctly in the keymap.

It is important that the `enum` be defined in an order consistent to the keymap
and the emoji lookup table. Hopefully this will make sense when you see those
sections.

### Keymap Reference

The keymap is this weird array that looks like this:

```
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE_LAYER] = LAYOUT_preonic_grid(
KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY,
KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY,
KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY,
KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY,
KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY
)
};
```

I've replaced the actual keycode identifiers with `KEY` so it fits visually. As
you might guess, this array corresponds to the visual layout of the 5x12 key
grid. Having replaced the keycode identifier above, swap it out for the old one
in this array.

### Emoji Text

Rather than have a gigantic tree of `switch`/`case` for every keycode, the key
logic in `process_record_user()` does a lookup in an array for the emoji
keystring itself. The array looks like this:

```
#define DISCORD_TOTAL_KEYS 60
#define DISCORD_MAX_STRLEN 32
const char discord_keystrings[DISCORD_TOTAL_KEYS][DISCORD_MAX_STRLEN] = {
	":keyb_pepecry:",
	":keyb_pepedab:",
	":keyb_pepeblanket:",
	":keyb_pepeserenity:",
	":keyb_pepehmm:",
	":keyb_pepesimp:",
	":keyb_pepeclap:",
	...
	":keyb_thonkspin:",
	":keyb_teeth:"
};
```

As you might have noticed, this is in the same order as the `discord_keycodes`
`enum` and this fact is used during the lookup. Once you swap out the text of
the emoji you can use the instructions above (mostly the QMK documentation) to
rebuild the firmware and flash it to the keyboard.
