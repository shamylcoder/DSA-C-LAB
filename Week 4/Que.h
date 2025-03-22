#ifndef QUE_H
#define QUE_H

//#define maxQue 100
//typedef int ItemType;
template<class ItemType>

class Que{
    //ItemType items[maxQue];
    int front,rear,count;
    int maxQue;
    ItemType *items;
    public:
    Que();
    ~Que();
    Que(int max);
    bool IsFull();
    bool IsEmpty();
    //void Insert(ItemType newItem);
    //void Remove(ItemType &Item);
    void InsertRight(ItemType newItem);
    void InsertLeft(ItemType newItem);
    void RemoveRight(ItemType& item);
    void RemoveLeft(ItemType& item);
};

#endif