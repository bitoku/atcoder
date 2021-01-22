#include <bits/stdc++.h>
using namespace std;

int ctoi(char c) {
    return c - '0';
}

template<class T>
void printIter(const T &a, string delimiter) {
    if (a.size() == 0) return;
    auto it = a.begin();
    cout << *it;
    it++;
    while (it != a.end()) {
        cout << delimiter << *it;
        it++;
    }
    cout << endl;
}

const int mod = 2019;

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
    string S;
    cin >> S;
    vector<int> mods(S.size()+1);
    unordered_map<int, int> m;
    for (int i = 0; i < 2019; ++i) {
        m[i] = 0;
    }

    mods[0] = 0;
    m[0]++;
    for (int i = 0; i < S.size(); i++) {
        int k = ctoi(S[S.size() - 1 - i]);
        mods[i+1] = (mods[i] + k * mod_pow(10, i, mod)) % mod;
        m[mods[i+1]]++;
    }

    long long ans = 0;

    for (int i = 0; i < 2019; i++) {
        if (m[i] < 2) continue;
        ans += m[i] * (m[i] - 1) / 2;
    }

    cout << ans << endl;
}
