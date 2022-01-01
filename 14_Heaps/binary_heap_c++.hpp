/**
 * Received help from:
 * https://codereview.stackexchange.com/questions/272496/binary-heap-structure-class-c/272523#272523
 */

#pragma once

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T, typename C>
class Heap
{
public:
	void push(const T &value);
	T top() const;
	void pop();
	template <typename _T, typename _C>
	friend std::ostream& operator<<(std::ostream &cout, const Heap<_T, _C> &_heap);
protected:
	void heapify(); // currently unused
	void sift_down(std::size_t index);
	void sift_up(std::size_t index);
	std::vector<T> container;
};

template <typename T>
class Max_heap : public Heap<T, std::greater<T>> {};

template <typename T>
class Min_heap : public Heap<T, std::less<T>> {};

template <typename T, typename C>
void Heap<T, C>::push(const T &value)
{
	container.push_back(value);
	sift_up(container.size() - 1);
}

template <typename T, typename C>
T Heap<T, C>::top() const
{
	if (container.empty())
		throw std::out_of_range("ERROR: The heap is empty!");
	
	return container[0];
}

template <typename T, typename C>
void Heap<T, C>::pop()
{
	if (container.empty())
		throw std::out_of_range("ERROR: The heap is empty! Cannot remove an element.");
	
	container.front() = container.back();
	container.pop_back();
	sift_down(0);
}

template <typename T, typename C>
std::ostream& operator<<(std::ostream &cout, const Heap<T, C> &_heap)
{
	for (const T &elem : _heap.container)
		cout << elem << ' ';
	
	return cout;
}

template <typename T, typename C>
void Heap<T, C>::heapify()
{
	if (container.empty())
		return;
	
	for (int i = container.length() / 2; i >= 0; --i)
		sift_down(i);
}

template <typename T, typename C>
void Heap<T, C>::sift_down(std::size_t index)
{
	C comparator;
	std::size_t left_child_index = index * 2 + 1;
	std::size_t right_child_index = index * 2 + 2;
	std::size_t target_index = index;
	
	if (left_child_index < container.size() && comparator(container[left_child_index], container[target_index]))
		target_index = left_child_index;
	
	if (right_child_index < container.size() && comparator(container[right_child_index], container[target_index]))
		target_index = right_child_index;
	
	if (index != target_index)
	{
		std::swap(container[target_index], container[index]);
		sift_down(target_index);
	}
}

template <typename T, typename C>
void Heap<T, C>::sift_up(std::size_t index)
{
	if (index == 0)
		return;
	
	C comparator;
	std::size_t parent_index = (index - 1) / 2;
	
	if (comparator(container[index], container[parent_index]))
	{
		std::swap(container[index], container[parent_index]);
		sift_up(parent_index);
	}
}