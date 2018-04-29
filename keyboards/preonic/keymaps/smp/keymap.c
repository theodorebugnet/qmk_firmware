#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _WORKMAN 1
#define _CALC 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  WORKMAN,
  LOWER,
  RAISE
};

enum tap_dances {
    _CP_CL, //Caps + _Calc
    _LAltGr //Double tap Alt for AltGr
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [_CP_CL] = ACTION_TAP_DANCE_DUAL_ROLE(KC_CAPS, _CALC),
    [_LAltGr] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT)
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom macros
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define SFT_ESC     SFT_T(KC_ESC)               // Tap for Esc, hold for Shift
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift
#define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
#define MEH_GRV     MEH_T(KC_GRV)               // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)
#define HYP_GRV     ALL_T(KC_GRV)               // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | meme |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bcksp|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SftEsc|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |EtrEsc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Hyp` | Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_mit( \
  TD(_CP_CL), KC_1,    KC_2,    KC_3,        KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,     KC_Q,    KC_W,    KC_E,        KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_BSPC,    KC_A,    KC_S,    KC_D,        KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  SFT_ESC,    KC_Z,    KC_X,    KC_C,        KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
  HYP_GRV,    KC_LCTL, KC_LGUI, TD(_LAltGr), LOWER,       KC_SPC,       RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Workman
 * ,-----------------------------------------------------------------------------------.
 * | meme |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bcksp|   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |   "  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SftEsc|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |EtrEsc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Hyp` | Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_WORKMAN] = LAYOUT_preonic_mit( \
  TD(_CP_CL), KC_1,    KC_2,    KC_3,        KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,     KC_Q,    KC_D,    KC_R,        KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_DEL,
  KC_BSPC,    KC_A,    KC_S,    KC_H,        KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT,
  SFT_ESC,    KC_Z,    KC_X,    KC_M,        KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
  HYP_GRV,    KC_LCTL, KC_LGUI, TD(_LAltGr), LOWER,       KC_SPC,       RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Calc
 * ,-----------------------------------------------------------------------------------.
 * |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  | Bksp |  NUM |   /  |   *  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  NO  |  Up  |  NO  |  NO  |  NO  |  NO  | Del  |   7  |   8  |   9  |   +  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Left | Down | Right|  NO  |  NO  |  NO  |   =  |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |   ,  |   1  |   2  |   3  |  Etr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Exit |    Space    |  NO  |   0  |   0  |   .  |  Etr |
 * `-----------------------------------------------------------------------------------'
 */
[_CALC] = LAYOUT_preonic_mit( \
  KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_BSPC,  KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
  _______, KC_NO,    KC_UP,    KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_DEL,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
  _______, KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_NO,     KC_NO,    KC_NO,    KC_PEQL,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
  _______, KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_PCMM,  KC_P1,   KC_P2,   KC_P3,   KC_PENT,
  _______, _______,  _______,  _______,  TG(_CALC),      KC_SPC,        KC_NO,    KC_P0,   KC_P0,   KC_PDOT, KC_PENT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |   5  |   6  |WinMnu| Wake |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  | Calc | Sleep|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Mute     |      | Next | Vol+ | Vol- | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_mit( \
  KC_F1,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5,    KC_6,    KC_CALC, KC_WAKE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,    KC_3,    KC_APP,  KC_SLEP,
  _______, _______, _______, _______, _______,     KC_MUTE,      _______, KC_MNXT, KC_VOLU, KC_VOLD, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F13 |  F14 |  F15 |  F16 | ISO# |   _  |   ?  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F17 |  F18 |  F19 |  F20 | ISO\ |   -  |   /  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home |PageDn|PageUp| End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_mit( \
  KC_F1,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_NUHS, KC_UNDS, KC_QUES, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_NUBS, KC_MINS, KC_SLSH, KC_EQL,  KC_LBRC, KC_RBRC, SFT_T(KC_BSLS),
  _______, _______, _______, _______, _______,     _______,      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |SclCyc|Aud on|AudOff|AGnorm|AGswap|Workmn|Qwerty|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_mit( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, WORKMAN, QWERTY,  _______, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
)


};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_qwerty[][2]     = SONG(COLEMAK_SOUND);
float tone_workman[][2]    = SONG(DVORAK_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);

float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
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
        case WORKMAN:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_workman);
            #endif
            persistent_default_layer_set(1UL<<_WORKMAN);
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
      }
    return true;
};

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_SONG(tone_startup);
}

void shutdown_user()
{
    PLAY_SONG(tone_goodbye);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif
