#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        v[--l]++;
        v[r]--;
    }
    for (int i = 1; i <= n; ++i) {
        v[i] += v[i-1];
        if (v[i-1] % 2 == 0) cout << '0';
        else cout << '1';
    }
    cout << endl;
}
