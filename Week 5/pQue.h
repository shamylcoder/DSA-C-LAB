#include<iostream>
using namespace std;

int main() {
    PQue<int> pq(5);
    pq.Insert(5, 2);
    pq.Insert(10, 1);
    pq.Insert(20, 3);

    int item;
    cout << "Removing elements in priority order:" << endl;

    pq.Remove(item);
    cout << item << endl;
    pq.Remove(item);
    cout << item << endl;
    pq.Remove(item);
    cout << item << endl;

    return 0;
}