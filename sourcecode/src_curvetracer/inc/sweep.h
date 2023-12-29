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

#ifndef CURVETRACER_SWEEP_H
#define CURVETRACER_SWEEP_H

#include <cinttypes>

class Sweep {

public:
    /*
     * Member variables
     */
	int device_index{};

	double value_start{};
	double value_stop{};
	double value_step{};

	int channel{};
	char mode{};

    /**
     * Calculated the required steps to changing the value
     * @return Required steps
     */
    [[nodiscard]] uint32_t calcSteps() const;

    /**
     * Calculates the value for a concrete step
     * @param index Number of the step
     * @return Calculated value
     */
    [[nodiscard]] uint32_t calcValue(uint32_t index) const;

    /**
     * Default constructor
     */
    Sweep();

    /**
     * Default deconstructor
     */
    ~Sweep();

};

#endif