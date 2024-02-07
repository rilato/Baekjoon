#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string A, B;
int DP[1001][1001]; // 이차원 점화식 테이블
vector<char> Path;  // LCS 저장 벡터

void getText(int r, int c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    for (int i = 1; i <= A.size(); i++) {
        for (int j = 1; j <= B.size(); j++) {
            // 같은 문자열일 경우 왼쪽 대각선 값 + 1
            if (A[i - 1] == B[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            // 다른 문자열일 경우 왼쪽과 위의 값 중 큰 수
            else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    cout << DP[A.size()][B.size()] << '\n';

    getText(A.size(), B.size());

    // Path에 저장된 내용 거꾸로 출력
    for (int i = Path.size() - 1; i >= 0; i--) {
        cout << Path[i];
    }

    return 0;
}

// LCS 출력 함수, 재귀 형태로 구현
void getText(int r, int c) {
    if (r == 0 || c == 0) {
        return;
    }

    // A[row]와 B[column]이 같으면 LCS에 기록하고 왼쪽 위로 이동
    if (A[r - 1] == B[c - 1]) {
        Path.push_back(A[r - 1]);
        getText(r - 1, c - 1);
    }
    // A[row]와 B[column]이 다르면 왼쪽과 위쪽 중 큰 수로 이동
    else {
        if (DP[r - 1][c] > DP[r][c - 1]) {
            getText(r - 1, c);
        }
        else {
            getText(r, c - 1);
        }
    }
}