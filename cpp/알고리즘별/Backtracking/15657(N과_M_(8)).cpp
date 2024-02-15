// 중복조합과 관련된 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector <int> v;
vector <int> answer;

void Backtracking(int depth, int idx);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    Backtracking(0, 0);

    return 0;
}

void Backtracking(int depth, int idx) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << answer[i] << " ";
        }

        cout << '\n';

        return;
    }

    // 중복조합이므로 방문 배열이 필요 없고, 중복적으로 숫자가 들어가도록 해야한다.
    for (int i = idx; i < N; i++) {
        answer.push_back(v[i]);
        Backtracking(depth + 1, i);
        answer.pop_back();
    }
}