#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll q;
    cin >> q;
    deque<ll> dq;
    for (int i = 0; i < q; ++i) {
        int t;
        ll x;
        cin >> t >> x;
        if (t == 1) dq.push_front(x);
        else if (t == 2) dq.push_back(x);
        else cout << dq[x-1] << endl;
    }
}