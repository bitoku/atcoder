#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; ++i) {
        q[p[i]] = i+1;
    }
    cout << q[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << q[i];
    }
    cout << endl;
}