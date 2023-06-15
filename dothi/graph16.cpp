#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;




const int MAX_SIZE = 100;
map<int, string> v_label;

void DFS(vector<vector<int>>& G,map<string, int>& v_index, int v){
bool visited[MAX_SIZE] = {false};
    string find;
    cin>>find;
    string dich;
    cin>>dich;
    queue<string> Open;
    // Khởi tạo stack và đưa đỉnh bắt đầu vào stack
    stack<int> stk;
    stk.push(v_index[find]);

    // Duyệt DFS
    while (!stk.empty()) {
        // Lấy đỉnh đầu stack và đánh dấu đã thăm
        int current_vertex = stk.top();
        if (current_vertex == v_index[dich])
        {
            while (Open.empty() != true){
                cout<<Open.front()<<" ";
                Open.pop();
            }
            return;
        }
        
        stk.pop();
        visited[current_vertex] = true;
        Open.push(v_label[current_vertex]);
        // In ra đỉnh hiện tại
        // cout << v_label[current_vertex] << " ";

        // Duyệt các đỉnh kề chưa được thăm và đưa vào stack
        for (int i = 0; i < v; i++) {
            if (G[current_vertex][i] != 0  && !visited[i]) {
                stk.push(i);
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
    }
}



 
int main()
{ 
    int v,e; //v là số đỉnh, e là số cạnh
	cin>>v>>e;
	vector<vector<int>> G (v,vector<int>(v,0)); // ma trận kề
	map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
	Input(v,v_index,e,G);
	DFS(G,v_index,v);
	return 0;
}
