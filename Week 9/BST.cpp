#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template<class T>
struct TreeNode {
    T info;
    TreeNode<T>* left;
    TreeNode<T>* right;
};

template<class T>
class TreeType {
private:
    TreeNode<T>* root;

public:
    TreeType();
    ~TreeType();

    bool IsEmpty() const;
    bool IsFull() const;

    int NumberOfNodes() const;

    void InsertItem(T item);
    void DeleteItem(T item);

    void RetrieveItem(T& item, bool& found);
    void PrintTree(ofstream& outfile);

private:
    void PrintHelper(TreeNode<T>* ptr, ofstream& outfile);
    void InsertHelper(TreeNode<T>*& ptr, T item);
    void RetrieveHelper(TreeNode<T>* ptr, T& item, bool& found);
    int CountNodes(TreeNode<T>* ptr);
    void DestroyHelper(TreeNode<T>* ptr);
    void DeleteHelper(TreeNode<T>*& ptr, T item);
};

template<class T>
TreeType<T>::TreeType() {
    root = NULL;
}

template<class T>
TreeType<T>::~TreeType() {
    DestroyHelper(root);
}

template<class T>
bool TreeType<T>::IsEmpty() const {
    return root == NULL;
}

template<class T>
bool TreeType<T>::IsFull() const {
    try {
        TreeNode<T>* temp = new TreeNode<T>;
        delete temp;
        return false;
    } catch (bad_alloc&) {
        return true;
    }
}

template<class T>
void TreeType<T>::RetrieveItem(T& item, bool& found) {
    RetrieveHelper(root, item, found);
}

template<class T>
void TreeType<T>::RetrieveHelper(TreeNode<T>* ptr, T& item, bool& found) {
    if (ptr == NULL)
        found = false;
    else if (item < ptr->info)
        RetrieveHelper(ptr->left, item, found);
    else if (item > ptr->info)
        RetrieveHelper(ptr->right, item, found);
    else {
        item = ptr->info;
        found = true;
    }
}

template<class T>
void TreeType<T>::InsertItem(T item) {
    InsertHelper(root, item);
}

template<class T>
void TreeType<T>::InsertHelper(TreeNode<T>*& ptr, T item) {
    if (ptr == NULL) {
        ptr = new TreeNode<T>;
        ptr->info = item;
        ptr->left = NULL;
        ptr->right = NULL;
    } else if (item < ptr->info)
        InsertHelper(ptr->left, item);
    else if (item > ptr->info)
        InsertHelper(ptr->right, item);
}

template<class T>
void TreeType<T>::DeleteItem(T item) {
    DeleteHelper(root, item);
}

template<class T>
void TreeType<T>::DeleteHelper(TreeNode<T>*& ptr, T item) {
    if (ptr == NULL)
        return;
    else if (item < ptr->info)
        DeleteHelper(ptr->left, item);
    else if (item > ptr->info)
        DeleteHelper(ptr->right, item);
    else {
        TreeNode<T>* temp;
        if (ptr->left == NULL) {
            temp = ptr;
            ptr = ptr->right;
            delete temp;
        } else if (ptr->right == NULL) {
            temp = ptr;
            ptr = ptr->left;
            delete temp;
        } else {
            TreeNode<T>* successor = ptr->right;
            while (successor->left != NULL)
                successor = successor->left;
            ptr->info = successor->info;
            DeleteHelper(ptr->right, successor->info);
        }
    }
}

template<class T>
void TreeType<T>::PrintTree(ofstream& outfile) {
    PrintHelper(root, outfile);
}

template<class T>
void TreeType<T>::PrintHelper(TreeNode<T>* ptr, ofstream& outfile) {
    if (ptr != NULL) {
        PrintHelper(ptr->left, outfile);
        outfile << ptr->info << endl;
        PrintHelper(ptr->right, outfile);
    }
}

template<class T>
int TreeType<T>::NumberOfNodes() const {
    return CountNodes(root);
}

template<class T>
int TreeType<T>::CountNodes(TreeNode<T>* ptr) {
    if (ptr == NULL)
        return 0;
    else
        return 1 + CountNodes(ptr->left) + CountNodes(ptr->right);
}

template<class T>
void TreeType<T>::DestroyHelper(TreeNode<T>* ptr) {
    if (ptr != NULL) {
        DestroyHelper(ptr->left);
        DestroyHelper(ptr->right);
        delete ptr;
    }
}

/*int main() {
    TreeType<string> tree;
    ofstream out("sorted_strings.txt");

    string arr[] = {"banana", "apple", "grape", "orange", "kiwi", "mango", "pear"};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        tree.InsertItem(arr[i]);
    }

    tree.PrintTree(out);
    out.close();

    // Optional: read and display sorted strings from the file
    ifstream in("sorted_strings.txt");
    string word;
    while (getline(in, word)) {
        cout << word << endl;
    }
    in.close();

    return 0;
}*/
// Exercise 9.1

// Assuming TreeType and TreeNode classes are defined above this

int main() {
    TreeType<string> tree;
    ofstream out("sorted_strings.txt");

    // Sample array of strings to sort
    string words[] = {"banana", "apple", "grape", "orange", "kiwi", "mango", "pear"};
    int size = sizeof(words) / sizeof(words[0]);

    // Insert each string into the binary search tree
    for (int i = 0; i < size; i++) {
        tree.InsertItem(words[i]);
    }

    // Output sorted strings to file using in-order traversal
    tree.PrintTree(out);
    out.close();

    // Read and print the sorted strings from the file to console
    ifstream in("sorted_strings.txt");
    string word;
    while (getline(in, word)) {
        cout << word << endl;
    }
    in.close();

    return 0;
}

