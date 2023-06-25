#include <iostream>
#include <vector>
#include<map>
#include <algorithm>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<pair<int, int>> items;
    for (int i = 1; i <= N; i++) {
        int price;
        cin >> price;
        items.push_back(make_pair(price, i));
    }

    sort(items.begin(), items.end()); 

    int sum = 0;
    vector<int> chosen_items;
    map<int, int> result;
    int start = 0;
    int end = N - 1;

    while (start < end) {
        if (sum + items[start].first + items[end].first <= X) {
            sum += items[start].first;
            chosen_items.push_back(items[start].second);
            result[items[start].second];
            sum += items[end].first;
            chosen_items.push_back(items[end].second);
            result[items[end].second]++;
            if (chosen_items.size() == 4)
                break;

            start++;
            end--;
        } else {
            end--;
        }
    }

    if (chosen_items.size() < 4)
        cout << "Impossible" << endl;
    else {
        cout << sum << endl;
        // for (int i = 0; i < 4; i++)
        //     cout << chosen_items[i] << " ";
        for (auto it = result.begin(); it != result.end(); it++) {
        cout<<it->first<<" ";
    }
        cout << endl;
    }

    return 0;
}
