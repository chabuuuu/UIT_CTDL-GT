#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, int start, int end, vector<bool>& visited, vector<int>& path) {
    visited[start] = true;
    path.push_back(start);
    if (start == end) {
        return;
    }
    for (int i = graph[start].size() - 1; i >=0; i--){
        int neighbor = graph[start][i];
        if (!visited[neighbor]) {
            dfs(graph, neighbor, end, visited, path);
            if (!path.empty() && path.back() == end) {
                return;
            }
        }
    }

    // for (int neighbor : graph[start]) {
    //     if (!visited[neighbor]) {
    //         dfs(graph, neighbor, end, visited, path);
    //         if (!path.empty() && path.back() == end) {
    //             return;
    //         }
    //     }
    // }
    path.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<string> vertices(n);

    for (int i = 0; i < n; i++) {
        cin >> vertices[i];
    }

    for (int i = 0; i < m; i++) {
        string start, end;
        cin >> start >> end;

        int startIndex = -1, endIndex = -1;
        for (int j = 0; j < n; j++) {
            if (vertices[j] == start) {
                startIndex = j;
            }
            if (vertices[j] == end) {
                endIndex = j;
            }
        }

        if (startIndex != -1 && endIndex != -1) {
            graph[startIndex].push_back(endIndex);
        }
    }

    int numQueries;
    cin >> numQueries;

    for (int i = 0; i < numQueries; i++) {
        string start, end;
        cin >> start >> end;

        int startIndex = -1, endIndex = -1;
        for (int j = 0; j < n; j++) {
            if (vertices[j] == start) {
                startIndex = j;
            }
            if (vertices[j] == end) {
                endIndex = j;
            }
        }

        if (startIndex != -1 && endIndex != -1) {
            vector<bool> visited(n, false);
            vector<int> path;
            dfs(graph, startIndex, endIndex, visited, path);

            if (!path.empty() && path.back() == endIndex) {
                for (int vertex : path) {
                    cout << vertices[vertex] << " ";
                }
                cout << endl;
            } else {
                cout << "no_path" << endl;
            }
        } else {
            cout << "no_path" << endl;
        }
    }

    return 0;
}
