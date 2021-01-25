#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<unsigned long long> f(n+1);
    vector<unsigned long long> t(n+1);
    f[0] = 1;
    t[0] = 1;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        if (s == "OR") {
            f[i] = f[i-1];
            t[i] = f[i-1] + 2 * t[i-1];
        } else {
            f[i] = f[i-1] * 2 + t[i-1];
            t[i] = t[i-1];
        }
    }
    cout << t[n] << endl;
}
