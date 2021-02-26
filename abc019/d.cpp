#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int N;
    cin >> N;
    ll mx = 0;
    int mi = 0;
    for (int i = 2; i <= N; ++i) {
        cout << "? " << 1 << ' ' << i << endl;
        ll x;
        cin >> x;
        if (x > mx) {
            mx = x;
            mi = i;
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (i == mi) continue;
        cout << "? " << i << ' ' << mi << endl;
        ll x;
        cin >> x;
        if (x > mx) {
            mx = x;
        }
    }
    cout << "! " << mx << endl;
}
