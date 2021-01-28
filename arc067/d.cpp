#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    ll a, b;
    cin >> n >> a >> b;
    vector<int> x(n);
    cin >> x[0];
    ll result = 0;
    for (int i = 1; i < n; ++i) {
        cin >> x[i];
        result += min((x[i] - x[i-1]) * a, b);
    }
    cout << result << endl;
}
