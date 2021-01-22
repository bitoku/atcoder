#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class Compare>
ll binsearch(ll left, ll right, Compare func) {
    // leftは常に条件を満たさない, rightは常に条件を満たす
    // 解にleft, rightは含まれない。
    while ( abs(right - left) > 1) {
        ll mid = left + right / 2;
        if (func(mid)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll m = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        m = max(A[i], m);
    }
    auto f = [&](ll key) -> bool{
        ll cnt = 0;
        for (int i = 0; i < N; ++i) {
            cnt += (A[i] / key) + min(A[i] % key, 1ll) - 1;
        }
        if (cnt <= K) return true;
        return false;
    };
    cout << binsearch(0ll, m+1, f) << endl;
}
