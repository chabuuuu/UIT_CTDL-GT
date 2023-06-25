#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    
    cin >> n;

    vector<int> array(n);


    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[array[i]]++;
    }




    int ketQua = 0;

    for (auto it = count.begin(); it != count.end(); ++it) {
        int value = it->second;
        int key = it->first;




        if (key > value) {

            ketQua = ketQua + value;
        } else {
            ketQua = ketQua + value - key;
        }
    }

    cout << ketQua << endl;

    return 0;
}
