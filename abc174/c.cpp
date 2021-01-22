#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll K;
    cin >> K;
    ll x = 7;
    for (int i = 0; i < K; ++i) {
        if (x % K == 0) {
            cout << i+1 << endl;
            return 0;
        }
        x = (x*10 + 7) % K;
    }
    cout << -1 << endl;
}
