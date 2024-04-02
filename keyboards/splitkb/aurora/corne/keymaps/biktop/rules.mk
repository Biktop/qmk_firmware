# Copyright 2022 splitkb.com <support@splitkb.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

COMBO_ENABLE = yes

BACKLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
RGBLIGHT_ENABLE = no

MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
AUDIO_ENABLE = no

MIDI_ENABLE = no
UNICODE_ENABLE = no

KEY_OVERRIDE_ENABLE = no
TAP_DANCE_ENABLE = no
AUTO_SHIFT_ENABLE = no
DYNAMIC_MACRO_ENABLE = no
COMMAND_ENABLE = yes
LEADER_ENABLE = no

LTO_ENABLE = yes #enable link time optimization to reduce binary size

# Firmware size reduction
GRAVE_ESC_ENABLE   = no
# MAGIC_ENABLE       = no
SPACE_CADET_ENABLE = no

# EXTRAFLAGS += -flto

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += rgb_matrix.c
endif

ifeq ($(strip $(CONSOLE_ENABLE)), yes)
    TMK_COMMON_DEFS += -DCONSOLE_ENABLE
else
    TMK_COMMON_DEFS += -DNO_PRINT
    TMK_COMMON_DEFS += -DNO_DEBUG
endif

# Bootloader selection
BOOTLOADER = caterina
