#include <iostream>
#include <vector>

using namespace std;

int N, M;
int answer = 0;
vector <int> v;
vector <bool> visited;
vector <int> combine;

void Backtracking();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N);
    visited.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    Backtracking();

    cout << answer;

    return 0;
}

void Backtracking() {
    if (combine.size() == N) {
        int temp = 0;

        // |A[0] - A[1]| + |A[2] - A[3]|이 아니다.
        // |A[0] - A[1]| + |A[1] - A[2]|이다. A[1]이 중복되어 들어간다.
        for (int i = 0; i < N - 1; i++) {
            temp += abs(combine[i] - combine[i + 1]);
        }

        answer = max(answer, temp);

        // 디버깅을 위해 현재의 조합 출력
        //cout << "Current Combination: ";
        //for (int num : combine) {
        //    cout << num << " ";
        //}
        //cout << ", Temp: " << temp << ", Answer: " << answer << '\n';

        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            combine.push_back(v[i]);
            visited[i] = true;
            Backtracking();
            combine.pop_back();
            visited[i] = false;
        }
    }
}