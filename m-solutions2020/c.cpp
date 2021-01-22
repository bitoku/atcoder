#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    deque<ll> inter;
    for (int i = 0; i < K; ++i) {
        inter.push_back(A[i]);
    }
    for (int i = K; i < N; ++i) {
        ll first = inter.front(); inter.pop_front();
        ll last = A[i];
        inter.push_back(A[i]);
        if (first < last) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
