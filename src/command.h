/*
    This file is part of the AdNW keyboard firmware.

    Copyright 2010-2018 Stefan Fröbe, <frobiac /at/ gmail [d0t] com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


#include <stdbool.h>
#include <stdint.h>

void setCommandMode(bool);
bool commandMode(void);
uint8_t commandModeSub(void);

/// return true if handled here and no echo is needed
bool handleCommand(uint8_t hid, uint8_t mod);
bool handleSubCmd(char c, uint8_t hid, uint8_t mod);

/// possible subcommands
enum {
    SUB_NONE=0,
    SUB_TP,
    SUB_LAYOUT,
    SUB_MACRO,
    SUB_MACRO_REC,
    SUB_PASSHASH,
    SUB_PW_XOR,
    SUB_CONFIG,
    SUB_LED,
    SUB_EXTRA,
    SUB_END
};

