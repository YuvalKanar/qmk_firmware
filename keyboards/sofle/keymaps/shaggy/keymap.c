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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT),           ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(RM_VALD, RM_VALU),           ENCODER_CCW_CW(RM_PREV, RM_NEXT) },
    [3] = { ENCODER_CCW_CW(RM_HUED, RM_HUEU),           ENCODER_CCW_CW(RM_SATD, RM_SATU) }
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
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

[0] = LAYOUT(
  KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                      KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC,
  KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                      KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
  KC_ESC ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                      KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
  KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_MPLY,      KC_MUTE,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                  KC_LGUI,KC_LCTL,KC_LALT,MO(2)  ,KC_ENT ,      KC_SPC ,MO(3)  ,KC_RALT,KC_RCTL,KC_RGUI
),

/*
 * GAME
 * ,-----------------------------------------.                               ,-----------------------------------------.
 * |   5  |  `   |   1  |   2  |   3  |   4  |                               | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * |   T  | Tab  |   Q  |   W  |   E  |   R  |                               | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * |   G  | ESC  |   A  |   S  |   D  |   F  |-------.               ,-------| ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+------+------| ____  |               | ____  |------+------+------+------+------+------|
 * |   B  |LShift|   Z  |   X  |   C  |   V  |-------|               |-------| ____ | ____ | ____ | ____ | ____ | ____ |
 * `-------------+------+------+------+------|       |               |       |------+------+------+------+-------------'
 *               | ____ | ____ | ____ | ____ | Space |               | Enter | ____ | ____ | ____ | ____ |
 *               `-----------------------------------'               '-----------------------------------'
 */

[1] = LAYOUT(
    KC_5   ,KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,                    _______,_______,_______,_______,_______,_______,
    KC_T   ,KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,                    _______,_______,_______,_______,_______,_______,
    KC_G   ,KC_ESC ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,                    _______,_______,_______,_______,_______,_______,
    KC_B   ,KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,_______,    _______,_______,_______,_______,_______,_______,_______,
                    _______,_______,_______,_______,KC_SPC ,    KC_ENT ,_______,_______,_______,_______
),

/* LOWER
 * ,-----------------------------------------.                               ,-----------------------------------------.
 * | ____ |  F1  |  F2  |  F3  |  F4  |  F5  |                               |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | ____ |   1  |   2  |   3  |   4  |   5  |                               |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | ____ |   !  |   @  |   #  |   $  |   %  |-------.               ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------| ____  |               | ____  |------+------+------+------+------+------|
 * | ____ |      |   _  |   -  |   =  |   {  |-------|               |-------|   }  |   [  |   ]  |   +  |      | ____ |
 * `-------------+------+------+------+------|       |               |       |------+------+------+------+-------------'
 *               | ____ | ____ | ____ | ____ | ____  |               | ____  | ____ | ____ | ____ | ____ |
 *               `-----------------------------------'               '-----------------------------------'
 */

[2] = LAYOUT(
    _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                    KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
    _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                    KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_F12 ,
    _______,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,                    KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_PIPE,
    _______,XXXXXXX,KC_UNDS,KC_MINS,KC_EQL ,KC_LCBR,_______,    _______,KC_RCBR,KC_LBRC,KC_RBRC,KC_PLUS,XXXXXXX,_______,
                    _______,_______,_______,_______,_______,    _______,_______,_______,_______,_______
),

/* RAISE
 * ,----------------------------------------.                                ,-----------------------------------------.
 * |      |      |      |      |      |      |                               |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | ____ | Ins  | Pscr | Menu |Pause |      |                               | PgUp | Home |  Up  | End  |      |      |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | ____ | LCrl | LWin | LAlt |      |      |-------.               ,-------| PgDn | Left | Down | Rigth|      |      |
 * |------+------+------+------+------+------|       |               |       |------+------+------+------+------+------|
 * | ____ |      |      |      |      |      |-------|               |-------|      |      |      |      |      | ____ |
 * `-------------+------+------+------+------|       |               |       |------+------+------+------+-------------'
 *               | ____ | ____ | ____ |TG(3) | ____  |               | ____  | ____ | ____ | ____ | ____ |
 *               `-----------------------------------'               '-----------------------------------'
 */

[3] = LAYOUT(
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_DEL ,
    _______,KC_INS ,KC_PSCR,KC_APP ,KC_PAUS,XXXXXXX,                    KC_PGUP,KC_HOME,KC_UP  ,KC_END ,XXXXXXX,XXXXXXX,
    _______,KC_LCTL,KC_LGUI,KC_LALT,XXXXXXX,XXXXXXX,                    KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,XXXXXXX,XXXXXXX,
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
                    _______,_______,_______,TG(1)  ,_______,    _______,_______,_______,_______,_______
),
};
