#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack<T> &stack);
	MutantStack<T> &operator=(const MutantStack<T> &stack);
	virtual ~MutantStack();
};

template <typename T>
MutantStack<T>::MutantStack() 
	: std::stack<T>()
{ }

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &stack)
	: std::stack<T>(stack)
{ }

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &stack)
{
	if (this != &stack)
		std::stack<T>::operator=(stack);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{ }

#endif