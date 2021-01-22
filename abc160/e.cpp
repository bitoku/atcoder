//
// Created by 徳備彩人 on 2020/04/02.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    priority_queue<long long> a, b, c;
    priority_queue<long long, vector<long long>, greater<>> ab;
    long long ans;
    for (int i = 0; i < A; i++) {
        long long p;
        cin >> p;
        a.push(p);
    }
    for (int i = 0; i < B; i++) {
        long long p;
        cin >> p;
        b.push(p);
    }
    for (int i = 0; i < C; i++) {
        long long p;
        cin >> p;
        c.push(p);
    }
    long long result = 0;
    for (int i = 0; i < X; i++) {
        c.push(a.top());
        a.pop();
    }
    for (int i = 0; i < Y; i++) {
        c.push(b.top());
        b.pop();
    }
    for (int i = 0; i < X + Y; i++) {
        result += c.top();
        c.pop();
    }
    cout << result << endl;
}