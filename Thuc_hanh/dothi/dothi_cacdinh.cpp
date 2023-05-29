#include<iostream>
 #include<map>
 #include<set>
 using namespace std;


void Input(map<int,set<int>> number_list, int n){
cin>>n;
int x,y;
for (int i = 0; i < n; i++){
    cin>>x;
    cin>>y;
    number_list[0].insert(x);
    number_list[0].insert(y);
}

set<int>::iterator it;

for (it=number_list[0].begin(); it!=number_list[0].end(); ++it){
cout << *it << ' ';
}
}


 
int main()
{
	map<int,set<int>> number_list;
	int n;
	Input(number_list,n);
	return 0;
}
