#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> students(n);
    for (int i = 0; i < n; i++) {
        students[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        int student;
        cin >> student;

        // Tìm vị trí của sinh viên trong hàng đợi
        auto it = find(students.begin(), students.end(), student);

        // Dịch chuyển sinh viên đến đầu hàng
        if (it != students.end()) {
            students.erase(it);
            students.insert(students.begin(), student);
        }
    }

    // In thứ tự sinh viên
    for (int i = 0; i < n; i++) {
        cout << students[i] << " ";
    }
    cout << endl;

    return 0;
}
