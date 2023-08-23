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

// Paste default layer enums here

    _DPAD,
    _STICK,
    _JOYFN
};

// Paste defined layer enums here

#define DPAD  TG(_DPAD)
#define STICK  TG(_STICK)
#define JOYFN LT(_JOYFN, KC_SPC)
enum custom_keycodes {  
	// Cross, Circle, Square, and Triangle buttons
	JS_CRO = SAFE_RANGE,
	JS_CIR,
	JS_SQU,
	JS_TRI,

	// L R buttons    
	JS_L1,
	JS_R1,
	JS_L2,
	JS_R2,

	// Select and Start buttons
	JS_SEL,
	JS_STRT,

	// LS RS buttons
	JS_L3,
	JS_R3,

	// DPAD/Stick buttons
	JS_UP,
	JS_DN,
	JS_LT,
	JS_RT,
	
	// Home button
	JS_HOM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Paste your default layer here


  // DPAD mode layer, map all joystick custom keycodes (JS_CRO, JS_CIR, ...) here
  // use DPAD key for toggling off dpad mode
  [_DPAD] = LAYOUT(
    DPAD,    
  ),
  // Stick mode layer, map all joystick custom keycodes (JS_CRO, JS_CIR, ...) here
  // use STICK key for toggling off stick mode
  [_STICK] = LAYOUT(
    STICK,
  ),
  // Switch layer to switch between default layer, 
  // use MO(_JOYFN) key on your default layer
  [_JOYFN] = LAYOUT(
    DPAD,             
    STICK,  
  ),
};


// Joystick configurations and macros 

bool UP_FLAG = false;
bool DN_FLAG = false;
bool LT_FLAG = false;
bool RT_FLAG = false;

// left stick axis 0,1  |  right stick axis 2,3
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
	JOYSTICK_AXIS_VIRTUAL, // x
	JOYSTICK_AXIS_VIRTUAL, // y
};

// SOCD: up+down = up
bool joy_up(bool ok) {
	if (ok) {
		UP_FLAG = true;
		if (DN_FLAG) {
		 IS_LAYER_ON(_DPAD) ? unregister_joystick_button(13): joystick_set_axis(1, 0);
		}
		 IS_LAYER_ON(_DPAD) ? register_joystick_button(12): joystick_set_axis(1, -127);
	} else {
		UP_FLAG = false;
		IS_LAYER_ON(_DPAD) ? unregister_joystick_button(12): joystick_set_axis(1, 0);
	}
	return false;
}

// SOCD: down+up = up
bool joy_dn(bool ok) {
	if (ok) {
		DN_FLAG = true;
		if (!UP_FLAG) {
		 IS_LAYER_ON(_DPAD) ? register_joystick_button(13): joystick_set_axis(1, 127);
		}
	} else {
		DN_FLAG = false;
		IS_LAYER_ON(_DPAD) ? unregister_joystick_button(13): joystick_set_axis(1, 0);
	}
	return false;
}

// SOCD: left+right = neutral 
bool joy_lt(bool ok) {
	if (ok) {
		LT_FLAG = true;
		if (RT_FLAG) {
		 	IS_LAYER_ON(_DPAD) ? unregister_joystick_button(15): joystick_set_axis(0, 0);
		} else {
			IS_LAYER_ON(_DPAD) ? register_joystick_button(14): joystick_set_axis(0, -127);
		}
	} else {
		LT_FLAG = false;
		IS_LAYER_ON(_DPAD) ? unregister_joystick_button(14): joystick_set_axis(0, 0);
		if(RT_FLAG) {
			IS_LAYER_ON(_DPAD) ? register_joystick_button(15): joystick_set_axis(0, 127);
		}
	}
	return false;
}

// SOCD: right+left = neutral 
bool joy_rt(bool ok) {
	if (ok) {
		RT_FLAG = true;
		if (LT_FLAG) {
		 	IS_LAYER_ON(_DPAD) ? unregister_joystick_button(14): joystick_set_axis(0, 0);
		} else {
			IS_LAYER_ON(_DPAD) ? register_joystick_button(15): joystick_set_axis(0, 127);
		}
	} else {
		RT_FLAG = false;
		IS_LAYER_ON(_DPAD) ? unregister_joystick_button(15): joystick_set_axis(0, 0);
		if(LT_FLAG) {
			IS_LAYER_ON(_DPAD) ? register_joystick_button(14): joystick_set_axis(0, -127);
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
			return joy_up(p); // button 12 | LS Axis (1, -127)
		case JS_DN:
			return joy_dn(p); // button 13 | LS Axis (1, 127)
		case JS_LT:
			return joy_lt(p); // button 14 | LS Axis (0, -127)
		case JS_RT:
			return joy_rt(p); // button 15 | LS Axis (0, 127)

		// PS Home button
		case JS_HOM:
			return joy_x(p, 16);

		default:
			return true;
	}
};
