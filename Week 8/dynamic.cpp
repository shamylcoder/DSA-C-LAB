#include <iostream>
using namespace std;

template <typename T>
class BinaryTree {
private:
    struct TreeNode {
        T info;
        TreeNode* left;
        TreeNode* right;
    };

    typedef TreeNode* NODEPTR;
    NODEPTR root;

    NODEPTR maketree(T x) {
        NODEPTR p = new TreeNode;
        p->info = x;
        p->left = nullptr;
        p->right = nullptr;
        return p;
    }

    void setleft(NODEPTR p, T x) {
        if (p == nullptr) {
            cout << "Void Insertion" << endl;
        } else if (p->left != nullptr) {
            cout << "Invalid Insertion: Left child already exists" << endl;
        } else {
            p->left = maketree(x);
        }
    }

    void setright(NODEPTR p, T x) {
        if (p == nullptr) {
            cout << "Void Insertion" << endl;
        } else if (p->right != nullptr) {
            cout << "Invalid Insertion: Right child already exists" << endl;
        } else {
            p->right = maketree(x);
        }
    }

    void pretrav(NODEPTR tree) {
        if (tree != nullptr) {
            cout << tree->info << " ";
            pretrav(tree->left);
            pretrav(tree->right);
        }
    }

    void intrav(NODEPTR tree) {
        if (tree != nullptr) {
            intrav(tree->left);
            cout << tree->info << " ";
            intrav(tree->right);
        }
    }

    void posttrav(NODEPTR tree) {
        if (tree != nullptr) {
            posttrav(tree->left);
            posttrav(tree->right);
            cout << tree->info << " ";
        }
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void createRoot(T x) {
        if (root != nullptr) {
            cout << "Root already exists" << endl;
        } else {
            root = maketree(x);
        }
    }

    NODEPTR getRoot() {
        return root;
    }

    void insertLeft(NODEPTR p, T x) {
        setleft(p, x);
    }

    void insertRight(NODEPTR p, T x) {
        setright(p, x);
    }

    void preorderTraversal() {
        pretrav(root);
        cout << endl;
    }

    void inorderTraversal() {
        intrav(root);
        cout << endl;
    }

    void postorderTraversal() {
        posttrav(root);
        cout << endl;
    }
};
int main() {
    BinaryTree<int> tree;

    tree.createRoot(10);
    auto root = tree.getRoot();

    tree.insertLeft(root, 5);
    tree.insertRight(root, 15);

    tree.insertLeft(root->left, 3);
    tree.insertRight(root->left, 7);

    tree.insertLeft(root->right, 12);
    tree.insertRight(root->right, 18);

    cout << "Preorder Traversal: ";
    tree.preorderTraversal(); // 10 5 3 7 15 12 18

    cout << "Inorder Traversal: ";
    tree.inorderTraversal(); // 3 5 7 10 12 15 18

    cout << "Postorder Traversal: ";
    tree.postorderTraversal(); // 3 7 5 12 18 15 10

    return 0;
}
