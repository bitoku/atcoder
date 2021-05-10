#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool possible = false;
    int x = 0;
    for (int i = 0; i < n-1; ++i) {
        if (a[i] + a[i+1] >= l) {
            x = i;
            possible = true;
        }
    }
    if (!possible) {
        cout << "Impossible" << endl;
        return 0;
    }
    vector<int> k;
    for (int i = x; i < n - 1; ++i) {
        k.push_back(i);
    }
    for (int i = x-1; i >= 0; --i) {
        k.push_back(i);
    }
    cout << "Possible" << endl;
    reverse(k.begin(), k.end());
    for (int i = 0; i < n - 1; ++i) {
        cout << k[i] + 1 << endl;
    }

}