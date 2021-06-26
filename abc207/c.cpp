#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

struct Query {
    int t;
    ll l;
    ll r;
};

int main() {
    ll n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].t >> queries[i].l >> queries[i].r;
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            auto p = queries[i];
            auto q = queries[j];
            bool pq, qp;
            if (p.t == 1 || p.t == 3) {
                if (q.t == 1 || q.t == 2) {
                    pq = p.r < q.l;
                } else {
                    pq = p.r <= q.l;
                }
            } else {
                pq = p.r <= q.l;
            }
            if (q.t == 1 || q.t == 3) {
                if (p.t == 1 || p.t == 2) {
                    qp = q.r < p.l;
                } else {
                    qp = q.r <= p.l;
                }
            } else {
                qp = q.r <= p.l;
            }
            if (!(pq || qp)) result++;
        }
    }
    cout << result << endl;
}