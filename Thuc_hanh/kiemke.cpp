#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void customSort(vector<int> & a, int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
			j--;
		}
		if (i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		customSort(a, i, r);
	}
	if (l < j){
		customSort(a, l, j);
	}
}
int main() {
    int n;
    cin >> n;

    vector<int> codes(n);
    for (int i = 0; i < n; i++) {
        cin >> codes[i];
    }
    customSort(codes,0, n - 1 );
    int count = 1;
    for (int i = 1; i <n ; i++){
        if (codes[i] != codes[i - 1]){
            count++;
        }
    }
    cout<<count;
    return 0;
}
