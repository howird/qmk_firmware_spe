#include "centromere.h"
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum telophase_layers
{
	_QWERTY,
	_LOWER,
	_RAISE,
	_ADJUST
};

enum centromere_keycodes
{
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST
};

#define ___ KC_TRNS

#define LAYOUT_split_3x6_3( \
  k0a, k00, k01, k02, k03, k04,      k05, k06, k07, k08, k09, k0b, \
  k1a, k10, k11, k12, k13, k14,      k15, k16, k17, k18, k19, k1b,\
  k2a, k20, k21, k22, k23, k24,      k25, k26, k27, k28, k29, k2b,\
                 k32, k33, k34,      k35, k36, k37  \
) \
  {                                                       \
    { k00, k01, k02, k03, k04, ___, ___, k05, k06, k07, k08, k09 }, \
    { k10, k11, k12, k13, k14, ___, ___, k15, k16, k17, k18, k19 }, \
    { k20, k21, k22, k23, k24, ___, ___, k25, k26, k27, k28, k29 }, \
    { ___, ___, k32, k33, k34, ___, ___, k35, k36, k37, ___, ___ }, \
    { ___, ___, k2a, k1a, k0a, ___, ___, k0b, k1b, k2b, ___, ___ }  \
  }

#define LAYOUT_split_3x5_3( \
  k00, k01, k02, k03, k04,      k05, k06, k07, k08, k09, \
  k10, k11, k12, k13, k14,      k15, k16, k17, k18, k19,\
  k20, k21, k22, k23, k24,      k25, k26, k27, k28, k29,\
            k32, k33, k34,      k35, k36, k37  \
) \
  {                                                       \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09 }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19 }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29 }, \
    { ___, ___, k32, k33, k34, k35, k36, k37, ___, ___ }, \
    { ___, ___, ___, ___, ___, ___, ___, ___, ___, ___ }  \
  }

#define LAYOUT LAYOUT_split_3x6_3

// Fillers to make layering more clear
#define XXXXXXX KC_NO
#define _______ KC_TRNS

enum centromere_layers
{
	_STD,
	_NUM,
	_FN
};

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//         [0] = LAYOUT_split_3x6_3(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LGUI, KC_LCTL, MO(1), KC_SPC, MO(2), KC_RALT),
//         [1] = LAYOUT_split_3x6_3(KC_TILD, KC_ASTR, KC_7, KC_8, KC_9, KC_PLUS, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_DEL, KC_CAPS, KC_SLSH, KC_4, KC_5, KC_6, KC_MINS, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_COLN, KC_BSLS, KC_LSFT, KC_0, KC_1, KC_2, KC_3, KC_EQL, KC_NO, KC_NO, KC_LT, KC_GT, KC_QUES, KC_ENT, KC_LGUI, KC_LCTL, MO(1), KC_UNDS, MO(2), KC_RALT),
//         [2] = LAYOUT_split_3x6_3(KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_VOLU, KC_NO, KC_DEL, KC_NO, KC_NO, SGUI(KC_S), KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_MPLY, KC_NO, KC_PIPE, KC_LSFT, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_NO, KC_NO, KC_LT, KC_GT, KC_VOLD, KC_MUTE, KC_NO, KC_LGUI, KC_LCTL, MO(1), KC_SPC, MO(2), KC_RALT),
//         [3] = LAYOUT_split_3x6_3(KC_ESC, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_PSCR, KC_SLCK, KC_PAUS, KC_NO, KC_DEL, KC_TAB, KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO, KC_NO, KC_HOME, KC_PGUP, KC_NO, KC_NO, KC_LSFT, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, KC_NO, KC_DEL, KC_END, KC_PGDN, KC_NO, KC_ENT, KC_LGUI, KC_LCTL, MO(1), KC_SPC, MO(2), KC_RALT)
// };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO, KC_NO, LT(2,KC_A), LALT_T(KC_S), LGUI_T(KC_D), LCTL_T(KC_F), KC_G, KC_H, RCTL_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), LT(2,KC_SCLN), KC_BSPC, KC_NO, KC_Z, LT(4,KC_X), KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, LT(4,KC_DOT), KC_SLSH, KC_NO, KC_NO, LSFT_T(KC_TAB), KC_BSPC, KC_SPC, KC_SPC, LT(1,KC_ENT)),
    [1] = LAYOUT_split_3x6_3(KC_NO, KC_ASTR, KC_7, KC_8, KC_9, KC_PLUS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SLSH, LALT_T(KC_4), LGUI_T(KC_5), LCTL_T(KC_6), KC_MINS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_DEL, KC_NO, KC_0, KC_1, KC_2, KC_3, KC_EQL, KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_DEL, KC_UNDS, KC_UNDS, MO(1)),
    [2] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_TILD, KC_AT, KC_DLR, KC_GRV, KC_NO, KC_ASTR, KC_CIRC, KC_PIPE, KC_NO, KC_NO, KC_NO, MO(2), KC_EXLM, KC_LCBR, KC_RCBR, KC_QUOT, KC_DQUO, KC_LPRN, KC_RPRN, KC_AMPR, KC_BSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_HASH, KC_PERC, KC_LT, KC_GT, KC_NO, KC_NO, KC_NO, KC_NO, LSFT(KC_TAB), KC_TRNS, KC_UNDS, KC_UNDS, KC_TRNS),
    [3] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_WH_U, KC_NO, KC_NO, KC_WH_U, KC_NO, KC_MS_U, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN2, KC_BTN3, KC_BTN1, KC_NO, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_NO, MO(3), KC_NO, KC_WH_D, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MO(3), KC_NO, KC_NO, KC_ACL1, KC_ACL2, KC_BTN1, KC_BTN2, KC_NO),
    [4] = LAYOUT_split_3x6_3(KC_NO, KC_HOME, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_PGDN, KC_PGUP, KC_NO, KC_NO, KC_NO, KC_NO, KC_END, KC_F4, KC_F5, KC_F6, KC_F11, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO, KC_NO, KC_NO, KC_INS, KC_F1, KC_F2, KC_F3, KC_F12, KC_NO, KC_NO, KC_NO, MO(4), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPLY, KC_NO, KC_NO)
};


uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
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

void matrix_scan_user(void) {
		return;
};
