#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll> consumption(200001);
    for (int i = 0; i < n; ++i) {
        ll s, t, p;
        cin >> s >> t >> p;
        consumption[s] += p;
        consumption[t] -= p;
    }
    for (int i = 1; i < 200001; ++i) {
        consumption[i] += consumption[i - 1];
    }
    for (int i = 0; i < 200001; ++i) {
        if (consumption[i] > w) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}
