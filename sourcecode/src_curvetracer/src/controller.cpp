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

#include "controller.h"
#include "controller_connect.h"
#include "controller_measurements.h"
#include "controller_sweeps.h"
#include "sweep_counter.h"

/*
 * Configuration of the state
 */
static std::vector<device_t> vector_devices;
static std::vector<measurement_t> vector_measurement;
static std::vector<Sweep> vector_steps;
static MeasurementArray* vector_results;
static std::string folder;

/**
 * Starts an automatic sweep and measurement cycle
 * @param session Visa Session
 * @param devices Vector of devices
 * @param measurement Vector os Measurements
 * @param step  Vector of sweeps
 * @param folder Path to a folder where the results will be stored
 */
void controller_start(VisaSession *session, std::vector<device_t> devices, std::vector<measurement_t> measurement,
                      std::vector<Sweep> step, const std::string& _folder) {
	
	vector_devices = devices;
    vector_measurement = measurement;
	vector_steps = step;

	bool error = false;

    //Check if lists are empty
	if (vector_devices.empty()) {
		printf("ERROR: No devices in list!");
		error = true;
	}
	if (vector_measurement.empty()) {
		printf("ERROR: No measurements in list!");
		error = true;
	}
	if (vector_steps.empty()) {
		printf("ERROR: No steps in list!");
		error = true;
	}

    if(!controller_check_measurements(devices, measurement)){
        printf("ERROR: Measurement list invalid!");
        error = true;
    }

    if(!controller_check_sweep(devices, step)){
        printf("ERROR: Sweep list invalid!");
        error = true;
    }

    /*
     * block start when error found
     */
	if(error){
		return;
	}

    /*
     * Calculate the required steps for each sweep
     */
    auto *limits = new uint32_t[vector_steps.size()];
    for(uint32_t i = 0;i< vector_steps.size();i++){
        limits[i] = vector_steps[i].calcSteps();
    }

    /*
     * Create sweep counter to manage the state of the different sweeps
     */
    SweepCounter counter(vector_steps.size(),limits);

    /*
     * create measurement arrays for each measurement in vector
     */
    uint32_t measurement_count = vector_measurement.size();
    vector_results = new MeasurementArray[measurement_count];
    for(uint32_t i=0;i< measurement_count;i++){
        vector_results[i] = MeasurementArray(vector_steps.size(), limits);
    }

    /*
     * Connect to all devices
     */
	controller_connect(session, devices);

    /*
     * Loop until all combination of sweeps are done
     */
    while(counter.counter_isFinished()){

        /*
         * Set all devices to the sweep value
         */
        for (uint32_t i = 0; i < vector_steps.size(); i++) {
            controller_set_step(vector_devices[vector_steps[i].device_index],
                                vector_steps[i].channel,
                                vector_steps[i].calcValue(counter.counter_getValue(i)),
                                vector_steps[i].mode);
        }

        /*
         * start measuring for all devices
         */
        for (uint32_t i = 0; i < vector_measurement.size(); i++) {
            controller_measure(vector_devices, vector_measurement[i], vector_results[i], folder,
                               counter.counter_getValues(),i);
        }

        /*
         * Generate next combination of sweep values
         */
        counter.counter_increase();
    }

    /*
     * Disconnect from all devices
     */
    controller_disconnect(devices);

    /*
     * write data from measurement array into files
     */
	for (uint32_t i = 0; i < vector_measurement.size(); i++) {
		std::string filename = _folder + "\\result_" + std::to_string(i) + ".txt";
		vector_results[i].write_to_file(filename);
	}

    /*
     * clean up
     */
	delete[] vector_results;
}

/**
 * Checks if the data in the measurement vector is correct
 * @param devices Vector of devices
 * @param measurement Vector of measurements
 * @return true if no error was found
 */
bool controller_check_measurements(std::vector<device_t> &devices, std::vector<measurement_t> &measurement){
    bool isOK = true;

    //Check if an invalid device is used
    for (uint32_t i = 0; i < vector_measurement.size(); i++) {
        if(measurement[i].device > devices.size()){
            isOK = false;
        }
    }

    return isOK;
}

/**
 * Checks if the data in the sweep vector is correct
 * @param devices Vector of devices
 * @param sweep Vector of sweeps (to check)
 * @return true if no error was found
 */
bool controller_check_sweep(std::vector<device_t> &devices, std::vector<Sweep> &sweep){
    bool isOK = true;

    for (uint32_t i = 0; i < vector_measurement.size(); i++) {
        //Check if an invalid device is used
        if(sweep[i].device_index > devices.size()){
            isOK = false;
        }
        //Check if range is valid
        if(sweep[i].value_step > 0){
            if(sweep[i].value_stop < sweep[i].value_start){
                isOK = false;
            }
        }else{
            if(sweep[i].value_stop > sweep[i].value_start){
                isOK = false;
            }
        }
    }

    return isOK;
}
