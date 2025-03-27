#include"list.cpp"

int main() {
        //Exercise 6.1
    List<int> l;
    l.push(87);
    cout << "Pushing values 88, 89, 91, 93 onto the list:\n";
    l.push(88);
    l.push(89);
    l.push(91);
    l.push(93);

    cout << "Inserting 90 after 20:\n";
    l.insertafter(89,90);

    cout << "Deleting value 10:\n";
    l.deleteItem(91);

    cout << "Popping top value: " << l.pop() << endl;

    if (l.emptyList()) {
        cout << "List is now empty.\n";
    } else {
        cout << "List is not empty.\n";
    }
    //Exercise 6.2
    string input = "hello";
    List<char> charList;

    for (char c : input) {
        charList.push(c);
    }

    cout << "Reversed string: ";
    while (!charList.emptyList()) {
        cout << charList.pop();
    }
    cout << endl;
            //Exercise 6.3
                LinkedStr list;
            
                list.makeStr(5);  // Create a list of 5 elements
                list.displayStr();
            
                cout << "Removing first element...\n";
                list.removeFirst();
                list.displayStr();
            
                cout << "Removing last element...\n";
                list.removeLast();
                list.displayStr();
            
                int k;
                cout << "Enter value to remove: ";
                cin >> k;
                list.remove(k);
                list.displayStr();
            
                return 0;
                 
    getch();
    return 0;
}
