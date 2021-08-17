#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<ll> sumx(n+1), sumy(n+1);
    for (int i = 0; i < n; ++i) {
        sumx[i+1] = sumx[i] + x[i];
        sumy[i+1] = sumy[i] + y[i];
    }
    ll result = 0;
    ll temp = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        temp = min(temp, sumx[n] - sumx[i+1] - sumx[i] + i * x[i] - (n - i - 1) * x[i]);
    }
    result += temp;
    temp = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        temp = min(temp, sumy[n] - sumy[i+1] - sumy[i] + i * y[i] - (n - i - 1) * y[i]);
    }
    result += temp;
    cout << result << endl;
}