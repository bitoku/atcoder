#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> cnt(1000002);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        b++;
        cnt[a]++;
        cnt[b]--;
    }
    ll result = 0;
    ll temp = 0;
    for (int i = 0; i < 1000001; ++i) {
        temp += cnt[i];
        result = max(temp, result);
    }
    cout << result << endl;
}
