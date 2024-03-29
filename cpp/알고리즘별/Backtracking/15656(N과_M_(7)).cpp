// 중복순열을 구하는 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector <int> v;
vector <int> answer;

void Backtracking(int depth);

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

    Backtracking(0);

    return 0;
}

void Backtracking(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << answer[i] << " ";
        }

        cout << '\n';

        return;
    }

    // 중복을 가능하게 만들기 위해, visited 배열에 방문 표시를 따로 하지 않는다.
    for (int i = 0; i < N; i++) {
        answer.push_back(v[i]);
        Backtracking(depth + 1);
        answer.pop_back();
    }
}
