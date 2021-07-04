#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    int b = -1;
    int cnt = 0;
    vector<ll> k;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (b < a) cnt++;
        else {
            k.push_back(cnt);
            cnt = 1;
        }
        b = a;
    }
    k.push_back(cnt);
    ll result = 0;
    for (auto x: k) {
        result += (x + 1) * x / 2;
    }
    cout << result << endl;
}