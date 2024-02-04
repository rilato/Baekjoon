#include <iostream>
#include <vector>

using namespace std;

int K;
vector <int> S;
vector <bool> visited;
vector <int> answer;

// 로또의 순열 찾기
void Backtracking(int depth, int idx);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        cin >> K;

        if (K == 0) {
            break;
        }

        S.resize(K);
        visited.resize(K);

        for (int i = 0; i < K; i++) {
            cin >> S[i];
        }

        Backtracking(0, 0);

        cout << '\n';

        S.clear();
        visited.clear();
        answer.clear();
    }

    return 0;
}

void Backtracking(int depth, int idx) {
    // 로또 번호는 6개 이므로 6개가 되면 출력 후 리턴
    if (depth == 6) {
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }

        cout << '\n';

        return;
    }

    for (int i = idx; i < K; i++) {
        if (!visited[i]) {
            visited[i] = true;
            answer.push_back(S[i]);
            Backtracking(depth + 1, i + 1);
            answer.pop_back();
            visited[i] = false;
        }
    }
}