#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    set<ll> used;
    for (ll i = 2; i * i <= n; ++i) {
        if (used.find(i) != used.end()) continue;
        ll temp = i * i;
        while (temp <= n) {
            used.insert(temp);
            temp *= i;
        }
    }
    cout << n - used.size() << endl;
}
