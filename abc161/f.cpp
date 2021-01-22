#include <bits/stdc++.h>
using namespace std;

template< typename T >
void divisor(T n, vector<T>& divisors) {
    T root_n = (T)sqrt(n);
    for (int i = 1; i <= root_n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (n / i != i) divisors.push_back(n / i);
        }
    }
}

int main() {
    long long n;
    cin >> n;
    vector<long long> divisors;
    divisor(n, divisors);
    int cnt = 0;
    for (auto k : divisors) {
        if (k == 1) continue;
        long long tempn = n;
        while (tempn % k == 0) tempn /= k;
        if (tempn % k == 1) cnt++;
    }
    divisors.clear();
    divisor(n-1, divisors);
    for (auto k : divisors) {
        if (k == 1) continue;
        if (n % k == 1) cnt++;
    }
    cout << cnt << endl;
}
