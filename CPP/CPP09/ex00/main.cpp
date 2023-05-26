#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) 
{
   switch (argc)
   {
   case 3:
   {
      //argv[1] == filename.csv argv[2] == filename2.txt
      if (Function::validArgv(argv + 1))
         BitcoinExchange exchange(argv[1]);
      return 0;
   }
   default:
      std::cout << "invaild " << std::endl;
      std::cout << "usage: ./ex00 [filename].csv [filename2].txt" << std::endl;
      return 0;
   }
}