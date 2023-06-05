 #include<iostream>
 #include<vector>
 #include<map>
 using namespace std;


void Input(int &v,map<string, int>& v_index, int e,vector<vector<int>>& G  ){
string s;
for (int i  = 0; i< v; i++){
    cin>>s;
    v_index[s] = i;
}
    for(int i = 0;i<e;i++){
        string x, y;
        int z;
        cin>>x>>y;
        cin>>z;
        G[v_index[x]][v_index[y]] = z;
    }
    for(int i = 0;i<v;i++){
        for(int j =0 ;j<v;j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }

}





int main()
{
    	int v,e; //v là số đỉnh, e là số cạnh
	cin>>e>>v;
	vector<vector<int>> G (v,vector<int>(v,0)); // ma trận kề
	map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
	Input(v,v_index,e,G);
	return 0;
}
