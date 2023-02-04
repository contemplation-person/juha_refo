#include <iostream>
#include <string>

int main(int c, char **v) {

    if (c == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::string str;
    for(int i = 1; i < c; i++){
        str = v[i];
        for(size_t j = 0; j < str.size(); j++) {
            std::cout << static_cast<char> (std::toupper(str[j]));
        }
    }
    std::cout << std::endl;
    return (0);
}

