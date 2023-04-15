#include "MyException.hpp"
MyException::MyException() {}
MyException::MyException(int line, std::string file, std::string massage)
    : _line(line), _file(file), _massage(massage)
{ }

void MyException::print() {
    std::cerr << "\033[31m" <<_file + " - " << _line << " : " + _massage << "\033[0m" << std::endl;
}

GradeTooHighException::GradeTooHighException() { }
GradeTooHighException::GradeTooHighException(int line, std::string file, std::string _name, int _grade)
{
    std::string massage = _name + ", bureaucrat grade " + std::to_string(_grade);
    MyException(line, file, massage);
}

GradeTooLowException::GradeTooLowException() { }
GradeTooLowException::GradeTooLowException(int line, std::string file, std::string _name, int _grade)
{
    std::string massage = _name + ", bureaucrat grade " + std::to_string(_grade);
    MyException(line, file, massage);
}
