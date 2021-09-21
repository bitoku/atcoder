#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll q;
    cin >> q;
    priority_queue<ll, vector<ll>, greater<>> pq;
    deque<ll> v;
    for (int i = 0; i < q; ++i) {
        int query;
        cin >> query;
        if (query == 1) {
            int x;
            cin >> x;
            v.push_back(x);
        } else if (query == 2) {
            if (!pq.empty()) {
                cout << pq.top() << endl;
                pq.pop();
            } else {
                cout << v.front() << endl;
                v.pop_front();
            }
        } else {
            while (!v.empty()) {
                pq.push(v.front());
                v.pop_front();
            }
        }
    }
}