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

void CalculateDegree(Graph& G, int u)
{
    int outDegree = 0; // nửa bậc ngoài
    int inDegree = 0; // nửa bậc trong

    // Tính nửa bậc ngoài
    Node* currentNode = G.arr[u].head;

    if (G.arr[u] == NULL){
        cout<<"No find";
        return;
    }
    while (currentNode != NULL)
    {
        outDegree++;
        currentNode = currentNode->next;
    }

    // Tính nửa bậc trong
    for (int i = 0; i < G.v; i++)
    {
        currentNode = G.arr[i].head;
        while (currentNode != NULL)
        {
            if (currentNode->info == u)
                inDegree++;
            currentNode = currentNode->next;
        }
    }

    // Xuất kết quả
    cout << "Nua bac ngoai: " << outDegree << endl;
    cout << "Nua bac trong: " << inDegree << endl;
}

// Hàm nhập danh sách các cạnh và xây dựng danh sách kề
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
    int u;
    cin>>u;
    CalculateDegree(G, u);
}

// Hàm tính nửa bậc trong và ngoài của đỉnh u


 
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