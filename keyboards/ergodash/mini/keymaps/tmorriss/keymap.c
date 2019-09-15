#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwertyls
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |   '  |                    | Bksp |   Y  |   U  |   I  |   O  |   P  |   -  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  Ctrl|   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |   /  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   $  |                    | Space|   N  |   M  |   ,  |   .  |  Up  |   ~  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |  Esc |   _  |  Alt | GUI  ||||||||  Eisu| Lower| Space|||||||| Enter| Raise|  Kana|||||||| Shift| Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_QUOTE,                        KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
    KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_SLSH , \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_DLR,                        KC_SPC, KC_N,    KC_M,    KC_COMM, KC_DOT,     KC_UP, KC_TILD, \
    KC_ESC, KC_UNDS, KC_LALT,KC_LGUI,          KC_HANJ,   LOWER , KC_SPC,        KC_ENT ,RAISE, KC_HAEN,            KC_RSFT, KC_LEFT, KC_DOWN,   KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Tab |   !  |   "  |   #  |   $  |   %  |   `  |                    |Delete|   ^  |   &  |   (  |   )  |  Up  |   |  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  Ctrl|   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  | Left | Down |  Up  | Right|   *  |   +  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  |   $  |                    | Space| Down |      |   <  |   >  |  Up  |   `  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |  Esc |   _  |  Alt |  GUI ||||||||  Eisu| Lower| Space|||||||| Enter| Raise|  Kana|||||||| Shift| Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT( 
    KC_TAB , KC_EXLM, KC_DQT, KC_HASH,  KC_DLR,  KC_PERC, KC_GRV,                        KC_DEL, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_UP,  KC_PIPE, \
    KC_LCTL , KC_1,     KC_2,    KC_3,    KC_4,     KC_5, KC_LBRC,                        KC_RBRC, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_ASTR, KC_PLUS, \
    KC_LSFT,  KC_6,     KC_7,    KC_8,    KC_9,     KC_0,  KC_DLR,                         KC_SPC, KC_DOWN, _______,    KC_LT,   KC_GT,     KC_UP, KC_GRV, \
    KC_ESC, KC_UNDS, KC_LALT, KC_LGUI,           KC_HANJ,   LOWER, KC_SPC,        KC_ENT,RAISE , KC_HAEN,            KC_RSFT,  KC_LEFT, KC_DOWN,   KC_RGHT  \
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * |  Tab |   !  |   "  |   #  |   $  |   %  |   `  |                    | Bksp |   7  |   8  |   9  |   0  |   @  |   \  |
  * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
  * |  Ctrl|   F1 |   F2 |   F3 |   F4 |   F5 |   [  |                    |   ]  |   4  |   5  |   6  |   +  |   *  |   =  |
  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
  * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 |   $  |                    | Space|   1  |   2  |   3  |   .  |  Up  |   `  |
  * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
  * |  Esc |  F11 |  F12 |  GUI ||||||||  Eisu| Lower| Space|||||||| Enter| Raise|   0  |||||||| Shift| Left | Down | Right|
  * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    KC_TAB , KC_EXLM,KC_DQT,   KC_HASH, KC_DLR,  KC_PERC, KC_GRV,                       KC_BSPC,   KC_7,    KC_8,    KC_9,     KC_0, KC_AT,  KC_BSLS, \
    KC_LCTL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LBRC,                      KC_RBRC,   KC_4,    KC_5,    KC_6, KC_PLUS, KC_ASTR, KC_EQL , \
    KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_DLR,                       KC_SPC,   KC_1,    KC_2,    KC_3,  KC_DOT,   KC_UP, KC_GRV, \
    KC_ESC , KC_F11 , KC_F12,  KC_LGUI,          KC_HANJ,  LOWER , KC_SPC,        KC_ENT,RAISE ,   KC_0,            KC_RSFT,  KC_LEFT, KC_DOWN,   KC_RGHT  \
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |BriDow| BriUp|      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |VolDow| VolUp|      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, KC_BRID, KC_BRIU, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, KC__VOLDOWN, KC__VOLUP, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
