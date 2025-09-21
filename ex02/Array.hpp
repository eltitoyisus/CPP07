/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:46:57 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/31 23:46:57 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	public:
		Array() { // empty array
			_size = 0;
			_arr = new T[_size];
		}
		Array(unsigned int n) { // array of n element
			_size = n;
			_arr = new T[_size];
		}
		Array(const Array& other) { // it musnt affect the array
			_size = other._size;
			_arr = new T[_size];
			for (unsigned int i = 0; i < _size; i++) {
				_arr[i] = other._arr[i];
			}
		}
		Array& operator=(const Array& other) { // it musnt modify the array
			if (this != &other) {
				delete[] _arr;
				_size = other._size;
				_arr = new T[_size];
				for (unsigned int i = 0; i < _size; i++) {
					_arr[i] = other._arr[i];
				}
			}
			return *this;
		}
		~Array() {
			delete[] _arr;
		}
		// member function size returns number of elements on the array.
		// takes no params and doesnt modify
		T& operator[](unsigned int idx) {
			if (idx >= _size)
				throw std::out_of_range("Index out of bounds");
			return _arr[idx];
		}

		const T& operator[](unsigned int idx) const {
			if (idx >= _size)
				throw std::out_of_range("Index out of bounds");
			return _arr[idx];
		}

		unsigned int size() const {
			return _size;
		}
	private:
		T* _arr;
		unsigned int _size;
};

#endif
