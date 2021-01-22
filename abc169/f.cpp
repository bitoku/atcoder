#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;

template< typename T >
T mod_pow(T x, T n, const T &p) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}

int main() {
    int n, s;
    vector<int> a;
    cin >> n >> s;
    for (int i=0;i<n;i++) {
        int aa;
        cin >> aa;
        a.push_back(aa);
    }
    map<int, long long> ff;
    ff[0]++;
    for (int i=0;i<n;i++) {
        map<int, long long> fff;
        for (auto v: ff) {
            fff[v.first] = (fff[v.first] + v.second*2) % M;
            if (v.first + a[i] > s) {
                continue;
            }
            fff[v.first + a[i]] = (fff[v.first + a[i]] + v.second) % M;
        }
        ff = fff;
    }
    cout << (ff[s]) % M << endl;
}