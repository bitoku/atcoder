#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll x, y;
    cin >> x >> y;
    ll cnt = 0;
    for (; x <= y; x <<= 1) {
        cnt++;
    }
    cout << cnt << endl;
}
