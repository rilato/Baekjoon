#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

int N, num;
deque <pair <int, int>> dq;
vector <int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> num;

        dq.push_back({ num, i });
    }

    while (!dq.empty()) {
        ans.push_back(dq.front().second);

        int move = dq.front().first;

        dq.pop_front();

        if (dq.size() == 1) {
            ans.push_back(dq.front().second);
            break;
        }

        if (move > 0) {
            for (int i = 0; i < move - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for (int i = 0; i < abs(move); i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}