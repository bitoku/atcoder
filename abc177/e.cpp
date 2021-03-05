#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

vector<vector<int>> get_factors(int n) {
    vector<vector<int>> v(n);
    for (int i = 2; i < n; ++i) {
        if (!v[i].empty()) continue;
        for (int j = 1; j * i < n; ++j) {
            v[i*j].push_back(i);
        }
    }
    return v;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a[0];
    ll gcd_all = a[0];
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        gcd_all = gcd(gcd_all, a[i]);
    }
    if (gcd_all != 1) {
        cout << "not coprime" << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    vector<vector<int>> f = get_factors(1000001ll);
    vector<bool> used(1000001ll);
    for (const auto x : a) {
        for (const auto y : f[x]) {
            if (used[y]) {
                cout << "setwise coprime" << endl;
                return 0;
            }
            used[y] = true;
        }
    }
    cout << "pairwise coprime" << endl;
}
