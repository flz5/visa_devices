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

#ifndef VISADEVICES_SWEEP_COUNTER_H
#define VISADEVICES_SWEEP_COUNTER_H

#include <vector>
#include <cinttypes>

class SweepCounter {

private:
    /*
     * Member variables
     */
    uint32_t size{};
    //counter values (array)
    uint32_t *counter{};
    //counter limits (array)
    uint32_t *limits{};

public:
    bool isInit{};
    bool isFinished{};

    /**
     * configures the counter. When already configured existing data is deleted and arrays will be recreated.
     * @param _size Number of counters
     * @param _limits Limits of counters
     */
    void config(uint32_t _size, const uint32_t *limits);

    /**
     * Increases the counter value
     */
    void counter_increase();

    /**
     * Resets the counter values
     */
    void counter_reset();

    /**
     * Return the value of a specific counter inside the position data
     * @param position Index for the position data
     * @return Counter value
     */
    uint32_t counter_getValue(uint32_t position);

    /**
     * Returns the position data
     * @return Pointer to position array
     */
    uint32_t* counter_getValues();

    /**
     * Return if all possible combinations were done
     * @return true, when all reached
     */
    [[nodiscard]] bool counter_isFinished() const;

    /**
     * Specific constructor, directly initialize the class
     * @param size Length of the position data
     * @param limits Limits for individual position values
     */
    SweepCounter(uint32_t size, uint32_t *limits);

    /**
     * Deconstructor, deletes all arrays
     */
    ~SweepCounter();

};


#endif //VISADEVICES_SWEEP_COUNTER_H
