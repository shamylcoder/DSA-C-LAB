#include<iostream>
#include<conio.h>
using namespace std;
 template <class T>
 class Dlist{
    struct node{
        T data;
       // long data;
        node *prev, node *next;
        node(T t, node *p,node *n) : prev(p), next(n) {}
    };
    node *head; node *tail;
    public:
    Dlist(): head(NULL), tail(NULL){}
    template<int N>
    Dlist(T (&arr) [N]) : head(NULL) ,tail(NULL){
        for(int i=0;i!=N;++i)
        push_back(arr[i]);
    }
bool empty()const{return (!head || tail);}
operator bool()const{return !empty();}
void push_back(T);
void push_front(T);

T pop_back();
T pop_front();
~Dlist(){
    while(head){
        node *temp(head);
        head=head->next;
        delete temp;
    }
}
};

template <class T>
void Dlist<T>::push_back(T data){
    tail = new node(data, tail, NULL);
    if (tail->prev)
    tail->prev->next = tail;
    if(empty())
    head = tail;
}
template <class T>
void Dlist<T>::push_front(T data){
    head = new node(data, NULL, head);
    if(head->next)
    head->next->prev=head;
    if(empty())
    tail = head;
}
template <class T>
T Dlist<T>::pop_back(){
    if(empty())
    throw("double-linked : list empty");
    node *temp(tail);
    T data(tail->data);
    tail = tail->prev;
    if(tail)
    tail->next = NULL;
    else
    head = NULL;
    delete temp;
    return data;
};
template <class T>
T Dlist<T>::pop_front(){
    if(empty())
    throw("double-linked : list empty");
    node *temp(head);
    T data(head->data);
    head = head->next;
    if(head)
    head->next = NULL;
    else
    tail = NULL;
    delete temp;
    return data;
};