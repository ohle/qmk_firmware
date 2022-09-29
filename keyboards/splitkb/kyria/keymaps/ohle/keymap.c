#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _NUM,
    _SYM,
    _FUN,
    _NAV,
    _MOUSE,
};


// Aliases for readability
#define NUM_TAB  LT(_NUM, KC_TAB)
#define SYM_SPC  LT(_SYM, KC_SPC)
#define FUN_TAB  LT(_FUN, KC_TAB)
#define NAV      MO(_NAV)
#define MOUSE    MO(_MOUSE)

#define MT_A     MT(MOD_HYPR, KC_A)
#define MT_S     MT(MOD_LGUI, KC_S)
#define MT_S     MT(MOD_LALT, KC_D)
#define MT_F     MT(MOD_LCTL, KC_F)
#define MT_J     MT(MOD_RCTL, KC_J)
#define MT_K     MT(MOD_RALT, KC_K)
#define MT_L     MT(MOD_GUI, KC_L)
#define MT_COL   MT(MOD_HYPR, KC_SCLN)

#define LSHFT    OSM(MOD_LSFT)
#define RSHFT    OSM(MOD_RSFT)

#define PAUSE    KC_MEDIA_PLAY_PAUSE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: QWERTY
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | ENTER  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   Esc  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | : ;  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | , <  | . >  | / ?  | RShift |
 * `----------------------+------+------+------| Sym  | Num  |  | Fun  |      |------+------+------+----------------------'
 *                        | Mouse| Nav  | Enter| Space| Tab  |  | Tab  | Space| Enter| bcksp|  del |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
     PAUSE   , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_ENT,
     KC_ESC  , MT_A ,  MT_S   ,  MT_D  ,   MT_F ,   KC_G ,                                        KC_H,   MT_J ,  MT_K ,   MT_L , MT_COL, KC_QUOT,
     LSHFT   , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , XXXXXXX,XXXXXXX,     XXXXXXX, XXXXXXX, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, RSHFT,
                                MOUSE  ,   NAV  , KC_ENT , SYM_SPC,NUM_TAB,     FUN_TAB, KC_SPC,KC_ENT, KC_BSPC,KC_DEL
    ),
/*
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE |      |      |      |      |      |                              |  ` ~ | 7 &  | 8 *  | 9 (  |  )   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Hypr | GUI  |  Alt | Ctrl |      |                              |  = + | 4 $  | 5 %  | 6 ^  |  {   |   }    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |      |  |      |      |  \ | | 1 !  | 2 @  | 3 #  | [ {  |  ] }   |
 * `----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      | Space|      |  |      | Space|      | 0 )  |  - _ |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_GRV , KC_7   , KC_8   , KC_9   , KC_RPRN, _______,
      _______, KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, _______,                                     KC_EQL , KC_4   , KC_5   , KC_6   , KC_LCBR, KC_RCBR,
      LSHFT  , _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_1   , KC_2   , KC_3   , KC_LBRC, MT(MOD_RSFT, KC_RPRC),
                                 _______, _______, _______, KC_SPC , _______, _______, KC_SPC , _______, KC_0   , KC_MINUS
    ),
/*
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE |      |      |      |      |      |                              |   ~  |   &  |   *  |   (  |   )  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Hyper|  Ctrl|  Alt |  Gui |      |                              |   +  |   $  |   %  |   ^  |  {   |   }    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |      |  |      |      |   |  |   !  |   @  |   #  |  [   | Shift ]|
 * `----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      | Space|      |  |      | Space|      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_TILD, KC_AMPR, KC_ASTR, KC_LPRN, KR_RPRN, _______,
      _______, KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, _______,                                     KC_PLUS, KC_DLR , KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR,
      LSHFT  , _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, KC_EXLM, KC_AT  , KC_HASH, KC_LBRC, MT(MOD_RSFT, KC_RBRC),
                                 _______, _______, _______, KC_SPC , _______, _______, KC_SPC , _______, _______, _______
    ),
/*
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE | F12  |  F7  |  F8  |  F9  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | F11  |  F4  |  F5  |  F6  |      |                              |      | Hyper| Ctrl |  Alt |  GUI |        |
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
                                 _______, _______, _______, KC_SPC , _______, _______, KC_SPC , _______, _______, _______
    ),
/*
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE |      |      |      |      |      |                              | MW←  |  MW↓ |  MW↑ |  MW→ |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Hyper|  Ctrl|  Alt |  Gui |      |                              |  ←   |   ↓  |   ↑  |   →  |      |        |
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
                                 _______, _______, _______, KC_SPC , _______, _______, KC_SPC , _______, _______, _______
    ),


/*
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE |      |      |      |      | acc2 |                              | MW←  |  MW↓ |  MW↑ |  MW→ |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Hyper|  Ctrl|  Alt |  Gui | acc1 |                              |  ←   |   ↓  |   ↑  |   →  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |      |      |      |      | acc0 |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      | Space|      |  |      | Space|      |      |      |
 *                        | --   |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MOUSE] = LAYOUT(
      _______, _______, _______, _______, _______, KC_ACL2,                                     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
      _______, KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, KC_ACL1,                                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
      LSHFT  , _______, _______, _______, _______, KC_ACL0, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, KC_SPC , _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______
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
#define ACCSCROLL_STEP_SIZE 5
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

        if (clockwise) {
            for (uint8_t i = 0; i < scrollStepSize; i++) {
                tap_code(KC_DOWN);
            }
        } else {
            for (uint8_t i = 0; i < scrollStepSize; i++) {
                tap_code(KC_UP);
            }
        }
    }
    return false;
}
#endif
