#include <iostream>
#include <string>
#include <initializer_list>
template <typename T>

class MyVector
{
private:
	T* data;
	size_t _size;
	size_t capacity;

	void resize(size_t newCapacity)
	{
		T* new_data = new T[newCapacity];
		for(size_t i=0; i<_size ; i++)
		{
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
		capacity = newCapacity;
	}

public:
	MyVector() : data(nullptr),_size(0),capacity(0) {} //default constructor

	MyVector(size_t n)  //constructor having fix size after it can be increase
	{
		_size = n;
		capacity = n;
		data = new T[capacity];
	}

    MyVector(std::initializer_list<T> initlist) //initializer list directly pass
	{
        _size = 0;
        capacity = initlist.size();
        data = new T[capacity];

        for (const T& val : initlist) 
		{
            data[_size++] = val;
        }
    }
	
	~MyVector()
	{
		delete[] data;
		_size = 0;
		capacity = 0;
	}

	void push_back(const T& value)
	{
		if(_size == capacity)
		{
			size_t newcapacity = (capacity==0)?1:capacity*2;
			resize(newcapacity);
		}
		data[_size++] = value;
	}
	
	void pop_back()
	{
		if(_size>0)
			_size--;
	}

	size_t size() const
	{
		return _size;
	}

	size_t Capacity() const
	{
		return capacity;
	}

	bool empty() const
	{
		int i = 0;
		return _size == 0;
	}

	T& operator[] (size_t index)
	{
		if(index >= _size)
			throw std::out_of_range("Index out of range");

		return data[index];
	}
	const T& operator[] (size_t index) const
	{
		if(index >= _size)
			throw std::out_of_range("Index out of range");

		return data[index];
	}

	T* begin() 
	{ 
		return data; 
	}

    T* end() 
	{ 
		return data + _size; 
	}

    const T* begin() const 
	{ 
		return data; 
	}

    const T* end() const 
	{ 
		return data + _size; 
	}
};

int main()
{

	MyVector<int> ivtr = {1,2,3,4,5};
	

	for(int k : ivtr)
	{
		std::cout<<k<<std::endl;
	}

	return 0;
}
