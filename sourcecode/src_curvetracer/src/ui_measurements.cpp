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
#include "ui_measurement.h"
#include "ui.h"

/**
 * Displays the interface to add a new measurement
 * @return measurement to add
 */
measurement_t ui_measurement_add() {

	ui_clear();
	ui_set_color( CONSOLE_COLOR_STD);
	std::cout << "VisaDevices CurveTracer" << std::endl;
	std::cout << "====================================" << std::endl;
    std::cout << std::endl;
	std::cout << "Measurement - Add" << std::endl;

	int v_step = 0;
	char mode;
	double val;
	std::string text;

	measurement_t mm;

	std::cout << "Device ID:";
	std::cin >> v_step;
	mm.device = v_step;

	std::cout << "Device Channel:";
	std::cin >> v_step;
	mm.channel = v_step;

	std::cout << "Device Mode:";
	std::cin >> mode;
	mm.mode = static_cast<unsigned char >(mode);

	std::cout << "Filename:";
	std::cin >> text;
	mm.filename = text;

	return mm;
}

/**
 * Shows a list of measurements
 * @param data List of devices
 */
void ui_measurement_list(std::vector<measurement_t> data) {
	ui_clear();
	ui_set_color( CONSOLE_COLOR_STD);
	std::cout << "VisaDevices CurveTracer" << std::endl;
	std::cout << "====================================" << std::endl;
    std::cout << std::endl;
	std::cout << "Measurement - List" << std::endl;
    std::cout << std::endl;
	std::cout << "Index\tDevice\tChannel\tMode\tFilename" << std::endl;

	for (int i = 0; i < data.size(); i++) {
		std::cout << i << "\t";
		std::cout << data[i].device << "\t" << data[i].channel << "\t" << data[i].mode << "\t";
		std::cout << data[i].filename;
		std::cout << std::endl;
	}

	std::cout << std::endl;
	ui_set_color( CONSOLE_COLOR_STD);
	ui_wait_enter();
}

/**
 * Shows user interface to delete a measurement from the given list
 * @param data List to modify
 */
void ui_measurement_remove(std::vector<measurement_t> &data) {
	ui_clear();
	ui_set_color( CONSOLE_COLOR_STD);
	std::cout << "VisaDevices CurveTracer" << std::endl;
	std::cout << "====================================" << std::endl;
    std::cout << std::endl;
	std::cout << "Measurement - Remove" << std::endl;
    std::cout << std::endl;

	std::cout << "Index to remove:";
	int ind;
	std::cin >> ind;

    if(ind >= 0 && ind < data.size()){
        data.erase(data.begin() + ind);
    }
}