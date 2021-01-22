#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> cards;
    vector<int> lis;
    cin >> n;
    for (int i=0;i<n;i++) {
        int a;
        cin >> a;
        cards.push_back(a);
    }
    for (auto card: cards) {
        auto it = upper_bound(lis.begin(), lis.end(), card);
        if (it == lis.end()) {
            lis.push_back(card);
        } else {
            *it = card;
        }
    }
    cout << cards.size() - lis.size() << endl;
    return 0;
}
