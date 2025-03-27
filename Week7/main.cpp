#include"dlist.cpp"

int main(){
    int arr[] = {4,6,8,32,19};
    Dlist<int> dlist(arr);
    dlist.push_back(11);
    dlist.push_front(100);
    while(dlist)
    cout<<dlist.pop_back()<<" ";
/*
     // Push values
     DList <long> longList;
     longList.push_back(1000000001);
     longList.push_back(2000000002);
     longList.push_front(999999999);
     longList.push_front(888888888);
 
     cout << "List forward: ";
     longList.display_forward();
 
     cout << "List backward: ";
     longList.display_backward();
 
     // Pop values
     cout << "Popped from front: " << longList.pop_front() << endl;
     cout << "Popped from back: " << longList.pop_back() << endl;
 
     cout << "List after pops: ";
     longList.display_forward();
 
*/
    getch();
    return 0;
}