#include QMK_KEYBOARD_H
#include "version.h"

#define BASE   0 // default layer
#define DEV    1 // DevLayer
#define NUM    2 // Number/Navigation
#define COL    3 // Colemak
#define COLDEV 4 // Colemake Devlayer

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.       ,--------------------------------------------------.
 * | Escape |   1  |   2  |   3  |   4  |   5  |  F11 |       | LCol |   6  |   7  |   8  |   9  |   0  |  Bksp  |
 * |--------+------+------+------+------+-------------|       |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  F2  |       |  F4  |   Y  |   U  |   I  |   O  |  Esc |  Del   |
 * |--------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|       |------|   H  |   J  |   K  |   L  |   ;  |  Enter |
 * |--------+------+------+------+------+------|  F3  |       |  F5  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |       |      |   N  |   M  |   ,  |   .  |   /  |  LNum  |
 * `--------+------+------+------+------+-------------'       `-------------+------+------+------+------+--------'
 * | NOOP   | Left |  Up  | Down | Right|                                   | Left |  Up  | Down | Right|  Clear |
 * `------------------------------------'                                   `------------------------------------'
 *                                      ,-------------.       ,-------------.
 *                                      | LGui | RAlt |       | RGui | LAlt |
 *                               ,------|------|------|       |------+------+------.
 *                               |      |      | NOOP |       | RCtl |      |      |
 *                               | Space| LCtl |------|       |------| LSft | LDev |
 *                               |      |      | LNum |       | NOOP |      |      |
 *                               `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,     KC_1,       KC_2,     KC_3,       KC_4,       KC_5,     KC_F11,
        KC_TAB,     KC_Q,       KC_W,     KC_E,       KC_R,       KC_T,     KC_F2,
        KC_BSPC,    KC_A,       KC_S,     KC_D,       KC_F,       KC_G,
        KC_LSFT,    KC_Z,       KC_X,     KC_C,       KC_V,       KC_B,     KC_F3,
        KC_NO,      KC_LEFT,    KC_UP,    KC_DOWN,    KC_RIGHT,

                                                                            KC_LCMD,    KC_ROPT,
                                                                                        KC_NO,
                                                                  KC_SPC,   KC_LCTRL,   MO(NUM),


        // right hand
                    TO(COL),    KC_6,     KC_7,       KC_8,       KC_9,     KC_0,       KC_BSPC,
                    KC_F4,      KC_Y,     KC_U,       KC_I,       KC_O,     KC_ESC,     KC_DEL,
                                KC_H,     KC_J,       KC_K,       KC_L,     KC_SCLN,    KC_ENTER,
                    KC_F5,      KC_N,     KC_M,       KC_COMM,    KC_DOT,   KC_SLSH,    MO(NUM),
                                          KC_LEFT,    KC_UP,      KC_DOWN,  KC_RIGHT,   TO(BASE),

        KC_RCMD,    KC_LOPT,
        KC_RCTL,
        KC_NO,       KC_RSFT,    MO(DEV)
    ),


/* Keymap 1: DevLayer
 * Note: It is assumed that the computer's keyboard layout is set to `colemak` which means that to type
 * the `;` and `:` keys, you need to send the `p` and `shift+p` keycodes.
 *
 * ,---------------------------------------------------.       ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |       |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|       |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   #  |   $  |   %  |      |       |      |   ^  |   &  |   *  | :(P) |      |        |
 * |---------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * |         |   (  |   )  |   {  |   }  |   `  |------|       |------|   |  |   -  |   "  |   =  | ;(p) |        |
 * |---------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * |         |   [  |   ]  |   <  |   >  |   ~  |      |       |      |   \  |   _  |   '  |   +  |   ?  |  NOOP  |
 * `---------+------+------+------+------+-------------'       `-------------+------+------+------+------+--------'
 * |  EPRM   |      |      |      |      |                                   |      |      |      |      |        |
 * `-------------------------------------'                                   `------------------------------------'
 *                                       ,-------------.       ,-------------.
 *                                       |      |      |       |      |      |
 *                                ,------|------|------|       |------+------+------.
 *                                |      |      |      |       |      |      |      |
 *                                |      |      |------|       |------|      | HOLD |
 *                                |      |      | NOOP |       | NOOP |      |      |
 *                                `--------------------'       `--------------------'
 */
[DEV] = LAYOUT_ergodox(
        // left hand
        KC_TRNS,    KC_F1,      KC_F2,    KC_F3,      KC_F4,      KC_F5,      KC_F11,
        KC_TRNS,    KC_EXCLAIM, KC_AT,    KC_HASH,    KC_DOLLAR,  KC_PERCENT, KC_TRNS,
        KC_TRNS,    KC_LPRN,    KC_RPRN,  KC_LCBR,    KC_RCBR,    KC_GRAVE,
        KC_TRNS,    KC_LBRC,    KC_RBRC,  KC_LT,      KC_GT,      KC_TILDE,   KC_TRNS,
        EPRM,       KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,

                                                                              KC_TRNS,    KC_TRNS,
                                                                                          KC_TRNS,
                                                                  KC_TRNS,    KC_TRNS,    KC_NO,


        // right hand
                    KC_F12,     KC_F6,    KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_TRNS,
                    KC_TRNS,    KC_CIRC,  KC_AMPR,    KC_ASTR,    LSFT(KC_P), KC_TRNS,    KC_TRNS,
                                KC_PIPE,  KC_MINUS,   KC_DQUO,    KC_EQUAL,   KC_P,       KC_TRNS,
                    KC_TRNS,    KC_BSLASH,KC_UNDS,    KC_QUOTE,   KC_PLUS,    KC_QUES,    KC_TRNS,
                                          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    TO(BASE),

        KC_TRNS,    KC_TRNS,
        KC_TRNS,
        KC_NO,      KC_TRNS,    KC_TRNS
),


/* Keymap 2: Number/Navigation
 *
 * ,---------------------------------------------------.       ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |       | RGB  |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|       |------+------+------+------+------+------+--------|
 * |         | PREV | STOP | PLAY | NEXT | VOL+ |      |       |BRIGHT|      |   7  |   8  |   9  |      |        |
 * |---------+------+------+------+------+------|      |       |   +  |------+------+------+------+------+--------|
 * |         | LEFT |  UP  | DOWN | RIGHT| VOL- |------|       |------|      |   4  |   5  |   6  |   0  |        |
 * |---------+------+------+------+------+------| MUTE |       |BRIGHT|------+------+------+------+------+--------|
 * |         | HOME | PGUP | PGDN | END  | MUTE | MIC  |       |   -  |      |   1  |   2  |   3  |      |  HOLD  |
 * `---------+------+------+------+------+-------------'       `-------------+------+------+------+------+--------'
 * |         |      |      |      |      |                                   |      |      |      |      |        |
 * `-------------------------------------'                                   `------------------------------------'
 *                                       ,-------------.       ,-------------.
 *                                       |      |      |       |      |      |
 *                                ,------|------|------|       |------+------+------.
 *                                |      |      |      |       |      |      |      |
 *                                |      |      |------|       |------|      |      |
 *                                |      |      | HOLD |       | NOOP |      |      |
 *                                `--------------------'       `--------------------'
 */
[NUM] = LAYOUT_ergodox(
        // left hand
        KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_MPRV,    KC_STOP,  KC_MPLY,    KC_MNXT,    KC_VOLU,    KC_TRNS,
        KC_TRNS,    KC_LEFT,    KC_UP,    KC_DOWN,    KC_RIGHT,   KC_VOLD,
        KC_TRNS,    KC_HOME,    KC_PGUP,  KC_PGDOWN,  KC_END,     KC_MUTE,    HYPR(KC_M),
        KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,

                                                                              KC_TRNS,    KC_TRNS,
                                                                                          KC_TRNS,
                                                                  KC_TRNS,    KC_TRNS,    KC_TRNS,


        // right hand
                    RGB_TOG,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                    RGB_VAI,    KC_TRNS,  KC_7,     KC_8,       KC_9,       KC_TRNS,    KC_TRNS,
                                KC_TRNS,  KC_4,     KC_5,       KC_6,       KC_0,       KC_TRNS,
                    RGB_VAD,    KC_TRNS,  KC_1,     KC_2,       KC_3,       KC_TRNS,    KC_TRNS,
                                          KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    TO(BASE),

        KC_TRNS,    KC_TRNS,
        KC_TRNS,
        KC_NO,      KC_TRNS,    KC_TRNS
),


/* Keymap 3: Colemak
 *
 * ,---------------------------------------------------.       ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |       |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|       |------+------+------+------+------+------+--------|
 * |         |   Q  |   W  |   F  |   P  |   G  |      |       |      |   J  |   L  |   U  |   Y  |  Esc |        |
 * |---------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * |         |   A  |   R  |   S  |   T  |   D  |------|       |------|   H  |   N  |   E  |   I  |   O  |        |
 * |---------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * |         |   Z  |   X  |   C  |   V  |   B  |      |       |      |   K  |   M  |   ,  |   .  |   /  |        |
 * `---------+------+------+------+------+-------------'       `-------------+------+------+------+------+--------'
 * |         |      |      |      |      |                                   |      |      |      |      |        |
 * `-------------------------------------'                                   `------------------------------------'
 *                                       ,-------------.       ,-------------.
 *                                       |      |      |       |      |      |
 *                                ,------|------|------|       |------+------+------.
 *                                |      |      |      |       |      |      |  Col |
 *                                |      |      |------|       |------|      |  Dev |
 *                                |      |      | NOOP |       |      |      |      |
 *                                `--------------------'       `--------------------'
 */
[COL] = LAYOUT_ergodox(
        // left hand
        KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_Q,       KC_W,     KC_F,       KC_P,       KC_G,       KC_TRNS,
        KC_TRNS,    KC_A,       KC_R,     KC_S,       KC_T,       KC_D,
        KC_TRNS,    KC_Z,       KC_X,     KC_C,       KC_V,       KC_B,       KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,

                                                                              KC_TRNS,    KC_TRNS,
                                                                                          KC_TRNS,
                                                                  KC_TRNS,    KC_TRNS,    KC_NO,


        // right hand
                    TO(BASE),   KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                    KC_TRNS,    KC_J,     KC_L,       KC_U,       KC_Y,       KC_ESC,     KC_TRNS,
                                KC_H,     KC_N,       KC_E,       KC_I,       KC_O,       KC_TRNS,
                    KC_TRNS,    KC_K,     KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_TRNS,
                                          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    TO(BASE),

        KC_TRNS,    KC_TRNS,
        KC_TRNS,
        KC_TRNS,    KC_TRNS,    MO(COLDEV)
),


/* Keymap 4: Colemak DevLayer
 * This layer is identical to DevLayer, except `;` and `:` are represented natively
 * instead of being `p` and `P` respectively.
 *
 * ,---------------------------------------------------.       ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |       |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|       |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   #  |   $  |   %  |      |       |      |   ^  |   &  |   *  |   :  |      |        |
 * |---------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * |         |   (  |   )  |   {  |   }  |   `  |------|       |------|   |  |   -  |   "  |   =  |   ;  |        |
 * |---------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * |         |   [  |   ]  |   <  |   >  |   ~  |      |       |      |   \  |   _  |   '  |   +  |   ?  |  NOOP  |
 * `---------+------+------+------+------+-------------'       `-------------+------+------+------+------+--------'
 * |  EPRM   |      |      |      |      |                                   |      |      |      |      |        |
 * `-------------------------------------'                                   `------------------------------------'
 *                                       ,-------------.       ,-------------.
 *                                       |      |      |       |      |      |
 *                                ,------|------|------|       |------+------+------.
 *                                |      |      |      |       |      |      |      |
 *                                |      |      |------|       |------|      | HOLD |
 *                                |      |      | NOOP |       | NOOP |      |      |
 *                                `--------------------'       `--------------------'
 */
[COLDEV] = LAYOUT_ergodox(
        // left hand
        KC_TRNS,    KC_F1,      KC_F2,    KC_F3,      KC_F4,      KC_F5,      KC_F11,
        KC_TRNS,    KC_EXCLAIM, KC_AT,    KC_HASH,    KC_DOLLAR,  KC_PERCENT, KC_TRNS,
        KC_TRNS,    KC_LPRN,    KC_RPRN,  KC_LCBR,    KC_RCBR,    KC_GRAVE,
        KC_TRNS,    KC_LBRC,    KC_RBRC,  KC_LT,      KC_GT,      KC_TILDE,   KC_TRNS,
        EPRM,       KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,

                                                                              KC_TRNS,    KC_TRNS,
                                                                                          KC_TRNS,
                                                                  KC_TRNS,    KC_TRNS,    KC_NO,


        // right hand
                    KC_F12,     KC_F6,    KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_TRNS,
                    KC_TRNS,    KC_CIRC,  KC_AMPR,    KC_ASTR,    KC_COLON,   KC_TRNS,    KC_TRNS,
                                KC_PIPE,  KC_MINUS,   KC_DQUO,    KC_EQUAL,   KC_SCOLON,  KC_TRNS,
                    KC_TRNS,    KC_BSLASH,KC_UNDS,    KC_QUOTE,   KC_PLUS,    KC_QUES,    KC_TRNS,
                                          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    TO(BASE),

        KC_TRNS,    KC_TRNS,
        KC_TRNS,
        KC_NO,      KC_TRNS,    KC_TRNS
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
