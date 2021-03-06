#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll acnt[500] = {};
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        acnt[a + 200]++;
    }
    ll result = 0;
    for (ll i = 0; i < 500; ++i) {
        if (acnt[i] == 0) continue;
        for (ll j = 0; j < 500; ++j) {
            if (acnt[j] == 0) continue;
            result += (i - j) * (i - j) * acnt[i] * acnt[j];
        }
    }
    cout << result / 2 << endl;
}
