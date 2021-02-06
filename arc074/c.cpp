#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll h, w;
    cin >> h >> w;
    if (h % 3 == 0 || w % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll temp = h * w;
    for (int i = 1; i <= h / 2; ++i) {
        ll a, b, c;
        ll k = h - i;
        a = i * w;
        if (k > 1) {
            b = (k / 2) * w;
            c = (k - k / 2) * w;
            temp = min(temp, max({abs(a-b), abs(b-c), abs(c-a)}));
        }
        b = k * (w / 2);
        c = k * (w - w / 2);
        temp = min(temp, max({abs(a-b), abs(b-c), abs(c-a)}));
    }
    for (int i = 1; i <= w / 2; ++i) {
        ll a, b, c;
        ll k = w - i;
        a = i * h;
        if (k > 1) {
            b = (k / 2) * h;
            c = (k - k / 2) * h;
            temp = min(temp, max({abs(a-b), abs(b-c), abs(c-a)}));
        }
        b = k * (h / 2);
        c = k * (h - h / 2);
        temp = min(temp, max({abs(a-b), abs(b-c), abs(c-a)}));
    }
    cout << temp << endl;
}
