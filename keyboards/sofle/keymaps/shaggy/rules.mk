RGB_MATRIX_ENABLE = yes
ENCODER_MAP_ENABLE = yes
SPLIT_KEYBOARD = yes
CONVERT_TO = rp2040_ce
BOOTLOADER = rp2040

TAP_DANCE_ENABLE = yes

OLED_DRIVER_ENABLE = yes
LTO_ENABLE = yes
LUNA_ENABLE = yes
OCEAN_DREAM_ENABLE = yes
WPM_ENABLE = yes

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
	SRC += oled.c
	
	ifdef OCEAN_DREAM_ENABLE
		ifeq ($(strip $(OCEAN_DREAM_ENABLE)), yes)
			SRC += ocean_dream.c
			OPT_DEFS += -DOCEAN_DREAM_ENABLE
    	endif
	endif

	ifdef LUNA_ENABLE
		ifeq ($(strip $(LUNA_ENABLE)), yes)
			SRC += luna.c
			OPT_DEFS += -DLUNA_ENABLE
		endif
	endif
endif
