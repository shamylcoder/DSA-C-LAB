#include<iostream>
#define NUMNODES 500
using namespace std;
class bt{

struct Treenode{
    int info;
    int left,right,parent;
};
Treenode BT[NUMNODES];
   int nc;
   public:

   bt(){
    nc=0;
   };
   bt(int info){
        BT[0].info = info;
        BT[0].left = -1;
        BT[0].right = -1;
        BT[0].parent = -1;
        nc=1;
   }
  void maketree(int info){
    BT[0].info = info;
    BT[0].left = -1;
    BT[0].right = -1;
    BT[0].parent = -1;
    nc=1;
  }
  bool isempty(){

   if(nc==0){
   return true;
   }
     return false;
  }
  void setleft(int index,int value){
      if(nc>=NUMNODES||index<0&&index>=nc){
        return;
      }
      if(BT[index].left== -1){
        int newnode = nc;
        BT[newnode].info = value;
        BT[newnode].left = -1;
        BT[newnode].right = -1;
        BT[newnode].parent = index;
        nc++;
      }
  }
  void setright(int index,int value){
    if(nc>=NUMNODES||index<0&&index>=nc){
        return;
      }
      if(BT[index].right== -1){
        int newnode = nc;
        BT[newnode].info = value;
        BT[newnode].left = -1;
        BT[newnode].right = -1;
        BT[newnode].parent = index;
        nc++;
      }
  }
  bool isleft(int index){
    if(index<0||index>= nc){
        return false;
    }
  int parent= BT[index].parent;
  if(parent==-1){
    return false;
  }
  
  }
  bool isright(int index){

  }
  void preorder(int index){
    if(index<0||index>= nc){
        return ;
    }
    cout <<BT[index].info<<" ";
    preorder(BT[index].left);
    preorder(BT[index].left);
  }
  void inorder(int index){
    if(index<0||index>= nc){
        return ;
    }

    inorder(BT[index].left);
    cout <<BT[index].info<<" ";
    inorder(BT[index].left);
  }
  void postorder(int index){
    if(index<0||index>= nc){
        return ;
    }
    postorder(BT[index].left);
    postorder(BT[index].left);
    cout <<BT[index].info<<" ";
  }
int siblings(int index){
    if(index<0||index>= nc){
        return false;
    }
    int parent =BT[index].parent;
    if(parent==-1){
        return false;
    }
    if (BT[parent].left==index){
        return BT[parent].right;
    }
    if (BT[parent].right==index){
        return BT[parent].left;
    }
}
int search(int value){
    for(int i=0;i<nc;i++){
        if(BT[i].info==value)return i;
    }
    return -1;
}
int findparent(int value){
    for(int i=0;i<nc;i++){
        if(BT[0].info==value){
            cout <<"The vertex has no parent  its the root";
            return -1;
        }
        if(BT[i].info==value){
           return BT[i].parent;
        }
    }
    
    return -1;
}
    void insertBST(int value) {
        if (isempty()) {
            maketree(value);
            return;
        }

        int current = 0;
        while (true) {
            if (value < BT[current].info) {
                if (BT[current].left == -1) {
                    setleft(current, value);
                    break;
                }
                current = BT[current].left;
            } else if (value > BT[current].info) {
                if (BT[current].right == -1) {
                    setright(current, value);
                    break;
                }
                current = BT[current].right;
            } else {
                break; // No duplicates
            }
        }
    }

    void inorder_traversal() {
        inorder(0);
        cout << endl;
    }

    void preorder_traversal() {
        preorder(0);
        cout << endl;
    }

    void postorder_traversal() {
        postorder(0);
        cout << endl;
    }

};
int main() {
    bt tree;

    // Insert values into the BST
    tree.insertBST(50);
    tree.insertBST(30);
    tree.insertBST(70);
    tree.insertBST(20);
    tree.insertBST(40);
    tree.insertBST(60);
    tree.insertBST(80);

    cout << "Inorder traversal (should be sorted): ";
    tree.inorder_traversal();

    cout << "Preorder traversal: ";
    tree.preorder_traversal();

    cout << "Postorder traversal: ";
    tree.postorder_traversal();

    // Search example
    int value = 40;
    int index = tree.search(value);
    if (index != -1)
        cout << "Value " << value << " found at index " << index << endl;
    else
        cout << "Value " << value << " not found in tree." << endl;

    return 0;
}
