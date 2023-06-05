#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

void BFS(vector<vector<int>>& graph, map<string, int>& vertexMap, int numVertices)
{
    vector<bool> visited(numVertices, false);
    queue<int> queue;
    string find;
    cin>>find;

    // Bắt đầu từ đỉnh đầu tiên
    visited[vertexMap[find]] = true;
    queue.push(vertexMap[find]);

    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();

        // In ra tên đỉnh hiện tại
        for (auto it = vertexMap.begin(); it != vertexMap.end(); ++it) {
            if (it->second == currentVertex) {
                cout << it->first << " ";
                break;
            }
        }

        // Duyệt qua các đỉnh kề chưa được thăm
        for (int i = 0; i < numVertices; ++i) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}

void Input(int v, map<string, int>& vertexMap, int e, vector<vector<int>>& G) {
    for (int i = 0; i < v; ++i) {
        string vertexName;
        cin >> vertexName;
        vertexMap[vertexName] = i;
    }

    for (int i = 0; i < e; ++i) {
        string start, end;
        cin >> start >> end;
        int startIndex = vertexMap[start];
        int endIndex = vertexMap[end];
        G[startIndex][endIndex] = 1;
        // G[endIndex][startIndex] = 1;
    }
}

int main()
{ 
    int v, e; //v là số đỉnh, e là số cạnh
    cin >> v >> e;
    vector<vector<int>> G(v, vector<int>(v, 0)); // ma trận kề
    map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
    Input(v, v_index, e, G);
    BFS(G, v_index, v);
    return 0;
}
