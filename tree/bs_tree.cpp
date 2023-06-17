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
    int n = 0;
    while (n != -1){
         cin>>n;
         if (n!= -1){
            Insert(T,n);
         }else{
            cin>>x;
         }

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

void Function(TREE& T){
    int arr[100];
    int i = 0;
    if (T->key == x){
        cout<<"Root no ancestor"<<endl;
        return;
    }
    if (searchNode(T, i, arr) != NULL){
        for (int k = 0; k <i; k ++){
            cout<<arr[k]<<"\t";
        }
    }else{
        cout<<"No Find"<<endl;
    }
}

int main() {
    TREE T; //50 20 80 10 30 60 90 40 70 //CreateEmptyTree(T)
    CreateTree(T);
    Function(T);
return 0;
}