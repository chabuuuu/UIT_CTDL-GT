#include<iostream>
#include<map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

const int MAX_SIZE = 100;
map<int, string> v_label;

void DFS(vector<vector<int>>& G,map<string, int>& v_index, int v, string find, string dich){
bool visited[MAX_SIZE] = {false};
    // Khởi tạo stack và đưa đỉnh bắt đầu vào stack
    if (find == dich){
        cout<<find<<" "<<dich<<endl;
        return;
    }
    map<int, int> parent;
    queue<int> stk;
    stk.push(v_index[find]);
    visited[v_index[find]] = true;

    // Duyệt DFS
    while (!stk.empty()) {
        // Lấy đỉnh đầu stack và đánh dấu đã thăm
        int current_vertex = stk.front();
        stk.pop();
        // visited[current_vertex] = true;

        // In ra đỉnh hiện tại
        // cout << v_label[current_vertex] << " ";

        // Duyệt các đỉnh kề chưa được thăm và đưa vào stack
        for (int i = 0; i < v; i++) {
            if (G[current_vertex][i] != 0  && !visited[i]) {
                stk.push(i);
                visited[i] = true;
                parent[i] = current_vertex;
                if (i == v_index[dich]){
                    int dinhCha;
                    int dinhCon = i;
                    stack<string> res ;
                    res.push(v_label[i]);
                    //cout<<v_label[i]<<" ";
                    while (dinhCha != v_index[find]){
                        dinhCha = parent[dinhCon];
                        res.push(v_label[dinhCha]);
                        //cout<<v_label[dinhCha]<<" ";
                        dinhCon = dinhCha;
                    }
                    while(res.empty() != true){
                        cout<<res.top()<<" ";
                        res.pop();
                    }
                    cout<<endl;
                    return;
                }
            }
        }
    }
    cout<<"no_path"<<endl;

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
    }
}


int main()
{ 
    int v,e; //v là số đỉnh, e là số cạnh
	cin>>v>>e;
	vector<vector<int>> G (v,vector<int>(v,0)); // ma trận kề
	map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
	Input(v,v_index,e,G);

    int n;
    cin>>n;
    string dau, dich;
    while (n--){
    cin>>dau>>dich;
    DFS(G, v_index, v, dau, dich);
    }
 
	return 0;
}
