#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

ll n;

int main() {
    cin >> n;
    ll x = n;
    int cnt = 0;
    while (x > 0) {
        if (cnt % 2 == 0) x = x / 2;
        else x = (x - 1) / 2;
        cnt++;
    }
    if (cnt % 2 == 0) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}