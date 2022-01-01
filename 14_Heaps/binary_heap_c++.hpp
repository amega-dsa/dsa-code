#pragma once

#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T, typename C=std::greater<T>> // by default a max heap
class Heap
{
public:
	Heap() = default;
	~Heap() = default;
	void insert(T value);
	T top() const;
	void remove_top();
	template <typename _T, typename _C>
	friend std::ostream& operator<<(std::ostream &cout, const Heap<_T, _C> &_heap);
private:
	void switch_elements(size_t index1, size_t index2);
	void heapify(); // currently unused
	void sift_down(size_t index);
	void sift_up(size_t index);
	std::vector<T> container;
};

template <typename T, typename C>
void Heap<T, C>::insert(T value)
{
	container.push_back(value);
	sift_up(container.size() - 1);
}

template <typename T, typename C>
T Heap<T, C>::top() const
{
	try
	{
		if (container.empty())
			throw std::out_of_range("ERROR: The heap is empty!");
	}
	catch (const std::out_of_range &err)
	{
		std::cerr << err.what() << '\n';
	}
	
	return container[0];
}

template <typename T, typename C>
void Heap<T, C>::remove_top()
{
	try
	{
		if (container.empty())
			throw std::out_of_range("ERROR: The heap is empty! Cannot remove an element.");
	}
	catch (const std::out_of_range &err)
	{
		std::cerr << err.what() << '\n';
	}
	
	container.front() = container.back();
	container.pop_back();
	if (!container.empty())
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
void Heap<T, C>::switch_elements(size_t index1, size_t index2)
{
	T temp = container[index1];
	container[index1] = container[index2];
	container[index2] = temp;
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
void Heap<T, C>::sift_down(size_t index)
{
	C compare;
	size_t left_child_index = index * 2 + 1;
	size_t right_child_index = index * 2 + 2;
	size_t target_index = index;
	
	if (left_child_index < container.size() && compare(container[left_child_index], container[target_index]))
		target_index = left_child_index;
	
	if (right_child_index < container.size() && compare(container[right_child_index], container[target_index]))
		target_index = right_child_index;
	
	if (index != target_index)
	{
		switch_elements(target_index, index);
		sift_down(target_index);
	}
}

template <typename T, typename C>
void Heap<T, C>::sift_up(size_t index)
{
	if (index == 0)
		return;
	
	C compare;
	size_t parent_index = (index - 1) / 2;
	
	if (compare(container[index], container[parent_index]))
	{
		switch_elements(index, parent_index);
		sift_up(parent_index);
	}
}