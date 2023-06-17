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
	int x ;
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



void BFS(vector< vector<int> > G, map<string, int> index, int v) {
	string s1;
    string s2;
	cin >> s1 >> s2;

	vector< pair<string, int> > vector_index(index.begin(), index.end());


	sort(vector_index.begin(),vector_index.end(),cmp);

	map<string, int>::iterator it;

	it = index.find(s1);
	int X = it->second;
	it = index.find(s2);
	int Y = it->second;

	if(Find(G,v,X) == false) {
		cout << "no_path" << endl;
		return;
	}

	int addr = 0;
	stack<int> Close;
	Close.push(Y);

	while(true) {
		addr = Print(G,v,Y,X);
		Close.push(addr);
		if(addr == X) {
			break;
		}
		Y = addr;
	}

	while(!Close.empty()) {
		addr = Close.top();
		cout << vector_index[addr].first << ' ';
		Close.pop();
	}

	cout << "\n";
}

int main()
{
    int v,e;
	cin >> v >> e;
	vector< vector<int> > G (v,vector<int>(v,0));
	map<string, int> v_index;
	Input(v,v_index,e,G);
	int N;
	cin >> N;
	while(N--) {
		BFS(G,v_index,v);
	}
	return 0;
}