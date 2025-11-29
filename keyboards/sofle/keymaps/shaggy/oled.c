#include "quantum.h"
#include "split_util.h"

#ifdef LUNA_ENABLE
#include "luna.h"
#endif

#ifdef OCEAN_DREAM_ENABLE
#include "ocean_dream.h"
#endif

static void print_status_narrow(void) {
    oled_write_P(PSTR("\n\n "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Qwrt"), false);
            break;
        case 1:
            oled_write_P(PSTR("GA"), false);
            break;
        case 2:
            oled_write_P(PSTR("GB"), false);
        default:
            oled_write_P(PSTR("Mod\n"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
        case 1:
        case 2:
            oled_write_P(PSTR(" Base"), false);
            break;
        case 3:
            oled_write_P(PSTR("Lower"), false);
            break;
        case 4:
            oled_write_P(PSTR("Raise"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);

    static char wpm_str[4];

    sprintf(wpm_str, "%03d", get_current_wpm());
    oled_write_P(PSTR(" WPM\n "), false);
    oled_write(wpm_str, false);
}

#ifndef OCEAN_DREAM_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(qmk_logo, false);
}
#endif

bool oled_task_user(void) {
	if (isLeftHand) {
        print_status_narrow();
#ifdef LUNA_ENABLE
        render_luna(0, 13);
#endif
    } else {
#ifdef OCEAN_DREAM_ENABLE
        render_stars();
#else
        render_logo();
#endif
    }
	return false;
}
