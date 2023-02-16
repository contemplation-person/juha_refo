#include <iostream>
#include <string>

int main() {
    std::string   str = "HI THIS IS BRAIN";
    std::string  *strptr = &str;
    std::string  &ref = str;

    std::cout << "str : " << str << std::endl;
    std::cout << "ptr : " << *strptr << std::endl;
    std::cout << "ref : " << ref << std::endl;

    std::cout << "str address : " << &str << std::endl;
    std::cout << "ptr address : " << strptr << std::endl;
    std::cout << "ref address : " << &ref << std::endl;
    return 0;
}
