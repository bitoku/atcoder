#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int k, t;
    cin >> k >> t;
    priority_queue<int> pq;
    for (int i = 0; i < t; ++i) {
        int a;
        cin >> a;
        pq.push(a);
    }
    int before = pq.top() - 1; pq.pop();
    while (!pq.empty()) {
        int x = pq.top() - 1; pq.pop();
        if (before > 0) {
            pq.push(before);
        }
        before = x;
    }
    cout << before << endl;
}
