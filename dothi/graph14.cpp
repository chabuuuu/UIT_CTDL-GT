 #include <iostream>

using namespace std;

struct Node
{
    int info;
    Node* next;
};

struct List
{
    Node* head=NULL;
    Node* tail=NULL;
};

struct Graph
{
    int v; // số đỉnh của đồ thị 
    List* arr; //mảng của các danh sách
};

void addNode(List& list, int value)
{
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = NULL;

    if (list.head == NULL)
    {
        list.head = newNode;
        list.tail = newNode;
    }
    else
    {
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

void Input(Graph& G, int e)
{
    // Tạo các danh sách rỗng ban đầu
    for (int i = 0; i < G.v; i++)
    {
        G.arr[i].head = NULL;
        G.arr[i].tail = NULL;
    }

    // Nhập danh sách các cạnh
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        // Thêm đỉnh v vào danh sách kề của đỉnh u
        addNode(G.arr[u], v);
    }

    // In ra danh sách kề
    for (int i = 0; i < G.v; i++)
    {
        cout << i << ": ";
        Node* currentNode = G.arr[i].head;
        int temp  = 0;
        if (currentNode == NULL){
            cout<<"{}";
        }else{
             while (currentNode != NULL)
        {
            if (temp != 0){
                cout<<", ";
                cout  <<currentNode->info;
                currentNode = currentNode->next;
            }else{
                 cout <<"{" <<currentNode->info;
            currentNode = currentNode->next;
            }
            temp++;
           
        }
        cout<<"}";
        }
       
        cout << endl;
    }
}
 
int main()
{
    int e,v;
    cin>>e>>v;
    Graph G;
    G.v=v;
    G.arr = new List[v];
    Input(G,e);

    return 0;
}