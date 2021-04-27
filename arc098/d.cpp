#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 4/27 AC

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<bitset<20>> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 20; ++j) {
            b[i] = a[i];
        }
    }
    int l = 0;
    vector<int> x(20);
    ll result = 0;
    for (int r = 0; r < n; ++r) {
        for (int i = 0; i < 20; ++i) {
            if(b[r][i]) x[i]++;
        }
        while (any_of(x.begin(), x.end(), [](int k) {return k >= 2;})) {
            for (int i = 0; i < 20; ++i) {
                if (b[l][i]) x[i]--;
            }
            l++;
        }
        result += r - l + 1;
    }
    cout << result << endl;
}