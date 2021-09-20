#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

vector<int> b;
vector<deque<ll>> a;

void push(int i) {
    if (a[i].empty()) return;
    ll x = a[i].front();
    a[i].pop_front();
    if (b[x] != -1) {
        push(i);
        int k = b[x];
        push(k);
        b[x] = -1;
    } else {
        b[x] = i;
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    a.resize(m);
    b.resize(n+1, -1);
    for (int i = 0; i < m; ++i) {
        ll k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            ll aa;
            cin >> aa;
            a[i].push_back(aa);
        }
    }
    for (int i = 0; i < m; ++i) {
        push(i);
    }
    for (auto x: b) {
        if (x != -1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}