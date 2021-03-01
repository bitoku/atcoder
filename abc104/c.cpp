#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

struct Problem {
    int n;
    ll comp;
    ll score;
};

int main() {
    ll d, g;
    cin >> d >> g;
    vector<Problem> prob(d);
    for (int i = 0; i < d; ++i) {
        cin >> prob[i].n >> prob[i].comp;
        prob[i].score = (i + 1) * 100;
    }
    ll result = INT_MAX;
    for (int i = 0; i < 1 << d; ++i) {
        bitset<10> bit(i);
        ll score = 0;
        ll n = 0;
        for (int j = 0; j < d; ++j) {
            if (!bit[j]) continue;
            score += prob[j].n * prob[j].score + prob[j].comp;
            n += prob[j].n;
        }
        if (score >= g) {
            result = min(result, n);
            continue;
        }
        for (ll j = d - 1; j >= 0; --j) {
            if (bit[j]) continue;
            ll x = (g - score + prob[j].score - 1) / prob[j].score;
            if (x <= prob[j].n - 1) {
                n += x;
                result = min(result, n);
            }
            break;
        }
    }
    cout << result << endl;
}
