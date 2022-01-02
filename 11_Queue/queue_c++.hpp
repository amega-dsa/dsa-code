#pragma once

#include <cstddef>
#include <iostream>
#include <list>
#include <stdexcept>

template <typename T>
class Queue
{
public:
	std::size_t size() const noexcept;
	bool empty() const noexcept;
	const T& front() const;
	const T& back() const;
	void pop();
	void push(const T &value);
	template <typename _T>
	friend std::ostream& operator<<(std::ostream &cout, const Queue<_T> &_queue);
private:
	std::list<T> container;
};

template <typename T>
std::size_t Queue<T>::size() const noexcept
{
	return container.size();
}

template <typename T>
bool Queue<T>::empty() const noexcept
{
	return container.empty();
}

template <typename T>
const T& Queue<T>::front() const
{
	if (empty())
		throw std::out_of_range("ERROR! The queue is empty!");
	
	return container.front();
}

template <typename T>
const T& Queue<T>::back() const
{
	if (empty())
		throw std::out_of_range("ERROR! The queue is empty!");
	
	return container.back();
}

template <typename T>
void Queue<T>::pop()
{
	if (container.empty())
		throw std::out_of_range("ERROR! The queue is empty!");
	
	container.pop_front();
}

template <typename T>
void Queue<T>::push(const T &value)
{
	container.push_back(value);
}

template <typename T>
std::ostream& operator<<(std::ostream &cout, const Queue<T> &_queue)
{
	for (const T &elem : _queue.container)
		cout << elem << ' ';
	
	return cout;
}