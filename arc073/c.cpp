#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll N, T;
    cin >> N >> T;
    ll result = 0;
    ll time = 0;
    for (int i = 0; i < N; ++i) {
        ll t;
        cin >> t;
        result += min(T, t - time);
        time = t;
    }
    result += T;
    cout << result << endl;
}
