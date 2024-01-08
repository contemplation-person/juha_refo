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

	// std::stack == std::deque<T>와 같으므로... 아래와 같이 줄일 수 있다.
	// 그러나 아래와 같이 타입을 설정하면 스택이라는 의미보다 덱이라는 의미가 강해지므로
	// 이렇게 사용하지 않지만, 이렇게 사용할 수 있다는 것을 알아두기 위해 적어보았다.

	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
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

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin()); }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (this->c.rend());
}

#endif
