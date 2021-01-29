#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> s(n+1);
    map<ll, int> scnt;
    scnt[0]++;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
        scnt[s[i+1]]++;
    }
    ll result = 0;
    for (auto c: scnt) {
        ll cnt = c.second;
        result += cnt * (cnt - 1) / 2;
    }
    cout << result << endl;
}
