#include "keymap_common.h"
/* Revised 02\02 Split space and backspace. Moved Home and End */

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Standard NRS67 Keymap */
	KEYMAP (
			ESC, 1,   2,   3,   4,   5,   6, \
			7,   8,   9,   0,   MINS,EQL, BSPC, \
			TAB, Q,   W,   E,   R,   T,   Y, \
			U,   I,   O,   P,   LBRC,RBRC,DEL, \
			FN0, A,   S,   D,   F,   G,   H, \
			J,   K,   L,   SCLN,QUOT,ENT, \
			LSFT,BSLS,Z,   X,   C,   V,   B, \
			N,   M,   COMM,DOT, RSFT,UP,  CAPS, \
			LCTL,LGUI,LALT,PGDN,PGUP,BSPC, \
			SPC, RCTL,RGUI,LEFT,DOWN,RGHT),
			
/* FN0 : NRS67 FN0'd */
    KEYMAP (
			TRNS,F1,  F2,  F3,  F4,  F5,  F6, \
			F7,  F8,  F9,  F10, F11, F12, TRNS, \
			TRNS,FN1, MS_U,TRNS,WH_U,TRNS,TRNS, \
			TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
			FN0 ,MS_L,MS_D,MS_R,WH_D,TRNS,TRNS, \
			TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
			TRNS,FN2,TRNS,CALC,TRNS,TRNS,TRNS, \
			TRNS,TRNS,TRNS,TRNS,TRNS,VOLU,MUTE, \
			TRNS,TRNS,TRNS,TRNS,TRNS,BTN1, \
			BTN2,TRNS,TRNS,TRNS,VOLD,TRNS),
};


enum macro_id {
    HELLO,
	BACKSLASH,
    VOLUP,
    ALT_TAB,
};


const uint16_t PROGMEM fn_actions[] = {
    /* Poker Layout */
    [0] = ACTION_LAYER_MOMENTARY(1), 			// FN0 move to Fn'd
	[1] = ACTION_MODS_KEY(MOD_LSFT, KC_SLSH),
	[2] = ACTION_MACRO(BACKSLASH),
	[30] = ACTION_MACRO(HELLO),					// Add FN31 or FN32 to keymap if needed
	[31] = ACTION_MODS_KEY(MOD_LCTL + MOD_LSFT, KC_ESC),
};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case HELLO:
            return (record->event.pressed ?
                    MACRO( I(0), T(H), T(E), T(L), T(L), W(255), T(O), END ) :
                    MACRO_NONE );
        case VOLUP:
            return (record->event.pressed ?
                    MACRO( D(VOLU), U(VOLU), END ) :
                    MACRO_NONE );
		case BACKSLASH:
            return (record->event.pressed ?
                    MACRO( I(0),D(SLSH), END ) :
                    MACRO_NONE );
        case ALT_TAB:
            return (record->event.pressed ?
                    MACRO( D(LALT), D(TAB), END ) :
                    MACRO( U(TAB), END ));
    }
    return MACRO_NONE;
}