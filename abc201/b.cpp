#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<string> s(n);
    vector<ll> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> t[i];
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {return t[i] < t[j];});
    cout << s[idx[n - 2]] << endl;
}