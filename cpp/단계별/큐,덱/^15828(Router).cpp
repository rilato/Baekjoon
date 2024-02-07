// #include <queue>의 활용법을 익힌다

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size, num;
    queue <int> q;

    cin >> size;

    while (1) {
        cin >> num;

        if (num == -1)
            break;

        if (!num)
            q.pop();
        else {
            if (q.size() < size)
                q.push(num);
        }
    }

    if (q.empty())
        cout << "empty";

    else {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
    }
}