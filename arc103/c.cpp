#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> even, odd;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (i % 2 == 0) {
            even[v[i]]++;
        } else {
            odd[v[i]]++;
        }
    }
    pair<ll, ll> even1, even2, odd1, odd2;
    even1.second = 0;
    odd1.second = 0;
    even2.second = 0;
    odd2.second = 0;
    for (const auto [k, x]: even) {
        if (x > even1.second) {
            even2.first = even1.first;
            even2.second = even1.second;
            even1.first = k;
            even1.second = x;
        } else if (x > even2.second) {
            even2.first = k;
            even2.second = x;
        }
    }
    for (const auto [k, x]: odd) {
        if (x > odd1.second) {
            odd2.first = odd1.first;
            odd2.second = odd1.second;
            odd1.first = k;
            odd1.second = x;
        } else if (x > odd2.second) {
            odd2.first = k;
            odd2.second = x;
        }
    }
    if (odd1.first != even1.first) {
        cout << n - odd1.second - even1.second << endl;
    } else {
        cout << n - max(odd1.second + even2.second, odd2.second + even1.second) << endl;
    }
}
