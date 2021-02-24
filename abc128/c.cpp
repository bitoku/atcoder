#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    int N, M;
    cin >> N >> M;
    vector<bitset<10>> light(M);
    vector<int> p(M);
    for (int i = 0; i < M; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int s;
            cin >> s;
            light[i][s-1] = true;
        }
    }
    for (int i = 0; i < M; ++i) {
        cin >> p[i];
    }
    int cnt = 0;
    const int limit = mod_pow(2, N, 100000);
    for (int i = 0; i < limit; ++i) {
        bitset<10> bit = bitset<10>(i);
        bool ok = true;
        for (int j = 0; j < M; ++j) {
            if ((light[j] & bit).count() % 2 != p[j]) {
                ok = false;
                break;
            }
        }
        if (ok) cnt++;
    }

    cout << cnt << endl;
}
