#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    ll k;
    cin >> n >> k;
    vector<string> s(n+2);
    s[0] = string("#", n+2);
    s[n+1] = string("#", n+2);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] = "#" + s[i] + "#";
    }

}