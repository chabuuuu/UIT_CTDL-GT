
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int>& A,int K){
	map<int,int> Hash;

for (int i = 0; i < n; i++) {
        Hash[A[i]]++;
    }

   
    int index = 0 ;
     vector<int> selectedColors;
     int count  = K;
    for (auto it = Hash.begin(); it != Hash.end(); it++) {
        if (count > 0){
            selectedColors.push_back(it->first);
        }
        count -- ; 
    }
       
       
       if (selectedColors.size() ==  K){
        return selectedColors;
    }
    int temp  = K - Hash.size();

    for (int i  = 0 ; i < temp; i ++){
       for (int i = 0; i < selectedColors.size(); i ++){
        if (temp == 0){
            break;
        }
        if (Hash[selectedColors[i]] > 1){
            Hash[selectedColors[i]] --;
            selectedColors.push_back(selectedColors[i]);
            temp -- ;
        }
       }
    }
      

    return selectedColors;


	
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> k;
	
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> ans = get_ans(a,k);
	
	for (const int& x: ans) cout << x << ' ';
	return 0;
}
