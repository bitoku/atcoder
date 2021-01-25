#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> possible_max(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    possible_max[0] = a[0];
    for (int i = 1; i < n; ++i) {
        possible_max[i] = possible_max[i-1] + a[i];
    }
    int eaten_max = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (possible_max[i] * 2 < a[i+1]) {
            eaten_max = i;
        }
    }
    cout << n - (eaten_max+1) << endl;
}

