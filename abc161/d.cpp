#include <iostream>
#include <queue>
using namespace std;

int main() {
    int K;
    priority_queue<long long, vector<long long>, greater<>> q;
    cin >> K;
    if (K < 10) {
        cout << K << endl;
        return 0;
    }
    for (int i=1; i < 10; i++) {
        q.push(i);
    }
    for (int i = 0; i < K-1; i++) {
        long long n = q.top();
        q.pop();
        int a = n / 10 % 10 - n % 10;
        if (a == 1 || (a == 0 && n % 10 != 9)) {
            q.push(n + 1);
        }
        if (n % 10 == 0) {
            q.push(n * 10);
        } else {
            q.push(n * 10 + (n % 10 - 1));
        }
    }
    cout << q.top() << endl;
}
