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

#include "measurement_array.h"
#include "sweep.h"
#include "sweep_counter.h"
#include <iostream>
#include <fstream>
#include <vector>

/**
 * Default constructor, used for array based initialisation
 */
MeasurementArray::MeasurementArray()= default;

/**
 * Constructor
 * @param _size Length of position data
 * @param limits Limits of position data
 */
MeasurementArray::MeasurementArray(uint32_t _size, uint32_t *limits) {
    this->init(_size,limits);
}

/**
 * Configures the array, if already configured existing data is deleted
 * and arrays will be recreated
 * @param _size
 * @param limits
 */
void MeasurementArray::init(uint32_t _size, uint32_t *limits) {

	//Dealloc when size was already set (=> allocated memory)
	if (this->size != 0) {
        delete[] this->array_value;
        delete[] this->array_title;
        delete[] this->array_limits;
	}

	//Copy size
	this->size = _size;

    uint32_t arrsize = this->buildSize(limits,_size);
    this->array_value = new double[arrsize];

    this->array_limits = new uint32_t[_size];
    for (int i = 0; i < this->size; i++) {
        array_limits[i] = limits[i];
    }

    this->array_title = new std::string[this->size];
    for (int i = 0; i < this->size; i++) {
        array_title[i] = "?";
    }

}

 /**
  * Sets the array_title for column (n)
  * @param n
  * @param title
  */
void MeasurementArray::set_title(int n, std::string title) {
	this->array_title[n] = title;
}

/**
 * Inserts data at the given position
 * @param position Position (array)
 * @param data Data to store
 */
void MeasurementArray::insert(uint32_t *position, double data){
    //TODO: Check if offset is valid for the array
    uint32_t offset = this->buildIndex(position);
    array_value[offset] = data;
}

/**
 * Return the length of the used position array
 * @return Count in Elements
 */
uint32_t MeasurementArray::getPositionLength() const{
    return this->size;
}

/**
 * Sets the device sweep data
 * @param val Vector of sweep configurates
 */
void MeasurementArray::setDeviceSweep(std::vector<Sweep> &val){
    this->sweeps = val;
}

/**
 * Calculated the index for the storage array, based on the position data
 * @param position Positon
 * @return Index to array elements
 */
uint32_t MeasurementArray::buildIndex(const uint32_t *position){

    uint32_t index = 0;

    index += position[0];
    uint32_t mm = 1;

    for(int i = 1;i<this->size;i++){
        mm *= this->array_limits[i-1];
        index += position[i] * mm;
    }

    return index;
}

/**
 * Calculates the required size for the array to store all values,
 * based on the possible positions
 * @param limits Position, limits of counters
 * @param _size Position, number of counter
 * @return Size (in Elements)
 */
uint32_t MeasurementArray::buildSize(const uint32_t *limits, uint32_t _size){
    uint32_t asize = 1;

    for(uint32_t i = 0; i < _size; i++){
        asize *= limits[i];
    }
    return asize;
}

/**
 * Check given position
 * @param position Position
 * @return true when valid
 */
bool MeasurementArray::isValid(const uint32_t *position){
    bool isOk = true;

    for(int i = 0 ;i< this->size;i++){
        if(position[i] > this->array_limits[i]){
            isOk = false;
        }
    }
    return isOk;
}

/**
 * Writes the stored data to a csv file
 * @param filename Filename/Path of the file
 */
void MeasurementArray::write_to_file(const std::string& filename) {

	int *pos_copy = new int[this->size];

	for (int i = 0; i < this->size; i++) {
		pos_copy[i] = 0;
	}

    SweepCounter kk(this->size,this->array_limits);
    kk.counter_reset();


	std::ofstream outputFile(filename + ".txt");

    //write title line
    outputFile << "Measured;";
	for (int i = 0; i < this->size; i++) {
		if (i != this->size - 1) {
			outputFile << array_title[i] << ";";
		}
		else {
			outputFile << array_title[i] << std::endl;
		}
	}

    while(!kk.isFinished){
        uint32_t *cv = kk.counter_getValues();
        uint32_t addr = this->buildIndex(cv);

        outputFile << array_value[addr] << ";";

        for (int i = 0; i < this->size; i++) {
            if (i != this->size - 1) {
                outputFile << cv[i] << ";";;
            }
            else {
                outputFile << cv[i] << std::endl;
            }
        }
        kk.counter_increase();
    }

	outputFile.flush();
	outputFile.close();
}

/**
 * Destructor, deletes arrays
 */
MeasurementArray::~MeasurementArray() {
    delete[] this->array_value;
    delete[] this->array_title;
    delete[] this->array_limits;
}
