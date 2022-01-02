#pragma once

#include "../14_Heaps/binary_heap_c++.hpp"

/**
 * Currently constrained to an underling max heap structure
 */
template <typename T>
class Priority_queue
{
public:
	// std::size_t size() const noexcept; <- needs size check in heap class
	// bool empty() const noexcept; <- needs empty check in heap class
	const T& top() const;
	void pop();
	void push(const T &value);
	template <typename _T>
	friend std::ostream& operator<<(std::ostream &cout, const Priority_queue<_T> &pq);
private:
	Max_heap<T> container;
};

template <typename T>
const T& Priority_queue<T>::top() const
{
	return container.top();
}

template <typename T>
void Priority_queue<T>::pop()
{
	container.pop();
}

template <typename T>
void Priority_queue<T>::push(const T &value)
{
	container.push(value);
}

template <typename T>
std::ostream& operator<<(std::ostream &cout, const Priority_queue<T> &pq)
{
	cout << pq.container;
	
	return cout;
}