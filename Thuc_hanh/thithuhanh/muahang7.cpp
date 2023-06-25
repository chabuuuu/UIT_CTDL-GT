#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

void nhap(int &N, vector<int>& a , int &toiDa){
    cin >> N>>toiDa;


    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
}

void chonQua(int &N, vector<int>& a , int &toiDa){

    vector<pair<int, int>> pairs;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            pairs.push_back(make_pair(a[i] + a[j], i * N + j));
        }
    }

    sort(pairs.begin(), 
    pairs.end(), 
    cmp);




int gtln = 0;
int x1, x2, x3, x4;
int left = 0;
int right = pairs.size() - 1;

while (left < right) {
int sum = pairs[left].first + pairs[right].first;

if (sum <= toiDa) {
int i = pairs[left].second / N;
int j = pairs[left].second % N;
int k = pairs[right].second / N;
int l = pairs[right].second % N;

if (i != j 
&& i != k
 && i != l 
 && j != k 
 && j != l 
 && k != l) {
    if (sum > gtln) {
        gtln = sum;
        x1 = i;
        x2 = j;
        x3 = k;
        x4 = l;
    }
}

left++;
}
else {
right--;
}
}

    if (gtln == 0) {
        cout << "Impossible" << endl;
    }
    else {
        cout << gtln << endl;
        cout << x1 + 1 << " " << x2 + 1 << " " << x3 + 1 << " " << x4 + 1 << endl;
    }
}

int main() {
    int N, toiDa;
    vector<int> a(N);
    nhap(N, a, toiDa);
    if (N < 4) {
        cout << "Impossible" << endl;
        return 0;
    }
    chonQua(N, a, toiDa);
    return 0;
}