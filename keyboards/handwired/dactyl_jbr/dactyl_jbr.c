#include "dactyl_jbr.h"

void keyboard_pre_init_user(void) {
    setPinOutput(B4);
    setPinOutput(B5);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case L_UL:
            writePinHigh(B4);
            writePinLow(B5);
            break;
        case L_UR:
            writePinLow(B4);
            writePinHigh(B5);
            break;
        default:
            writePinLow(B4);
            writePinLow(B5);
            break;
    }

    return state;
}