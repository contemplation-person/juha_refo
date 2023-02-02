#include <iostream>
/*
$>./megaphone "shhhhh... I think the students are asleep..."
    SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
    DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
    * LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
*/
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

