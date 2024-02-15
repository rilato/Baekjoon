// �ߺ����հ� ���õ� ����

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

    // �ߺ������̹Ƿ� �湮 �迭�� �ʿ� ����, �ߺ������� ���ڰ� ������ �ؾ��Ѵ�.
    for (int i = idx; i < N; i++) {
        answer.push_back(v[i]);
        Backtracking(depth + 1, i);
        answer.pop_back();
    }
}