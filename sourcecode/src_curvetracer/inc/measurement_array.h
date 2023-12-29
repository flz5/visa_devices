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

#ifndef CURVETRACER_MEASUREMENT_ARRAY_H
#define CURVETRACER_MEASUREMENT_ARRAY_H

#include <string>
#include <cinttypes>
#include "sweep.h"
#include <vector>

class MeasurementArray {

public:
    /**
     * Default constructor, used for array based initialisation
     */
    MeasurementArray();

    /**
     * Constructor
     * @param _size Length of position data
     * @param limits Limits of position data
     */
	MeasurementArray(uint32_t _size, uint32_t *limits);

    /**
     * Destructor, deletes arrays
     */
    ~MeasurementArray();

    /**
     * Configures the array, if already configured existing data is deleted
     * and arrays will be recreated
     * @param _size
     * @param limits
     */
    void init(uint32_t _size, uint32_t *limits);

    /**
     * Sets the array_title for column (n)
     * @param n
     * @param title
     */
	void set_title(int n, std::string title);

    /**
     * Inserts data at the given position
     * @param position Position (array)
     * @param data Data to store
     */
	void insert(uint32_t *position, double data);

    /**
     * Check given position
     * @param position Position
     * @return true when valid
     */
    bool isValid(const uint32_t *position);

    /**
     * Writes the stored data to a csv file
     * @param filename Filename/Path of the file
     */
	void write_to_file(const std::string& filename);

    /**
     * Sets the device sweep data
     * @param val Vector of sweep configurates
     */
    void setDeviceSweep(std::vector<Sweep> &val);

    /**
     * Return the length of the used position array
     * @return Count in Elements
     */
    [[nodiscard]] uint32_t getPositionLength() const;

private:

    /*
     * Member variables
     */
	int size = 0;

    uint32_t* array_limits = nullptr;
    double *array_value = nullptr;
	std::string* array_title = nullptr;

    std::vector<Sweep> sweeps;

    /**
     * Calculated the index for the storage array, based on the position data
     * @param position Positon
     * @return Index to array elements
     */
    uint32_t buildIndex(const uint32_t *position);

    /**
     * Calculates the required size for the array to store all values,
     * based on the possible positions
     * @param limits Position, limits of counters
     * @param _size Position, number of counter
     * @return Size (in Elements)
     */
    static uint32_t buildSize(const uint32_t *limits, uint32_t _size);

};

#endif