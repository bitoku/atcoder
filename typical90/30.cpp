#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for (int i = 2; i <= n; i += 2) {
        v[i]++;
    }
    ll result = 0;
    for (int i = 3; i <= n; i += 2) {
        if (v[i] > 0) continue;
        for (int j = i; j <= n; j += i) {
            v[j]++;
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (v[i] >= k) result++;
    }
    cout << result << endl;
}