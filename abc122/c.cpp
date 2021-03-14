#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> x(n);
    for (int i = 1; i < n; ++i) {
        x[i] = x[i-1];
        if (s[i-1] == 'A' && s[i] == 'C') {
            x[i]++;
        }
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << x[r-1] - x[l-1] << endl;
    }
}
