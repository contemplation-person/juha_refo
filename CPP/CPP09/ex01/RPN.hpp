#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <exception>

class RPN {
public:
	RPN(const char *str);
	~RPN();

private:
	RPN();
	RPN(const RPN& rpn);
	RPN& operator=(const RPN& rpn);

	const char* _str;

	class OutofRange: public std::exception 
	{
	public:
		virtual const char* what() const throw();
	};


	class BadInput: public std::exception 
	{
	public:
		virtual const char* what() const throw();
	};

	class DividZero: public std::exception 
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif