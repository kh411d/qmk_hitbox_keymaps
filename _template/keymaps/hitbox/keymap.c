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


/* Joystick layer start from here */
// Direction Layers defaulted to standard SOCD
    _DPAD,
	_LSTICK,

// SOCD Layers
	_SOCDN,
	_SOCDLIP,

// Toggle layers
    _JOYFN
};


// Joystick variables init 
#define BASE    TO(_BASE)
#define DPAD    TO(_DPAD)
#define LSTICK  TO(_LSTICK)
#define SOCDN   TO(_SOCDN)
#define SOCDLIP TO(_SOCDLIP)
#define JOYFN   LT(_JOYFN, KC_SPC)

enum custom_keycodes {  
	// Cross, Circle, Square, Triangle buttons
	JS_CRO = SAFE_RANGE,
	JS_CIR,
	JS_SQU,
	JS_TRI,   

	// L R buttons
	JS_L1,
	JS_R1,
	JS_L2,
	JS_R2,

	// Select Start buttons
	JS_SEL,
	JS_STRT,

	// LS and LR button press
	JS_L3,
	JS_R3,

	// SOCD Standard
	JS_UP,
	JS_DN,
	JS_LT,
	JS_RT,

	// SOCD True neutral
	JS_UP_N,
	JS_DN_N,

	// SOCD Last Input Priority
	JS_UP_LIP,
	JS_DN_LIP,
	JS_LT_LIP,
	JS_RT_LIP,

	// PS/Home button
	JS_HOM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // The Keyboard Layer
  [_BASE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, 
	XXXXXXX,    KC_S,    KC_D,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                                                              
	XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, JOYFN,   XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, QK_BOOT
  ),

  // The Joystick Layers 
  [_DPAD] = LAYOUT(
    JS_HOM,  JS_SEL,  JS_STRT, JS_L3,    JS_R3,   XXXXXXX,  JS_SQU,   JS_TRI,  JS_R1,   JS_L1,   
	XXXXXXX, JS_LT,   JS_DN,   JS_RT,	 XXXXXXX, XXXXXXX,  JS_CRO,   JS_CIR,  JS_R2,   JS_L2,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                                                              
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, JS_UP,    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
  ),
 
  [_LSTICK] = LAYOUT(
    JS_HOM,  JS_SEL,  JS_STRT, JS_L3,    JS_R3,   XXXXXXX,  JS_SQU,   JS_TRI,  JS_R1,   JS_L1,   
	XXXXXXX, JS_LT,   JS_DN,   JS_RT,	 XXXXXXX, XXXXXXX,  JS_CRO,   JS_CIR,  JS_R2,   JS_L2,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                                                              
	BASE,    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, JS_UP,    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_SOCDN] = LAYOUT(
    JS_HOM,  JS_SEL,  JS_STRT, JS_L3,    JS_R3,   XXXXXXX,  JS_SQU,   JS_TRI,  JS_R1,   JS_L1,   
	XXXXXXX, JS_LT,   JS_DN_N, JS_RT,	 XXXXXXX, XXXXXXX,  JS_CRO,   JS_CIR,  JS_R2,   JS_L2,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                                                              
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, JS_UP_N,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_SOCDLIP] = LAYOUT(
    JS_HOM,  JS_SEL,    JS_STRT,   JS_L3,      JS_R3,   XXXXXXX,    JS_SQU,   JS_TRI,  JS_R1,   JS_L1,   
	XXXXXXX, JS_LT_LIP, JS_DN_LIP, JS_RT_LIP,  XXXXXXX, XXXXXXX,    JS_CRO,   JS_CIR,  JS_R2,   JS_L2,
    XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                                                              
	XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX, JS_UP_LIP,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
  ),
  
  [_JOYFN] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, 
	XXXXXXX, XXXXXXX, LSTICK,  DPAD,     XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                                                              
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  JOYFN,   XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
  ),
};

// Combo usage for exit and socd mode
const uint16_t PROGMEM exit_joystick[]     = {JS_HOM, JS_LT, COMBO_END};
const uint16_t PROGMEM exit_joystick_alt[] = {JS_HOM, JS_LT_LIP, COMBO_END};
const uint16_t PROGMEM socd_s_activate[]   = {JS_HOM, JS_CRO, COMBO_END};
const uint16_t PROGMEM socd_n_activate[]   = {JS_HOM, JS_CIR, COMBO_END};
const uint16_t PROGMEM socd_l_activate[]   = {JS_HOM, JS_R2, COMBO_END};
combo_t key_combos[] = {
	COMBO(exit_joystick, BASE),
	COMBO(exit_joystick_alt, BASE),
	COMBO(socd_s_activate, DPAD),
	COMBO(socd_n_activate, SOCDN),
	COMBO(socd_l_activate, SOCDLIP),
};

bool DPAD_ACTIVE = true;
bool LSTICK_ACTIVE = false;

layer_state_t layer_state_set_user(layer_state_t state) {

	if (IS_LAYER_ON_STATE(state, _DPAD)) {
		DPAD_ACTIVE = true;
		LSTICK_ACTIVE = false;
	} else if (IS_LAYER_ON_STATE(state, _LSTICK)) {
		DPAD_ACTIVE = false;
		LSTICK_ACTIVE = true;
	} 

	// base layer to deactivate all joystick state
	if (IS_LAYER_ON_STATE(state, _BASE)) {
		DPAD_ACTIVE = false;
		LSTICK_ACTIVE = false;
	}

  return state;
}


/* Start Joystick configurations and macros */
bool UP_FLAG = false;
bool DN_FLAG = false;
bool LT_FLAG = false;
bool RT_FLAG = false;

// left stick axis 0,1  |  right stick axis 2,3
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
	JOYSTICK_AXIS_VIRTUAL, // x
	JOYSTICK_AXIS_VIRTUAL, // y
};

// Input Map
// UP:    button 12 | LS Axis (1, -127) 
// DOWN:  button 13 | LS Axis (1, 127) 
// LEFT:  button 14 | LS Axis (0, -127) 
// RIGHT: button 15 | LS Axis (0, 127) 

// SOCD: up+down = up
bool joy_up(bool ok) {
	if (ok) {
		UP_FLAG = true;
		if (DN_FLAG) {
		 DPAD_ACTIVE ? unregister_joystick_button(13): joystick_set_axis(1, 0);
		}
		 DPAD_ACTIVE ? register_joystick_button(12): joystick_set_axis(1, -127);
	} else {
		UP_FLAG = false;
		DPAD_ACTIVE ? unregister_joystick_button(12): joystick_set_axis(1, 0);
		if (DN_FLAG) {
			DPAD_ACTIVE ? register_joystick_button(13): joystick_set_axis(1, 127);
		}
	}
	return false;
}

// SOCD: down+up = up
bool joy_dn(bool ok) {
	if (ok) {
		DN_FLAG = true;
		if (!UP_FLAG) {
		 DPAD_ACTIVE ? register_joystick_button(13): joystick_set_axis(1, 127);
		} 
	} else {
		DN_FLAG = false;
		DPAD_ACTIVE ? unregister_joystick_button(13): joystick_set_axis(1, 0);
		if (UP_FLAG) {
			DPAD_ACTIVE ? register_joystick_button(12): joystick_set_axis(1, -127);
		}
	}
	return false;
}

// SOCD true neutral: up+down = neutral
bool joy_up_n(bool ok) {
	if (ok) {
		UP_FLAG = true;
		if (DN_FLAG) {
		 DPAD_ACTIVE ? unregister_joystick_button(13): joystick_set_axis(1, 0);
		} else {
			DPAD_ACTIVE ? register_joystick_button(12): joystick_set_axis(1, -127);
		}
	} else {
		UP_FLAG = false;
		DPAD_ACTIVE ? unregister_joystick_button(12): joystick_set_axis(1, 0);
		if(DN_FLAG) {
			DPAD_ACTIVE ? register_joystick_button(13): joystick_set_axis(1, 127);
		}
	}
	return false;
}

// SOCD true neutral: down+up = neutral
bool joy_dn_n(bool ok) {
	if (ok) {
		DN_FLAG = true;
		if (UP_FLAG) {
		 DPAD_ACTIVE ? unregister_joystick_button(12): joystick_set_axis(1, 0);
		} else {
			DPAD_ACTIVE ? register_joystick_button(13): joystick_set_axis(1, 127);
		}
	} else {
		DN_FLAG = false;
		DPAD_ACTIVE ? unregister_joystick_button(13): joystick_set_axis(1, 0);
		if(UP_FLAG) {
			DPAD_ACTIVE ? register_joystick_button(12): joystick_set_axis(1, -127);
		}
	}
	return false;
}


// SOCD last input priority: up+down = down 
bool joy_up_lip(bool ok) {
	if (ok) {
		UP_FLAG = true;
		if (DN_FLAG) {
		 DPAD_ACTIVE ? unregister_joystick_button(13): joystick_set_axis(1, 0);
		}
		 DPAD_ACTIVE ? register_joystick_button(12): joystick_set_axis(1, -127);
	} else {
		UP_FLAG = false;
		DPAD_ACTIVE ? unregister_joystick_button(12): joystick_set_axis(1, 0);
		if(DN_FLAG) {
			DPAD_ACTIVE ? register_joystick_button(13): joystick_set_axis(1, 127);
		}
	}
	return false;
}

// SOCD last input priority: down+up = up
bool joy_dn_lip(bool ok) {
	if (ok) {
		DN_FLAG = true;
		if (UP_FLAG) {
		 DPAD_ACTIVE ? unregister_joystick_button(12): joystick_set_axis(1, 0);
		}
		DPAD_ACTIVE ? register_joystick_button(13): joystick_set_axis(1, 127);
	} else {
		DN_FLAG = false;
		DPAD_ACTIVE ? unregister_joystick_button(13): joystick_set_axis(1, 0);
		if(UP_FLAG) {
			DPAD_ACTIVE ? register_joystick_button(12): joystick_set_axis(1, -127);
		}
	}
	return false;
}

// SOCD: left+right = neutral 
bool joy_lt(bool ok) {
	if (ok) {
		LT_FLAG = true;
		if (RT_FLAG) {
		 	DPAD_ACTIVE ? unregister_joystick_button(15): joystick_set_axis(0, 0);
		} else {
			DPAD_ACTIVE ? register_joystick_button(14): joystick_set_axis(0, -127);
		}
	} else {
		LT_FLAG = false;
		DPAD_ACTIVE ? unregister_joystick_button(14): joystick_set_axis(0, 0);
		if(RT_FLAG) {
			DPAD_ACTIVE ? register_joystick_button(15): joystick_set_axis(0, 127);
		}
	}
	return false;
}

// SOCD: right+left = neutral 
bool joy_rt(bool ok) {
	if (ok) {
		RT_FLAG = true;
		if (LT_FLAG) {
		 	DPAD_ACTIVE ? unregister_joystick_button(14): joystick_set_axis(0, 0);
		} else {
			DPAD_ACTIVE ? register_joystick_button(15): joystick_set_axis(0, 127);
		}
	} else {
		RT_FLAG = false;
		DPAD_ACTIVE ? unregister_joystick_button(15): joystick_set_axis(0, 0);
		if(LT_FLAG) {
			DPAD_ACTIVE ? register_joystick_button(14): joystick_set_axis(0, -127);
		}
	}
	return false;
}

// SOCD Last Input Priority: left+right = right 
bool joy_lt_lip(bool ok) {
	if (ok) {
		LT_FLAG = true;
		if (RT_FLAG) {
		 	DPAD_ACTIVE ? unregister_joystick_button(15): joystick_set_axis(0, 0);
		} 
		DPAD_ACTIVE ? register_joystick_button(14): joystick_set_axis(0, -127);
	} else {
		LT_FLAG = false;
		DPAD_ACTIVE ? unregister_joystick_button(14): joystick_set_axis(0, 0);
		if(RT_FLAG) {
			DPAD_ACTIVE ? register_joystick_button(15): joystick_set_axis(0, 127);
		}
	}
	return false;
}

// SOCD Last Input Priority: right+left = left 
bool joy_rt_lip(bool ok) {
	if (ok) {
		RT_FLAG = true;
		if (LT_FLAG) {
		 	DPAD_ACTIVE ? unregister_joystick_button(14): joystick_set_axis(0, 0);
		} 
		DPAD_ACTIVE ? register_joystick_button(15): joystick_set_axis(0, 127);
	} else {
		RT_FLAG = false;
		DPAD_ACTIVE ? unregister_joystick_button(15): joystick_set_axis(0, 0);
		if(LT_FLAG) {
			DPAD_ACTIVE ? register_joystick_button(14): joystick_set_axis(0, -127);
		}
	}
	return false;
}

bool joy_x(bool ok, uint8_t button) {
	ok ? register_joystick_button(button): unregister_joystick_button(button);
	return false;
}

// The order of button numbering is following the button report number from the good ol PS3 joystick
// e.g. Cross = button 0, Circle = button 1, ... , Home = button 16
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	bool p = record->event.pressed;
	switch (keycode) {
		case JS_CRO:
			return joy_x(p, 0);
		case JS_CIR:
			return joy_x(p, 1);
		case JS_SQU:
			return joy_x(p, 2);
		case JS_TRI:
			return joy_x(p, 3);	
		case JS_L1:
			return joy_x(p, 4);
		case JS_R1:
			return joy_x(p, 5);
		case JS_L2:
			return joy_x(p, 6);
		case JS_R2:
			return joy_x(p, 7);
		case JS_SEL:
			return joy_x(p, 8);
		case JS_STRT:
			return joy_x(p, 9);
		case JS_L3:
			return joy_x(p, 10);
		case JS_R3:
			return joy_x(p, 11);

		// DPAD and Stick buttons
		case JS_UP:
			return joy_up(p); // button 12 | LS Axis (1, -127) with standard SOCD
		case JS_DN:
			return joy_dn(p); // button 13 | LS Axis (1, 127) with standard SOCD
		case JS_LT:
			return joy_lt(p); // button 14 | LS Axis (0, -127) with standard SOCD
		case JS_RT:
			return joy_rt(p); // button 15 | LS Axis (0, 127) with standard SOCD

		case JS_UP_N:
			return joy_up_n(p); // apply true neutral SOCD
		case JS_DN_N:
			return joy_dn_n(p); // appy true neutral SOCD

		case JS_UP_LIP:
			return joy_up_lip(p); // apply last input priority SOCD
		case JS_DN_LIP:
			return joy_dn_lip(p); // apply last input priority SOCD
		case JS_LT_LIP:
			return joy_lt_lip(p); // apply last input priority SOCD
		case JS_RT_LIP:
			return joy_rt_lip(p); // apply last input priority SOCD

		// PS Home button
		case JS_HOM:
			return joy_x(p, 16);

		default:
			return true;
	}
};
