#include <cstdlib>
#include <iostream>
using namespace std;

int main(int a, char **str)
{
    char * p_end;
    if (a < 2) 
    {
        cout << "인자 넣어줘요" << endl;
        return 0;
    }
    for (int i = 1; i < a; i++)
    {
        cout << "--------------------------------------------------------------" << std::endl
             << "origin str" << "\t: " << str[i] << std::endl
             << "double value" << i << "\t: " << strtod(str[i], &p_end) << endl
             << ". value" << i << "\t: " << p_end << endl
             << "point value" << i << "\t: " << (*p_end == '\0' ? "\\0" : p_end) << endl;
    }
    cout << static_cast<char>(strtod(str[0],NULL)) << "<~" << endl;
    return 0;
}
