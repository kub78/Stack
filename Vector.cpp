#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include "Vector.h"

VectorStack::VectorStack(const VectorStack& other) {
	_size = other._size;
	_capacity = other._capacity;
	_multiplicativeCoef = other._multiplicativeCoef;
	if (_capacity > _size * _multiplicativeCoef) {
		_capacity = _size * _multiplicativeCoef;
	}
	_data = new Value[_capacity];
	memcpy(_data, other._data, sizeof(Value) * _size);
}
VectorStack::~VectorStack()
{
	delete [] _data;
}

void VectorStack::AddMem() {
	if (_size >= _capacity) {
		if (_capacity == 0) {
			_capacity = 1;
		}
		_capacity = _capacity * _multiplicativeCoef;
		Value* tmp_mem = new Value[_size];
		memcpy(tmp_mem, _data, _size * sizeof(Value));
		_data = new Value[_capacity];
		memcpy(_data, tmp_mem, _size * sizeof(Value));
		delete[] tmp_mem;
	}
}

void VectorStack::push(const Value& value) {
	if (_data == nullptr) {
		_size = 1;
		_capacity = 1 * _multiplicativeCoef;
		_data = new Value[_capacity];
		_data[0] = value;
	}
	else {
		AddMem();
		_data[_size] = value;
		_size++;
	}
}

void VectorStack::pop() {
	if (_size == 0 || _data == nullptr) {
		throw _size;
	}
	_size--;
}

const ValueType &VectorStack::top() const { 
	return _data[_size - 1]; 
}

bool VectorStack::isEmpty() const {
    if (_size == 0) {
      return true;
    } 
  else {
      return false;
    }
}

size_t VectorStack::size() const { 
	return _size; 
}