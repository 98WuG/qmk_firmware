#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _GAMING 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _VIM 5
#define _ADJUST 16

// RGB
const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {10, 5, 3, 1};
const uint8_t RGBLED_RAINBOW_MOOD_INTERVALS[] PROGMEM = {15, 3, 1};
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {1, 1, 1};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
  //DMONEY,
  WORK,
  PORTAL,
  ISABLO,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  Alt |Adjust|Raise |Space |Space |Lower | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, \
  CTL_T(KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(_VIM,KC_SCLN), CTL_T(KC_ENT), \
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC , \
  LT(KC_LCTRL,KC_LBRC), KC_LCBR, KC_LALT, KC_LGUI,  RAISE,   LT(_VIM,KC_SPC),   KC_SPC,  LOWER,   KC_LEFT, KC_DOWN, KC_RCBR,   LT(KC_RCTRL,KC_RBRC) \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_RGHT, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_ENT,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_ENT, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    LT(_VIM,KC_G),    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_SPC,  KC_SPC,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  _______, KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE, KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, PORTAL, \
  _______, _______, _______, _______, _______, KC_DEL,  RGB_TOG, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  _______, KC_MINUS,KC_EQUAL,KC_GRAVE,KC_BSLS, KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______,   WORK,     ISABLO, _______, _______, RGB_TOG, KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   AG_NORM, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  GAMING, DVORAK,  _______, _______, \
  RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, _______, _______, _______, _______, \
  RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, _______, RGB_TOG, RGB_TOG, _______, RGB_SAI, RGB_VAD, RGB_VAI, _______ \
),

[_VIM] =  LAYOUT_ortho_4x12( \
  _______, KC_BTN2, KC_MS_U, KC_BTN1, _______, QWERTY, _______, _______, _______, _______, _______, _______, \
  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_WH_U, KC_LEFT,  KC_DOWN, KC_UP,  KC_RGHT, _______, _______, \
  _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, KC_WH_D, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_GAMING);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
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
	case PORTAL:
	  if (record->event.pressed) {
		  rgblight_enable();
		  rgblight_mode(25);
		  int i;
		  for(i = 0; i < 4; i = i + 1) {
			  rgblight_setrgb_at(0,60,150,i);
		  }
		  for(i = 4; i < 8; i = i + 1) {
			  rgblight_setrgb_at(255,60,0,i);
		  }
	  }
	  return false;
	  break;
//	case DMONEY:
//	  if (record->event.pressed) {
//		  SEND_STRING("Finally a text book that starts with 2-State Systems! I have been teaching quantum mechanics off and on for 25 years to gifted high school students. I have experience using many other quantum texts. In John Townsend's latest edition, we finally have an excellent modern textbook that makes the mathematical and physical learning curve as gentle as possible WITHOUT CUTTING CORNERS ON THE PHYSICS. Prof. Townsend's treatment (developed over a sequence of refinements in his approach in previous texts = battle tested) enables students to engage the fundamentals of quantum mechanics and many of its emerging applications that rely on understanding few-state and composite systems. The approach is preferable to more traditional approaches because it climbs the mathematical hill starting from the gentlest point, avoiding mathematical issues and levels of abstraction that arise from infinite dimensionality in quantum systems until after basic physical principles have been introduced. The early use of Dirac notation and the clear separation of state space and matrix representations add considerable clarity for the beginning student. Townsend's approach moves students as quickly as possible to the point that they can honestly engage the fundamentals of forefront applications in quantum information , quantum computing, quantum teleportation, and other fundamental developing applications. Unlike some older texts, Townsend engages the 'spookiest' parts of quantum mechanics ( EPR, BELL Inequalities, GHZ states...) early. For this alone, he deserves extra credit! It is terribly important that physics students develop an understanding and intuition for quantum mechanics as early in life as possible and they can only do this by engaging the conceptually challenging aspects head-on but in the technically simplest context. Prof Townsend has found the sweet spot. This is THE best existing gateway text I have seen for serious physics students.");
//	  }
//	  return false;
//	  break;
	case WORK:
	  if (record->event.pressed) {
		  SEND_STRING("\\( \\int_{k<\\Lambda} [Dg][DA][D\\psi ][D\\Phi ] \\exp\\left\\{i \\int d^4x \\sqrt{-g} \\left[ \\frac{m_p^2}{2}R-\\frac{1}{4} F_{\\mu \\nu}^a F^{a \\mu \\nu} + i\\bar{\\psi}^i \\gamma^{\\mu} D_{\\mu} \\psi^i + \\left( \\bar{\\psi}^i_L V_{ij} \\Phi \\psi_R^j + \\text{h.c.} \\right) - \\left| D_{\\mu} \\Phi \\right|^2 - V(\\Phi) + D_{\\mu} A^{\\mu} N(\\widetilde{K}) - A_{\\mu} F^{\\mu} \\right] \\right\\} \\)");
	  }
	  return false;
	  break;
	case ISABLO:
	  if (record->event.pressed) {
		  int i;
		  for(i = 0; i < 1000; i = i + 1) {
			  SEND_STRING("isablo");
			  SEND_STRING(SS_TAP(X_ENTER));
			  _delay_ms(500);
		  }
	  }
	  return false;
	  break;
  }
  return true;
}
