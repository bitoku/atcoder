#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll sum = 0;
    int left = 0;
    int right = 0;
    ll cnt = 0;
    for (; right < N; ++right) {
        cin >> A[right];
        sum += A[right];
        while (sum >= K) {
            sum -= A[left];
            cnt += N - right;
            left++;
        }
    }
    cout << cnt << endl;
}
