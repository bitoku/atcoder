#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    int m = p[0];
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] <= m) result++;
        m = min(m, p[i]);
    }
    cout << result << endl;
}
