 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

#if defined(LUNA_ENABLE)
#include "luna.h"
#endif

#if defined(OCEAN_DREAM_ENABLE)
#include "ocean_dream.h"
#endif

enum LAYERS {
  B,  // Base
  GA, // Game A Preset
  GB, // Game B Preset
  L,  // Lower
  R   // Raise
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [B]  = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT),           ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [GA] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
    [GB] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
    [L]  = { ENCODER_CCW_CW(RM_VALD, RM_VALU),           ENCODER_CCW_CW(RM_PREV, RM_NEXT) },
    [R]  = { ENCODER_CCW_CW(RM_HUED, RM_HUEU),           ENCODER_CCW_CW(RM_SATD, RM_SATU) }
};
#endif

#define LT_ENT LT(B, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base QWERTY
 * ,-----------------------------------------.                               ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                               |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                               |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.               ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Play  |               | Mute  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|               |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-------------+------+------+------+------|       |               |       |------+------+------+------+-------------'
 *               | LGUI | LCTL | LAlt |LOWER | Enter |               | Space |RAISE | RAlt | RCTL | RGUI |
 *               `-----------------------------------'               '-----------------------------------'
 */

[B] = LAYOUT(
  KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                      KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC,
  KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                      KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
  KC_ESC ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                      KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
  KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_MPLY,      KC_MUTE,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                  KC_LGUI,KC_LCTL,KC_LALT,MO(L)  ,KC_ENT ,      KC_SPC ,MO(R)  ,KC_RALT,KC_RCTL,KC_RGUI
),

/*
 * Game A
 * Shifts one column of keys to the right on the left side of the keyboard for a comfortable WASD layout
 * ,-----------------------------------------.                               ,-----------------------------------------.
 * |   5  |  `   |   1  |   2  |   3  |   4  |                               | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * |   T  | Tab  |   Q  |   W  |   E  |   R  |                               | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * |   G  | ESC  |   A  |   S  |   D  |   F  |-------.               ,-------| ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+------+------| ____  |               | ____  |------+------+------+------+------+------|
 * |   B  |LShift|   Z  |   X  |   C  |   V  |-------|               |-------| ____ | ____ | ____ | ____ | ____ | ____ |
 * `-------------+------+------+------+------|       |               |       |------+------+------+------+-------------'
 *               | ____ | ____ | ____ | ____ | Space |               |LT_ENT | ____ | ____ | ____ | ____ |
 *               `-----------------------------------'               '-----------------------------------'
 */

[GA] = LAYOUT(
    KC_5   ,KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,                    _______,_______,_______,_______,_______,_______,
    KC_T   ,KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,                    _______,_______,_______,_______,_______,_______,
    KC_G   ,KC_ESC ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,                    _______,_______,_______,_______,_______,_______,
    KC_B   ,KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,_______,    _______,_______,_______,_______,_______,_______,_______,
                    _______,_______,_______,_______,KC_SPC ,    LT_ENT ,_______,_______,_______,_______
),

/*
 * Game B
 * ,-----------------------------------------.                               ,-----------------------------------------.
 * | ____ | ____ | ____ | ____ | ____ | ____ |                               | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ | ____ |                               | PgUp | Home |  Up  | End | ____ | ____ |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ | ____ |-------.               ,-------| PgDn | Left | Down | Right| ____ | ____ |
 * |------+------+------+------+------+------| ____  |               | ____  |------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ | ____ |-------|               |-------| ____ | ____ | ____ | ____ | ____ | ____ |
 * `-------------+------+------+------+------|       |               |       |------+------+------+------+-------------'
 *               | ____ | ____ | ____ | ____ |LT_ENT |               | ____  | ____ | ____ | ____ | ____ |
 *               `-----------------------------------'               '-----------------------------------'
 */

[GB] = LAYOUT(
    _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,                    KC_PGUP,KC_HOME,KC_UP  ,KC_END ,_______,_______,
    _______,_______,_______,_______,_______,_______,                    KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,
                    _______,_______,_______,_______,LT_ENT ,    _______,_______,_______,_______,_______
),

/*
 * LOWER
 * ,-----------------------------------------.                               ,-----------------------------------------.
 * |      |      |      |      |      |      |                               |      |      |      |      |   -  |   =  |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | ____ |   1  |   2  |   3  |   4  |   5  |                               |   6  |   7  |   8  |   9  |   0  |   [  |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | ____ |   !  |   @  |   #  |   $  |   %  |-------.               ,-------|   ^  |   &  |   *  |   (  |   )  |   ]  |
 * |------+------+------+------+------+------| ____  |               | ____  |------+------+------+------+------+------|
 * | ____ |      |      |   _  |   {  |      |-------|               |-------|      |   }  |   +  |      |      | ____ |
 * `-------------+------+------+------+------|       |               |       |------+------+------+------+-------------'
 *               | ____ | ____ | ____ | ____ | ____  |               | ____  | ____ | ____ | ____ | ____ |
 *               `-----------------------------------'               '-----------------------------------'
 */

[L] = LAYOUT(
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_MINS,KC_EQL ,
    _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                    KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_LBRC,
    _______,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,                    KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_RBRC,
    _______,XXXXXXX,XXXXXXX,KC_UNDS,KC_LCBR,XXXXXXX,_______,    _______,XXXXXXX,KC_RCBR,KC_PLUS,XXXXXXX,XXXXXXX,_______,
                    _______,_______,_______,_______,_______,    _______,_______,_______,_______,_______
),

/*
 * RAISE
 * ,----------------------------------------.                                ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                               |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | ____ | Ins  | Pscr | Menu |Pause |      |                               | PgUp | Home |  Up  | End  | F11  | F12  |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | ____ | LCrl | LWin | LAlt |      |TG(GA)|-------.               ,-------| PgDn | Left | Down | Rigth|      |      |
 * |------+------+------+------+------+------|       |               |       |------+------+------+------+------+------|
 * | ____ |      |      |      |      |TG(GB)|-------|               |-------|      |      |      |      |      | ____ |
 * `-------------+------+------+------+------|       |               |       |------+------+------+------+-------------'
 *               | ____ | ____ | ____ | ____ | ____  |               | ____  | ____ | ____ | ____ | ____ |
 *               `-----------------------------------'               '-----------------------------------'
 */

[R] = LAYOUT(
    XXXXXXX,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                    KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_DEL ,
    _______,KC_INS ,KC_PSCR,KC_APP ,KC_PAUS,XXXXXXX,                    KC_PGUP,KC_HOME,KC_UP  ,KC_END ,KC_F11 ,KC_F12 ,
    _______,KC_LCTL,KC_LGUI,KC_LALT,XXXXXXX,TG(GA) ,                    KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,XXXXXXX,XXXXXXX,
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,TG(GB) ,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
                    _______,_______,_______,_______,_______,    _______,_______,_______,_______,_______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
#ifdef OCEAN_DREAM_ENABLE
            is_calm = (record->event.pressed) ? true : false;
#endif
#ifdef LUNA_ENABLE
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
#endif
            break;
        case KC_SPC:
#ifdef LUNA_ENABLE
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
#endif
            break;
    }
    return true;
}
