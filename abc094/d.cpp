#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int x = a.back() / 2;
    auto it = lower_bound(a.begin(), a.end(), x);
    if (it == a.begin()) {
        cout << a.back() << ' ' << *it << endl;
    } else {
        auto before = it-1;
        if (*it == a.back() || abs(*it - x) > abs(*before - x)) {
            cout << a.back() << ' ' << *before;
        } else {
            cout << a.back() << ' ' << *it;
        }
    }
}
