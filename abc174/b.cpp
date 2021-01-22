#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, D;
    cin >> N >> D;
    ll cnt = 0;
    for (int i = 0; i < N; ++i) {
        ll x, y;
        cin >> x >> y;
        if (sqrt(x * x + y * y) <= D) {
            cnt++;
        }
    }
    cout << cnt << endl;
}
