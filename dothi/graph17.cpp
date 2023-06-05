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


void BFS(vector<vector<int>>& G,map<string, int>& v_index, int v){
 
    queue<string> Open;
    vector<bool> Close(v,false);

    vector<string> res;
    string find; 
    cin>>find;
    Open.push(find);


    while( !Open.empty() )
    {
        string p=Open.front(); 
        Open.pop();
        Close[v_index[p]]=true;

        vector<string> listDinhKe;

        for (int i=0; i<v; i++)
        {
            if(G[v_index[p]][i]==1) 
            {
                listDinhKe.push_back(v_label[i]);
            }
        }

        for (int i=0; i<listDinhKe.size(); i++)
        {
            if( Close[v_index[listDinhKe[i]]] !=  true) {

                Open.push(listDinhKe[i]);

            }
        }

        res.push_back(p);
    }
    
    
    for (int i=0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
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

