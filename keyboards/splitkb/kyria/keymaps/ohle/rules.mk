ENCODER_ENABLE = yes       # Enables the use of one or more encoders
MOUSEKEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
UNICODE_ENABLE = yes

LTO_ENABLE = yes # Link-time optimization to reduce size
CONSOLE_ENABLE = yes
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

OLED_ENABLE = no
RGBLIGHT_ENABLE = no

DYNAMIC_TAPPING_TERM_ENABLE = yes

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pimoroni_trackball

SRC += getreuer/features/achordion.c
