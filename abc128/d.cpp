#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 06/26

int main() {
    ll n, k;
    cin >> n >> k;
    deque<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ll result = 0;
    // 合計i個とる
    for (int i = 1; i <= min(k, n); ++i) {
        // 左からj個取る
        for (int j = 0; j <= i; ++j) {
            priority_queue<ll, vector<ll>, greater<>> s;
            for (int l = 0; l < j; ++l) {
                s.push(v[l]);
            }
            for (int l = n-1; l >= n - i + j; --l) {
                s.push(v[l]);
            }
            for (int l = 0; l < k - i && !s.empty(); ++l) {
                if (s.top() > 0) break;
                s.pop();
            }
            ll temp = 0;
            while (!s.empty()) {
                temp += s.top(); s.pop();
            }
            result = max(result, temp);
        }
    }
    cout << result << endl;
}