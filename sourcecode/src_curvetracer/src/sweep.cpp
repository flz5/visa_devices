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

#include "sweep.h"

/**
 * Calculated the required steps to changing the value
 * @return Required steps
 */
uint32_t Sweep::calcSteps() const{
    double diff = this->value_stop - this->value_start;
    return static_cast<uint32_t>(diff/this->value_step);
}

/**
 * Calculates the value for a concrete step
 * @param index Number of the step
 * @return Calculated value
 */
uint32_t Sweep::calcValue(uint32_t index) const{
    return static_cast<uint32_t>(this->value_start + (index*this->value_step));
}

/**
 * Default constructor
 */
Sweep::Sweep()= default;

/**
 * Default deconstructor
 */
Sweep::~Sweep()= default;