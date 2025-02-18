#ifndef STACK_H
#define STACK_H
#include<iostream>
#include<string>
using namespace std;
/*
class Stack {

public:
	Stack();
	Stack(int max);
	~Stack();
	int IsEmpty() const;
	int IsFull() const;
	void Validity(const std::string newitem);

private:
	int top;
	int maxStack;
	char* items;
};
*/
class stack{
char* arr;
int maxsize;
int topdex;
public :
stack();
~stack();
stack(int size);
int IsEmpty();
int IsFull();
void Push(char ch);
char Pop();
char top();
int precedence(char op);
void check(string infix);
void ConvertandEvaluate(string infix);
};

#endif