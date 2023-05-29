#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) 
{
   switch (argc)
   {
   case 2:
   {
      BitcoinExchange exchange(argv[1]);
      return 0;
   }
   case 3:
   {
      //argv[1] == filename.csv argv[2] == filename2.txt
      BitcoinExchange exchange(argv[1], argv[2]);
      return 0;
   }
   default:
      std::cout << "usage: ./ex00 [fileName.txt] or ./ex00 [filename].csv [filename2].txt" << std::endl;
      return 0;
   }
}