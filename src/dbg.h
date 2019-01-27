/*
    This file is part of the AdNW keyboard firmware.

    Copyright 2010-2016 Stefan Fröbe, <frobiac /at/ gmail [d0t] com>

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


#ifndef __DBG_H__
#define __DBG_H__

#include "print.h"

#define printf(...)

/// define DEBUG_OUTPUT in makefile to enable printf() for hid_listen.
#ifdef DEBUG_OUTPUT
#include "Descriptors.h"
#include "mem-check.h"

typedef struct {
    char data[DBG_EPSIZE];
} USB_DBGReport_Data_t;

uint8_t DBG__get_report(USB_DBGReport_Data_t* report);

#define TRACE(...)

#else
#define TRACE(...)
#define printf(...)

typedef struct {
    char data[0];
} USB_DBGReport_Data_t;

uint8_t DBG__get_report(USB_DBGReport_Data_t* report); // { return 0; } ;
#endif

#endif // __DBG_H__
