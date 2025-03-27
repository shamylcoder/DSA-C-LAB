#pragma once

#include <iostream>
using namespace std;

template <class ItemType>
class Que {
public:
    Que(int max = 500);
    ~Que();

    bool IsFull() const;
    bool IsEmpty() const;
    void Insert(ItemType newItem);
    void Remove(ItemType& item);

private:
    int front, rear, maxQue, count;
    ItemType* items;
};

template <class ItemType>
Que<ItemType>::Que(int max) {
    maxQue = max + 1;
    front = rear = count = 0;
    items = new ItemType[maxQue];
}

template <class ItemType>
Que<ItemType>::~Que() {
    delete[] items;
}

template <class ItemType>
bool Que<ItemType>::IsEmpty() const {
    return count == 0;
}

template <class ItemType>
bool Que<ItemType>::IsFull() const {
    return count == maxQue - 1;
}

template <class ItemType>
void Que<ItemType>::Insert(ItemType newItem) {
    if (IsFull()) {
        cout << "Overflow\n";
        return;
    }
    items[rear] = newItem;
    rear = (rear + 1) % maxQue;
    count++;
}

template <class ItemType>
void Que<ItemType>::Remove(ItemType& item) {
    if (IsEmpty()) {
        cout << "Underflow\n";
        return;
    }
    item = items[front];
    front = (front + 1) % maxQue;
    count--;
}

template <class ItemType>
class PQue {
public:
    PQue(int levels);
    ~PQue();

    bool IsFull() const;
    bool IsEmpty() const;
    void Insert(ItemType newItem, int p);
    void Remove(ItemType& item);

private:
    int levels;
    Que<ItemType>** pQ;
};

template <class ItemType>
PQue<ItemType>::PQue(int levels) {
    this->levels = levels;
    pQ = new Que<ItemType> *[levels];
    for (int i = 0; i < levels; i++) {
        pQ[i] = new Que<ItemType>(10);
    }
}

template <class ItemType>
PQue<ItemType>::~PQue() {
    for (int i = 0; i < levels; i++) {
        delete pQ[i];
    }
    delete[] pQ;
}

template <class ItemType>
bool PQue<ItemType>::IsEmpty() const {
    for (int i = 0; i < levels; i++) {
        if (!pQ[i]->IsEmpty()) {
            return false;
        }
    }
    return true;
}

template <class ItemType>
bool PQue<ItemType>::IsFull() const {
    for (int i = 0; i < levels; i++) {
        if (!pQ[i]->IsFull()) {
            return false;
        }
    }
    return true;
}

template <class ItemType>
void PQue<ItemType>::Insert(ItemType newItem, int p) {
    if (p < 0 || p >= levels) {
        cout << "Invalid Priority." << endl;
        return;
    }
    pQ[p]->Insert(newItem);
}

template <class ItemType>
void PQue<ItemType>::Remove(ItemType& item) {
    for (int i = 0; i < levels; i++) {
        if (!pQ[i]->IsEmpty()) {
            pQ[i]->Remove(item);
            return;
        }
    }
    cout << "Underflow" << endl;
}



