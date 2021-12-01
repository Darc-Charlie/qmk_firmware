#include "9keymacropad.h"

enum custom_keycodes {
	CPYFNDPST,
};

// On my Cherry tester 9-key, physical right row is keymaped to the left colum below and vice versa.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_LALT, KC_LSFT, KC_LCTL, 
		KC_END, KC_TAB, KC_HOME, 
		LT(1, KC_DEL), KC_LGUI, KC_ESC),

	KEYMAP(
		LSFT(KC_F10), CPYFNDPST, KC_TRNS, 
		BL_BRTG, RESET, BL_STEP, 
		KC_TRNS, LALT(KC_F12), LSFT(LALT(KC_F12))),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
		case CPYFNDPST:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_C) SS_TAP(X_F) SS_TAP(X_V) SS_UP(X_LCTRL));
			} else {}
			break;
	}

	return true;
}
