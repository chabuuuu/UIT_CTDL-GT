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

TNODE* searchNode(TREE T, int& i, int arr[100]) {
    if (T != NULL) {
       
        if (T->key == x) 
        {

            return T;
        }
        arr[i] = T->key;
        i++;
        // cout<<T->key<<"\t";

        if (T->key > x)  
        {
         
            return searchNode(T->pLeft,i, arr);
        }
        
        return searchNode(T->pRight, i, arr);
    }
    return NULL;
}

int GetTreeHeight(TREE T) {
    if (T == NULL)
        return 0;
    else {
        int leftHeight = GetTreeHeight(T->pLeft);
        int rightHeight = GetTreeHeight(T->pRight);
        return max(leftHeight, rightHeight) + 1;
    }
}

void PrintNodesAtLevelK(TREE T, int level, int k) {
    if (T == NULL)
        return;

    if (level == k)
        cout << T->key << " ";

    PrintNodesAtLevelK(T->pLeft, level + 1, k);
    PrintNodesAtLevelK(T->pRight, level + 1, k);
}

void Function(TREE& T) {
    
    if (isEmptyTree == true){
        return;
    }
   
    int treeHeight = GetTreeHeight(T) - 1;

    if (x >= 0 && x <= treeHeight) {
        cout<<"Xuat cac node o muc "<<x<<":"<<endl;
        PrintNodesAtLevelK(T, 0, x);
    } else if (x < 0 || x > treeHeight) {
        cout << "Khong co node o muc " << x;
    } else {
        cout << "Empty Tree";
    }
}

int main() {
    TREE T; //50 20 80 10 30 60 90 40 70 //CreateEmptyTree(T)
    CreateTree(T);
    Function(T);
return 0;
}