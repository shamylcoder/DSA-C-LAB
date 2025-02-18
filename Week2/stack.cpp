#include <stdlib.h>
#include"stack.h"
/*Stack::Stack() {

	maxStack = 20;
	top = -1;
	items = new char[20];
}

Stack::Stack(int max)
{
	maxStack = max;
	top = -1;
	items = new char[max];
}

Stack::~Stack()
{
	delete[] items;
}


int Stack::IsEmpty() const
{
	return (top == -1);
}
int Stack::IsFull() const
{
	return (top == maxStack - 1);
}


void Stack::Validity(const std::string newitem)
{
	if (IsFull())
	{
		cout << "Stack Overflow." << endl;
		exit(1);
	}
	
	int i=0;

	for (i = 0; i < newitem.size(); i++) {


		if (newitem[i] == '(') {

			cout << newitem[i] << " at " << i << endl;
			top++;
			items[top] = newitem[i];
		}
	}
if (IsEmpty())
		{
			cout << "Stack Underflow." << endl;
			exit(1);
		}

		else
		{

			for (i = 0; i < newitem.size(); i++) {

				if (newitem[i] == ')') {

					cout << newitem[i] << " at " << i << endl;

					char ch = items[top];
					top--;
				}
			}
		}
	
		if (IsEmpty()) {

			cout << "Expression is valid because stack is empty." << endl;
		}
		else {
			cout << "Expression is not valid because stack is not empty." << endl;
		}
}
*/
/*
stack::stack(){
	maxsize =100;
	arr = new char[maxsize];
	topdex = -1; 
}
stack::~stack(){
	delete[] arr ;
}
stack::stack(int size){
	maxsize = size;
	arr = new char[maxsize];
}
int stack::IsEmpty(){
	return topdex == -1;
}
int stack::IsFull(){
	return topdex == maxsize -1;
}
void stack::Push(char ch){
	if(!IsFull()){
		arr[++topdex]=ch;
	}
}
char stack::Pop(){
	if (!IsEmpty()) {
		return arr[topdex--]; 
	}
	else{ 
		return '\0';

}
}
char stack::top(){
	return IsEmpty() ? '\0' : arr[topdex]; 

}
int stack::precedence(char op){
	if (op=='+'||op=='-')
	return 1;
	if (op=='*'||op=='/')
	return 0;
}
void stack::check(string infix){
	stack s(infix.length());
	string postfix ="";
	for(int i=0;i<infix.length();i++){
		char c = infix[i];
		if(c>='A'&& c<='Z')
		postfix +=c;
		else{
			while (!s.IsEmpty() && precedence(s.top()) >= precedence(c))
				postfix += s.Pop();
			s.Push(c);
		}
	}
	while (!s.IsEmpty() && precedence(s.top()) >= precedence(c))
	postfix += s.Pop();
s.Push(c);
}
*/
//Example +Exercise 2.2(c)
/*
void stack::ConvertandEvaluate(string infix){
	stack s(infix.length());
	string postfix = "";

	for (int i = 0; i < infix.length(); i++) {
		char c = infix[i];

		if (isalnum(c)) {
			postfix += c;
		}
		else if (c == '(') {
			s.Push(c);
		}
		else if (c == ')') {
			while (!s.IsEmpty() && s.top() != '(') {
				postfix += s.Pop();
			}
			if (!s.IsEmpty() && s.top() == '(') {
				s.Pop();
			}
		}

}
else {
	while (!s.IsEmpty() && precedence(s.Top()) >= precedence(c)) {
		postfix += s.Pop();
	}
	s.Push(c);
}
}

while (!s.IsEmpty()) {
postfix += s.Pop();
}

cout << "Postfix expression: " << postfix << endl;

stack e(postfix.size());

for (int i = 0; i < postfix.size(); i++) {
char ch = postfix[i];
if (isdigit(ch)) {
	e.Push(ch - '0');
}
else {
	int oprd2 = e.Pop();
	int oprd1 = e.Pop();
	int res;
	if (ch == '+') {
		res = oprd1 + oprd2;
	}
	else if (ch == '-') {
		res = oprd1 - oprd2;
	}
	else if (ch == '/') {
		res = oprd1 / oprd2;
	}
	else if (ch == '*') {
		res = oprd1 * oprd2;
	}
	e.Push(res);
}


int answer = e.Pop();
cout << "Solution of the expression is given by: " << answer << endl;
}*/