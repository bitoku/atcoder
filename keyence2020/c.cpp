#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k, s;
    cin >> n >> k >> s;
    if (k == 0) {
        cout << s-1;
        for (int i = 1; i < n; ++i) {
            cout << ' ' << s-1;
        }
        cout << endl;
        return 0;
    }
    cout << s;
    for (int i = 1; i < k; ++i) {
        cout << ' ' << s;
    }
    for (int i = k; i < n; ++i) {
        if (s <= 2) {
            cout << ' ' << s+1;
        } else {
            cout << ' ' << s-1;
        }
    }
    cout << endl;
}