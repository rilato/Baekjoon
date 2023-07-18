// �迭�� ������, �� �ε����� ��ǥ ���� �ִ� ����� ���Ͽ� ���ε��� ��� ���� ������.

#include <iostream>
#include <vector>

using namespace std;

int n, m, input, a, b;
vector<int> parent;

void merge(int a, int b);
int find(int a);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    parent.resize(n + 1);

    for (int i = 0; i < n + 1; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> input >> a >> b;

        if (input == 0) {
            merge(a, b);
        }

        else if (input == 1) {
            if (find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}

// union ���� : �ٷ� �����ϴ� ���� �ƴ�, ��ǥ ��峢�� ������
void merge(int a, int b) {
    a = find(a);
    b = find(b);

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
    if (a == parent[a]) {
        return a;
    }
    else {
        // a�� ��ǥ ��� ���� find(parent[a]) ������ ���� -> ����Լ� ����
        return parent[a] = find(parent[a]);
    }
}