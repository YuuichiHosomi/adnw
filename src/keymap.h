#ifndef KEYMAP_H
#define KEYMAP_H 1

#include <stdint.h>
#include "hid_usage.h"

#define LAYERS 4
#define ROWS   8
#define COLS   6  ///< cols of both keyboard halves are "stacked" in layout and physically connected

#define _ANALOG _no

// *************************************************************
// *    Matrix of physical keyboard to key mapping
// *
// * @todo  PROGMEM and configuration
// *        Shift != Mod1, see "/'
// *************************************************************

struct keycode {
    uint8_t  ch;    ///< could be useful for dumping the layout
    uint8_t  hid;   ///< HID usage code, will be interpreted by OS keyboard layout!
    uint8_t  mods;  ///< HID modifiers , will be interpreted by OS keyboard layout!
} ;


/*
   ----- Thumb & MKT ----
   M   W 2 C A  3 1 A    â«
   ? ?  ? ?  ?

   ----- M0 Default AdNW (Ulf) -----
   k u q . j   v g c l f
   h i e a o   d t r n s
   x y - . "   b p w m z

   ----- M2 / special ---
   @ _ [ ] #   ! < > = &
   \ / { } *   ? ( ) + -
     $ | ~ `   ^ % " '

   ----- M3 / MoveNum ---
    ? ? ? ? ?     7 8 9 +
    ? ? ? ? ?     4 5 6 -
      ? ? ?     0 1 2 3

   ----- Mouse ----------
   S
   1 2 3


   ----- Compose --------
    F1.....F6
    F7....F12


   ----------------------
 */


uint8_t getModifier(uint8_t row, uint8_t col, uint8_t layer);
uint8_t getKeyCode(uint8_t row, uint8_t col, uint8_t layer);


static const struct keycode /*PROGMEM*/ ModeKeyMatrix[ROWS][COLS] = {
    // Left half
    { _no,     _no,     _no,     _no,       _no,     _no },
    { _no,     _no,     _no,     _no,       _no,     _no },
    { _no,     _no,     _no,     _no,       _no,     _no },
    { _no,     _no,     _no,     _ESC,      _TAB,  _SPACE },

    { _no,     _no,     _no,     _no,       _no,     _no },
    { _no,     _no,     _no,     _no,       _no,     _no },
    { _no,     _no,     _no,     _no,       _no,     _no },
    { _BSPACE, _ENTER,  _no,     _no,       _no,     _no }
};


#define _THUMB_ROW_LEFT     _no /*macro*/, _L_GUI,     _MOD_1,     _L_CTRL , _L_ALT,       _L_SHIFT
#define _THUMB_ROW_RIGHT    _MOD_2,     _MOD_3,     _COMPOSE,   _R_ALT,  _no, _no


static const struct keycode /*PROGMEM*/ KeyMatrix[LAYERS+2][ROWS][COLS] = {
    // normal layer
    {
        { _ESC, _k, _u, _q, _PERIOD,_j  },
        { _TAB, _h, _i, _e, _a, _o  },
        { _no,  _x, _y, _MINUS, _COMMA, _DQUOTE },
        { _THUMB_ROW_LEFT },

        { _v,   _g, _c, _l, _f,     _BSPACE },
        { _d,   _t, _r, _n, _s, _ENTER  },
        { _b,   _p, _w, _m, _z, _no     },
        { _THUMB_ROW_RIGHT}
    },

    // MOD1 layer (shifted)
    {
        { _ESC, _K,         _U,         _Q,         _COLON,     _J},
        { _TAB, _H,         _I,         _E,         _A,         _O},
        { _no,  _X,         _Y,         _USCORE,    _SCOLON,    _SQUOTE},
        { _THUMB_ROW_LEFT },

        { _V,     _G,         _C,         _L,         _F,         _BSPACE },
        { _D,     _T,         _R,         _N,         _S,         _ENTER  },
        { _B,     _P,         _W,         _M,         _Z,         _no     },
        { _THUMB_ROW_RIGHT}
    },

    // MOD2 layer (special chars)
    {
        { _no, _AT,      _no,       _L_BRACKET, _R_BRACKET, _HASH },
        { _no, _BSLASH,  _SLASH,    _L_BRACE,   _R_BRACE,   _ASTERIX},
        { _no, _no,      _DOLLAR,   _BAR,       _TILDE, _GRAVE },
        { _THUMB_ROW_LEFT },

        { _EXCLAM,  _LESS,      _GREATER,   _EQUAL,     _AMPERSAND, _no },
        { _QUESTION,_L_PAREN,   _R_PAREN,   _PLUS,      _MINUS,     _no },
        { _CARET,   _PERCENT,   _DQUOTE,    _SQUOTE,    _no,        _no },
        { _THUMB_ROW_RIGHT}
    },

    // MOD3 layer (movement controls and numbers)
    {
        { _no, _PGUP,   _BSPACE,    _UP,        _DEL ,      _PGDN},
        { _no, _HOME,   _LEFT,      _DOWN,      _RIGHT,     _END },
        { _no, _ESC,    _TAB,       _INS,       _ENTER,     _no },
        { _THUMB_ROW_LEFT },

        { _EXCLAM,  _7,         _8,         _9,     _PLUS,      _no },
        { _EQUAL,   _4,         _5,         _6,     _MINUS,     _no },
        { _0,       _1,         _2,         _3,     _no,        _no },
        { _THUMB_ROW_RIGHT}
    },

    //MOUSE MODE
    /// @todo These should not be shifted, maybe factor out entirely!
    {
        { _no, _SSHARP,     _U_UML,    _no,      _A_UML,     _O_UML },
        { _no, _MS_BTN_1,   _MS_BTN_2,_MS_BTN_3, _MS_SCROLL, _no},
        { _no, _no, _no, _no, _no, _no},
        { _no, _no, _no, _L_CTRL, _L_ALT, _L_SHIFT },

        { _no, _no, _no, _no, _no, _no },
        { _no, _no, _no, _no, _no, _no },
        { _no, _no, _no, _no, _no, _no },
        { _no, _no, _no, _no, _no, _no },
//        { _MS_BTN_2,      _MS_BTN_3,     _no,    _no ,_MOUSE, _MOUSE}
    },

    // COMPOSE
    {
        { _no, _no,     _U_UML, _no,    _no,    _no },
        { _no, _SSHARP, _no,    _no,    _A_UML, _O_UML},
        { _no, _no,     _no,    _no,    _no,    _no},
        { _THUMB_ROW_LEFT },

        { _F1,      _F2,        _F3,        _F4,        _F5,    _F6     },
        { _F7,      _F8,        _F9,        _F10,       _F11,   _F12    },
        { _no,      _no,        _no,        _no,        _no,    _no     },
        { _THUMB_ROW_RIGHT}
    }
}; // end of matrix[][][]

#endif

