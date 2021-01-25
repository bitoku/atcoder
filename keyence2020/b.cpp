#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> line(n);
    for (int i = 0; i < n; ++i) {
        int x, l;
        cin >> x >> l;
        line[i] = make_pair(x - l, x + l);
    }
    sort(line.begin(), line.end());
    int cnt = 0;
    ll current_left = LONG_LONG_MIN;
    ll current_right = LONG_LONG_MIN;
    for (int i = 0; i < n; ++i) {
        int left = line[i].first;
        int right = line[i].second;
        if (left == current_left || left < current_right) {
            if (right < current_right) {
                current_left = left;
                current_right = right;
            }
            cnt++;
        } else {
            current_left = left;
            current_right = right;
        }
    }
    cout << n - cnt << endl;
}
