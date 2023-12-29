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

#include <iostream>
#include "ui_sweep.h"
#include "ui.h"

/**
 * Displays the interface to add a new sweep
 * @return sweep to add
 */
Sweep ui_sweep_add() {

	ui_clear();
	ui_set_color( CONSOLE_COLOR_STD);
	std::cout << "VisaDevices CurveTracer" << std::endl;
	std::cout << "====================================" << std::endl;
    std::cout << std::endl;
	std::cout << "Sweep - Add" << std::endl;

	int v_step = 0;
	char mode;
	double val;

    Sweep item;

	std::cout << "Device ID:";
	std::cin >> v_step;
	item.device_index = v_step;

	std::cout << "Device Channel:";
	std::cin >> v_step;
	item.channel = v_step;

	std::cout << "Device Mode:";
	std::cin >> mode;
	item.mode = mode;

	std::cout << "Value Start:";
	std::cin >> val;
	item.value_start = val;

	std::cout << "Value Inc.:";
	std::cin >> val;
	item.value_step = val;

	std::cout << "Value Stop:";
	std::cin >> val;
	item.value_stop = val;

	return item;
}

/**
 * Shows a list of sweeps
 * @param list List of sweeps
 */
void ui_sweep_list(std::vector<Sweep> list) {

	ui_clear();
	ui_set_color( CONSOLE_COLOR_STD);
	std::cout << "VisaDevices CurveTracer" << std::endl;
	std::cout << "====================================" << std::endl;
    std::cout << std::endl;
	std::cout << "Sweep - List" << std::endl;
    std::cout << std::endl;

	std::cout << "Index\tDevice\tChannel\tMode\tStart\tInc\tStop" << std::endl;

	for (int i = 0; i < list.size(); i++) {
		std::cout << i << "\t";
		std::cout << list[i].device_index << "\t" << list[i].channel << "\t" << list[i].mode << "\t";
		std::cout << list[i].value_start << "\t" << list[i].value_step << "\t" << list[i].value_stop;
		std::cout << std::endl;
	}

	std::cout << std::endl;
	ui_set_color( CONSOLE_COLOR_STD);
	ui_wait_enter();
}

/**
 * Shows user interface to delete a sweep from the given list
 * @param list List to modify
 */
void ui_sweep_remove(std::vector<Sweep> &list) {
	ui_clear();
	ui_set_color( CONSOLE_COLOR_STD);
	std::cout << "VisaDevices CurveTracer" << std::endl;
	std::cout << "====================================" << std::endl;
    std::cout << std::endl;
	std::cout << "Sweep - Remove";

	std::cout << "Index to remove:" << std::endl;
    std::cout << std::endl;
	int ind;
	std::cin >> ind;

    if(ind >= 0 && ind < list.size()){
        list.erase(list.begin() + ind);
    }
}
