#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<int>());
    priority_queue<tuple<ll, int, int>> p;
    p.push(make_tuple(A[0], 0, 0));
    ll cnt = 0;
    for (int i = 1; i < N; ++i) {
        auto t = p.top(); p.pop();
        cnt += get<0>(t);
        p.push(make_tuple(min(A[get<1>(t)], A[i]), get<1>(t), i));
        p.push(make_tuple(min(A[get<2>(t)], A[i]), i, get<2>(t)));
    }
    cout << cnt << endl;
}
