#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        for (int j = 0; (1 << j) <= a; ++j) {
            if (a & (1 << j)) {
                cnt += j;
                break;
            }
        }
    }
    cout << cnt << endl;
}
