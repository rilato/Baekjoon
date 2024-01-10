// �迭 ȸ�� ��, ��� ���� ������ �ٲ�Ƿ�, 6���� ��� �Լ����� N M�� ������� �ʰ�, size()�� ���� �Ϲ�ȭ�� ���ش�.

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

    // �迭 ȸ���� ���� ��� ���� ���̰� �޶��� �� �����Ƿ�, size()�� ���� ���������� ������ ����
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }

        cout << '\n';
    }

    return 0;
}

// �迭 ���� ����
// ȸ���� ���� N�� M�� �ڹٲ���� ���ɼ��� �����Ƿ�, N M ��� size()�� ����Ѵ�.
void reverseRow() {
    for (int i = 0; i < v.size() / 2; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            int temp = v[i][j];
            v[i][j] = v[v.size() - 1 - i][j];
            v[v.size() - 1 - i][j] = temp;
        }
    }
}

// �迭 �¿� ����
// ȸ���� ���� N�� M�� �ڹٲ���� ���ɼ��� �����Ƿ�, N M ��� size()�� ����Ѵ�.
void reverseCol() {
    for (int j = 0; j < v[0].size() / 2; j++) {
        for (int i = 0; i < v.size(); i++) {
            int temp = v[i][j];
            v[i][j] = v[i][v[0].size() - 1 - j];
            v[i][v[0].size() - 1 - j] = temp;
        }
    }
}

// �迭 ���������� 90�� ȸ��
// �迭 ȸ�� ��, ��� ���� ������ �ٲ�Ƿ�, N M�� ������� �ʰ�, size()�� ���� �Ϲ�ȭ�� ���ش�.
void turnRight() {
    vector <vector <int>> temp;
    // temp�� ���� �� == v�� ���� ��, temp�� ���� �� == v�� ���� ��
    temp.resize(v[0].size(), vector <int>(v.size()));

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            // �迭 ȸ�� ��, ��� ���� ������ �ٲ�Ƿ�, N M�� ������� �ʰ�, size()�� ���� �Ϲ�ȭ�� ���ش�.
            // temp�� ���� ���� == v�� ���� ����
            temp[j][v.size() - 1 - i] = v[i][j];
        }
    }

    // ������ v �迭 ������ �����
    v.clear();
    v = temp;
}

// �迭 �������� 90�� ȸ��
// �迭 ȸ�� ��, ��� ���� ������ �ٲ�Ƿ�, N M�� ������� �ʰ�, size()�� ���� �Ϲ�ȭ�� ���ش�.
void turnLeft() {
    vector <vector <int>> temp;
    // temp�� ���� �� == v�� ���� ��, temp�� ���� �� == v�� ���� ��
    temp.resize(v[0].size(), vector <int>(v.size()));

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            // �迭 ȸ�� ��, ��� ���� ������ �ٲ�Ƿ�, N M�� ������� �ʰ�, size()�� ���� �Ϲ�ȭ�� ���ش�.
            // temp�� ���� ���� == v�� ���� ����
            temp[v[i].size() - 1 - j][i] = v[i][j];
        }
    }

    // ������ v �迭 ������ �����
    v.clear();
    v = temp;
}

// 4��� �Ͽ� �ð�������� �ű��
// 1 2
// 3 4 ����� v�� �ٿ�����
// ȸ���� ���� N�� M�� �ڹٲ���� ���ɼ��� �����Ƿ�, N M ��� size()�� ����Ѵ�.
void turnColckwise() {
    vector <vector <int>> temp;
    temp.resize(v.size(), vector <int>(v[0].size()));

    // v�� 1�� ������ temp�� 2�� �������� �ű��
    for (int i = 0; i < v.size() / 2; i++) {
        for (int j = 0; j < v[0].size() / 2; j++) {
            temp[i][v[0].size() / 2 + j] = v[i][j];
        }
    }

    // v�� 2�� ������ temp�� 4�� �������� �ű��
    for (int i = 0; i < v.size() / 2; i++) {
        for (int j = v[0].size() / 2; j < v[0].size(); j++) {
            temp[v.size() / 2 + i][j] = v[i][j];
        }
    }

    // v�� 4�� ������ temp�� 3�� �������� �ű��
    for (int i = v.size() / 2; i < v.size(); i++) {
        for (int j = v[0].size() / 2; j < v[0].size(); j++) {
            temp[i][j - v[0].size() / 2] = v[i][j];
        }
    }

    // v�� 3�� ������ temp�� 1�� �������� �ű��
    for (int i = v.size() / 2; i < v.size(); i++) {
        for (int j = 0; j < v[0].size() / 2; j++) {
            temp[i - v.size() / 2][j] = v[i][j];
        }
    }

    // ������ v �迭 ������ �����
    v.clear();
    v = temp;
}

// 4��� �Ͽ� �ݽð�������� �ű��
// 1 2
// 3 4 ����� v�� �ٿ�����
// ȸ���� ���� N�� M�� �ڹٲ���� ���ɼ��� �����Ƿ�, N M ��� size()�� ����Ѵ�.
void turnCounterclockwise() {
    vector <vector <int>> temp;
    temp.resize(v.size(), vector <int>(v[0].size()));

    // v�� 1�� ������ temp�� 3�� �������� �ű��
    for (int i = 0; i < v.size() / 2; i++) {
        for (int j = 0; j < v[0].size() / 2; j++) {
            temp[v.size() / 2 + i][j] = v[i][j];
        }
    }

    // v�� 3�� ������ temp�� 4�� �������� �ű��
    for (int i = v.size() / 2; i < v.size(); i++) {
        for (int j = 0; j < v[0].size() / 2; j++) {
            temp[i][v[0].size() / 2 + j] = v[i][j];
        }
    }

    // v�� 4�� ������ temp�� 2�� �������� �ű��
    for (int i = v.size() / 2; i < v.size(); i++) {
        for (int j = v[0].size() / 2; j < v[0].size(); j++) {
            temp[i - v.size() / 2][j] = v[i][j];
        }
    }

    // v�� 2�� ������ temp�� 1�� �������� �ű��
    for (int i = 0; i < v.size() / 2; i++) {
        for (int j = v[0].size() / 2; j < v[0].size(); j++) {
            temp[i][j - v[0].size() / 2] = v[i][j];
        }
    }

    // ������ v �迭 ������ �����
    v.clear();
    v = temp;
}