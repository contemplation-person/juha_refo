#include "LibCPP.hpp"

void print(char c) { std::cout << c; }
void print(double d) { std::cout << d; }
void print(int i) { std::cout << i; }
void print(float f) { std::cout << f; }
void print(std::string str) {std::cout << str;}
void print(const char *arrC){std::cout << arrC;}

void printEndl(char c) { std::cout << c << std::endl; }
void printEndl(double d) { std::cout << d << std::endl; }
void printEndl(float f) { std::cout << f << std::endl; }
void printEndl(int i) { std::cout << i << std::endl; }
void printEndl(std::string str) {std::cout << str << std::endl;}
void printEndl(const char *arrC) { std::cout << arrC << std::endl; }
