#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    int n;
    cin >> n;
    deque<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll result = a.front();
    vector<pair<ll, ll>> ope;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] < 0) continue;
        ope.emplace_back(result, a[i]);
        result -= a[i];
    }
    ope.emplace_back(a.back(), result);
    result = a.back() - result;
    for (int i = 1; i < n - 1 && a[i] < 0; ++i) {
        ope.emplace_back(result, a[i]);
        result -= a[i];
    }
    cout << result << endl;
    for (int j = 0; j < ope.size(); ++j) {
        cout << ope[j].first << ' ' << ope[j].second << endl;
    }
}
