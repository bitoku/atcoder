#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    ll T=0, A=0;
    for (int i = 0; i < n; ++i) {
        ll t, a;
        cin >> t >> a;
        if (T == 0 && A == 0) {
            T = t;
            A = a;
            continue;
        }
        ll nt = T % t == 0 ? T / t : T / t + 1;
        ll na = A % a == 0 ? A / a : A / a + 1;
        ll nn = max(nt, na);
        T = t * nn;
        A = a * nn;
    }
    cout << T + A << endl;
}
