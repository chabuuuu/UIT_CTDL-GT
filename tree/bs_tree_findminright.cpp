#include<iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};

typedef TNODE* TREE;

int x;
bool isEmptyTree;


void CreateEmptyTree(TREE &T)
{
    T=NULL;
}

TNODE* CreateNode(int x)
{
    TNODE* p=new TNODE();
    if(p==NULL)exit(1);
    p->key=x;
    p->pLeft=NULL;
    p->pRight=NULL;
    return p;
}


int Insert(TREE &T, int x) {
    if (T)
    {
        if (T->key == x) return 0;
        if (T->key > x)  return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
    T = CreateNode(x);
    return 1;
}

void CreateTree(TREE &T)
{    T=NULL;
isEmptyTree = false;
    int n = 0;
    int count = 0;
    while (n != -1){
         cin>>n;
            if (n == -1 && count == 0){
            cout<<"Empty Tree"<<endl;
            isEmptyTree = true;
            return;
         }
         if (n!= -1){
            Insert(T,n);
         }else{
            cin>>x;
         }
         count++;
      

    }


}


TNODE* FindMinRight(TREE T) {
    if (T->pLeft == NULL) {
        return T;
    }
    
    return FindMinRight(T->pLeft);
}


TNODE* SearchNode(TREE T, int X) {
    if (T == NULL) {
        return NULL;
    }
    
    if (T->key == X) {
        return T;
    } else if (X < T->key) {
        return SearchNode(T->pLeft, X);
    } else {
        return SearchNode(T->pRight, X);
    }
}

void Function(TREE T) {
    
    TNODE* node = SearchNode(T, x);
    if (node == NULL) {
        cout << "No Find";
        return;
    }
    
    if (node->pLeft != NULL && node->pRight != NULL) {
        TNODE* maxLeftNode = FindMinRight(node->pRight);
        cout << maxLeftNode->key;
    } else {
        cout << "No Node 2";
    }
}






int main() {
    TREE T; //50 20 80 10 30 60 90 40 70 //CreateEmptyTree(T)
    CreateTree(T);
    Function(T);
return 0;
}