#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    set<int, greater<>> s;
    s.insert(0);
    for (int i = 0; i < n; ++i) {
        int x;
        set<int, greater<>> ns;
        cin >> x;
        for (const auto k : s) {
            ns.insert(k);
            ns.insert(k + x);
        }
        s = ns;
    }
    for (const auto k : s) {
        if (k != 0 && k % 10 == 0) continue;
        cout << k << endl;
        break;
    }
}
