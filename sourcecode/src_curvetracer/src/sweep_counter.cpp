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

#include "sweep_counter.h"

/**
 * configures the counter. When already configured existing data is deleted and arrays will be recreated.
 * @param _size Number of counters
 * @param _limits Limits of counters
 */
void SweepCounter::config(uint32_t _size, const uint32_t *_limits){

    if(this->isInit){
        delete this->counter;
        delete this->limits;
    }

    this->counter = new uint32_t[_size];
    this->limits = new uint32_t[_size];

    for(int i = 0; i < _size; i++){
        this->counter[i] = 0;
        this->limits[i] = _limits[i];
    }

    this->isInit = true;
    this->isFinished = false;
}

/**
 * Increases the counter value
 */
void SweepCounter::counter_increase(){
    for(int i = 0;i<this->size;i++){
        if(this->counter[i] > this->limits[i]){

            if(i >= this->size){
                this->isFinished = true;
            }else{
                this->counter[i+1]++;
            }
            this->counter[i] = 0;
        }
    }
}

/**
 * Resets the counter values
 */
void SweepCounter::counter_reset(){
    for(int i = 0;i<this->size;i++){
        this->counter[i] = 0;
    }
    this->isFinished = false;
}

/**
 * Return the value of a specific counter inside the position data
 * @param position Index for the position data
 * @return Counter value
 */
uint32_t SweepCounter::counter_getValue(uint32_t position){
    return this->counter[position];
}

/**
 * Returns the position data
 * @return Pointer to position array
 */
uint32_t* SweepCounter::counter_getValues(){
    return this->counter;
};

/**
 * Return if all possible combinations were done
 * @return true, when all reached
 */
bool SweepCounter::counter_isFinished() const{
    return this->isFinished;
}

/**
 * Specific constructor, directly initialize the class
 * @param size Length of the position data
 * @param limits Limits for individual position values
 */
SweepCounter::SweepCounter(uint32_t size, uint32_t *limits){
    this->config(size,limits);
}

/**
 * Deconstructor, deletes all arrays
 */
SweepCounter::~SweepCounter(){
    //delete arrays
    delete this->counter;
    delete this->limits;
}