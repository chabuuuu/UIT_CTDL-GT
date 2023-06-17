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


bool IsPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool IsExist(Stack s, int x) {
    node* p = s.head;
    while (p != nullptr) {
        if (p->info == x)
            return true;
        p = p->next;
    }
    return false;
}

void Push(Stack& s, int x) {
    if (s.head == nullptr) {
        s.head = CreateNode(x);
        s.tail = s.head;
    }
    else {
        node* newNode = CreateNode(x);
        s.tail->next = newNode;
        s.tail = newNode;
    }
}

void CreateStack(Stack& s) {
    int x;
    cin >> x;

    while (x != -1) {
        if (IsPrime(x) && !IsExist(s, x)) {
            Push(s, x);
        }
        cin >> x;
    }
}

void PrintStack(Stack s) {
    if (s.head == nullptr) {
        cout << "No SNT" << endl;
        return;
    }

    node* p = s.head;
    while (p != nullptr) {
        cout << p->info << "\t";
        p = p->next;
    }
}

int main() {
    Stack L;
    CreateEmptyStack(L);
    CreateStack(L);
    PrintStack(L);
    return 0;
}
