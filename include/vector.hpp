#pragma once
#include <iostream>
// EX0 implementation header
class Vector
{
public:
	Vector(std::size_t capacity, int data);
	~Vector();
	std::size_t size();
	int* data();
	int& at(size_t i);
	int sum();
	Vector(const Vector& v);
	void operator=(const Vector& v);

	int* p;
	std::size_t capacity;
	typedef int value_type;
};
