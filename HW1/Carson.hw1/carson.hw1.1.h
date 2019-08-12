#ifndef QUEUE_H
#define QUEUE_H
#include <vector>
#include <iostream>
#include <math.h>

template <class T>
class tqueue
{
public:
	tqueue();
	void push(T num);
	void pop();
	T front();
	bool empty();
	int size();
private:
	std::vector<T> _v;
	std::size_t _size;
	std::size_t _front;
};


template <class T>
tqueue<T>::tqueue()
{
	_size = 0;
	_front = 0;
	_v.resize(8);
}

template <class T>
void tqueue<T>::push(T num)
{
	if(_size == 0)
	{
		_v[_front] = num;
		_size++;
	}
	else if(_size == 1)
	{
		_v[(_front + 1) % _v.size()] = num;
		_size++;
	}
	else if(_size > 1 && _size < _v.size())
	{
		int nextIndex = ((_front + _size) % _v.size());
		_v[nextIndex] = num;
		_size++;
	}
	else 
	{
		std::size_t osize = _size;
		_v.resize(_v.size() * 2);
		// std::size_t index = 0;
		for(std::size_t i = 0; i < _front; ++i)
		{
			_v[((osize + i) % _v.size())] = _v[i];
		}
		_v[(_front + (_size)) % _v.size()] = num;
		_size++;
	}

}

template <class T>
void tqueue<T>::pop()
{
	
	if(_size > 0)
	{
		_front = (_front + 1) % _v.size();
		_size--;
	}
	else return;
}

template <class T>
T tqueue<T>::front()
{
	return _v[_front];
}

template <class T>
bool tqueue<T>::empty()
{
	if(_size == 0)
	{
		return true;
	}
	else return false;
}

template <class T>
int tqueue<T>::size()
{
	return _size;
}


#endif