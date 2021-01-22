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

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> s(H);
    for (int i = 0; i < H; ++i) {
        cin >> s[i];
    }

    int h = mod_pow(2, H, 10000);
    int w = mod_pow(2, W, 10000);
//    cout << h << endl;
//    cout << w << endl;
    int cnt = 0;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            vector<string> ss = s;
            bitset<6> a = i;
            bitset<6> b = j;

            for (int x = 0; x < W; ++x) {
                if(!a[x]) continue;
                for (int y = 0; y < H; ++y) {
                    ss[y][x] = 'x';
                }
            }

            for (int y = 0; y < H; ++y) {
                if(!b[y]) continue;
                for (int x = 0; x < W; ++x) {
                    ss[y][x] = 'x';
                }
            }
            int black = 0;
//            printIter(ss, "\n");
//            cout << endl;
            for (int y = 0; y < H; ++y) {
                for (int x = 0; x < W; ++x) {
                    if (ss[y][x] == '#') black++;
                }
            }
            if (black == K) cnt++;
        }

    }
    cout << cnt << endl;
}
