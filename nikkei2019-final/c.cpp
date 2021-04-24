#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll h, w, k;
    cin >> h >> w >> k;
    vector<ll> row(h, w);
    vector<ll> col(w, h);
    ll result = 0;
    for (int i = 0; i < h; ++i) {
        result += (w - 1 + 2 * i) * w / 2;
    }
    for (int i = 0; i < k; ++i) {
        ll r, c;
        cin >> r >> c;
        row[--r]--;
        col[--c]--;
        result -= r + c;
    }
    for (int i = 1; i < h; ++i) {
        row[i] += row[i-1];
    }
    for (int i = 1; i < w; ++i) {
        col[i] += col[i-1];
    }
    for (int i = 1; i < h; ++i) {
        if (result + row[i-1] - (row[h-1] - row[i-1]) < result) {
            result = result + row[i-1] - (row[h-1] - row[i-1]);
        } else {
            break;
        }
    }
    for (int i = 1; i < w; ++i) {
        if (result + col[i-1] - (col[w-1] - col[i-1]) < result) {
            result = result + col[i-1] - (col[w-1] - col[i-1]);
        } else {
            break;
        }
    }
    cout << result << endl;
}