/* Copyright 2021 Eric Duplantis <eric@duplant.is>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "print.h"

enum discord_layers {
	_BASE_LAYER
};

/*
 * The order of this enum must correspond to the indices of the
 * discord_keystrings array!
 *
 * The value of an item in the enum minus SAFE_RANGE should equal the value of
 * the corresponding entry in the array for that keycode.
 */
enum discord_keycodes {
	EMOJI_PEPECRY = SAFE_RANGE,
	EMOJI_PEPEDAB,
	EMOJI_PEPEBLANKET,
	EMOJI_PEPESERENITY,
	EMOJI_PEPEHMM,
	EMOJI_PEPESIMP,
	EMOJI_PEPECLAP,
	EMOJI_PEPEDANCE,
	EMOJI_PENGUIN,
	EMOJI_TAXFOX1,
	EMOJI_TAXFOX2,
	EMOJI_GPOY,
	EMOJI_MITCHOTHY,
	EMOJI_TKPOG,
	EMOJI_QUINNATHAN,
	EMOJI_STROMER,
	EMOJI_POGOTHY,
	EMOJI_FLATFUCKTK,
	EMOJI_ACNHSTARE,
	EMOJI_SUPERNATURAL,
	EMOJI_JENSEN,
	EMOJI_MISHA,
	EMOJI_SKELEHAG,
	EMOJI_PLAYDEAD,
	EMOJI_KERMITHEARTS,
	EMOJI_KERMITCRY,
	EMOJI_KERMITTYPE,
	EMOJI_HELLMO,
	EMOJI_FAIRYGODPARENTS,
	EMOJI_MRBURNS,
	EMOJI_BYEHOMER,
	EMOJI_GRIN,
	EMOJI_EVILGRIN,
	EMOJI_MEAT,
	EMOJI_SAURON,
	EMOJI_ANGYPANDA,
	EMOJI_HEARTELMO,
	EMOJI_KERMIEOMG,
	EMOJI_KYERMIT,
	EMOJI_BUNNYHUG,
	EMOJI_GAYRAT,
	EMOJI_CRYOKCAT,
	EMOJI_CHEFKISS,
	EMOJI_FEETIES,
	EMOJI_SMOOTHBRAIN,
	EMOJI_DUCKGUN,
	EMOJI_JONAHMOTHER,
	EMOJI_JONAHTEETH,
	EMOJI_SIMSPLUS,
	EMOJI_SIMSMINUS,
	EMOJI_NEKO,
	EMOJI_ACNHBOBDANCE,
	EMOJI_DOGDANCE,
	EMOJI_CRABDANCE,
	EMOJI_SADHONK,
	EMOJI_PLEADINGHEART,
	EMOJI_CRYINGHEART,
	EMOJI_CRYINGPLEAD,
	EMOJI_THONKSPIN,
	EMOJI_TEETH
};

/*
 * Indexes in this array must correspond to the discord_keycodes enum!
 *
 * The index of an entry in this array plus SAFE_RANGE should equal the value of
 * the corresponding entry in the enum for that keycode.
 */
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
	":keyb_pepedance:",
	":keyb_penguin:",
	":keyb_taxfox1:",
	":keyb_taxfox2:",
	":keyb_gpoy:",
	":keyb_mitchothy:",
	":keyb_tkpog:",
	":keyb_quinnathan:",
	":keyb_stromer:",
	":keyb_pogothy:",
	":keyb_flatfucktk:",
	":keyb_acnhstare:",
	":keyb_supernatural:",
	":keyb_jensen:",
	":keyb_misha:",
	":keyb_skelehag:",
	":keyb_playdead:",
	":keyb_kermithearts:",
	":keyb_kermitcry:",
	":keyb_kermittype:",
	":keyb_hellmo:",
	":keyb_fairygodparents:",
	":keyb_mrburns:",
	":keyb_byehomer:",
	":keyb_grin:",
	":keyb_evilgrin:",
	":keyb_meat:",
	":keyb_sauron:",
	":keyb_angypanda:",
	":keyb_heartelmo:",
	":keyb_kermieomg:",
	":keyb_kyermit:",
	":keyb_bunnyhug:",
	":keyb_gayrat:",
	":keyb_cryokcat:",
	":keyb_chefkiss:",
	":keyb_feeties:",
	":keyb_smoothbrain:",
	":keyb_duckgun:",
	":keyb_jonahmother:",
	":keyb_jonahteeth:",
	":keyb_simsplus:",
	":keyb_simsminus:",
	":keyb_neko:",
	":keyb_acnhbobdance:",
	":keyb_dogdance:",
	":keyb_crabdance:",
	":keyb_sadhonk:",
	":keyb_pleadingheart:",
	":keyb_cryingheart:",
	":keyb_cryingplead:",
	":keyb_thonkspin:",
	":keyb_teeth:"
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base layer
 *
 * Refer to the spreadsheet for a better visual of the layout since the names
 * are too long to represent more compactly.
 */
[_BASE_LAYER] = LAYOUT_preonic_grid(
EMOJI_PEPECRY,      EMOJI_PEPEDAB,   EMOJI_PEPEBLANKET, EMOJI_PEPESERENITY, EMOJI_PEPEHMM,         EMOJI_PEPESIMP,   EMOJI_PEPECLAP,  EMOJI_PEPEDANCE,     EMOJI_PENGUIN,     EMOJI_TAXFOX1,     EMOJI_TAXFOX2,     EMOJI_GPOY, 
EMOJI_MITCHOTHY,    EMOJI_TKPOG,     EMOJI_QUINNATHAN,  EMOJI_STROMER,      EMOJI_POGOTHY,         EMOJI_FLATFUCKTK, EMOJI_ACNHSTARE, EMOJI_SUPERNATURAL,  EMOJI_JENSEN,      EMOJI_MISHA,       EMOJI_SKELEHAG,    EMOJI_PLAYDEAD, 
EMOJI_KERMITHEARTS, EMOJI_KERMITCRY, EMOJI_KERMITTYPE,  EMOJI_HELLMO,       EMOJI_FAIRYGODPARENTS, EMOJI_MRBURNS,    EMOJI_BYEHOMER,  EMOJI_GRIN,          EMOJI_EVILGRIN,    EMOJI_MEAT,        EMOJI_SAURON,      EMOJI_ANGYPANDA, 
EMOJI_HEARTELMO,    EMOJI_KERMIEOMG, EMOJI_KYERMIT,     EMOJI_BUNNYHUG,     EMOJI_GAYRAT,          EMOJI_CRYOKCAT,   EMOJI_CHEFKISS,  EMOJI_FEETIES,       EMOJI_SMOOTHBRAIN, EMOJI_DUCKGUN,     EMOJI_JONAHMOTHER, EMOJI_JONAHTEETH, 
EMOJI_SIMSPLUS,     EMOJI_SIMSMINUS, EMOJI_NEKO,        EMOJI_ACNHBOBDANCE, EMOJI_DOGDANCE,        EMOJI_CRABDANCE,  EMOJI_SADHONK,   EMOJI_PLEADINGHEART, EMOJI_CRYINGHEART, EMOJI_CRYINGPLEAD, EMOJI_THONKSPIN,   EMOJI_TEETH
)
};

/* Uncomment to enable debug for development purposes */
void keyboard_post_init_user(void) {
	//debug_enable=true;
	//debug_matrix=true;
};

void send_discord_emoji(uint16_t keycode, bool send_newline) {
	if ( keycode >= SAFE_RANGE ) {
		uint16_t index = keycode - SAFE_RANGE;
		send_string(discord_keystrings[index]);
		if ( send_newline ) {
			SEND_STRING("\n");
		};
	};
};

static uint16_t keypress_timer = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if ( record->event.pressed ) {
		keypress_timer = timer_read();
		dprintf("Keydown event\n");
	} else {
		if ( timer_elapsed(keypress_timer) < 200 ) {
			dprintf("Keyup event after <200 ms, no newline\n");
			send_discord_emoji(keycode, false);
		} else {
			dprintf("Keyup event after >200 ms, newline added\n");
			send_discord_emoji(keycode, true);
		};
	};
	return false;
};
