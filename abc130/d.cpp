#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll sum = 0;
    int head = 0;
    int tail = 0;
    ll cnt = 0;
    for (; tail < N; ++tail) {
        cin >> A[tail];
        sum += A[tail];
        ll tmp = 0;
        while (sum - A[head] > K) {
            tmp++;
        }
        cnt = cnt * 2 +
    }
}
