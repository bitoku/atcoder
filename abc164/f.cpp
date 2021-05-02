#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll i = n;
    vector<ll> steps;
    while (i > 0) {
        ll step;
        for (step = m; step >= 1; --step) {
            if (i - step >= 0 && s[i - step] == '0') {
                i = i - step;
                steps.push_back(step);
                break;
            }
        }
        if (step == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(steps.begin(), steps.end());
    cout << steps[0];
    for (int j = 1; j < steps.size(); ++j) {
        cout << ' ' << steps[j];
    }
    cout << endl;
}