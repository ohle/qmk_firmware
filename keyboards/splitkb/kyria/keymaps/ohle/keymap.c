#include QMK_KEYBOARD_H
#include "getreuer/features/achordion.h"

enum layers {
    _BASE = 0,
    _NUM,
    _SYM,
    _FUN,
    _NAV,
    _MOUSE,
    _ALTSYM,
    _GAME,
};


enum custom_keycodes {
    C_MU = SAFE_RANGE, // C_XXX: Compose characters
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
    SL_SPC, // SL_: Smart Layer keycodes. Emit a keycode and deactivate a
    SL_ENT, // layer at the same time
    SL_ESC,
    NXTWRD,
    PRVWRD,
};

void clear_ball(void);

// Aliases for readability
#define MOUSE_TAB LT(_MOUSE, KC_TAB)
#define SYM_ENT   LT(_SYM, KC_ENT)
#define ASYM_SPC  LT(_ALTSYM, KC_SPC)
#define FUN_BSPC  LT(_FUN, KC_BSPC)
#define NAV       MO(_NAV)
#define NUM       MO(_NUM)
#define MOUSE     MO(_MOUSE)
#define ALTSYM    OSL(_ALTSYM)

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

enum combo_events {
    UJ_LPRN,
    IK_RPRN,
    JM_LCBR,
    KCOMMA_RCBR,
    OL_LBRC,
    YH_PLUS,
    HN_EQUALS,
    TWOZERO_BACKSPACE,
    PSEMI_RBRC,
    UIO_NUMBERS,
    N789_NUMBERS,
    JKL_NAV,
    ARROWJKL_NAV,
    MCOMMDOT_MOUSE,
    DMPLY1DMREC2DMPLY2_MOUSE,
    SDF_GAME,
    GASD_GAME,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM uj_combo[] = { KC_U, MT_J, COMBO_END };
const uint16_t PROGMEM ik_combo[] = { KC_I, MT_K, COMBO_END };
const uint16_t PROGMEM jm_combo[] = { MT_J, KC_M, COMBO_END };
const uint16_t PROGMEM kcomma_combo[] = { MT_K, KC_COMM, COMBO_END };
const uint16_t PROGMEM ol_combo[] = { KC_O, MT_L, COMBO_END };
const uint16_t PROGMEM twozero_combo[] = { LT(0, KC_2), KC_0, COMBO_END };
const uint16_t PROGMEM psemi_combo[] = { KC_P, MT_COL, COMBO_END };
const uint16_t PROGMEM yh_combo[] = { KC_Y, KC_H, COMBO_END };
const uint16_t PROGMEM hn_combo[] = { KC_H, KC_N, COMBO_END };
const uint16_t PROGMEM uio_combo[] = { KC_U, KC_I, KC_O, COMBO_END };
const uint16_t PROGMEM n789_combo[] = { KC_7, KC_8, KC_9, COMBO_END };
const uint16_t PROGMEM jkl_combo[] = { MT_J, MT_K, MT_L, COMBO_END };
const uint16_t PROGMEM arrowjkl_combo[] = { KC_DOWN, KC_UP, KC_RIGHT, COMBO_END };
const uint16_t PROGMEM mcommdot_combo[] = { KC_M, KC_COMM, KC_DOT, COMBO_END };
const uint16_t PROGMEM dmply1dmrec2dmply2_combo[] = { DM_PLY1, DM_REC2, DM_PLY2, COMBO_END };
const uint16_t PROGMEM sdf_combo[] = { MT_S, MT_D, MT_F, COMBO_END };
const uint16_t PROGMEM gasd_combo[] = { KC_A, KC_S, KC_D, COMBO_END };

combo_t key_combos[] = {
    [UJ_LPRN] = COMBO(uj_combo, KC_LPRN),
    [IK_RPRN] = COMBO(ik_combo, KC_RPRN),
    [JM_LCBR] = COMBO(jm_combo, KC_LCBR),
    [KCOMMA_RCBR] = COMBO(kcomma_combo, KC_RCBR),
    [OL_LBRC] = COMBO(ol_combo, KC_LBRC),
    [YH_PLUS] = COMBO(yh_combo, KC_PLUS),
    [HN_EQUALS] = COMBO(hn_combo, KC_EQL),
    [PSEMI_RBRC] = COMBO(psemi_combo, KC_RBRC),
    [TWOZERO_BACKSPACE] = COMBO(twozero_combo, KC_BSPC),
    [UIO_NUMBERS] = COMBO_ACTION(uio_combo),
    [N789_NUMBERS] = COMBO_ACTION(n789_combo),
    [JKL_NAV] = COMBO_ACTION(jkl_combo),
    [ARROWJKL_NAV] = COMBO_ACTION(arrowjkl_combo),
    [MCOMMDOT_MOUSE] = COMBO_ACTION(mcommdot_combo),
    [DMPLY1DMREC2DMPLY2_MOUSE] = COMBO_ACTION(dmply1dmrec2dmply2_combo),
    [SDF_GAME] = COMBO_ACTION(sdf_combo),
    [GASD_GAME] = COMBO_ACTION(gasd_combo)
};


enum {
    TD_2COMMA,
    TD_3DOT,
    TD_0BSPC,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_2COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_COMM),
    [TD_3DOT] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_DOT),
    [TD_0BSPC] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_BSPC),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: QWERTY
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  del   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   Esc  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | : ;  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | , <  | . >  | / ?  | RShift |
 * `----------------------+------+------+------| Sym  | Num  |  | Fun  |      |------+------+------+----------------------'
 *                        |Altsym| Mouse| Nav  | enter| tab  |  | bspc | Space|LShift| bcksp| Enter|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
     KC_ESC  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_DEL,
     ALTSYM  , MT_A ,  MT_S   ,  MT_D  ,   MT_F ,   KC_G ,                                        KC_H,   MT_J ,  MT_K ,   MT_L , MT_COL, KC_QUOT,
     LSHFT   , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , XXXXXXX,XXXXXXX,     XXXXXXX, XXXXXXX, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, RSHFT,
                                 PAUSE ,   NAV ,    NUM , SYM_ENT ,MOUSE_TAB,   FUN_BSPC, KC_SPC, LSHFT, KC_BSPC,KC_ENT
    ),
/*
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE |      |      |      |      |      |                              |  ` ~ | 7 &  | 8 *  | 9 (  |  (   |   )    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Hypr | GUI  |  Alt | Ctrl |      |                              |  = + | 4 $  | 5 %  | 6 ^  |  {   |   }    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |      |  |      |      |  \ | | 1 !  | 2 @  | 3 #  |  ,   |   .    |
 * `----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      | Space|      |  |      | Space|  - _ | 0 )  |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      SL_ESC , _______, DT_PRNT, DT_DOWN, DT_UP, _______,                                     KC_GRV , KC_7   , KC_8   , KC_9   , KC_LPRN, KC_RPRN,
      _______, KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, _______,                                     KC_EQL , KC_4   , KC_5   , KC_6   , KC_BSPC, KC_RCBR,
      LSHFT  , KC_SCLN , KC_COMM, KC_DOT , KC_SLSH, KC_QUOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_1   , LT(0, KC_2)   , LT(0, KC_3)   , KC_COMM, MT(MOD_RSFT, KC_DOT),
                                 _______, _______, _______, SL_ENT , _______, _______, _______, KC_MINUS, KC_0 , _______
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
 * |  PAUSE |      |NXTWRD|NXTWRD|      |      |                              | MW←  |  MW↓ |  MW↑ |  MW→ |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Hypr | GUI  |  Alt | Ctrl |      |                              |  ←   |   ↓  |   ↑  |   →  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |      | Cut  | Copy | Paste|      |      |      |  |      |      | Home |PgDown| PgUp |  End |      |        |
 * `----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      | Space|      |  |      | Space|      |      |      |
 *                        |      |      | --   |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      SL_ESC , _______,  NXTWRD,  NXTWRD, _______, _______,                                     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
      _______, KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, _______,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
      LSHFT  , _______, KC_CUT , KC_COPY, KC_PSTE, PRVWRD , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
                                 _______, _______, _______, _______ , _______, _______, _______ , _______, _______, _______
    ),
/*
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  PAUSE |      |      |      |      | acc2 |                              | MW←  |  MW↓ |  MW↑ |  MW→ |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Hypr | GUI  |  Alt | Ctrl | acc1 |                              |  ←   |   ↓  |   ↑  |   →  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |      | Cut  | Copy | Paste| acc0 |      |      |  |      |      |  MR1 |  MP1 |  MR2 |  MP2 |      |        |
 * `----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      | Space|      |  |      | Space|      |      |      |
 *                        | --   |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MOUSE] = LAYOUT(
      _______, _______, _______, _______, _______, KC_ACL2,                                     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
      _______, KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, KC_ACL1,                                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
      LSHFT  , _______, KC_CUT , KC_COPY, KC_PSTE, KC_ACL0, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_REC1, DM_PLY1, DM_REC2, DM_PLY2, _______, _______,
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
 /*
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  * `----------------------+------+------+------+      |      |  |      |      |------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_GAME] = LAYOUT(
       _______, _______, KC_Q   , KC_W   , KC_E   , _______,                                     _______, _______, _______, _______, _______, _______,
       _______, KC_E   , KC_A   , KC_S   , KC_D   , _______,                                     _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, KC_F   , _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,
                                  _______, KC_LSFT, KC_LCTL, KC_SPC , _______, _______, _______, _______, _______, _______
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

#define ACCSCROLL_MAX_STEP 20
#define ACCSCROLL_STEP_SIZE 1
#define ACCSCROLL_REPEAT_INTERVAL 200

static uint16_t scrollTimer = 0;
static uint8_t scrollStepSize = 1;

bool encoder_update_user(uint8_t index, bool clockwise) {

    uint8_t layer = get_highest_layer(layer_state);
    if (index == 0) {
        // Volume control
        if (clockwise) {
            if (layer == _FUN) {
                tap_code16(C(KC_PLUS));
            } else {
                tap_code(KC_VOLU);
            }
        } else {
            if (layer == _FUN) {
                tap_code16(C(KC_MINUS));
            } else {
                tap_code(KC_VOLD);
            }
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
            if (layer == _NAV) {
                SEND_STRING(SS_RCTL(SS_RSFT(SS_TAP(X_RIGHT))));
            } else if (layer == _MOUSE) {
                SEND_STRING(SS_TAP(X_TAB));
            } else {
                for (uint8_t i = 0; i < scrollStepSize; i++) {
                    tap_code(KC_DOWN);
                }
            }
        } else {
            if (layer == _NAV) {
                SEND_STRING(SS_RCTL(SS_RSFT(SS_TAP(X_LEFT))));
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

uint16_t mouseguard_timer = 0;
#define SEND_COMPSEQ(seq) SEND_STRING(SS_TAP(COMPOSE_KEY)seq)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mouseguard_timer = timer_read();
    /* if (!process_achordion(keycode, record)) { */
    /*     return false; */
    /* } */

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
        case SL_SPC:
            layer_clear();
            SEND_STRING(" ");
            break;
        case SL_ENT:
            layer_clear();
            SEND_STRING("\n");
            break;
        case SL_ESC:
            layer_clear();
            tap_code(KC_ESC);
            break;
        case NXTWRD:
            tap_code16(C(KC_RGHT));
            break;
        case PRVWRD:
            tap_code16(C(KC_LEFT));
            break;
        case LT(0, KC_0):
            if (record->tap.count && record->event.pressed) {
                return true; // process tapped key normally
            } else if (record->event.pressed) {
                tap_code(KC_BSPC); // intercept hold and send backspace
                return false;
            }
            return true; // process release normally
        case LT(0, KC_2):
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code(KC_COMM);
                return false;
            }
            return true;
        case LT(0, KC_3):
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code(KC_DOT);
                return false;
            }
            return true;
        default:
            return true;
    }
    return false;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case UIO_NUMBERS:
        case N789_NUMBERS:
            if (pressed) {
                layer_invert(_NUM);
            }
            break;
        case JKL_NAV:
        case ARROWJKL_NAV:
            if (pressed) {
                layer_invert(_NAV);
            }
            break;
        case MCOMMDOT_MOUSE:
        case DMPLY1DMREC2DMPLY2_MOUSE:
            if (pressed) {
                layer_invert(_MOUSE);
            }
            break;
        case SDF_GAME:
        case GASD_GAME:
            if (pressed) {
                layer_invert(_GAME);
            }
            break;
    }
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

uint16_t mousemode_timer;
uint16_t mouse_debounce;
bool mousemode = false;


report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    mouse_xy_report_t x = mouse_report.x, y = mouse_report.y;
    mouse_report.x = 0;
    mouse_report.y = 0;

    if (timer_elapsed(mouseguard_timer) < 500) {
        return mouse_report;
    }
    if (x != 0 || y != 0) {
        mousemode = true;
        layer_on(_MOUSE);
        mousemode_timer = timer_read();
    }
    // on nav layer, scroll
    if (layer_state_is(_NAV)) {
        mouse_report.h = TRACKBALL_SCROLL_SCALE * x;
        mouse_report.v = -TRACKBALL_SCROLL_SCALE * y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        mouse_report.x = x;
        mouse_report.y = y;
    }

    return mouse_report;
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
        uint16_t other_keycode, keyrecord_t *other_record) {
    // Allow same-hand holds when the other key is in the row below the
    // alphas
    if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 3) {
        return true;
    }

    // Otherwise, follow opposite-hands rule
    return achordion_opposite_hands(tap_hold_record, other_record);
}

void matrix_scan_user() {
    /* achordion_task(); */
    if (mousemode && timer_elapsed(mousemode_timer) >= MOUSEMODE_LINGER) {
        mousemode = false;
        layer_off(_MOUSE);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _NAV:
            pimoroni_trackball_set_rgbw(181, 137, 0, 0);
            break;
        case _MOUSE:
            pimoroni_trackball_set_rgbw(0, 0, 0, 255);
            break;
        case _NUM:
            pimoroni_trackball_set_rgbw(211, 54, 130, 0);
            break;
        case _GAME:
            pimoroni_trackball_set_rgbw(255, 0, 0, 0);
            break;
        default:
            pimoroni_trackball_set_rgbw(0, 0, 0, 0);
    }
    return state;
}
#endif
