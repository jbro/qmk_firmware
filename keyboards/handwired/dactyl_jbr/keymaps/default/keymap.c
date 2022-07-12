#include QMK_KEYBOARD_H

#define KC_M_D LT(L_UR, KC_D)
#define KC_M_K LT(L_UR, KC_K)
#define KC_M_F LT(L_UL, KC_F)
#define KC_M_J LT(L_UL, KC_J)

#define CK_Z    LCTL_T(KC_Z)
#define CK_X    LALT_T(KC_X)
#define CK_C    LGUI_T(KC_C)
#define CK_V    LSFT_T(KC_V)
#define CK_M    RSFT_T(KC_M)
#define CK_COMM RGUI_T(KC_COMM)
#define CK_DOT  RALT_T(KC_DOT)
#define CK_SLSH RCTL_T(KC_SLSH)

#define CK_PIPE LCTL_T(KC_PIPE)
#define CK_BSLS LALT_T(KC_BSLS)
#define CK_GRV  LGUI_T(KC_GRV)
#define CK_EQL  RSFT_T(KC_EQL)
#define CK_PLUS RGUI_T(KC_PLUS)
#define CK_LCBR RALT_T(KC_LCBR)
#define CK_RCBR RCTL_T(KC_RCBR)

//XXX make shift and numlock keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [L_BA] = LAYOUT(
            KC_NO  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_NO  ,
            KC_NO  , KC_A   , KC_S   , KC_M_D , KC_M_F , KC_G   ,                       KC_H   , KC_M_J , KC_M_K , KC_L   , KC_SCLN, KC_UP  ,
           TO(L_UL), CK_Z   , CK_X   , CK_C   , CK_V   , KC_B   ,                       KC_N   , CK_M   , CK_COMM, CK_DOT , CK_SLSH, KC_DOWN,
                              KC_PGUP, KC_PGDN,                                                           KC_LEFT, KC_RGHT,
                                                KC_ESC , KC_TAB ,                       KC_SPC , KC_ENT ,
                                                             KC_NO, KC_NO,    KC_NO, KC_NO,
                                                             KC_NO, KC_NO,    KC_NO, KC_NO
    ),
    [L_UL] = LAYOUT(
            KC_NO  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MPLY,
            KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                       KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
           TO(L_UR), KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO  ,                       KC_NO  , KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, KC_NO  ,
                              KC_HOME, KC_END ,                                                           KC_MPRV, KC_MNXT,
                                                KC_NO  , KC_APP ,                       KC_BSPC, KC_NO  ,
                                                             KC_NO, KC_NO,    KC_NO, KC_NO,
                                                             KC_NO, KC_NO,    KC_NO, KC_NO
    ),
    [L_UR] = LAYOUT(
            QK_BOOT, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MUTE,
            KC_NO  , KC_TILD, KC_DQUO, KC_QUOT, KC_NO  , KC_NO  ,                       KC_NO  , KC_UNDS, KC_MINS, KC_LBRC, KC_RBRC, KC_VOLU,
           TO(L_BA), CK_PIPE, CK_BSLS, CK_GRV , KC_LSFT, KC_NO  ,                       KC_NO  , CK_EQL , CK_PLUS, CK_LCBR, CK_RCBR, KC_VOLD,
                              KC_NO  , KC_NO  ,                                                           KC_NO  , KC_NO  ,
                                                KC_NO  , KC_NO  ,                       KC_DEL , KC_NO  ,
                                                             KC_NO, KC_NO,    KC_NO, KC_NO,
                                                             KC_NO, KC_NO,    KC_NO, KC_NO
    )
};
