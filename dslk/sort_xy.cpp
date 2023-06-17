#include <iostream>
using namespace std;

struct point {
    int x, y;
};

struct node {
    point info;
    node* next;
};

struct List {
    node* head;
    node* tail;
};

void CreateEmptyList(List& L) {
    L.head = L.tail = nullptr;
}

void InsertTail(List& L, point p) {
    node* newNode = new node;
    newNode->info = p;
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

void SwapPoints(point& p1, point& p2) {
    point temp = p1;
    p1 = p2;
    p2 = temp;
}

void SortPoints(List& L) {
    if (L.head == nullptr || L.head->next == nullptr) {
        return; // Danh sách rỗng hoặc chỉ có 1 phần tử, không cần sắp xếp
    }

    node* p, * q;
    for (p = L.head; p != nullptr; p = p->next) {
        for (q = p->next; q != nullptr; q = q->next) {
            if (q->info.x < p->info.x || (q->info.x == p->info.x && q->info.y < p->info.y)) {
                SwapPoints(p->info, q->info);
            }
        }
    }
}

void PrintList(List L) {
    node* p = L.head;
    while (p != nullptr) {
        cout << "(" << p->info.x << "," << p->info.y << ")" << endl;
        p = p->next;
    }
}

void CreateList(List& L) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        point p;
        cin >> p.x >> p.y;
        InsertTail(L, p);
    }

    SortPoints(L);
}

int main() {
    List L;
    CreateEmptyList(L);
    CreateList(L);
    PrintList(L);

    return 0;
}
