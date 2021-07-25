#include QMK_KEYBOARD_H
#include "xtonhasvim.h"
#include "common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_planck_grid(
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
            CTRL_ESC,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NAV_SCLN,KC_QUOT,
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
            MEH,     KC_LCTL, KC_LALT, KC_LGUI, FKEYS,   SYMBOL,  KC_SPC,  KC_ENT,  KC_RGUI, KVM_SWT, COPY,    PASTE),

    // Every symbol required for coding and every-day use.
    [_SYMBOL] = LAYOUT_planck_grid(
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
            KC_TILD, KC_LPRN, KC_RPRN, KC_HASH, KC_EQL,  KC_PERC, KC_CIRC, KC_MINS, KC_ASTR, KC_LCBR, KC_RCBR, KC_LBRC,
            MEH,     KC_EXLM, KC_AT,   KC_PLUS, KC_DLR,  KC_PIPE, KC_AMPR, KC_UNDS, KC_LT,   KC_GT,   KC_BSLS, KC_RBRC,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    // Function keys, mouse emulation and less commonly used special keys.
    [_FKEYS] = LAYOUT_planck_grid(
            _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, KC_WH_U, KC_DEL,
            KC_LCTL, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_D, _______,
            MEH,     KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______),

    // Loosely vim-based cursor and document navigation keys.
    // Accessed by holding semicolon.
    [_NAV] = LAYOUT_planck_grid(
            _______, _______, _______, WORD_R,  _______, _______, _______, KC_PGUP, LINE_R,  LINE_L,  _______, _______,
            _______, _______, _______, KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
            _______, _______, _______, _______, _______, WORD_L,  _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    // One-handed gaming layout.
    // Left hand shifted one key further left than usual for WASD usage.
    [_GAME] = LAYOUT_planck_grid(
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LOCK,
            _______, KC_ESC,  _______, FKEYS,   KC_SPC,  _______, _______, _______, _______, _______, XBX_IMG, XBX_MOV),

    // Special macros accessible via MEH key (bottom-left corner key).
    // Undefined keys will get the standard MEH modifiers added.
    [_MEH] = LAYOUT_planck_grid(
            _______, LOCK,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, VIM_START,_______,_______, _______, CAP_IMG, CAP_MOV),

    // Keyboard level commands.
    // Accessed via MEH+SYMBOL keys.
    [_ADJUST] = LAYOUT_planck_grid(
            _______, RGB_HUI, RGB_HUD, RGB_TOG, DM_REC1, _______, _______, _______, _______, _______, DM_PLY1, RESET,
            _______, RGB_SAI, RGB_SAD, _______, _______, GAME,    _______, _______, _______, _______, _______, _______,
            _______, _______, _______, KC_LOCK,VIM_START,_______, _______, _______, CK_TOGG, CK_UP,   CK_DOWN, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    // xtonhasvim compatibility layer. VIM_ prefixes probably not required, along with this layer.
    [_VIM] = LAYOUT_planck_grid(
            _______, _______, VIM_W,   VIM_E,   VIM_R,   _______, VIM_Y,   VIM_U,   VIM_I,   VIM_O,   VIM_P,   _______,
            VIM_ESC, VIM_A,   VIM_S,   VIM_D,   _______, VIM_G,   VIM_H,   VIM_J,   VIM_K,   VIM_L,   _______, _______,
            VIM_SHIFT,_______,VIM_X,   VIM_C,   VIM_V,   VIM_B,   _______, _______, VIM_COMMA,VIM_PERIOD,_______,_______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    // xtonhasvim compatibility layer. Probably not required with some refactoring.
    [_VINSERT] = LAYOUT_planck_grid(
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            VIM_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
};

// track the time of the last key input.
static uint16_t last_key_time;

// track the last keycode pressed.
static uint16_t last_key_code;

// track the state of MEH over multiple key presses.
// 0 - not activated
// 1 - pressed but waiting activation
// 2 - activated MEH combo
static int meh_activated;

// track the state of NAV_SCLN
// 0 - not activated
// 1 - pressed (waiting to decide on semicolon or nav)
// 2 - consumed (upgraded to semicolon or used in nav layer)
// 3 - consumed (as ctrl-tab rotation)
// 4 - consumed (as cmd)
static int semicolon_nav_activated;

// keep track of the current kvm target (to play a different sound on switch).
static int kvm_target;

// keep track of the kvm target which is in game mode.
static int game_target = -1;

#define IS_GAME kvm_target == game_target

// whether a symbol was typed after symbol layer switch
// 0  - not consumed
// 1  - consumed by standard case
// 2+ - consumed by special case
static int symbol_consumed;

// track the state of backtick surround
// 0 - not activated
// 1 - started (cursor placed between ``)
// 2 - consumed (success or revert)
static int backtick_surround_state;

static bool last_was_number;

// sounds
float song_kvm_setting[][2] = SONG(S__NOTE(_C5),S__NOTE(_C6),S__NOTE(_C7));

float song_kvm_0[][2] = SONG(S__NOTE(_C5),S__NOTE(_E5));
float song_kvm_1[][2] = SONG(S__NOTE(_E5),S__NOTE(_C5));

float song_game_0[][2] = SONG(S__NOTE(_C6),S__NOTE(_C5));
float song_game_1[][2] = SONG(S__NOTE(_C5),S__NOTE(_C6));

void set_game_mode(bool state, bool update_target_state)
{
    if (state)
    {
        layer_on(_GAME);
        PLAY_SONG(song_game_1);
        if (update_target_state)
            game_target = kvm_target;
    }
    else
    {
        layer_off(_GAME);
        if (update_target_state && game_target != -1)
        {
            PLAY_SONG(song_game_0);
            game_target = -1;
        }
    }
}

bool process_game_specials(uint16_t keycode, keyrecord_t *record) {

    if (!record->event.pressed)
        return true;

    bool isGameMode = IS_GAME;

    switch (keycode)
    {
        case GAME:
            set_game_mode(!isGameMode, true);
            return false;
        case KC_TAB:
            // turn off game mode on alt-tab
            if (isGameMode && get_mods() & MOD_BIT(KC_LALT))
            {
                if (record->event.pressed)
                    set_game_mode(false, true);
            }
            break;
    }

    return true;
}

void backtick_commit(void)
{
    switch (backtick_surround_state)
    {
        case 1:
            tap_code16(KC_RGHT);
            tap_code16(KC_BSPC);
            tap_code16(KC_BSPC);
            break;

        case 2:
            tap_code16(KC_RGHT);
            break;
    }

    backtick_surround_state = 0;
}

bool process_backtick_surround(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed)
        return true;

    uint8_t mod_state = get_mods();

    bool enter_via_lshift = keycode == KC_LSFT && mod_state & MOD_BIT(KC_RSFT);
    bool enter_via_rshift = keycode == KC_RSFT && mod_state & MOD_BIT(KC_LSFT);

    switch (backtick_surround_state)
    {
        case 0:
            // enter via shift+shift
            if (enter_via_lshift || enter_via_rshift) {
                unregister_code(KC_LSFT);
                unregister_code(KC_RSFT);

                // begin backtick surround sequence.
                tap_code16(KC_GRV);
                tap_code16(KC_GRV);
                tap_code16(KC_LEFT);
                backtick_surround_state = 1;

                register_code(keycode == KC_LSFT ? KC_RSFT : KC_LSFT);
                return true;
            }

            break;
        default:
            switch (keycode) {
                case KC_LSFT:
                case KC_RSFT:
                case KC_LCTL:
                    // don't consume symbol from keys that aren't meaninful.
                    break;

                case KC_SPC:
                case KC_ESC:
                case KC_COMM:
                case CTRL_ESC:
                    if (get_mods() == 0)
                        // exit via various commit keys
                        backtick_commit();
                    break;

                case KC_BSPC:
                    // only handle if not consumed (we might be backspacing within a surround).
                    if (backtick_surround_state == 1)
                    {
                        backtick_commit();
                        return false;
                    }

                    break;

                case KC_ENT:
                    // exit via enter
                    backtick_commit();
                    return false;

                default:
                    // or consume on any other key
                    backtick_surround_state = 2;
                    break;
            }

            break;
    }

    return true;
}

bool process_fkeys(uint16_t keycode, keyrecord_t *record) {
    if (keycode != FKEYS)
        return true;

    // Pressing the FKEY key without another key will backspace one word (opt-backspace).
    if (record->event.pressed)
    {
        if ((last_key_code == FKEYS || last_key_code == SYMBOL) && timer_elapsed(last_key_time) < 1000)
        {
            symbol_consumed = 2;
            SEND_STRING(SS_LALT(SS_TAP(X_BSPC)));
        }
    }
    else
    {
        if (symbol_consumed == 0 && last_key_code == FKEYS && timer_elapsed(last_key_time) < 300)
            SEND_STRING(SS_LALT(SS_TAP(X_BSPC)));

        symbol_consumed = 0;
    }

    return true;
}

bool process_symbol_specials(uint16_t keycode, keyrecord_t *record) {
    // handle actual layer toggle.
    if (keycode == SYMBOL)
    {
        if (record->event.pressed)
        {
            symbol_consumed = 0;
            layer_on(_SYMBOL);
        }
        else
        {
            layer_off(_SYMBOL);

            if (symbol_consumed == 3)
                unregister_code(KC_PGUP);
        }

        return true;
    }

    if (!IS_LAYER_ON(_SYMBOL))
        return true;

    // handle special case keys, where a certain key is pressed immediately following
    // symbol layer. this allows special space/backspace when intention is clear
    // and we are not attempting to just backspace or punctuate while typing symbols.
    if (record->event.pressed)
    {
        if (symbol_consumed != 1)
        {
            switch (keycode) {
                case KC_LSFT:
                case KC_RSFT:
                    // don't consume symbol from keys that aren't meaninful.
                    return true;

                case KC_SPC:
                    register_code(KC_PGUP);
                    symbol_consumed = 3;
                    return false;
                // dead use case.
                case KC_BSPC:
                    SEND_STRING(SS_LALT(SS_TAP(X_BSPC)));
                    symbol_consumed = 2;
                    return false;
            }
        }

        // When typing numbers, we usually want comma/period instead of angled brackets.
        if (last_was_number)
        {
            switch (keycode) {
                case KC_LT:
                    tap_code16(KC_COMM);
                    return false;
                case KC_GT:
                    tap_code16(KC_DOT);
                    return false;
            }
        }

        // only upgrade from initial state. 2 is capturing
        if (symbol_consumed == 0)
            symbol_consumed = 1;
    }
    else
    {
        switch (keycode) {
            case KC_SPC:
                if (symbol_consumed == 3)
                    unregister_code(KC_PGUP);
                return true;
        }
    }

return true;
}

void deactivate_meh(void) {
    if (meh_activated == 0)
        return;

    unregister_code(KC_LCTL);
    unregister_code(KC_LSFT);
    unregister_code(KC_LALT);
    layer_off(_MEH);

    if (meh_activated == 1)
        SEND_STRING(SS_LGUI(SS_TAP(X_C)));

    meh_activated = 0;
}

bool process_meh(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SYMBOL:
            // symbol+shift combination needs to activate regardless of order.
            if (record->event.pressed)
            {
                if (get_mods() & MOD_BIT(KC_LSFT))
                {
                    // `redirect` to MEH
                    meh_activated = 1;
                    layer_move(_MEH);
                    return false;
                }
            }
            else
            {
                deactivate_meh();
            }
            break;

        case MEH:
        case RMEH:
            if (record->event.pressed) {
                meh_activated = 1;
                layer_move(_MEH);
            }
            else
            {
                deactivate_meh();
            }

            return false;
        case KC_TAB:
            if (record->event.pressed && meh_activated == 1)
            {
                SEND_STRING("```csharp" SS_LSFT(SS_TAP(X_ENT)) SS_LSFT(SS_TAP(X_ENT)) "```");
                SEND_STRING(SS_TAP(X_UP));
                return false;
            }
            break;

        default:
            if (record->event.pressed && meh_activated == 1)
            {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_LALT);
                meh_activated = 2;
            }

            break;
        case CAP_MOV:
        case CAP_IMG:
            // don't want these to trigger the down codes of MEH.
            // bit ugly to have this here; probably need to rethink this logic.
            meh_activated = 2;
            break;
        case LOCK:
            if (record->event.pressed) {
                // lock windows
                SEND_STRING(SS_LGUI(SS_TAP(X_L)));
                // lock macOS and turn off screen
                SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_Q))));
            }
            meh_activated = 2;
            return false;
    }

    return true;
}

// track the state of CTRL_ESC over multiple key presses.
// 0 - not activated
// 1 - pressed (esc activated, ctrl pending on next keystroke)
// 2 - pressed (ctrl activated, esc pending on CTRL_ESC release if no combo consumption)
// 3 - consumed (upgraded to ctrl or autoexited on special case keys)
static int ctrl_escape_activated;

// ctrl-esc has two modes of activation depending on how long since the last key press.
// the assumption is that if it is pressed soon after another key, it is probably intended to be escape
// (ie. for vim insert mode exit), but if pressed out of the blue it's more likely to be a ctrl key.
//
// if pressed with no recent key presses, it will begin in ctrl mode, and only actuate an escape press
// on release (if not consumed as control). this allows for ctrl combos without an unnecessary escape fire.
//
// if pressed after a recent key, it will begin in esc mode, and only actuate a control press if another
// key is pressed during the hold.
bool process_ctrl_esc(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTRL_ESC:
            if (record->event.pressed) {
                if (timer_elapsed(last_key_time) < 250)
                {
                    register_code(KC_ESC);
                    ctrl_escape_activated = 1;
                }
                else
                {
                    register_code(KC_LCTL);
                    ctrl_escape_activated = 2;
                }
            }
            else
            {
                unregister_code(KC_ESC);
                unregister_code(KC_LCTL);

                if (timer_elapsed(last_key_time) < 250 && ctrl_escape_activated == 2)
                {
                    tap_code16(KC_ESC);
                }

                if (ctrl_escape_activated < 3)
                {
                    if (IS_LAYER_ON(_VINSERT))
                        layer_move(_VIM);
                }

                ctrl_escape_activated = 0;
            }

            return true;
        default:
            switch (ctrl_escape_activated)
            {
                case 1:
                    // ctrl combo capture.
                    unregister_code(KC_ESC);
                    register_code(KC_LCTL);
                    ctrl_escape_activated = 3;
                    break;
                case 2:
                    // consumption.
                    ctrl_escape_activated = 3;
                    break;
            }
            break;
    }

    return true;
}

void unregister_nav_scln_down_state(void) {
    unregister_code16(KC_SCLN);

    switch (semicolon_nav_activated)
    {
        case 3:
            unregister_code16(KC_LSFT);
            break;
        case 4:
            unregister_code16(KC_LGUI);
            break;
    }

    semicolon_nav_activated = 0;
}

bool process_nav_scln(uint16_t keycode, keyrecord_t *record) {
    // handle toggle logic (and potential semicolon output).
    switch (keycode) {
        case NAV_SCLN:
            if (record->event.pressed) {
                // timer case here is just to give more immediacy to semicolons when typing at EOL.
                // set low enough to not impede intended navigation
                if (get_mods() & MOD_BIT(KC_LSFT) || (get_mods() == 0 && timer_elapsed(last_key_time) < 150 && last_key_code != CTRL_ESC))
                {
                    register_code16(KC_SCLN);
                    semicolon_nav_activated = 2;
                    return true;
                }
                else
                {
                    semicolon_nav_activated = 1;
                    layer_on(_NAV);
                }
                return false;
            }
            else
            {
                switch (semicolon_nav_activated)
                {
                    case 1:
                        if (timer_elapsed(last_key_time) < 250)
                        {
                            // clears a potential ctrl modifier from CTRL_ESC.
                            // sequence of events is SCLN down - wait 500ms - CTRL_ESC down - SCLN up - CTRL_ESC up
                            clear_mods();
                            tap_code16(KC_SCLN);
                        }
                        break;
                }

                unregister_nav_scln_down_state();
                semicolon_nav_activated = 0;
                layer_off(_NAV);
                return false;
            }
    }


    if (!record->event.pressed || semicolon_nav_activated < 1)
        return true;

    switch (keycode) {
        case KC_UP:
        case KC_DOWN:
        case KC_PGUP:
        case KC_PGDN:
        case WORD_L:
        case WORD_R:
        case LINE_L:
        case LINE_R:
        case TAB_L:
        case TAB_R:
            unregister_nav_scln_down_state();
            semicolon_nav_activated = 2;

            // actions for these are handled by the keys/macros temselves.
            return true;

        case KC_LEFT:
        case KC_RGHT:
            if (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_LGUI))
            {
                if (semicolon_nav_activated != 3)
                    unregister_nav_scln_down_state();

                if (keycode == KC_LEFT)
                    register_code16(KC_LSFT);
                else
                    unregister_code16(KC_LSFT);

                tap_code16(KC_TAB);
                semicolon_nav_activated = 3;
                return false;
            }
            else
            {
                unregister_nav_scln_down_state();
                semicolon_nav_activated = 2;
                return true;
            }

        case KC_LGUI:
        case KC_LSFT:
        case KC_SPC:
            return true;

        case KC_G:
            // vim style home/end (change to cmd-down/up instead? home/end doesn't work great on apple OSes)
            if (get_mods() & MOD_BIT(KC_LSFT))
            {
                unregister_code16(KC_LSFT);
                tap_code16(KC_END);
                register_code16(KC_LSFT);
            }
            else
                tap_code16(KC_HOME);
            return false;

        case KC_ENT:
            // enter only cmd enters if the first thing.
            // this is to allow things like selecting options from lists (using up/down).
            if (semicolon_nav_activated > 1)
                return true;

            break;

        case CTRL_ESC:
            // this handles cases like SCLN_NAV -> KC_ESC rapidly after a previous character.
            if (semicolon_nav_activated == 1)
            {
                tap_code16(KC_SCLN);
                semicolon_nav_activated = 2;
                return true;
            }

            break;
    }

    // if the nav layer doesn't have a specific action for the pressed key, we add a cmd modifier.
    // this feels pretty good but may be a bit noisy/undefined.
    if (semicolon_nav_activated != 4 && semicolon_nav_activated != 2)
    {
        unregister_nav_scln_down_state();

        register_code16(KC_LGUI);
        semicolon_nav_activated = 4;
    }

    return true;
}

// track the state of KC_LSFT
// 0 - not activated
// 1 - down, not consumed
// 2 - down, consumed
static int lsft_state;

bool process_left_shift(uint16_t keycode, keyrecord_t *record) {
    if (last_key_code == KC_RSFT)
        // this should handle backtick escape instead.
        return true;

    if (keycode == KC_LSFT)
    {
        if (record->event.pressed)
        {
            if (get_mods() & MOD_BIT(KC_RSFT) || (last_key_code == KC_LSFT && timer_elapsed(last_key_time) < 250))
            {
                tap_code16(KC_UNDS);
                lsft_state = 2;
                return false;
            }

            lsft_state = 1;
            // block this because it handles weird on iOS (left shift release also releases right shift MAKING_this-happen)
            return false;
        }
        else
        {
            if (lsft_state == 1  && (last_key_code == KC_LSFT && timer_elapsed(last_key_time) < 250))
                tap_code16(KC_UNDS);

            lsft_state = 0;
        }
    }
    else if (record->event.pressed && lsft_state == 1)
    {
        register_code(KC_LSFT);
        lsft_state = 2;
    }

    return true;
}

// track the state of KC_RSFT
// 0 - not activated
// 1 - down, not consumed
// 2 - down, consumed
static int rsft_state;

bool process_right_shift(uint16_t keycode, keyrecord_t *record) {
    if (last_key_code == KC_LSFT)
        // this should handle backtick escape instead.
        return true;

    if (keycode == KC_RSFT)
    {
        if (record->event.pressed)
        {
            if (get_mods() & MOD_BIT(KC_LSFT) || (last_key_code == KC_RSFT && timer_elapsed(last_key_time) < 250))
            {
                tap_code16(KC_MINS);
                rsft_state = 2;
                return false;
            }

            rsft_state = 1;
            // block this because it handles weird on iOS (right shift release also releases left shift MAKING_this-happen)
            return false;
        }
        else
        {
            if (rsft_state == 1  && (last_key_code == KC_RSFT && timer_elapsed(last_key_time) < 250))
                tap_code16(KC_MINS);

            rsft_state = 0;
        }
    }
    else if (record->event.pressed && rsft_state == 1)
    {
        register_code(KC_RSFT);
        rsft_state = 2;
    }

    return true;
}

bool process_macros(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed)
        return true;

    switch (keycode) {
        case COPY:
            SEND_STRING(SS_LGUI("lc"));
            tap_code16(KC_ESC);
            tap_code16(KC_ESC);
            return false;

        case KVM_SWT:
            if (get_mods() & MOD_BIT(KC_LCTL))
            {
                SEND_STRING(SS_LCTL(SS_TAP(X_F12)) "t");
                PLAY_SONG(song_kvm_setting);
                return false;
            }

            tap_code16(KC_SCROLLLOCK);
            tap_code16(KC_SCROLLLOCK);

            // track the current target device to give audible feedback
            kvm_target = (kvm_target + 1) % 2;

            if (kvm_target == 1)
                PLAY_SONG(song_kvm_1);
            else
                PLAY_SONG(song_kvm_0);

            set_game_mode(IS_GAME, false);
            return false;

        case KC_W:
            // todo: move to vim implementation
            if (IS_LAYER_ON(_VINSERT)) {
                if (get_mods() & MOD_BIT(KC_LCTL) && (get_mods() & MOD_BIT(KC_LALT)) == 0)
                {
                    unregister_code(KC_LCTL);

                    register_code(KC_LALT);
                    tap_code16(KC_BSPC);
                    unregister_code(KC_LALT);

                    register_code(KC_LCTL);
                    return false;
                }
            }
            break;

        case KC_BSPC:
            // ctrl-backspace maps to opt-backspace
            if (get_mods() & MOD_BIT(KC_LCTL))
            {
                uint8_t mod_state = get_mods();
                clear_mods();

                register_code(KC_LALT);
                tap_code16(KC_BSPC);
                unregister_code(KC_LALT);

                set_mods(mod_state);
                return false;
            }
            break;
    }

    return true;
}

void update_last_was_number(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed)
    {
        switch (keycode) {
            case KC_1:
            case KC_2:
            case KC_3:
            case KC_4:
            case KC_5:
            case KC_6:
            case KC_7:
            case KC_8:
            case KC_9:
            case KC_0:
                last_was_number = true;
                break;
            default:
                last_was_number = false;
                break;
        }
    }
}

bool process_all_custom(uint16_t keycode, keyrecord_t *record) {
    if (!(IS_GAME))
    {
        // delay shift down presses until next key.
        if (!process_left_shift(keycode, record)) return false;
        if (!process_right_shift(keycode, record)) return false;
    }

    if (!process_meh(keycode, record)) return false;

    if (!process_macros(keycode, record)) return false;

    if (!process_symbol_specials(keycode, record)) return false;

    if (!process_fkeys(keycode, record)) return false;

    if (!process_game_specials(keycode, record)) return false;

    // in game mode, all excess processing is skipped (mainly to avoid unwanted macro / helper triggers).
    if (!(IS_GAME))
    {
        if (!process_nav_scln(keycode, record)) return false;

        if (!process_backtick_surround(keycode, record)) return false;
        if (!process_record_vimlayer(keycode, record)) return false;
        if (!process_ctrl_esc(keycode, record)) return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    bool retval = process_all_custom(keycode, record);

    if (record->event.pressed)
    {
        switch (keycode)
        {
            default:
                last_key_time = timer_read();
                last_key_code = keycode;
                break;
        }
    }

    update_last_was_number(keycode, record);
    return retval;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBOL, _FKEYS, _ADJUST);

    return state;
}