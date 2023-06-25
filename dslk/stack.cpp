#include <iostream>
#include <string.h>
using namespace std;
// Cấu trúc của một node
struct node {
	int info;
	node* next;
};
// Cấu trúc của một Stack 
struct Stack {
	node* head;
	node* tail;
};
void CreateEmptyStack(Stack &l)
{
    l.head=NULL;
    l.tail=NULL;
}
node* CreateNode(int x)
{
    node* p = new node();
    if(p==NULL) exit(1);
    p->info=x;
    p->next=NULL;
    return p;
}


bool isPrime(int x)
{
    if (x<2) 
    {
    return false;    
        
    }



    if (x==2) return true;

    for (int i=2;i<x;i++)
    {
        if (x%i==0)
            return false;
    }
    return true;
}
void Push(Stack &s, node *p) { // AddHead
    if (s.head == NULL) {
        s.head = p;
        s.tail = p;
    }
    else {
        p->next = s.head;
        s.head = p;
    }
}
int check(Stack l, int x)
{
    if (l.head == NULL)
        return 1;
    for (node*p = l.head; p!= NULL; p=p->next)
    {
        if (p->info==x)
            return 0;
    }
    return 1;
}

void swap(Stack&l, int x)
{
    for (node*p = l.head; p!= NULL; p=p->next)
    {
        if (p->info==x)
            p->info =-1;
    }
}
void CreateStack (Stack &l)
{
    int k;
do{
cin>>k;
if (k!=-1)
{
if (isPrime(k)==true)
{
    if (check(l,k)==1)
    {
        node*p= CreateNode(k);
        Push(l,p);
    }
    else
    {
        swap(l,k);
        node*p= CreateNode(k);
        Push(l,p);
    }
}
}
    }while(k!=-1);
}
void PrintStack(Stack l)
{
    if (l.head==NULL)
    {
        cout<<"No SNT";
        return;
    }
    for(node*p = l.head; 
    p!=NULL; 
    p=p->next)
    {
        if (p->info!=-1){
              cout<<p->info<<"\t";
        }
          
    }
}

int main() {
    Stack L;
    CreateEmptyStack(L);
    CreateStack(L);
    PrintStack(L);
    return 0;
}
