#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, x;
    cin >> n >> x;
    if (x == 1 || x == 2 * n - 1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    if (n == 2) {
        cout << "1 2 3" << endl;
        return 0;
    }
    vector<ll> t;
    vector<ll> v;
    if (x == 2) {
        v = {4, 1, 2, 3};
        for (int i = 1; i <= 2 * n - 1; ++i) {
            if (1 <= i && i <= 4) continue;
            t.push_back(i);
        }
    } else {
        v = {x-2, x+1, x, x-1};
        for (int i = 1; i <= 2 * n - 1; ++i) {
            if (x-2 <= i && i <= x+1) continue;
            t.push_back(i);
        }
    }
    for (int i = 0; i < n - 3; ++i) {
        cout << t[i] << endl;
    }
    for (int i = 0; i < 4; ++i) {
        cout << v[i] << endl;
    }
    for (int i = n - 3; i < 2 * n - 5; ++i) {
        cout << t[i] << endl;
    }
}