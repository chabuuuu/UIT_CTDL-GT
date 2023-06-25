#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int i = 0, j = n - 1;
    int sum = -1;

    while (i < j) {
        int curSum = a[i] + a[j];
        if (curSum <= x) {
            sum = max(sum, curSum);
            i++;
        } else {
            j--;
        }
    }

    cout << sum << endl;

    int count = 0;
    for (int k = 0; k < n; k++) {
        if (a[k] <= (sum / 2)) {
            count++;
        }
    }

    bool impossible = (count < 4);

    if (impossible) {
        cout << "Impossible" << endl;
        return 0;
    } else {
        for (int k = 1; k < n; k++) {
            if (a[k] <= (sum / 2)) {
                cout << k + 1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}