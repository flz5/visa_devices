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

#ifdef OS_WIN
#include <windows.h>
#endif

#include <iostream>
#include <limits>
#include <ios>
#include "ui.h"

/**
 * Clears output of the console
 */
void ui_clear() {
    #ifdef OS_WIN
    system("cls");
    #endif

    #if defined(OS_LINUX) || defined(OS_MAC)
    printf("\33c\e[3J\33c");
    #endif
}

/**
 * Change the color of the text output
 * @param color Foreground color of new text
 */
void ui_set_color(console_color_t color){

    #if defined(OS_WIN)
    //Windows only ...

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    //First save the current color information
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;

    //Set the new color information
    switch(color){
        case CONSOLE_COLOR_STD:
        {
             SetConsoleTextAttribute ( h, FOREGROUND_BLUE |
             FOREGROUND_GREEN | FOREGROUND_RED );
        }break;
        case CONSOLE_COLOR_BLUE:
        {
            SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY | FOREGROUND_BLUE );
        }break;
        case CONSOLE_COLOR_RED:{
            SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY | FOREGROUND_RED );
        }break;
        case CONSOLE_COLOR_CYAN:{
            SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY |
            FOREGROUND_GREEN | FOREGROUND_BLUE );
        }break;
        case CONSOLE_COLOR_GREEN:{
            SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY | FOREGROUND_GREEN );
        }break;
    }
    #endif

    #if defined(OS_MAC)
    //MAC OS only...
    switch(color){
        case CONSOLE_COLOR_STD:
        {
            printf("\x1b[0m");
        }break;
        case CONSOLE_COLOR_BLUE:
        {
            printf("\x1b[34m");
        }break;
        case CONSOLE_COLOR_RED:{
            printf("\x1b[31m");
        }break;
        case CONSOLE_COLOR_CYAN:{
            printf("\x1b[36m");
        }break;
        case CONSOLE_COLOR_GREEN:{
            printf("\x1b[32m");
        }break;
    }
    #endif
}

/**
 * Displays the program main menu
 * @param msg optional msg string
 * @return selected option
 */
int ui_menu(const char* msg) {
	ui_clear();
	ui_set_color( CONSOLE_COLOR_STD);
	std::cout << "VisaDevices CurveTracer" << std::endl;
	std::cout << "====================================" << std::endl;
	std::cout << "Devices" << std::endl;
	std::cout << "\t01. Add" << std::endl;
	std::cout << "\t02. List" << std::endl;
	std::cout << "\t03. Remove" << std::endl;
	std::cout << "Sweeps" << std::endl;
	std::cout << "\t04. Add" << std::endl;
	std::cout << "\t05. List" << std::endl;
	std::cout << "\t06. Remove" << std::endl;
	std::cout << "Measurements" << std::endl;
	std::cout << "\t07. Add" << std::endl;
	std::cout << "\t08. List" << std::endl;
	std::cout << "\t09. Remove" << std::endl;
	std::cout << "Results" << std::endl;
	std::cout << "\t10. Folder" << std::endl;;
	std::cout << "Programm" << std::endl;
	std::cout << "\t11. Start" << std::endl;
	std::cout << "\t12. About" << std::endl;
    std::cout << std::endl;
	std::cout << "\t99. Exit" << std::endl;
    std::cout << std::endl;

	ui_set_color( CONSOLE_COLOR_RED);
	std::cout << msg << std::endl;
	ui_set_color( CONSOLE_COLOR_STD);

	std::cout << "Command: ";
	ui_set_color( CONSOLE_COLOR_BLUE);
	int v_step = 0;

	std::cin.clear();
	fflush(stdin);
	std::cin >> std::dec >> v_step;

	return v_step;
}

/**
 * Shows about text
 */
void ui_about() {
	ui_clear();
	ui_set_color( CONSOLE_COLOR_STD);
	std::cout << "VisaDevices CurveTracer" << std::endl;
	std::cout << "====================================" << std::endl;
	std::cout << "About" << std::endl;
    std::cout << std::endl;
	std::cout << "Version 0.1.0" << std::endl;
	std::cout << "Copyright (c) 2019-2023 Frank Zimdars" << std::endl;
	ui_set_color( CONSOLE_COLOR_STD);
    ui_wait_enter();
}

/**
 * Wait on enter on the keyboard
 */
void ui_wait_enter() {
    std::cout << std::endl << "Press <ENTER> key to continue...";
	std::cin.clear();
    std::cin.ignore(8000, '\n');
	while (std::cin.get() != '\n'){
    }
}