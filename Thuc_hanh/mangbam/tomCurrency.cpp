
#include <bits/stdc++.h>
using namespace std;


int N;

void count_distinct(const vector<int>& ids){

	map<int,int> Hash; 
	for (int  i = 0 ; i < ids.size(); i++){
        Hash[ids[i]]  ++;
    }
    cout<<Hash.size()<<endl;
     for (map<int,int>::iterator it=Hash.begin(); it!=Hash.end(); ++it){
           cout << it->first<<" ";
     }
 
   




}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> N;
	vector<int> ids(N);
	
	for (int i = 0; i < N; i++) cin >> ids[i];
		
	count_distinct(ids);

	return 0;
}

