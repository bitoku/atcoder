#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

template<class T>
void printIter(const T &a, string delimiter) {
    if (a.size() == 0) return;
    auto it = a.begin();
    cout << *it;
    it++;
    while (it != a.end()) {
        cout << delimiter << *it;
        it++;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i += 2) {
        vector<int> div;
        divisor(i, div);
        if (div.size() == 8) {
            cnt++;
        }
    }
    cout << cnt << endl;
}
