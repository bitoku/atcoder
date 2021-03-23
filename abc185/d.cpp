#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    set<ll> blue;
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        blue.insert(a);
    }
    int cnt = 0;
    vector<int> gap;
    int last_blue = 0;
    for (const auto a : blue) {
        if (a - last_blue - 1 > 0) {
            gap.push_back(a - last_blue - 1);
        }
        last_blue = a;
    }
    if (n - last_blue > 0) {
        gap.push_back(n - last_blue);
    }
    if (gap.empty()) {
        cout << 0 << endl;
        return 0;
    }
    int k = *min_element(gap.begin(), gap.end());
    ll result = 0;
    for (int i = 0; i < gap.size(); ++i) {
        result += (gap[i] + k - 1) / k;
    }
    cout << result << endl;
}
