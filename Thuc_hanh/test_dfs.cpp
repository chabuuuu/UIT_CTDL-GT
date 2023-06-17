#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

bool cmp(pair<string,int> a, pair<string,int> b) {
    return a.second < b.second;
}

void Input(int v, map<string, int> &index, int e, vector< vector<int> > &G) {
    string nhap;

    for(int i = 0; i < v; i++) {
        cin >> nhap;
        index[nhap] = i;
    }
    string s1,s2;
    int x;
    int y;
    map<string, int>::iterator it;
    int temp = e;
    while(temp--) {
        cin >> s1 >> s2;
        it = index.find(s1);
        x = it->second;
        it = index.find(s2);

        y = it->second;

        G[x][y] = 1;
    }
}

bool Find(vector< vector<int> > &G, int v, int X) {
    for(int index = 0; index < v; index++) {
        if(G[X][index] != 0) {
            return true;
        }
    }
    return false;
}

int Print(vector< vector<int> > G, int v, int x, int y) {
    if(G[y][x] != 0) {
        return y;
    }
    for(int index = v-1; index >= 0; index--) {
        if(G[index][x] != 0) {
            G[index][x] = 0;
            return index;
        }
    }
    return -1;
}

void DFS(vector< vector<int> > G, map<string, int> index, int v, int X, int Y, vector<int>& visited, stack<int>& path) {
    visited[X] = 1;
    path.push(X);

    if (X == Y) {
        while (!path.empty()) {
            int addr = path.top();
            cout << vector_index[addr].first << ' ';
            path.pop();
        }
        cout << "\n";
        return;
    }

    for (int index = 0; index < v; index++) {
        if (G[X][index] != 0 && visited[index] == 0) {
            DFS(G, index, Y, visited, path);
        }
    }

    visited[X] = 0;
    path.pop();
}

void DFSWrapper(vector< vector<int> > G, map<string, int> index, int v) {
    string s1;
    string s2;
    cin >> s1 >> s2;

    vector< pair<string, int> > vector_index(index.begin(), index.end());
    sort(vector_index.begin(), vector_index.end(), cmp);

    map<string, int>::iterator it;

    it = index.find(s1);
    int X = it->second;
    it = index.find(s2);
    int Y = it->second;

    if (Find(G, v, X) == false) {
        cout << "no_path" << endl;
        return;
    }

    vector<int> visited(v, 0);
    stack<int> path;
    DFS(G, index, v, X, Y, visited, path);
}

int main() {
    int v,e;
    cin >> v >> e;
    vector< vector<int> > G (v, vector<int>(v, 0));
    map<string, int> v_index;
    Input(v, v_index, e, G);
    int N;
    cin >> N;
    while(N--) {
        DFSWrapper(G, v_index, v);
    }
    return 0;
}
