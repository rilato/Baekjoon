#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int answer = INT_MAX;
vector <vector <int>> v;
vector <int> idx;
vector <bool> visited;

void Permutation(int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N, vector <int>(N));
    visited.resize(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    // ��� ������ ���Ѵ�.
    Permutation(0);

    cout << answer;

    return 0;
}

void Permutation(int depth) {
    if (depth == N) {
        bool flag = true;
        int sum = 0;

        // idx�迭�� �������� �� ã�� ��� ���ϱ�
        for (int i = 0; i < idx.size() - 1; i++) {
            int idxI = idx[i];
            int idxJ = idx[i + 1];

            if (v[idxI][idxJ] == 0) {
                flag = false;
                break;
            }
            else {
                sum += v[idxI][idxJ];
            }
        }

        if (flag) {
            int idxI = idx[idx.size() - 1];
            int idxJ = idx[0];

            // ������ ���ư��� ���� �ִ� ��쿡�� ���� ����
            if (v[idxI][idxJ] != 0) {
                sum += v[idxI][idxJ];

                answer = min(answer, sum);
            }
        }

        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            idx.push_back(i);
            Permutation(depth + 1);
            idx.pop_back();
            visited[i] = false;
        }
    }
}