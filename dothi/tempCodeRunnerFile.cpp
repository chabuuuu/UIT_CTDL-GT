const int MAX_SIZE = 100;
map<int, string> v_label;


void BFS(vector<vector<int>>& G,map<string, int>& v_index, int v){
// Khởi tạo mảng đánh dấu đã thăm
    bool Close[MAX_SIZE] = {false};

    string find;
    cin>>find;

    // Khởi tạo hàng đợi và đưa đỉnh bắt đầu vào hàng đợi
    queue<int> Open;
    Open.push(v_index[find]);

    // Duyệt BFS
    while (!Open.empty()) {
        // Lấy đỉnh đầu hàng đợi và đánh dấu đã thăm
        int p = Open.front();
        Open.pop();
        Close[p] = true;

        // In ra đỉnh hiện tại
        cout <<v_label[p] << " ";

        // Duyệt các đỉnh kề chưa được thăm và đưa vào hàng đợi
        for (int q = 0; q < v; q++) {
            if (G[p][q] != 0 && Close[q] != true ) {
                Open.push(q);
                Close[q] = true; // Đánh dấu đã thăm trước khi đưa vào hàng đợi
            }
        }
    }
}



void Input(int &v, map<string, int>& v_index, int &e, vector<vector<int>>& G  ){
string s;
for (int i  = 0; i< v; i++){
    cin>>s;
    v_index[s] = i;
    v_label[i] = s;
}

for(int i = 0;i<e;i++){
        string x, y;
        cin>>x>>y;
        G[v_index[x]][v_index[y]] = 1;
        // G[v_index[y]][v_index[x]] = 1;
    }
}

