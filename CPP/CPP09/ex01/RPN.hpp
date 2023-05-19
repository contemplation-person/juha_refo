#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <string>

class RPN {
public:
	RPN(std::string str);
	~RPN();

private:
	class RPNOutofException : public std::exception {
	public:
		RPNOutofException() throw();
		RPNOutofException(const RPNOutofException& rpn) throw();
		RPNOutofException& operator=(const RPNOutofException& rpn) throw();
		virtual ~RPNOutofException() throw();
		virtual const char* what() const throw();
	};
	RPN();
	RPN(const RPN& rpn);
	RPN& operator=(const RPN& rpn);

};

#endif