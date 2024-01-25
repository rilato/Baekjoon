#include <iostream>
#include <vector>

using namespace std;

int N, M;
int answer = 0;
vector <vector <int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(N, vector <int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }

    // ���� ����
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 3; j++) {
            answer = max(answer, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i][j + 3]);
        }
    }

    // ���� ����
    for (int i = 0; i < N - 3; i++) {
        for (int j = 0; j < M; j++) {
            answer = max(answer, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 3][j]);
        }
    }

    // ���簢��
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i][j] + v[i + 1][j] + v[i][j + 1] + v[i + 1][j + 1]);
        }
    }

    // L
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 2][j + 1]);
        }
    }

    // L ���� ȸ��
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2] + v[i][j + 2]);
        }
    }

    // L ���� �� �� ȸ�� (��)
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 2][j + 1]);
        }
    }

    // L ���� ȸ��
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j]);
        }
    }

    // L �¿� ����
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i + 2][j] + v[i + 2][j + 1] + v[i + 1][j + 1] + v[i][j + 1]);
        }
    }

    // L �¿� ���� �� ���� ȸ��
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 2]);
        }
    }

    // L �¿� ���� �� ���� �� �� ȸ��
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i][j + 1]);
        }
    }

    // L �¿� ���� �� ���� ȸ��
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2]);
        }
    }

    // ����
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 2][j + 1]);
        }
    }

    // ���� ȸ��
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i + 1][j] + v[i + 1][j + 1] + v[i][j + 1] + v[i][j + 2]);
        }
    }

    // ���� �¿� ����
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 2][j]);
        }
    }

    // ���� �¿� ���� ȸ��
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 1][j + 2]);
        }
    }

    // ��
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2]);
        }
    }

    // ��
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 1][j + 1]);
        }
    }

    // ��
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i + 1][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 2][j + 1]);
        }
    }

    // ��
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 1]);
        }
    }

    cout << answer;

    return 0;
}