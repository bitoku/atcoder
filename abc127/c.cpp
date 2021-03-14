#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n+2);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        x[l]++;
        x[r+1]--;
    }
    for (int i = 1; i < n + 2; ++i) {
        x[i] += x[i-1];
    }
    ll result = 0;
    for (int i = 0; i < n + 2; ++i) {
        if (x[i] == m) {
            result++;
        }
    }
    cout << result << endl;
}
