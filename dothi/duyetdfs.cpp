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

void DFS(vector<vector<int>>& G,map<string, int>& v_index, int v, string find, string dich){
bool visited[MAX_SIZE] = {false};
    // string find;
    // cin>>find;
    // string dich;
    // cin>>dich;
    queue<string> Close;
    map<string, string> parent;
    // Khởi tạo stack và đưa đỉnh bắt đầu vào stack
    stack<int> stk;
    stk.push(v_index[find]);

    // Duyệt DFS
    while (!stk.empty()) {
        // Lấy đỉnh đầu stack và đánh dấu đã thăm
        int current_vertex = stk.top();
        // if (current_vertex == v_index[dich])
        // {   string dung = "";            
        //     string batdau = dich;

        //     while (dung != find ){
        //         dung = parent[batdau] ;
        //         batdau = dung;
        //         cout<<dung<<" ";
        //     }
        //     cout<<endl;

        //     return;
        // }
        
        stk.pop();
        visited[current_vertex] = true;
        Close.push(v_label[current_vertex]);

        // In ra đỉnh hiện tại
        // cout << v_label[current_vertex] << " ";

        // Duyệt các đỉnh kề chưa được thăm và đưa vào stack
        for (int i = 0; i < v; i++) {
            if (G[current_vertex][i] != 0  && !visited[i]) {
                stk.push(i);
                parent[v_label[i]] = v_label[current_vertex];
        if (i == v_index[dich])
        {   string dung = "";            
            string batdau = dich;

            while (dung != find ){
                dung = parent[batdau] ;
                batdau = dung;
                cout<<dung<<" ";
            }
            cout<<parent["K"];
            cout<<endl;

            return;
        }
            }
        }
    }
}


// bool isReachable(vector<vector<int>>& graph, int src, int dest,vector<bool> &discovered, vector<int> &path, int e, int v)
// {
//     // mark the current node as discovered
//     discovered[src] = true;
 
//     // include the current node in the path
//     path.push_back(src);
 
//     // if destination vertex is found
//     if (src == dest) {
//         return true;
//     }
//         for (int i = v; i >= 0; i--) {
//             if (graph[src][i] != 0 && discovered[i] != true ){
//                   if (isReachable(graph, i, dest, discovered, path, e , v)) {
//                 return true;
//             }
//             }
//         }
    
//     // backtrack: remove the current node from the path
//     path.pop_back();
 
//     // return false if destination vertex is not reachable from src
//     return false;
// }


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
    //         vector<bool> visited = {false};
    // vector<int> path;
           cin>>dau>>dich;
//     if (isReachable(G, v_index[dau], v_index[dich], visited, path, e, v) == true)
// {
//     for (int i: path) {
//         cout << v_label[i] << ' ';
//     }
//     cout << endl;
// }else{
//     cout<<"no_path"<<endl;
// }	// DFS(G,v_index,v);
    DFS(G, v_index, v, dau, dich);
    }
 
	return 0;
}
