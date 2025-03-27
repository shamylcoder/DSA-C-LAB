#include<iostream>
#include"Que.h"
#include"PQue.h"
using namespace std;
int main() {

	PQue<int> q1;

	q1.Insert(5, 2);
	q1.Insert(10, 1);
	q1.Insert(20, 5);


	int item;
	cout << "Removing Elements in Priority Order:" << endl;

	q1.Remove(item);
	cout << item << endl;

	q1.Remove(item);
	cout << item << endl;

	q1.Remove(item);
	cout << item << endl;

	return 0;
}