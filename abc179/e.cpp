#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    ll result = 0;
    set<int> remainder;
    ll i;
    for (i = 0; i < n && remainder.find(x) == remainder.end(); ++i) {
        remainder.insert(x);
        result += x;
        x = x * x % m;
    }
    if (i == n) {
        cout << result << endl;
        return 0;
    }
    vector<int> loopx;
    ll y = x;
    loopx.push_back(x);
    x = x*x % m;
    int j;
    ll loop = y;
    for (j = 1; y != x; ++j) {
        loopx.push_back(x);
        loop += x;
        x = x * x % m;
    }
    result += (n - (i + 1)) / loopx.size() * loop;
    for (int k = 0; k <= (n - (i + 1)) % loopx.size(); ++k) {
        result += loopx[k];
    }
    cout << result << endl;
}
