#include <vector.hpp>
#include <string.h>
// EX0 implementation source

Vector::Vector(std::size_t capacity, int data)
{
	this->capacity = capacity;
	this->p = new int[capacity];
	for (std::size_t i = 0; i < this->capacity; i++)
	{
		this->p[i] = data;
	}
}

Vector::~Vector()
{
	if (p != nullptr)
	{
		delete[] p;
	}
}


std::size_t Vector::size()
{
	return this->capacity;
}

int& Vector::at(size_t i)
{
	return p[i];
}


int* Vector::data()
{
	return this->p;
}


int Vector::sum()
{
	int sum = 0;
	for (std::size_t i = 0; i < this->capacity; i++)
	{
		sum += this->p[i];
	}
	return sum;
}

Vector::Vector(const Vector& v)
{
	this->capacity = v.capacity;
	this->p = new int[this->capacity];
	memcpy(this->p,v.p,this->capacity*sizeof(int));
}

void Vector::operator=(const Vector& v)
{
	if(this->p != nullptr)
	{
		delete[] this->p;
		this->capacity = 0;
		this->p = nullptr;
	}
	this->capacity = v.capacity;
	this->p = new int[this->capacity];
	memcpy(this->p,v.p,this->capacity*sizeof(int));
}





