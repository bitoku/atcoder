#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = (ll)1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;
    deque<ll> neg;
    deque<ll> nonneg;
    for (int i = 0; i < N; ++i) {
        ll a;
        cin >> a;
        if (a < 0) neg.push_back(a);
        else nonneg.push_back(a);
    }

    if (N == K) {
        ll ans = 1;
        int cnt = 0;
        for (int i = 0; i < neg.size(); ++i) {
            ans = (ans * neg[i]) % mod;
            cnt++;
        }
        for (int i = 0; i < nonneg.size(); ++i) {
            ans = (ans * nonneg[i]) % mod;
            cnt++;
        }
        cout << (mod + ans) % mod << endl;
        return 0;
    }

    if (K % 2 == 1 && neg.size() == N) {
        sort(neg.begin(), neg.end(), greater<ll>());
        ll ans = 1;
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            ans = (ans * neg[i]) % mod;
            cnt++;
            if (cnt == K) break;
        }
        cout << (mod + ans) % mod << endl;
        return 0;
    }

    sort(neg.begin(), neg.end());
    sort(nonneg.begin(), nonneg.end(), greater<ll>());

    int cnt = 0;
    ll ans = 1;
    while (cnt < K) {
        if (neg.size() <= 1) {
            ans = (ans * nonneg.front()) % mod; nonneg.pop_front();
            cnt++;
            continue;
        }
        if (nonneg.size() <= 1) {
            if (cnt + 1 == K) {
                ans = (ans * nonneg.front()) % mod; nonneg.pop_front();
                cnt++;
                continue;
            }
            ans = (ans * neg.front()) % mod; neg.pop_front();
            ans = (ans * neg.front()) % mod; neg.pop_front();
            cnt += 2;
            continue;
        }
        if (cnt + 1 < K && neg[0] * neg[1] > nonneg[0] * nonneg[1]) {
            ans = (ans * neg.front()) % mod; neg.pop_front();
            ans = (ans * neg.front()) % mod; neg.pop_front();
            cnt += 2;
            continue;
        }
        ans = (ans * nonneg.front()) % mod; nonneg.pop_front();
        cnt++;
    }
    cout << (mod + ans) % mod << endl;
}
