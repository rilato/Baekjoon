// queue의 사용방법을 익힌다.

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    queue <int> q;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        q.push(i + 1);
    }

    cout << "<";

    while (q.size() > 1) {
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << q.front() << ", ";
        q.pop();
    }

    cout << q.front() << ">";
}