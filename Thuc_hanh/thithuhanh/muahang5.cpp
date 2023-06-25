#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<pair<int, int>> items;
    for (int i = 0; i < N; i++) {
        int price;
        cin >> price;
        items.push_back(make_pair(price, i + 1));
    }

    sort(items.begin(), items.end());

    int total = 0;
    vector<int> selectedItems;
    int left = 0, right = N - 1;

    while (left < right) {
        if (items[left].first + items[right].first <= X) {
            total = items[left].first + items[right].first;
            selectedItems.push_back(items[left].second);
            selectedItems.push_back(items[right].second);

            break;
        }
        right--;
    }

    if (selectedItems.size() < 2) {
        cout << "Impossible" << endl;
    } else {
        sort(selectedItems.begin(), selectedItems.end());

        int remaining = X - total;
        left = 0;
        right = N - 1;

        while (left < right) {
            if (left != selectedItems[0] - 1 && left != selectedItems[1] - 1 &&
                right != selectedItems[0] - 1 && right != selectedItems[1] - 1 &&
                items[left].first <= remaining) {
                total += items[left].first;
                selectedItems.push_back(items[left].second);

                if (selectedItems.size() == 4)
                    break;
            }
            left++;
        }

        if (selectedItems.size() < 4) {
            cout << "Impossible" << endl;
        } else {
            cout << total << endl;
            for (int i = 0; i < 4; i++) {
                cout << selectedItems[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
