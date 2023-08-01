// �迭�� ������, �� �ε����� ��ǥ ���� �ִ� ����� ���Ͽ� ���ε��� ��� ���� ������.

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

void unionfunc(int a, int b);
int find(int a);
bool checkSame(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    parent.resize(N + 1);

    // ��ǥ ��带 �ڱ� �ڽ����� �ʱ�ȭ
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int question, a, b;

        cin >> question >> a >> b;

        // �Է����� 0�� ������, ������ ������ �����ϹǷ�, ���� ��ġ��
        if (question == 0) {
            unionfunc(a, b);
        }

        // �Է����� 1�� ������, ���� ������ �������� Ȯ���ϱ�
        else {
            if (checkSame(a, b)) {
                cout << "YES" << "\n";
            }

            else {
                cout << "NO" << "\n";
            }
        }
    }
}

// union ���� : �ٷ� ������ �ƴ� ��ǥ ��峢�� �����Ͽ� ��
void unionfunc(int a, int b) {
    // a, b�� ��ǥ ��� ã��
    a = find(a);
    b = find(b);

    // �� ������ ��ǥ ��峢�� ����
    if (a != b) {
        parent[b] = a;
    }
}

/**
 find ���� : ��ǥ ��带 ã�Ƽ� ��ȯ

 0 1 3
 0 3 7 �־��� ��, parent �迭�� ��Ȳ

        idx  : 1 2 3 4 5 6 7
 parent[idx] : 7 2 1 4 5 6 7
*/

// parent[3] = find(1);
// find(1) = parent[1] = find(7);
// parent[1] = find(7);
// find(7) == 7;

// => parent[3] == parent[1] == parent[7] == 7
int find(int a) {
    // a�� ��ǥ ���� ��ȯ
    if (a == parent[a])
        return a;
    // �ƴϸ� a�� ��ǥ ��� ���� find(parent[a]) ������ ���� -> ����Լ� ����
    else
        return parent[a] = find(parent[a]);	 // ����Լ��� ���·� ����
}

bool checkSame(int a, int b) { // �� ���Ұ� ���� �������� Ȯ��
    a = find(a);
    b = find(b);

    if (a == b) {
        return true;
    }

    return false;
}