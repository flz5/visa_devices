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

/*
	Hilfunktionen zur dynamischen Speicherverwaltung

*/


template<typename T>
T*** mem_alloc_3d(int x, int y, int z) {

	T*** arr = new T** [x];

	for (int i = 0; i < x; i++) {
		arr[i] = new T* [y];

		for (int j = 0; j < z; j++) {
			arr[i][j] = new T [z];
		}
	}

	return arr;
}

template<typename T>
void mem_dealloc_3d(T*** ptr, int x, int y, int z) {

	for (int i = 0; i < x; i++) {

		for (int j = 0; j < y; j++) {
			delete[] ptr[i][j];
		}
		delete[] ptr[i];
	}
	delete[] ptr;
}