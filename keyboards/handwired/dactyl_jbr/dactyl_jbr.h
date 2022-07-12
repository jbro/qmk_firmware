#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
L05, L04, L03, L02, L01, L00,                       R00, R01, R02, R03, R04, R05, \
L15, L14, L13, L12, L11, L10,                       R10, R11, R12, R13, R14, R15, \
L25, L24, L23, L22, L21, L20,                       R20, R21, R22, R23, R24, R25, \
          L33, L32,                                           R32, R33, \
                    L31, L30,                       R30, R31, \
                              L44, L42,    R42, R44, \
                              L45, L43,    R43, R45 \
) { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, XXX, XXX }, \
    { XXX, XXX, L42, L43, L44, L45 }, \
\
    { R00, R01, R02, R03, R04, R05 }, \
    { R10, R11, R12, R13, R14, R15 }, \
    { R20, R21, R22, R23, R24, R25 }, \
    { R30, R31, R32, R33, XXX, XXX }, \
    { XXX, XXX, R42, R43, R44, R45 } \
}
