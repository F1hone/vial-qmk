#pragma once

#include "quantum.h"

#define LAYOUT( \
     K00, K01, K02, K03, K04,    \
     K10, K11, K12, K13,	     \
     K20, K21, K22, K23,	     \
     K30, K31, K32, K33,	     \
     K40, K41, K42, K43,	     \
     K50, K51, K52, K53	         \
){ \
    {K00, K01, K02, K03, K04,  }, \
    {K10, K11, K12, K13, KC_NO }, \
    {K20, K21, K22, K23, KC_NO }, \
    {K30, K31, K32, K33, KC_NO }, \
    {K40, K41, K42, K43, KC_NO }, \
	{K50, K51, K52, K53, KC_NO }  \
}
