#include <iostream>
#include <vector>

using namespace std;

// void insertionSort(vector<int>& arr) {
//     int n = arr.size();
    
//     for (int i = 1; i < n; i++) {
//         int pos = arr[i];
//         int j = i - 1;

//         while (j >= 0 && arr[j] < pos) {
//             arr[j + 1] = arr[j];
//             j--;
//         }

//         arr[j + 1] = pos;
        
//         cout << "i=" << i << ": ";
//         cout << "pos=" << pos << "   ";
//         cout << "e=" << j + 1 << endl;
//     }
// }

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    int i = 1;
    int e, k;
    while (i<n){
        e = arr[i];
        k = i - 1;
        while (k>=0 && arr[k] <= e){
            arr[k+1] = arr[k];
            k = k - 1;
        }
        arr[k+1] = e;
           cout << "i=" << i << ": ";
       cout << "pos=" << e << "   ";
        cout << "e=" << k + 1 << endl;

        i = i + 1;
       
    }
 
    
}

int main() {
    vector<int> A;
    int num;
    
    while (cin >> num && num != -1) {
        A.push_back(num);
    }

    insertionSort(A);

    return 0;
}
