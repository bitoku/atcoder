#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> drink(n);
    for (int i = 0; i < n; ++i) {
        cin >> drink[i].first >> drink[i].second;
    }
    sort(drink.begin(), drink.end());
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        if (m > drink[i].second) {
            result += drink[i].first * drink[i].second;
            m -= drink[i].second;
        } else {
            result += drink[i].first * m;
            break;
        }
    }
    cout << result << endl;
}
