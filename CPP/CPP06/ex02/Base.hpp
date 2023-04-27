#pragma once
#ifndef __BASE_H__
#define __BASE_H__

class Base
{
public:
	virtual ~Base();
private:
	Base& operator=(const Base& b);
	Base(const Base& b);
};

class A : public Base
{
public:
	~A();
private:
	A& operator=(const A& a);
	A(const A& a);
};

class B : public Base
{
public:
	~B();
private:
	B& operator=(const B& b);
	B(const B& b);
};

class C : public Base
{
public:
	~C();
private:
	C& operator=(const C& c);
	C(const C& c);
};

Base * generate(void);
void identify(Base *p);
void identify(Base &p);

#endif