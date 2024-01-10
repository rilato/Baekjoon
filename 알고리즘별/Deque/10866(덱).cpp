#include <iostream>
#include <queue>

using namespace std;

int N, num;
string S;
deque <int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S;

        if (S == "push_back") {
            cin >> num;

            dq.push_back(num);
        }
        if (S == "push_front") {
            cin >> num;

            dq.push_front(num);
        }
        if (S == "back") {
            if (dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.back() << '\n';
            }
        }
        if (S == "front") {
            if (dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.front() << '\n';
            }
        }
        if (S == "size") {
            cout << dq.size() << '\n';
        }
        if (S == "empty") {
            if (dq.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        if (S == "pop_back") {
            if (dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.back() << '\n';

                dq.pop_back();
            }
        }
        if (S == "pop_front") {
            if (dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.front() << '\n';

                dq.pop_front();
            }
        }
    }

    return 0;
}