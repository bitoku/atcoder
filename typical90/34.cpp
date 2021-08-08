#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0, r = 0;
    map<ll, int> mp;
    ll result = 0;
    for (r = 0; r < n; ++r) {
        mp[a[r]]++;
        while (mp.size() > k) {
            mp[a[l]]--;
            if (mp[a[l]] == 0) mp.erase(a[l]);
            l++;
        }
        result = max(result, (ll)r - l + 1);
    }
    cout << result << endl;
}