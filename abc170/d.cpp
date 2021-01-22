#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<bool> prime(A.back()+1, true);
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (i > 0 && A[i] == A[i-1]) continue;
        if (i + 1 < N && A[i] == A[i+1]) {
            int k = A[i];
            while (k <= A.back()) {
                prime[k] = false;
                k += A[i];
            }
            continue;
        }
        if (prime[A[i]]) {
            cnt++;
            int k = A[i];
            while (k <= A.back()) {
                prime[k] = false;
                k += A[i];
            }
        }
    }
    cout << cnt << endl;

}
