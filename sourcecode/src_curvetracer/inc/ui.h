/*
 * This file is part of the VisaDevices library project.
 * Copyright (c) 2019-2023 Frank Zimdars.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CURVETRACER_UI_H
#define CURVETRACER_UI_H

/*
 * Used console colors (foreground only)
 */
typedef enum{
    CONSOLE_COLOR_BLUE = 9,
    CONSOLE_COLOR_RED = 12,
    CONSOLE_COLOR_GREEN = 99,
    CONSOLE_COLOR_CYAN = 98,
    CONSOLE_COLOR_STD =0
} console_color_t;

/**
 * Clears output of the console
 */
void ui_clear();

/**
 * Change the color of the text output
 * @param color Foreground color of new text
 */
void ui_set_color(console_color_t color);

/**
 * Displays the program main menu
 * @param msg optional msg string
 * @return selected option
 */
int ui_menu(const char* msg);

/**
 * Shows about text
 */
void ui_about();

/**
 * Wait on enter on the keyboard
 */
void ui_wait_enter();

#endif
