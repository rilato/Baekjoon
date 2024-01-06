#include <iostream>
#include <queue>

using namespace std;

int N, num;
string input;
queue <int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    while (N--) {
        cin >> input;

        if (input == "push") {
            cin >> num;

            q.push(num);
        }
        if (input == "pop") {
            if (q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        if (input == "size") {
            cout << q.size() << '\n';
        }
        if (input == "empty") {
            if (q.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        if (input == "front") {
            if (q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << q.front() << '\n';
            }
        }
        if (input == "back") {
            if (q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << q.back() << '\n';
            }
        }
    }

    return 0;
}