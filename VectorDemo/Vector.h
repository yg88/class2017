#pragma once
#include <cassert>
#include <iostream>

class Vector
{
public:
// 	Vector() :
// 		_data{new int[2]},
// 		_capacity{2},
// 		_size{0}
// 	{
// 	}

	Vector(size_t size = 2) :
		_data{new int[size]},
		_capacity{size},
		_size{size}
	{

	}

	Vector(Vector&& source) :
		_data{source._data},
		_capacity{ source._capacity },
		_size{ source._size }
	{
		source._data = nullptr;
		source._size = 0;
		source._capacity = 0;
	}

	Vector(const Vector& source) :
		_data{new int[source._capacity]},
		_capacity{source._capacity},
		_size{source._size}
	{
		memcpy(_data, source._data, _size * sizeof(int));
	}

	~Vector() 
	{
		if (_data != nullptr)
			delete[]_data;
	}

	void push_back(int value)
	{
		if (_capacity == _size)
		{
			int * temp = new int[_capacity * 2];
			_capacity *= 2;
			memcpy(temp, _data, _size * sizeof(int));
			delete[]_data;
			_data = temp;
		}

		_data[_size++] = value;
	}

	int at(size_t index)
	{
		assert(index < _size && "index should be less than _size");

		return _data[index];
	}

	int& operator[] (size_t index) const
	{
		assert(index < _size && "index should be less than _size");

		return _data[index];
	}

	const Vector& operator = (Vector&& rhs)
	{
		_data = rhs._data;
		_capacity = rhs._capacity;
		_size = rhs._size;

		rhs._data = nullptr;
		rhs._size = 0;
		rhs._capacity = 0;
	}

	const Vector& operator = (const Vector& rhs)
	{
		if (&rhs == this)
			return *this;

		_size = rhs._size;
		_capacity = rhs._capacity;
		delete[]_data;

// 		if (_capacity < rhs._capacity)
// 		{
// 			_capacity = rhs._capacity;
// 			delete[]_data;
// 			_data = new int[_capacity];
// 		}
		_data = new int[_capacity];
		memcpy(_data, rhs._data, rhs._size * sizeof(int));

		return *this;
	}

	size_t size() const
	{
		return _size;
	}

private:
	int * _data;
	size_t _capacity;
	size_t _size;
};

std::ostream& operator << (std::ostream& output, const Vector& v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << "\t";
	}

	return output;
}

