#pragma once

#include "quantum.h"

#define LAYOUT( \
	K000, K001, K002, K003, K004, K005, K006, K007, \
	K010, K011, K012, K013, K014, K015, K016, K017, \
	      K021, K022, K023, K024,                   \
	K030, K031,       K033, K034, K035, K036, K037, \
	      K041,       K043,             K046,       \
	K050, K051,       K053, K054, K055, K056,       \
          K061,       K063,             K066,       \
	K070, 			  K073,				K076,		\
		  K081,					  K085,				\
	K090, K091, K092, K093, K094, K095,		  K097,	\
	K100, K101, K102, K103, K104,       K106, K107,	\
		  K111, K112, K113, K114, K115, 	  K117,	\
	K120, K121, K122, K123, K124, K125, K126, K127,	\
		  K131, K132, K133, K134, K135,       K137,	\
	K140, K141, K142, K143, K144, K145,  	  K147,	\
	K150, K151, K152, K153, K154, K155, K156, K157,	\
	K160, K161, K162, K163, K164, K165,       K167,	\
								  K175,       K177,	\
	K180     										\
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007, KC_NO  }, \
	{ K010,  K011,  K012,  K013,  K014,  K015,  K016,  K017, KC_NO  }, \
	{ KC_NO, K021,  K022,  K023,  K024,  KC_NO, KC_NO, KC_NO, KC_NO }, \
	{ K030,  K031,  KC_NO, K033,  K034,  K035,  K036,  K037, KC_NO  }, \
	{ KC_NO, K041,  KC_NO, K043,  KC_NO, KC_NO, K046,  KC_NO, KC_NO }, \
	{ K050,  K051,  KC_NO, K053,  K054,  K055,  K056,  KC_NO, KC_NO }, \
	{ KC_NO, K061,  KC_NO, K063,  KC_NO, KC_NO, K066,  KC_NO, KC_NO }, \
	{ K070,  KC_NO, KC_NO, K073,  KC_NO, KC_NO, K076,  KC_NO, KC_NO }, \
	{ KC_NO, K081,  KC_NO, KC_NO, KC_NO, K085,  KC_NO, KC_NO, KC_NO }, \
	{ K090,  K091,  K092,  K093,  K094,  K095,  KC_NO, K097, KC_NO  }, \
	{ K100,  K101,  K102,  K103,  K104,  KC_NO, K106,  K107, KC_NO  }, \
	{ KC_NO, K111,  K112,  K113,  K114,  K115,  KC_NO, K117, KC_NO  }, \
	{ K120,  K121,  K122,  K123,  K124,  K125,  K126,  K127, KC_NO  }, \
	{ KC_NO, K131,  K132,  K133,  K134,  K135,  KC_NO, K137, KC_NO  }, \
	{ K140,  K141,  K142,  K143,  K144,  K145,  KC_NO, K147, KC_NO  }, \
	{ K150,  K151,  K152,  K153,  K154,  K155,  K156,  K157, KC_NO  }, \
	{ K160,  K161,  K162,  K163,  K164,  K165,  KC_NO, K167, KC_NO  }, \
	{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K175,  KC_NO, K177, KC_NO  }, \
	{ K180,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO  }	\
}
