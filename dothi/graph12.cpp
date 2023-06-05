  #include<iostream>
 #include<vector>
 #include<map>
 #include<set>
 using namespace std;



void Input(int &v,map<string, int>& v_index, int& e,vector<vector<int>>& G  ){
string s;
map<int, string> v_label;
for (int i  = 0; i< v; i++){
    cin>>s;
    v_index[s] = i;
    v_label[i] = s;
}


map<int,set<int>> number_list;


string x,y;
int z;
for (int i = 0; i < e; i++){
    cin>>x;
    cin>>y;
    cin>>z;
    number_list[v_index[x]].insert(v_index[y]);
    number_list[v_index[y]].insert(v_index[x]);
}
int find;
cin>>find;
bool check = false;
cout<<number_list[5].size();

for (int i = 0 ; i < v ; i++){
     
        if (number_list[i].size() == find){
            cout<<v_label[i]<<" ";
            check = true;
        }

}
if (check == false){
    cout<<"No find";
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
