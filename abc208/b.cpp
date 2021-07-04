#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    vector<ll> a(11, 1);
    for (int i = 1; i <= 10; ++i) {
        a[i] = a[i-1] * i;
    }
    ll p;
    cin >> p;
    ll result = 0;
    for (int i = 10; i >= 2; --i) {
        while (a[i] <= p) {
            p -= a[i];
            result++;
        }
    }
    cout << result + p << endl;
}