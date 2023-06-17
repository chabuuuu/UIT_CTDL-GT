#include <iostream>
using namespace std;

struct TIME {
    int gio, phut, giay;
};

struct node {
    TIME info;
    node* next;
};

struct List {
    node* head;
    node* tail;
};

void CreateEmptyList(List& L) {
    L.head = L.tail = nullptr;
}

void InsertTail(List& L, TIME t) {
    node* newNode = new node;
    newNode->info = t;
    newNode->next = nullptr;

    if (L.head == nullptr) {
        L.head = newNode;
        L.tail = newNode;
    }
    else {
        L.tail->next = newNode;
        L.tail = newNode;
    }
}

void SimplifyTime(TIME& t) {
    if (t.giay >= 60) {
        int extraMinutes = t.giay / 60;
        t.phut += extraMinutes;
        t.giay %= 60;
    }

    if (t.phut >= 60) {
        int extraHours = t.phut / 60;
        t.gio += extraHours;
        t.phut %= 60;
    }

    if (t.gio >= 24) {
        t.gio %= 24;
    }
}

void PrintTime(TIME t) {
    SimplifyTime(t);
    cout << t.gio << "h" << t.phut << "p" << t.giay << "s" << endl;
}

void PrintList(List L) {
    TIME result[100];
    int i = 0;
    node* p = L.head;
    while (p != nullptr) {
        // PrintTime(p->info);
        result[i] = p->info;
        i++;
        p = p->next;
    }
    for (int k = i - 1 ; k >= 0 ; k--){
        PrintTime(result[k]);
    }
    
}

void CreateList(List& L) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        TIME t;
        cin >> t.gio >> t.phut >> t.giay;
        InsertTail(L, t);
    }
}

int main() {
    List L;
    CreateEmptyList(L);
    CreateList(L);
    PrintList(L);

    return 0;
}
