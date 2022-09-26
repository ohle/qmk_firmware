# Miryoku-based Kyria layout

This is a Miryoku-inspired QWERTY layout for a Kyria with encoder knobs in the
ENC1 positions and two 2u thumb keys per side.

## Layers

1. Base layer (QWERTY)
2. Symbols/Numbers
3. Shifted symbols
4. Function keys
5. Navigation
6. Mouse

## Base layer
```
,-------------------------------------------.                              ,-------------------------------------------.
|   🎛️   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   🎛️   |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|   Esc  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | : ;  |  ' "   |
|--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
| LShift |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | , >  | . >  | / ?  | RShift |
`----------------------+------+------+------| Sym  | Num  |  | Fun  |      |------+------+------+----------------------'
                       | Mouse| Nav  | Enter| Space| Tab  |  | Tab  | Space| Enter| bcksp|  del |
                       |      |      |      |      |      |  |      |      |      |      |      |
                       `----------------------------------'  `----------------------------------'
```


Basic QWERTY with:

- Dedicated shift keys on the pinkies
- Enter on the thumb's home position
- Space and tab on the 2u keys
- Layer switches on the thumb keys
- Homerow mods: GUI, Alt, Ctrl, Hyper on both sides, from inside out
  - GUI on <kbd>F</kbd> and <kbd>J</kbd>
  - Alt on <kbd>D</kbd> and <kbd>K</kbd>
  - Ctrl on <kbd>S</kbd> and <kbd>L</kbd>
  - Hyper on <kbd>;:</kbd> and <kbd>A</kbd>

## Symbols/Numbers layer

```
,-------------------------------------------.                              ,-------------------------------------------.
|   🎛️   |      |      |      |      |      |                              |  ` ~ | 7 &  | 8 *  | 9 (  |      |   🎛️   |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|        | Hyper|  Ctrl|  Alt |  Gui |      |                              |  = + | 4 $  | 5 %  | 6 ^  | [ {  |  ] }   |
|--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
| LShift |      |      |      |      |      |      |      |  |      |      |  \ | | 1 !  | 2 @  | 3 #  | (    | Shift )|
`----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
                       |      |      |      | Space|      |  |      | Space|      | 0 )  |  - _ |
                       |      |      |      |      |      |  |      |      |      |      |      |
                       `----------------------------------'  `----------------------------------'

```

A numblock, with symbols as shifted versions of their standard numbers.


## Shifted symbols
                                                                                                                         
```
,-------------------------------------------.                              ,-------------------------------------------.
|   🎛️   |      |      |      |      |      |                              |   ~  |   &  |   *  |   (  |      |   🎛️   |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|        | Hyper|  Ctrl|  Alt |  Gui |      |                              |   +  |   $  |   %  |   ^  |   {  |    }   |
|--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
| LShift |      |      |      |      |      |      |      |  |      |      |   |  |   !  |   @  |   #  |  )   | Shift )|
`----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
                       |      |      |      | Space|      |  |      | Space|      |      |      |
                       |      |      |      |      |      |  |      |      |      |      |      |
                       `----------------------------------'  `----------------------------------'

```

These are just the shifted symbols from the Symbols/Numbers layer, duplicated to
make them available without shift.

## Function keys
```
,-------------------------------------------.                              ,-------------------------------------------.
|   🎛️   | f12  |  f7  |  f8  |  f9  |      |                              |      |      |      |      |      |   🎛️   |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|        | f11  |  f4  |  f5  |  f6  |      |                              |      | hyper| ctrl |  alt |  gui |        |
|--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
| LShift | f10  |  f1  |  f2  |  f3  |      |      |      |  |      |      |      |      |      |      |      | rshift |
`----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
                       |      |      |      | space|      |  |      | space|      |      |      |
                       |      |      |      |      |      |  |      |      |      |      |      |
                       `----------------------------------'  `----------------------------------'
```
Function keys on the left in a numblock arrangement.


## Navigation Layer
```
,-------------------------------------------.                              ,-------------------------------------------.
|   🎛️   |      |      |      |      |      |                              | MW←  |  MW↓ |  MW↑ |  MW→ |      |   🎛️   |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|        | Hyper|  Ctrl|  Alt |  Gui |      |                              |  ←   |   ↓  |   ↑  |   →  |      |        |
|--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
| LShift |      |      |      |      |      |      |      |  |      |      | Home | PgUp |PgDown|  End |      |        |
`----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
                       |      |      |      | Space|      |  |      | Space|      |      |      |
                       |      |      | --   |      |      |  |      |      |      |      |      |
                       `----------------------------------'  `----------------------------------'
```

Arrow keys on the home row in vim arrangement, mousewheel above and
Home/End/PgUp/PgDown below

## Mouse Layer
```
,-------------------------------------------.                              ,-------------------------------------------.
|   🎛️   |      |      |      |      | acc2 |                              | MW←  |  MW↓ |  MW↑ |  MW→ |      |   🎛️   |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|        | Hyper|  Ctrl|  Alt |  Gui | acc1 |                              |  ←   |   ↓  |   ↑  |   →  |      |        |
|--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
| LShift |      |      |      |      | acc0 |      |      |  |      |      |      |      |      |      |      |        |
`----------------------+------+------+------|      |      |  |      |      |------+------+------+----------------------'
                       |      |      |      | Space|      |  |      | Space|      |      |      |
                       | --   |      |      |      |      |  |      |      |      |      |      |
                       `----------------------------------'  `----------------------------------'
```

Mouse navigation on right homerow in vim arrangement; acceleration control with
left index. Buttons on right thumb cluster.


```c
enum layers {
    _BASE = 0,
    _NUM,
    _SYM,
    _FUN,
    _NAV,
    _MOUSE
};
```
or re-define the `QWERTY`, `COLEMAK` and `DVORAK` keys to point to custom keycodes starting on `SAFE_RANGE` and calling the `set_single_persistent_default_layer` function inside of `process_record_user`.

### Todo

Via splitkb discord:

> So I wanted to use the rotary encoder for scrolling, but didn't like the
> firmware weight of MOUSEKEYS and didn't like the big step size of PgUp/PgDn, yet
> I wanted to be able to scroll fast when I wanted to. I tried two approaches,
> namely: A) step size inversely proportional to the (squared) rotation tick
> interval and B) gradually larger steps when continuously scrolling. I found the
> second approach to be more reliable in precision scrolling (e.g. navigating rows
> in code/text).
> I wanted to share the implementation in case anyone would like a smoother
> lightweight scrolling with encoders. Simply put the following in your config.h
> file:
 
 ```
#define ACCSCROLL_MAX_STEP 100
#define ACCSCROLL_STEP_SIZE 3
#define ACCSCROLL_REPEAT_INTERVAL 75


And then in your keymap.c file define some variables:

// Timer for accelerated scrolling
static uint16_t scroll_timer = 0;
static uint8_t scroll_step_size = 1;


And then the following in the desired spot of your encoder_update_user() function:

                // Scroll up/down with accelerated speed
                if (timer_elapsed(scroll_timer) < ACCSCROLL_REPEAT_INTERVAL) {
                    scroll_step_size += ACCSCROLL_STEP_SIZE;
                    scroll_step_size = (scroll_step_size > ACCSCROLL_MAX_STEP) ? ACCSCROLL_MAX_STEP : scroll_step_size;
                } else {
                    scroll_step_size = 1;
                }
                scroll_timer = timer_read();

                if (clockwise) {
                    for (uint8_t i = 0; i < scroll_step_size; i++) {
                        tap_code(KC_UP);
                    }
                } else {
                    for (uint8_t i = 0; i < scroll_step_size; i++) {
                        tap_code(KC_DOWN);
                    }
                }

```
 
> (Oh, gosh, does Discord has something like a code formatting block instead of
> this?) triple backticks did the trick... And yes, I'm probably breaking style
> conventions, best practices etc. Feel free to review 🙂 The ACCSCROLL_* macros
> are of course for tuning the feel of the scroll. Step size is how fast scroll
> speed builds up. Max step is the fastest scroll speed. Repeat interval is the
> longest time (in ms) between ticks where it still should increase step size.
