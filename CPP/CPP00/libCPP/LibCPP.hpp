#pragma once
#include <iostream>

void print(char c);
void print(double d);
void print(int i);
void print(float f);
void print(std::string str);
void print(const char *arrC);

void printEndl(char c);
void printEndl(double d);
void printEndl(float f);
void printEndl(int i);
void printEndl(std::string str);
void printEndl(const char *arrC);

int isCinErr(std::string errorMessage);
