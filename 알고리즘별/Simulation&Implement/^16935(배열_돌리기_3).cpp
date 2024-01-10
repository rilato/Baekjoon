// 배열 회전 시, 행과 열의 개수가 바뀌므로, 6개의 모든 함수에서 N M을 사용하지 않고, size()를 통해 일반화를 해준다.

#include <iostream>
#include <vector>

using namespace std;

int N, M, T, num;
vector <vector <int>> v;

void reverseRow();
void reverseCol();
void turnRight();
void turnLeft();
void turnColckwise();
void turnCounterclockwise();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> T;

    v.resize(N, vector <int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }

    while (T--) {
        cin >> num;

        switch (num) {
        case 1:
            reverseRow();
            break;
        case 2:
            reverseCol();
            break;
        case 3:
            turnRight();
            break;
        case 4:
            turnLeft();
            break;
        case 5:
            turnColckwise();
            break;
        default:
            turnCounterclockwise();
        }
    }

    // 배열 회전에 의해 행과 열의 길이가 달라질 수 있으므로, size()를 통해 유동적으로 사이즈 조절
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }

        cout << '\n';
    }

    return 0;
}

// 배열 상하 반전
// 회전에 의해 N과 M이 뒤바뀌었을 가능성이 있으므로, N M 대신 size()를 사용한다.
void reverseRow() {
    for (int i = 0; i < v.size() / 2; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            int temp = v[i][j];
            v[i][j] = v[v.size() - 1 - i][j];
            v[v.size() - 1 - i][j] = temp;
        }
    }
}

// 배열 좌우 반전
// 회전에 의해 N과 M이 뒤바뀌었을 가능성이 있으므로, N M 대신 size()를 사용한다.
void reverseCol() {
    for (int j = 0; j < v[0].size() / 2; j++) {
        for (int i = 0; i < v.size(); i++) {
            int temp = v[i][j];
            v[i][j] = v[i][v[0].size() - 1 - j];
            v[i][v[0].size() - 1 - j] = temp;
        }
    }
}

// 배열 오른쪽으로 90도 회전
// 배열 회전 시, 행과 열의 개수가 바뀌므로, N M을 사용하지 않고, size()를 통해 일반화를 해준다.
void turnRight() {
    vector <vector <int>> temp;
    // temp의 행의 수 == v의 열의 수, temp의 열의 수 == v의 행의 수
    temp.resize(v[0].size(), vector <int>(v.size()));

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            // 배열 회전 시, 행과 열의 개수가 바뀌므로, N M을 사용하지 않고, size()를 통해 일반화를 해준다.
            // temp의 행의 개수 == v의 열의 개수
            temp[j][v.size() - 1 - i] = v[i][j];
        }
    }

    // 기존의 v 배열 완전히 지우기
    v.clear();
    v = temp;
}

// 배열 왼쪽으로 90도 회전
// 배열 회전 시, 행과 열의 개수가 바뀌므로, N M을 사용하지 않고, size()를 통해 일반화를 해준다.
void turnLeft() {
    vector <vector <int>> temp;
    // temp의 행의 수 == v의 열의 수, temp의 열의 수 == v의 행의 수
    temp.resize(v[0].size(), vector <int>(v.size()));

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            // 배열 회전 시, 행과 열의 개수가 바뀌므로, N M을 사용하지 않고, size()를 통해 일반화를 해준다.
            // temp의 행의 개수 == v의 열의 개수
            temp[v[i].size() - 1 - j][i] = v[i][j];
        }
    }

    // 기존의 v 배열 완전히 지우기
    v.clear();
    v = temp;
}

// 4등분 하여 시계방향으로 옮기기
// 1 2
// 3 4 만들어 v에 붙여넣자
// 회전에 의해 N과 M이 뒤바뀌었을 가능성이 있으므로, N M 대신 size()를 사용한다.
void turnColckwise() {
    vector <vector <int>> temp;
    temp.resize(v.size(), vector <int>(v[0].size()));

    // v의 1번 조각을 temp의 2번 조각으로 옮기기
    for (int i = 0; i < v.size() / 2; i++) {
        for (int j = 0; j < v[0].size() / 2; j++) {
            temp[i][v[0].size() / 2 + j] = v[i][j];
        }
    }

    // v의 2번 조각을 temp의 4번 조각으로 옮기기
    for (int i = 0; i < v.size() / 2; i++) {
        for (int j = v[0].size() / 2; j < v[0].size(); j++) {
            temp[v.size() / 2 + i][j] = v[i][j];
        }
    }

    // v의 4번 조각을 temp의 3번 조각으로 옮기기
    for (int i = v.size() / 2; i < v.size(); i++) {
        for (int j = v[0].size() / 2; j < v[0].size(); j++) {
            temp[i][j - v[0].size() / 2] = v[i][j];
        }
    }

    // v의 3번 조각을 temp의 1번 조각으로 옮기기
    for (int i = v.size() / 2; i < v.size(); i++) {
        for (int j = 0; j < v[0].size() / 2; j++) {
            temp[i - v.size() / 2][j] = v[i][j];
        }
    }

    // 기존의 v 배열 완전히 지우기
    v.clear();
    v = temp;
}

// 4등분 하여 반시계방향으로 옮기기
// 1 2
// 3 4 만들어 v에 붙여넣자
// 회전에 의해 N과 M이 뒤바뀌었을 가능성이 있으므로, N M 대신 size()를 사용한다.
void turnCounterclockwise() {
    vector <vector <int>> temp;
    temp.resize(v.size(), vector <int>(v[0].size()));

    // v의 1번 조각을 temp의 3번 조각으로 옮기기
    for (int i = 0; i < v.size() / 2; i++) {
        for (int j = 0; j < v[0].size() / 2; j++) {
            temp[v.size() / 2 + i][j] = v[i][j];
        }
    }

    // v의 3번 조각을 temp의 4번 조각으로 옮기기
    for (int i = v.size() / 2; i < v.size(); i++) {
        for (int j = 0; j < v[0].size() / 2; j++) {
            temp[i][v[0].size() / 2 + j] = v[i][j];
        }
    }

    // v의 4번 조각을 temp의 2번 조각으로 옮기기
    for (int i = v.size() / 2; i < v.size(); i++) {
        for (int j = v[0].size() / 2; j < v[0].size(); j++) {
            temp[i - v.size() / 2][j] = v[i][j];
        }
    }

    // v의 2번 조각을 temp의 1번 조각으로 옮기기
    for (int i = 0; i < v.size() / 2; i++) {
        for (int j = v[0].size() / 2; j < v[0].size(); j++) {
            temp[i][j - v[0].size() / 2] = v[i][j];
        }
    }

    // 기존의 v 배열 완전히 지우기
    v.clear();
    v = temp;
}