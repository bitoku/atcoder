#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

const int m = 1e9 + 7;

long long mpow(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b % 2 == 1) ans = ans * a % m;
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

void lcmf(const vector<int>& prime, unordered_map<int, int>& lcm, int x) {
    double root_x = sqrt(x);
    for (auto p: prime) {
        int e = 0;
        while ( x % p == 0 ) {
            x /= p;
            e++;
        }
        lcm[p] = max(lcm[p], e);
        if (x == 1) break;
        if (root_x < p) {
            lcm[x] = max(lcm[x], 1);
            break;
        }
    }
}

int main() {
    int n;
    vector<int> v;
    cin >> n;
    long long l = 1;
    vector<int> prime;
    unordered_map<int, int> lcm;
    int a;
    int p[1000001] = {0};
    for (int i = 2; i <= 1e6; i++) {
        if (p[i] == 1) continue;
        prime.push_back(i);
        lcm[i] = 0;
        for (int j = i*2; j <= 1e6; j += i) {
            p[j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
        lcmf(prime, lcm, a);
    }
    for (auto pair: lcm) {
        l = (l * mpow(pair.first, pair.second)) % m;
    }
    long long ans = 0;
    for (auto x: v) {
        ans = (ans + l * mpow(x, m-2)) % m;
    }
    cout << ans << endl;
    return 0;
}
