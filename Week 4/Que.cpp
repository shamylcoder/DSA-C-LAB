#include "Que.h"
#include <iostream>
using namespace std;
/*
Que::Que() {
    count = front = rear = 0;
}

int Que::IsEmpty() {
    return (count == 0);
}

int Que::IsFull() {
    return (count == maxQue);
}

void Que::Insert(ItemType newItem) {
    if (IsFull()) {
        cout << "Overflow" << endl;
    } else {
        items[rear] = newItem;
        rear = (rear + 1) % maxQue;
        ++count;
    }
}

void Que::Remove(ItemType &Item) {
    if (IsEmpty()) {
        cout << "Underflow" << endl;
    } else {
        Item = items[front];
        front = (front + 1) % maxQue;
        
    }
}*/
template<class ItemType>
Que<ItemType>::Que(){
    maxQue=501;
   // front = rear =0;
   count = 0;
   front = rear = -1
    items new ItemType[maxQue];
}
template<class ItemType>
Que<ItemType>::Que(int max){
    maxQue = max + 1;
   // front = rear =0;
     count = 0;
    front = rear = -1
    items new ItemType[maxQue];
}
template<class ItemType>
Que<ItemType>::~Que(){
    delete []items;
}
template<class ItemType>
bool Que<ItemType>::IsEmpty(){
    return (count == 0);
}
template<class ItemType>
bool Que<ItemType>::IsFull(){
    return (count == maxQue);
}
/*template<class ItemType>
void Que<ItemType>::Insert(ItemType newItem){
    if(IsFull()){
        cout<<"Over flow";
    }
    else
    {
        items[rear] = newItem;
        rear =(rear + 1)%maxQue;
        ++count;
    }
}
template<class ItemType>
void Que<ItemType>::Remove(ItemType& item){
    if(IsEmpty())
    cout<<"Under Flow";
    else{
        item =items[front];
        front = (front + 1)% maxQue;
        --count;
    }
}
    Exercise 4.3*/
    //Exercise 4.4
template<class ItemType>
void Que<ItemType>::InsertLeft(ItemType newItem){//Insert from the rear
    if(IsFull()){
        cout<<"Over flow";
    }
    elseif(rear==-1)
    rear=front=0;
    elseif(rear==maxQue-1)
    rear=0;
    else{
    rear++;
    items[rear]=newItem;
    }
}

template<class ItemType>
void Que<ItemType>::InsertRight(ItemType newItem){//Insert from the front
    if(IsFull()){
        cout<<"Over flow";
    }
    elseif(front==-1)
    rear=front=0;
    elseif(front==0)
    front =maxQue-1;
    else{
    front--;
    items[front]=newItem;
    }
}
template<class ItemType>
void Que<ItemType>::RemoveLeft(ItemType& item){//Remove from the rear
    if(IsEmpty()){
        cout<<"Under Flow";
        }
    elseif(front==rear)
    front=rear=-1
 elseif( rear=0;)
        rear=maxQue-1
 else{
    item =items[rear];
   rear--;
 }
}
template<class ItemType>
void Que<ItemType>::RemoveRight(ItemType& item){//Remove from the front
    if(IsEmpty()){
    cout<<"Under Flow";
    }
    elseif(front==rear)
       front=rear=-1
    elseif(front=maxQue-1)
        front=0;
    else{    
    item =items[front];
      front++;
    }
}