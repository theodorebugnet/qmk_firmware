/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


//TODO/MISSING: SysRq, PrtSc. Also NumLk, ScrlLk, Pause/Break, Insert.
//Additional features: Numpad
//Additional features: swap SYMB and NUMB
//Additional features: QWERTY mode
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |Hypr/Tab|   Q  |   D  |   R  |   W  |   B  |                         |   J  |   F  |   U  |   P  | ;  : |  Del   |
 * |--------+------+------+------+------+------|------.           ,------|------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   H  |   T  |   G  | back |           |Aplctn|   Y  |   N  |   E  |   O  |   I  |Ctrl/'" |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |Sft/Bspc|   Z  |   X  |   M  |   C  |   V  | frws |           |[BALL]|   K  |   L  | ,  < | .  > | /  ? |Sft/Ent |
 * `--------------------------------------------------'           `--------------------------------------------------'
 *                    ,----------.   ,-------.                             ,-------.   ,----------.
 *                    | Alt/Home |   |Ctr/PgD|                             |Sup/PgU|   | RAlt/End |
 *                    `----------'   `-------'                             `-------'   `----------'
 *                                        ,-------.                   ,-------.
 *                                        | back  |                   | frwd  |
 *                                 ,------|-------|                   |-------|------.
 *                                 | NUMB | SYMB  |                   | NUMB  | SYMB |
 *                                 | Space| Escape|                   | Ent   |Space |
 *                                 |      |       |                   |       |      |
 *                                 `--------------'                   `--------------'
 */
//What to put above space keys (instead of MMB and PgDn)? Leader combos for stuff? Caps lock and Num Lock (i.e. =calc/pad mode)?
//Put back/forward somewhere else? Put what in their place? The leader combos?
[BASE] = LAYOUT_gergo(
    MT(MOD_HYPR, KC_TAB),  KC_Q, KC_D, KC_R, KC_W, KC_B,                                            KC_J, KC_F, KC_U,    KC_P,   KC_SCLN, KC_DEL,
    MT(MOD_LCTL, KC_ESC),  KC_A, KC_S, KC_H, KC_T, KC_G, KC_WBAK,                          KC_APP,  KC_Y, KC_N, KC_E,    KC_O,   KC_I,    MT(MOD_RCTL, KC_QUOT),
    MT(MOD_LSFT, KC_BSPC), KC_Z, KC_X, KC_M, KC_C, KC_V, KC_WFWD, KC_WBAK,        KC_WFWD, KC_TRNS, KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH, MT(KC_RSFT, KC_ENT),
MT(MOD_LALT, KC_HOME), MT(MOD_LCTL, KC_PGDN), LT(NUMB, KC_SPC), LT(SYMB, KC_ESC), LT(NUMB, KC_ENT), LT(SYMB, KC_SPC), MT(MOD_RGUI, KC_PGUP), MT(MOD_RALT, KC_END)
    ),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  !   |  @   |  #   |  $   |  %   |                         |  ^   |  &   |  *   |  (   |  )   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |~(uk) ||(uk) |      | SLEP |  |   | Caps |           |      |  ~   |  _   |  +   |  {   |  }   |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |#(uk) |\(uk) |      | WAKE |  \   | Calc |           |[BALL]|  `   |  -   |  =   |  [   |  ]   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
//Figure something out for the inner keys
[SYMB] = LAYOUT_gergo(
KC_TRNS, KC_EXLM,       KC_AT,     KC_HASH, KC_DLR,  KC_PERC,                                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
KC_TRNS, LSFT(KC_NUHS), LSFT(KC_NUBS), KC_NO, KC_SLEP, KC_PIPE, KC_CAPS,                          KC_TRNS, KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS,
KC_TRNS, KC_NUHS,       KC_NUBS,       KC_NO, KC_WAKE, KC_BSLS, KC_CALC, KC_TRNS,        KC_TRNS, KC_TRNS, KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |VolMute |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |  F1    |  F2  | F3   | F4   | F5   | F6   | LMB  |           | MMB  | LEFT | DOWN |  UP  | RIGHT|VolUp | VolDn  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |  F7    |  F8  | F9   | F10  | F11  | F12  | RMB  |           |      | MLFT | MDWN | MUP  | MRGHT|Ply/Pa|  Skip  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[NUMB] = LAYOUT_gergo(
    KC_TRNS, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MUTE,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_BTN1,                           KC_BTN3, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU, KC_VOLD,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BTN2, KC_TRNS,         KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MPLY, KC_MNXT,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
 */
