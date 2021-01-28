#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    if (k % 2 == 0) {
        ll even = n / k;
        ll odd = (n + k / 2) / k;
        cout << even * even * even + odd * odd * odd << endl;
    } else {
        ll p = n / k;
        cout << p * p * p << endl;
    }
}
