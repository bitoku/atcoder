#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll q;
    cin >> q;
    map<ll, ll> mp;
    ll offset = 0;
    for (int i = 0; i < q; ++i) {
        int query;
        ll x;
        cin >> query;
        if (query == 1) {
            cin >> x;
            mp[x - offset]++;
        }
        if (query == 2) {
            cin >> x;
            offset += x;
        }
        if (query == 3) {
            x = mp.begin()->first;
            cout << x + offset << endl;
            mp[x]--;
            if (mp[x] == 0) mp.erase(x);
        }
    }
}