#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _NUM,
    _SYM,
    _FUN,
    _NAV,
    _MOUSE,
    _ALTSYM,
};


enum compose_keycodes {
    C_MU = SAFE_RANGE,
    C_AE,
    C_OE,
    C_UE,
    C_SZ,
    C_DEG,
    C_EUR,
    C_MDASH,
    C_R,
    C_C,
    C_LEQ,
    C_GEQ,
    C_NEQ,
    C_PM,
    C_TM,
    C_SQRT,
    C_SQ,
    C_CUB,
};

void clear_ball(void);

// Aliases for readability
#define NUM_TAB  LT(_NUM, KC_TAB)
#define SYM_ENT  LT(_SYM, KC_ENT)
#define ASYM_SPC LT(_ALTSYM, KC_SPC)
#define FUN_BSP  LT(_FUN, KC_BSPC)
#define NAV      MO(_NAV)
#define MOUSE    MO(_MOUSE)
#define ALTSYM   OSL(_ALTSYM)

#define MT_A     MT(MOD_HYPR, KC_A)
#define MT_S     MT(MOD_LGUI, KC_S)
#define MT_D     MT(MOD_LALT, KC_D)
#define MT_F     MT(MOD_LCTL, KC_F)
#define MT_J     MT(MOD_RCTL, KC_J)
#define MT_K     MT(MOD_RALT, KC_K)
#define MT_L     MT(MOD_RGUI, KC_L)
#define MT_COL   MT(MOD_HYPR, KC_SCLN)

#define LSHFT    OSM(MOD_LSFT)
#define RSHFT    OSM(MOD_RSFT)

#define PAUSE    KC_MEDIA_PLAY_PAUSE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: QWERTY
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  = +   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   Esc  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | : ;  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | , <  | . >  | / ?  | RShift |
 * `----------------------+------+------+------| Sym  | Num  |  | Fun  |      |------+------+------+----------------------'
 *                        |Altsym| Mouse| Nav  | enter| tab  |  | bspc | Space| del  | bcksp| Enter|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
     PAUSE   , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_EQL,
     KC_ESC  , MT_A ,  MT_S   ,  MT_D  ,   MT_F ,   KC_G ,                                        KC_H,   MT_J ,  MT_K ,   MT_L , MT_COL, KC_QUOT,
     LSHFT   , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , XXXXXXX,XXXXXXX,     XXXXXXX, XXXXXXX, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, RSHFT,
                                ALTSYM ,  MOUSE ,    NAV ,SYM_ENT, NUM_TAB,     FUN_BSP, KC_SPC,KC_DEL, KC_BSPC,KC_ENT
    ),
/*
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE |      |      |      |      |      |                              |  ` ~ | 7 &  | 8 *  | 9 (  |  (   |   )    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Hypr | GUI  |  Alt | Ctrl |      |                              |  = + | 4 $  | 5 %  | 6 ^  |  {   |   }    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |      |  |      |      |  \ | | 1 !  | 2 @  | 3 #  | [ {  |  ] }   |
 * `----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      | Space|      |  |      | Space|  - _ | 0 )  |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      _______, _______, DT_PRNT, DT_DOWN, DT_UP, _______,                                     KC_GRV , KC_7   , KC_8   , KC_9   , KC_LPRN, KC_RPRN,
      _______, KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, _______,                                     KC_EQL , KC_4   , KC_5   , KC_6   , KC_LCBR, KC_RCBR,
      LSHFT  , _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_1   , KC_2   , KC_3   , KC_LBRC, MT(MOD_RSFT, KC_RBRC),
                                 _______, _______, _______, _______ , _______, _______, _______ , KC_MINUS, KC_0   , _______
    ),
/*
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE |      |      |      |      |      |                              |   ~  |   &  |   *  |   (  |   (  |   )    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Hypr | GUI  |  Alt | Ctrl |      |                              |   +  |   $  |   %  |   ^  |  {   |   }    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |      |  |      |      |   |  |   !  |   @  |   #  |  [   | Shift ]|
 * `----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      | Space|      |  |      | Space|   _  |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_TILD, KC_AMPR, KC_ASTR, KC_LPRN, KC_LPRN, KC_RPRN,
      _______, KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, _______,                                     KC_PLUS, KC_DLR , KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR,
      LSHFT  , _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, KC_EXLM, KC_AT  , KC_HASH, KC_LBRC, MT(MOD_RSFT, KC_RBRC),
                                 _______, _______, _______, _______ , _______, _______, _______ , KC_UNDS, _______, _______
    ),
/*
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE | F12  |  F7  |  F8  |  F9  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | F11  |  F4  |  F5  |  F6  |      |                              |      | Ctrl |  Alt |  GUI | Hypr |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift | F10  |  F1  |  F2  |  F3  |      |      |      |  |      |      |      |      |      |      |      | RShift |
 * `----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      | Space|      |  |      | Space|      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUN] = LAYOUT(
      _______, KC_F12 , KC_F7  , KC_F8  , KC_F9  , _______,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_F11 , KC_F4  , KC_F5  , KC_F6  , _______,                                     _______, KC_RCTL, KC_RALT, KC_RGUI, KC_HYPR, _______,
      LSHFT  , KC_F10 , KC_F1  , KC_F2  , KC_F3  , _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, RSHFT,
                                 _______, _______, _______, _______ , _______, _______, _______ , _______, _______, _______
    ),
/*
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE |      |      |      |      |      |                              | MW←  |  MW↓ |  MW↑ |  MW→ |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Hypr | GUI  |  Alt | Ctrl |      |                              |  ←   |   ↓  |   ↑  |   →  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |      |  |      |      | Home |PgDown| PgUp |  End |      |        |
 * `----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      | Space|      |  |      | Space|      |      |      |
 *                        |      |      | --   |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
      _______, KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, _______,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
      LSHFT  , _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
                                 _______, _______, _______, _______ , _______, _______, _______ , _______, _______, _______
    ),


/*
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE |      |      |      |      | acc2 |                              | MW←  |  MW↓ |  MW↑ |  MW→ |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Hypr | GUI  |  Alt | Ctrl | acc1 |                              |  ←   |   ↓  |   ↑  |   →  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |      |      |      |      | acc0 |      |      |  |      |      |  MR1 |  MP1 |  MR2 |  MP2 |      |        |
 * `----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      | Space|      |  |      | Space|      |      |      |
 *                        | --   |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MOUSE] = LAYOUT(
      _______, _______, _______, _______, _______, KC_ACL2,                                     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
      _______, KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, KC_ACL1,                                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
      LSHFT  , _______, _______, _______, _______, KC_ACL0, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_REC1, DM_PLY1, DM_REC2, DM_PLY2, _______, _______,
                                 _______, _______, _______, _______ , _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______
    ),
/*
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  ²   |   ³  |   €  |   ®  |   ™  |                              |   ±  |   ü  |   π  |   ö  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  ä   |   ß  |   °  |      |      |                              |   ≠  |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |   ©  |   √  |      |      |      |  |      |      |      |   µ  |   ≤  |   ≥  |      |        |
 * `----------------------+------+------+------+      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |  —   |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ALTSYM] = LAYOUT(
      _______, C_SQ   , C_CUB  , C_EUR  , C_R    , C_TM   ,                                     C_PM   , C_UE   , _______,    C_OE   , UC(0x03c0), _______,
      _______, C_AE   , C_SZ   , C_DEG  , _______, _______,                                     C_NEQ  , _______, _______, _______, _______, _______,
      _______, _______, _______, C_C    , C_SQRT , _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, C_MU   , C_LEQ  , C_GEQ  , _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, C_MDASH, _______, _______
    ),
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+      |      |  |      |      |------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

#ifdef ENCODER_ENABLE

#define ACCSCROLL_MAX_STEP 100
#define ACCSCROLL_STEP_SIZE 2
#define ACCSCROLL_REPEAT_INTERVAL 200

static uint16_t scrollTimer = 0;
static uint8_t scrollStepSize = 1;

bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Accelerated scrolling using up/down arrows
        if (timer_elapsed(scrollTimer) < ACCSCROLL_REPEAT_INTERVAL) {
            scrollStepSize += ACCSCROLL_STEP_SIZE;
            scrollStepSize = (scrollStepSize > ACCSCROLL_MAX_STEP) ? ACCSCROLL_MAX_STEP : scrollStepSize;
        } else {
            scrollStepSize = 1;
        }
        scrollTimer = timer_read();

        uint8_t layer = get_highest_layer(layer_state);
        if (clockwise) {
            if (layer == _NAV) {
                SEND_STRING(SS_RCTL(SS_RALT(SS_TAP(X_RIGHT))));
            } else if (layer == _MOUSE) {
                SEND_STRING(SS_TAP(X_TAB));
            } else {
                for (uint8_t i = 0; i < scrollStepSize; i++) {
                    tap_code(KC_DOWN);
                }
            }
        } else {
            if (layer == _NAV) {
                SEND_STRING(SS_RCTL(SS_RALT(SS_TAP(X_LEFT))));
            } else if (layer == _MOUSE) {
                SEND_STRING(SS_LSFT(SS_TAP(X_TAB)));
            } else {
                for (uint8_t i = 0; i < scrollStepSize; i++) {
                    tap_code(KC_UP);
                }
            }
        }
    }
    return false;
}

#define SEND_COMPSEQ(seq) SEND_STRING(SS_TAP(COMPOSE_KEY)seq)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    uint8_t shifted = get_mods() & MOD_MASK_SHIFT;

    switch (keycode) {
        case C_MU:
            SEND_COMPSEQ("mu");
            break;
        case C_AE:
            if (shifted) {
                SEND_COMPSEQ("\"A");
            } else {
                SEND_COMPSEQ("\"a");
            }
            break;
        case C_OE:
            if (shifted) {
                SEND_COMPSEQ("\"O");
            } else {
                SEND_COMPSEQ("\"o");
            }
            break;
        case C_UE:
            if (shifted) {
                SEND_COMPSEQ("\"U");
            } else {
                SEND_COMPSEQ("\"u");
            }
            break;
        case C_SZ:
            SEND_COMPSEQ("ss");
            break;
        case C_DEG:
            SEND_COMPSEQ("oo");
            break;
        case C_EUR:
            SEND_COMPSEQ("=e");
            break;
        case C_MDASH:
            SEND_COMPSEQ("---");
            break;
        case C_R:
            SEND_COMPSEQ("or");
            break;
        case C_C:
            SEND_COMPSEQ("oc");
            break;
        case C_LEQ:
            SEND_COMPSEQ("<=");
            break;
        case C_GEQ:
            SEND_COMPSEQ(">=");
            break;
        case C_NEQ:
            SEND_COMPSEQ("/=");
            break;
        case C_PM:
            SEND_COMPSEQ("+-");
            break;
        case C_TM:
            SEND_COMPSEQ("tm");
            break;
        case C_SQRT:
            SEND_COMPSEQ("v/");
            break;
        case C_SQ:
            SEND_COMPSEQ("^2");
            break;
        case C_CUB:
            SEND_COMPSEQ("^3");
            break;
        default:
            return true;
    }
    return false;
}

void clear_ball() {
    pimoroni_trackball_set_rgbw(0, 0, 0, 0);
}

void caps_word_set_user(bool active) {
    if (active) {
        pimoroni_trackball_set_rgbw(42, 161, 152, 0);
    } else {
        clear_ball();
    }
}

void oneshot_mods_changed_user(uint8_t mods) {
    if (mods & MOD_MASK_SHIFT) {
        pimoroni_trackball_set_rgbw(133, 155, 0, 0);
    } else {
        clear_ball();
    }
}
#endif
