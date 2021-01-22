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
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> people(N);
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        for (int j = 0; j < A; ++j) {
            int x, y;
            cin >> x >> y;
            x--;
            people[i].push_back(make_pair(x, y));
        }
    }
    int p = (1 << N) - 1;
    int m = 0;
    for (; p >= 0; --p) {
        bool flag = true;
        bitset<15> bit = p;
        for (int i = 0; i < N; ++i) {
            if (!bit[i]) continue;
            for (const auto& t : people[i]) {
                if ((t.second == 1 && !bit[t.first]) || (t.second == 0 && bit[t.first])) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) m = max(m, (int)bit.count());
    }
    cout << m << endl;
}
