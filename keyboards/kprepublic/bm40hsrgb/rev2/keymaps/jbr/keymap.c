#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _LOWER,
  _UPPER,
  _CONF
};

#define LOWER OSL(_LOWER)
#define UPPER OSL(_UPPER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_ortho_4x12_1x2uC(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT ,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_APP,  KC_LCTL, KC_LGUI, KC_LALT, LOWER,       KC_SPC,       UPPER,   KC_RALT, KC_RGUI, KC_RCTL, KC_APP
),

[_LOWER] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_GRV,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP ,  KC_RGHT, KC_QUOT, _______,
    _______, KC_BSLS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

[_UPPER] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),
[_CONF] = LAYOUT_ortho_4x12_1x2uC(
    QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EE_CLR,
    QK_RBT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _UPPER, _CONF);
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  switch(get_highest_layer(layer_state|default_layer_state)) {
    case _UPPER:
      rgb_matrix_set_color(42, RGB_GREEN);
      break;
    case _LOWER:
      rgb_matrix_set_color(40, RGB_GREEN);
      break;
    case _CONF:
      for(uint8_t i = led_min; i <= led_max; i++) {
        rgb_matrix_set_color(i, RGB_RED);
      }
      break;
    default:
      break;
  }
}

void keyboard_post_init_user(void) {
  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Store the current modifier state in the variable for later reference
  mod_state = get_mods();
  switch (keycode) {
    case KC_BSPC: {
      // Initialize a boolean variable that keeps track
      // of the delete key status: registered or not?
      static bool delkey_registered;
        if (record->event.pressed) {
          // Detect the activation of either shift keys
          if (mod_state & MOD_MASK_SHIFT) {
            // First temporarily canceling both shifts so that
            // shift isn't applied to the KC_DEL keycode
            del_mods(MOD_MASK_SHIFT);
            register_code(KC_DEL);
            // Update the boolean variable to reflect the status of KC_DEL
            delkey_registered = true;
            // Reapplying modifier state so that the held shift key(s)
            // still work even after having tapped the Backspace/Delete key.
            set_mods(mod_state);
            return false;
          }
        } else { // on release of KC_BSPC
          // In case KC_DEL is still being sent even after the release of KC_BSPC
          if (delkey_registered) {
            unregister_code(KC_DEL);
            delkey_registered = false;
            return false;
          }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
      }
  }
  return true;
};