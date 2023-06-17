#include <iostream>
#include <vector>

using namespace std;

void swap (vector<int>& arr, int i, int max){
int temp = arr[i];
arr[i] = arr[max];
arr[max] = temp;
}

void selectionSort(vector<int>& arr) {
   int i = 0;
   int n = arr.size();
   int max;
   while ( i < n - 1){
    max = i;
    int j = i + 1;

    while (j < n){
        if (arr[j] > arr[max]){
            max = j;  
        }
           j++;
    }
    cout<<"i="<<i<<": "<<"swap ";
    cout<<"("<<arr[i]<<"-"<<arr[max]<<")"<<endl;
    swap(arr, i, max);
    i++;
   }
}

int main() {
    vector<int> A;
    int num;
    
    while (cin >> num && num != -1) {
        A.push_back(num);
    }

    selectionSort(A);

    return 0;
}
