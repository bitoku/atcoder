#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ll result = 0;
    for (int take = 1; take <= min(n, k); ++take) {
        for (int left = 0; left <= take; ++left) {
            ll temp = 0;
            multiset<int> minus;
            for (int i = 0; i < left; ++i) {
                temp += v[i];
                if (v[i] < 0) {
                    minus.insert(v[i]);
                }
            }
            for (int i = n - 1; i >= n - take + left; --i) {
                temp += v[i];
                if (v[i] < 0) {
                    minus.insert(v[i]);
                }
            }
            auto it = minus.begin();
            for (int i = 0; i < k - take && it != minus.end(); ++i) {
                temp -= *(it++);
            }
            result = max(result, temp);
        }
    }
    cout << result << endl;
}
