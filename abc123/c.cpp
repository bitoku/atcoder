#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n, x[5];
    cin >> n >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
    ll result = 0;
    ll k = min({x[0], x[1], x[2], x[3], x[4]});
    result += (n + k - 1) / k;
    result += 4;
    cout << result << endl;
}
