#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *createNode(int x){
node *p = new node;
p->data = x;
p->next = NULL;
return p;
}

node *addElement(node *p, int x){
    node *NEW = new node;
    NEW = createNode(x);
    p->next = NEW;
    return NEW;
}

int main(){
int n;
cin>>n;
int x;
cin>>x;
node *Node = createNode(x);
node *First = Node;
int n1 = n-1;
while (n1--){
    cin>>x;
    Node = addElement(Node, x);
}
node *p = First;
while (p != NULL){
    cout<<p->data<<" ";

    p = p->next;
}



    return 0;
}