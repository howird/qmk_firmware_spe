#include "centromere.h"
#include QMK_KEYBOARD_H

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

// Port of ~/nix/config/configs/keyboards/kanata/framework.kbd, with every key
// moved one column outward (Q/A/Z in the outer column, inner columns empty)
// and Esc on the right inner bottom key. Thumb keys are likewise moved one
// outward, and VOX sits on the left inner bottom key (B's original spot). Source JSON: framework.json.
enum layers {
    _BASE,
    _NUM,  // kanata: numarrows
    _SYM,  // kanata: symbols
    _FN    // kanata: functions
};

enum custom_keycodes {
    VOX = SAFE_RANGE  // voxtype dictation, see process_record_user
};

// home row mods
#define HM_A    LT(_SYM, KC_A)
#define HM_S    LALT_T(KC_S)
#define HM_D    LGUI_T(KC_D)
#define HM_F    LCTL_T(KC_F)
#define HM_J    RCTL_T(KC_J)
#define HM_K    RGUI_T(KC_K)
#define HM_L    RALT_T(KC_L)
#define HM_SCLN LT(_SYM, KC_SCLN)
#define FN_X    LT(_FN, KC_X)
#define FN_DOT  LT(_FN, KC_DOT)
#define SFT_TAB LSFT_T(KC_TAB)
#define NUM_ENT LT(_NUM, KC_ENT)
#define ZOOM_I  LCTL(KC_PLUS)
#define ZOOM_O  LCTL(KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,      XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        HM_A,    HM_S,    HM_D,    HM_F,    KC_G,    XXXXXXX,      XXXXXXX, KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN,
        KC_Z,    FN_X,    KC_C,    KC_V,    KC_B,    VOX,          KC_ESC,  KC_N,    KC_M,    KC_COMM, FN_DOT,  KC_SLSH,
                                   SFT_TAB, KC_BSPC, XXXXXXX,      XXXXXXX, KC_SPC,  NUM_ENT
    ),
    [_NUM] = LAYOUT_split_3x6_3(
        KC_ASTR, KC_7,    KC_8,    KC_9,    KC_PLUS, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SLSH, LALT_T(KC_4), LGUI_T(KC_5), LCTL_T(KC_6), KC_MINS, XXXXXXX,      XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        KC_0,    KC_1,    KC_2,    KC_3,    KC_EQL,  XXXXXXX,      XXXXXXX, XXXXXXX, ZOOM_O,  ZOOM_I,  XXXXXXX, XXXXXXX,
                                   SFT_TAB, KC_DEL,  XXXXXXX,      XXXXXXX, KC_UNDS, _______
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_TILD, KC_AT,   KC_DLR,  KC_GRV,  XXXXXXX,      XXXXXXX, XXXXXXX, KC_ASTR, KC_CIRC, KC_PIPE, XXXXXXX,
        XXXXXXX, KC_EXLM, KC_LCBR, KC_RCBR, KC_QUOT, XXXXXXX,      XXXXXXX, KC_DQUO, KC_LPRN, KC_RPRN, KC_AMPR, KC_BSLS,
        XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_HASH, XXXXXXX,      XXXXXXX, KC_PERC, KC_LT,   KC_GT,   KC_QUES, XXXXXXX,
                                   LSFT(KC_TAB), KC_DEL, XXXXXXX,  XXXXXXX, KC_UNDS, XXXXXXX
    ),
    // F4-F6 tap / Alt-GUI-Ctrl hold, like 4-6 on _NUM. F10-F12 replace the
    // laptop's F-row; brightness keys don't exist in this QMK version.
    [_FN] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX,
        XXXXXXX, LALT_T(KC_F4), LGUI_T(KC_F5), LCTL_T(KC_F6), KC_F11, XXXXXXX,      XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_MPLY, XXXXXXX
    )
};

// VOX mirrors kanata's @vox. niri binds Super+Ctrl+D to `voxtype record start`
// and Super+Ctrl+Shift+D to `voxtype record stop`.
//   - Every press sends start (a no-op if already recording).
//   - Releasing the first tap queues a stop VOX_TERM ms later; any key press
//     cancels it.
//   - A second press within VOX_TERM of the first is a double tap: it cancels
//     the stop and its release queues nothing, so recording keeps going.
// So: hold to talk, or double tap to start and single tap to stop.
#define VOX_TERM 250

static uint16_t vox_press_timer;
static uint16_t vox_stop_timer;
static bool     vox_dance_open;   // first tap happened, waiting for a second
static bool     vox_double;       // current press is the second tap
static bool     vox_stop_pending;

static void vox_send(bool stop) {
    register_code(KC_LCTL);
    register_code(KC_LGUI);
    if (stop) register_code(KC_LSFT);
    register_code(KC_D);
    unregister_code(KC_D);
    if (stop) unregister_code(KC_LSFT);
    unregister_code(KC_LGUI);
    unregister_code(KC_LCTL);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        vox_stop_pending = false;  // any key press cancels a queued stop
    }

    switch (keycode) {
        case VOX:
            if (record->event.pressed) {
                vox_double = vox_dance_open && timer_elapsed(vox_press_timer) < VOX_TERM;
                vox_dance_open = !vox_double;
                vox_press_timer = timer_read();
                vox_send(false);
            } else if (!vox_double) {
                vox_stop_pending = true;
                vox_stop_timer = timer_read();
            }
            return false;
    }
    return true;
}

void matrix_scan_user(void) {
    if (vox_stop_pending && timer_elapsed(vox_stop_timer) >= VOX_TERM) {
        vox_stop_pending = false;
        vox_send(true);
    }
}
