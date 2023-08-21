/* Copyright 2020 gtips
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _GAME1,
	_GAME2,
    _GAMEFN,
	_ADJUST
};

enum custom_keycodes {      
	GC_LSU = SAFE_RANGE,
	GC_LSD,
	GC_LSL,
	GC_LSR,
	GC_DPU,
	GC_DPD,
	GC_DPL,
	GC_DPR,
	GC_SQU,
	GC_CRO,
	GC_CIR,
	GC_TRI,
	GC_L1,
	GC_L2,
	GC_L3,
	GC_R1,
	GC_R2,
	GC_R3,
	GC_STA,
	GC_SEL,
	GC_HOM
};
	
// Joystick Config
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
	JOYSTICK_AXIS_VIRTUAL,
	JOYSTICK_AXIS_VIRTUAL,
	JOYSTICK_AXIS_VIRTUAL,
	JOYSTICK_AXIS_VIRTUAL,
	JOYSTICK_AXIS_VIRTUAL,
	JOYSTICK_AXIS_VIRTUAL,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define GAME1  TG(_GAME1)
#define GAME2  TG(_GAME2)
#define GAMEFN LT(_GAMEFN, KC_SPC)
#define ADJUST MO(_ADJUST)

const key_override_t enter_key_override = ko_make_basic(MOD_BIT(KC_LSFT), KC_ENTER, KC_DQUO);
const key_override_t **key_overrides = (const key_override_t *[]){
    &enter_key_override,
    NULL 
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_TAB,          KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    LCTL_T(KC_ESC),  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,
    KC_LSFT,         KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_BSLS),
                                                   KC_LALT,   LOWER,    GAMEFN,   RAISE,    KC_RGUI
  ),
  
  [_LOWER] = LAYOUT(
    KC_TILD,         KC_EXLM,  KC_AT,     KC_HASH,  KC_DLR,   KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    LCTL_T(KC_ESC),  XXXXXXX,  XXXXXXX,   KC_UP,    XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_DQUO,
    KC_LSFT,         XXXXXXX,  KC_LEFT,   KC_DOWN,  KC_RGHT,  XXXXXXX,            XXXXXXX,  KC_MINS,  KC_LT,    KC_GT,    KC_QUES,  RSFT_T(KC_PIPE),
                                                    _______,  _______,  GAMEFN,   _______,  _______
  ),
  
  [_RAISE] = LAYOUT(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,      KC_5,             KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,            KC_RCTL,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_QUOT,
    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,           KC_RGUI,  KC_PLUS,  KC_LT,    KC_GT,    KC_COLN,  RSFT_T(KC_PIPE),
                                           _______,   _______,  GAMEFN,  _______,  _______
  ),

  [_GAME1] = LAYOUT(
    GC_HOM,  GC_SEL,   GC_STA,  XXXXXXX, XXXXXXX,  GC_L3,            GC_R3,    GC_SQU,    GC_TRI,  GC_R1,   GC_L1,   XXXXXXX,
    XXXXXXX, XXXXXXX,  GC_DPL,  GC_DPD,  GC_DPR,  XXXXXXX,           XXXXXXX,  GC_CRO,    GC_CIR,  GC_R2,   GC_L2,   XXXXXXX,
    GAME1,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
                                         XXXXXXX, GC_DPU,   GC_DPU,  GC_DPU,   XXXXXXX
  ),
 
  [_GAME2] = LAYOUT(
    GC_HOM,  GC_SEL,  GC_STA,  XXXXXXX,  XXXXXXX, GC_L3,             GC_R3,   GC_SQU,  GC_TRI,  GC_R1,  GC_L1,   XXXXXXX,
    XXXXXXX, XXXXXXX, GC_LSL,  GC_LSD,   GC_LSR,  XXXXXXX,           XXXXXXX, GC_CRO,  GC_CIR,  GC_R2,  GC_L2,   XXXXXXX,
    GAME2,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,           XXXXXXX, GC_DPL,  GC_DPD,  GC_DPR, XXXXXXX, XXXXXXX,
                                         XXXXXXX, GC_LSU,   GC_LSU,  GC_LSU,  GC_DPU
  ),
  
  [_GAMEFN] = LAYOUT(
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   GAME1,             KC_HOME,  KC_PGDN,   KC_PGUP,  KC_END,   KC_DEL,   KC_BSPC,
    KC_LCTL,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   GAME2,             KC_LEFT,  KC_DOWN,   KC_UP,    KC_RGHT,  XXXXXXX,  KC_ENT,
    KC_LSFT,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,           XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            KC_LGUI,   _______,  GAMEFN,  _______,  KC_RGUI
  ),

  [_ADJUST] = LAYOUT(
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  QK_RBT,    XXXXXXX,           XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,           XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   QK_BOOT,           QK_BOOT,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
                                            XXXXXXX,   LOWER,   XXXXXXX,  RAISE,   XXXXXXX
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


bool LSU_STATE = false;
bool LSD_STATE = false;
bool LSL_STATE = false;
bool LSR_STATE = false;

bool DPU_STATE = false;
bool DPD_STATE = false;
bool DPL_STATE = false;
bool DPR_STATE = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case GC_LSU:
			if (record->event.pressed) {
				LSU_STATE = true;
				joystick_set_axis(1, -127);
			} else {
				LSU_STATE = false;
				if (LSD_STATE) {
					joystick_set_axis(1, 127);
				} else {
					joystick_set_axis(1, 0);
				}
			}
			return false;
		case GC_LSD:
			if (record->event.pressed) {
				LSD_STATE = true;
				if (!LSU_STATE) {
					joystick_set_axis(1, 127);
				}
			} else {
				LSD_STATE = false;	
				if (!LSU_STATE) {
					joystick_set_axis(1, 0);
				}	
			}
			return false;
		case GC_LSL:
			if (record->event.pressed) {
				LSL_STATE = true;
				joystick_set_axis(0, -127);
			} else {
				LSL_STATE = false;
				if (LSR_STATE) {
					joystick_set_axis(0, 127);
				} else {
					joystick_set_axis(0, 0);
				}
			}
			return false;
		case GC_LSR:
			if (record->event.pressed) {
				LSR_STATE = true;
				joystick_set_axis(0, 127);
			} else {
				LSR_STATE = false;
				if (LSL_STATE) {
					joystick_set_axis(0, -127);
				} else {
					joystick_set_axis(0, 0);
				}
			}
			return false;
		case GC_DPU:
			if (record->event.pressed) {
				DPU_STATE = true;
				if (DPD_STATE) {
					unregister_joystick_button(16);
				}
				register_joystick_button(18);
			} else {
				DPU_STATE = false;
				unregister_joystick_button(18);
			}
			return false;
		case GC_DPD:
			if (record->event.pressed) {
				DPD_STATE = true;
				if (!DPU_STATE) {
					register_joystick_button(16);
				}
			} else {
				DPD_STATE = false;
				unregister_joystick_button(16);
			}
			return false;
		case GC_DPL:
			if (record->event.pressed) {
				DPL_STATE = true;
				if (DPR_STATE) {
					unregister_joystick_button(17);
				} else {
					register_joystick_button(15);
				}
			} else {
				DPL_STATE = false;
				unregister_joystick_button(15);
				if (DPR_STATE) {
					register_joystick_button(17);
				}
			}
			return false;
		case GC_DPR:
			if (record->event.pressed) {
				DPR_STATE = true;
				if (DPL_STATE) {
					unregister_joystick_button(15);
				} else {
					register_joystick_button(17);
				}
			} else {
				DPR_STATE = false;
				unregister_joystick_button(17);
				if (DPL_STATE) {
					register_joystick_button(15);
				}
			}
			return false;
		case GC_SQU:
			if (record->event.pressed) {
				register_joystick_button(0);
			} else {
				unregister_joystick_button(0);
			}
			return false;
		case GC_CRO:
			if (record->event.pressed) {
				register_joystick_button(1);
			} else {
				unregister_joystick_button(1);
			}
			return false;
		case GC_CIR:
			if (record->event.pressed) {
				register_joystick_button(2);
			} else {
				unregister_joystick_button(2);
			}
			return false;
		case GC_TRI:
			if (record->event.pressed) {
				register_joystick_button(3);
			} else {
				unregister_joystick_button(3);
			}
			return false;
		case GC_L1:
			if (record->event.pressed) {
				register_joystick_button(4);
			} else {
				unregister_joystick_button(4);
			}
			return false;
		case GC_R1:
			if (record->event.pressed) {
				register_joystick_button(5);
			} else {
				unregister_joystick_button(5);
			}
			return false;
		case GC_L2:
			if (record->event.pressed) {
				register_joystick_button(6);
			} else {
				unregister_joystick_button(6);
			}
			return false;
		case GC_R2:
			if (record->event.pressed) {
				register_joystick_button(7);
			} else {
				unregister_joystick_button(7);
			}
			return false;
		case GC_SEL:
			if (record->event.pressed) {
				register_joystick_button(8);
			} else {
				unregister_joystick_button(8);
			}
			return false;
		case GC_STA:
			if (record->event.pressed) {
				register_joystick_button(9);
			} else {
				unregister_joystick_button(9);
			}
			return false;
		case GC_L3:
			if (record->event.pressed) {
				register_joystick_button(10);
			} else {
				unregister_joystick_button(10);
			}
			return false;
		case GC_R3:
			if (record->event.pressed) {
				register_joystick_button(11);
			} else {
				unregister_joystick_button(11);
			}
			return false;
		case GC_HOM:
			if (record->event.pressed) {
				register_joystick_button(12);
			} else {
				unregister_joystick_button(12);
			}
			return false;
		default:
			return true;
	}
};
