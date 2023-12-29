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
#include <vector>
#include <string>

#include "system/VisaSession.h"
#include "struct_measurement.h"
#include "struct_device.h"
#include "sweep.h"
#include "ui.h"
#include "ui_sweep.h"
#include "ui_measurement.h"
#include "ui_devices.h"
#include "ui_files.h"
#include "controller.h"

/**
 * Main function
 * @return
 */
int main()
{
	VisaSession* session = visa_session_open();
	system("title CurveTracer");

	std::vector<Sweep> list_sweep;
	std::vector<measurement_t> list_measurements;
	std::vector<device_t> list_devices;

	std::string message;
	std::string result_folder;

	bool active = true;

	while (active) {

		int nn = ui_menu(message.c_str());

		switch (nn) {
		case 1: {
			list_devices.push_back(ui_device_add());
			message = "";
		}break;
		case 2: {
			ui_device_list(list_devices);
			message = "";
		}break;
		case 3: {
			ui_device_remove(list_devices);
			message = "";
		}break;
		case 4: {
			list_sweep.push_back(ui_sweep_add());
			message = "";
		}break;
		case 5: {
			ui_sweep_list(list_sweep);
			message = "";
		}break;
		case 6: {
			ui_sweep_remove(list_sweep);
			message = "";
		}break;
		case 7: {
			list_measurements.push_back(ui_measurement_add());
			message = "";
		}break;
		case 8: {
			ui_measurement_list(list_measurements);
			message = "";
		}break;
		case 9: {
			ui_measurement_remove(list_measurements);
			message = "";
		}break;
		case 10: {
			result_folder = ui_folder_get();
		}break;
		case 11: {
			controller_start(session, list_devices, list_measurements, list_sweep, result_folder);
            ui_wait_enter();
		}break;
		case 12:
		{
			ui_about();
			message = "";
		}break;
		case 99:
		{
			active = false;
		}break;
		default: {
			message = "Command (" + std::to_string(nn) + ") not found!";
		}
		}
	}
}
