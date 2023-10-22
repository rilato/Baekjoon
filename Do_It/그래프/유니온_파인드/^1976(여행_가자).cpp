// �迭�� ������, �� �ε����� ��ǥ ���� �ִ� ����� ���Ͽ� ���ε��� ��� ���� ������.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> parent;

void unionfunc(int a, int b);
int find(int a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int dosi[201][201];
    int route[1001];

    cin >> N >> M;

    for (int i = 1; i <= N; i++) { 	// ���� ���� ������ ����
        for (int j = 1; j <= N; j++) {
            cin >> dosi[i][j];
        }
    }

    for (int i = 1; i <= M; i++) { 	//���� ���� ���� ����
        cin >> route[i];
    }

    parent.resize(N + 1);

    for (int i = 1; i <= N; i++) { 	// ��ǥ ��带 �ڱ� �ڽ����� �ʱ�ȭ
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) { 	// ������� Ž������ ���ð� ����Ǿ� ������ ���Ͽ� ����
        for (int j = 1; j <= N; j++) {
            if (dosi[i][j] == 1)
                unionfunc(i, j);
        }
    }

    // ���� ��ȹ ���õ��� �ϳ��� ��ǥ ���÷� ����Ǿ� �ִ��� Ȯ��
    int index = find(route[1]);

    bool connect = true;

    for (int i = 2; i <= M; i++) {
        if (index != find(route[i])) {
            cout << "NO" << "\n";

            connect = false;

            break;
        }
    }

    if (connect)
        cout << "YES" << "\n";

    return 0;
}

void unionfunc(int a, int b) {	 // union ���� : �ٷ� ������ �ƴ� ��ǥ ��峢�� �����Ͽ� ��
    a = find(a);    // find������ ����, ���� a�� b�� ����� �ֻ��� �κ��� ��Ʈ ��带 ����Ű�� ��.
    b = find(b);

    if (a != b) {   // a != b�� ��, ���� ������.
        parent[b] = a;
    }
}

int find(int a) { 	// find ���� : ��ǥ ��带 ����
    if (a == parent[a]) // �ε����� ���� ������ �갡 �Ѹ� �����.
        return a;
    else
        return parent[a] = find(parent[a]); 	// �迭�� ��(parent[a])�� �ε���(find�� ����)�� ���� �� ����
}