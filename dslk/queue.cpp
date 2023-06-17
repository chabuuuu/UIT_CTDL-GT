#include <iostream>
#include <string>
using namespace std;

struct node {
    int info;
    node* next;
};

struct Queue {
    node* head;
    node* tail;
};

void CreateEmptyQueue(Queue& q) {
    q.head = NULL;
    q.tail = NULL;
}

node* CreateNode(int x) {
    node* p = new node();
    if (p == NULL)
        exit(1);
    p->info = x;
    p->next = NULL;
    return p;
}

void Enqueue(Queue& q, int x) {
    node* newNode = CreateNode(x);
    if (q.head == NULL) {
        q.head = newNode;
        q.tail = newNode;
    } else {
        q.tail->next = newNode;
        q.tail = newNode;
    }
}

string Encode(string s) {
    Queue q;
    CreateEmptyQueue(q);

    int count = 1;
    string encodedStr = "";

    for (int i = 0; i < s.length(); i++) {
        if (i < s.length() - 1 && s[i] == s[i + 1]) {
            count++;
        } else {
            Enqueue(q, int(s[i]));
            Enqueue(q, count);
            count = 1;
        }
    }

    node* p = q.head;
    while (p != NULL) {
        encodedStr += to_string(p->info);
        p = p->next;
    }

    return encodedStr;
}

void CreateQueue(Queue& q) {
    string s;
    getline(cin, s);

    string encodedStr = Encode(s);

    for (int i = 0; i < encodedStr.length(); i++) {
        int num = encodedStr[i] - '0';
        Enqueue(q, num);
    }
}

void PrintQueue(Queue q) {
    for (node* p = q.head; p != NULL; p = p->next)
        cout << p->info;
}

int main() {
    Queue Q;
    CreateEmptyQueue(Q);
    CreateQueue(Q);
    PrintQueue(Q);
    return 0;
}
