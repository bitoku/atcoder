#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main() {
    unsigned long long n;
    cin >> n;

    double root_n = sqrt(n);
    map<int, int> factor;
    while (n % 2 == 0) {
        n /= 2;
        factor[2]++;
    }
    for (int i=3;i <= root_n; i++) {
        while (n % i == 0) {
            n /= i;
            factor[i]++;
        }
    }
    if (n > 1) {
        factor[n]++;
    }
    int cnt = 0;
    for (auto v: factor) {
        int k = v.second;
        for (int i=1;i<=k;i++) {
            if (k - i > i) {
                k -= i;
                cnt++;
                continue;
            } else {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}