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

void Input(int v,map<string, int> &v_index, int e, vector<vector<int>> &G)
{
    string t1, t2;
    for(int i=0; i<v; i++)
    {
        cin>>t1;
        v_index[t1]=i;
    }
    for(int i=0; i<e; i++)
    {
        cin>>t1>>t2;
        int i1=v_index[t1], i2=v_index[t2];
        G[i1][i2]=1;
    }
}

void BFS (vector<vector<int>> G, map<string, int>v_index, int v)
{
    queue<string> open;
    vector<bool> close(v,0);
    map<int, string> a_index;
    for(map<string, int>::iterator i=v_index.begin(); i!=v_index.end(); i++)
        {
            a_index[i->second]=i->first;
        }
    
    vector<string> ans;

    string s; cin>>s;
    open.push(s);
    while(!open.empty())
    {
        string p=open.front(); open.pop();
        close[v_index[p]]=1;

        vector<string> dinhke;
        for (int i=0; i<v; i++)
        {
            if(G[v_index[p]][i]==1) dinhke.push_back(a_index[i]);
        }

        for(int i=0; i<dinhke.size(); i++)
        {
            if(close[v_index[dinhke[i]]]==0) open.push(dinhke[i]);
        }

ans.push_back(p);
    }
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}
 
int main()
{ 
    int v,e; //v là số đỉnh, e là số cạnh
	cin>>e>>v;
	vector<vector<int>> G (v,vector<int>(v,0)); // ma trận kề
	map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
	Input(v,v_index,e,G);
	BFS(G,v_index,v);
	return 0;
}