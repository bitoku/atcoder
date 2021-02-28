#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll H, W, N;
    cin >> H >> W >> N;
    ll sh, sw;
    cin >> sh >> sw;
    string S, T;
    cin >> S;
    cin >> T;
    ll down = 1, up = H;
    for (ll i = N - 1; i >= 0; --i) {
        if (T[i] == 'D') down = max(1ll, down-1);
        if (T[i] == 'U') up = min(up+1, H);
        if (S[i] == 'D') up--;
        if (S[i] == 'U') down++;
        if (down > up) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (sh < down || up < sh) {
        cout << "NO" << endl;
        return 0;
    }
    ll left = 1, right = W;
    for (ll i = N - 1; i >= 0; --i) {
        if (T[i] == 'R') left = max(1ll, left-1);
        if (T[i] == 'L') right = min(right+1, W);
        if (S[i] == 'R') right--;
        if (S[i] == 'L') left++;
        if (left > right) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (sw < left || right < sw) {
        cout << "NO" << endl;
        return 0;
    }


    cout << "YES" << endl;
}
