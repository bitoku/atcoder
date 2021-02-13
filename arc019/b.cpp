#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string a;
    cin >> a;
    vector<int> diffidx;
    if (a.size() == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < a.size() / 2; ++i) {
        if (a[i] != a[a.size() - i - 1]) {
            diffidx.push_back(i);
        }
    }
    if (diffidx.size() > 1) {
        cout << 25 * a.size() << endl;
        return 0;
    }
    if (diffidx.empty()) {
        if (a.size() % 2 == 0) {
            cout << 25 * a.size() << endl;
        } else {
            cout << 25 * (a.size() - 1) << endl;
        }
        return 0;
    }
    cout << 25 * a.size() - 2 << endl;
}
