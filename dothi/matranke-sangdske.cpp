#include<iostream>
 #include<map>
 #include<set>
 using namespace std;


void Input(map<int,set<int>> number_list, int n){
cin>>n;
int x;
for (int i = 1; i <= n; i++){
    for (int j = 1 ; j <= n ; j ++){
        cin>>x;
        if (x == 1){
            number_list[i].insert(j);
            number_list[j].insert(i);
        }
    }
}

set<int>::iterator it;

for (int i = 1 ; i <= n; i++){
    if (number_list[i].empty()  == true){
        continue;
    }
    cout<<i<<"->";
for (it=number_list[i].begin(); it!=number_list[i].end(); ++it){
cout << *it << ' ';
}
cout<<endl;
}
}


 
int main()
{
	map<int,set<int>> number_list;
	int n;
	Input(number_list,n);
	return 0;
}
