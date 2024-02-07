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

    // 가로 직선
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 3; j++) {
            answer = max(answer, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i][j + 3]);
        }
    }

    // 세로 직선
    for (int i = 0; i < N - 3; i++) {
        for (int j = 0; j < M; j++) {
            answer = max(answer, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 3][j]);
        }
    }

    // 정사각형
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

    // L 우측 회전
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2] + v[i][j + 2]);
        }
    }

    // L 우측 두 번 회전 (ㄱ)
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 2][j + 1]);
        }
    }

    // L 좌측 회전
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j]);
        }
    }

    // L 좌우 반전
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i + 2][j] + v[i + 2][j + 1] + v[i + 1][j + 1] + v[i][j + 1]);
        }
    }

    // L 좌우 반전 후 우측 회전
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 2]);
        }
    }

    // L 좌우 반전 후 우측 두 번 회전
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i][j + 1]);
        }
    }

    // L 좌우 반전 후 좌측 회전
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2]);
        }
    }

    // 벼락
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 2][j + 1]);
        }
    }

    // 벼락 회전
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i + 1][j] + v[i + 1][j + 1] + v[i][j + 1] + v[i][j + 2]);
        }
    }

    // 벼락 좌우 반전
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 2][j]);
        }
    }

    // 벼락 좌우 반전 회전
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 1][j + 2]);
        }
    }

    // ㅗ
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2]);
        }
    }

    // ㅏ
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 1][j + 1]);
        }
    }

    // ㅓ
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            answer = max(answer, v[i + 1][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 2][j + 1]);
        }
    }

    // ㅜ
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            answer = max(answer, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 1]);
        }
    }

    cout << answer;

    return 0;
}