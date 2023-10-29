#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M, T;
int answer;
vector<int> v;  // ������ �ƴ� ������� ���� ����
vector<int> parent; // ������� �������踦 �˱� ����, UnionFind�� ������ ����
vector<vector<int>> party;  // ��Ƽ ������

void unionfunc(int a, int b);
int find(int a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    parent.resize(N + 1);

    // Union Find �迭 �ʱ�ȭ (��ǥ��带 �ڽ����� �ʱ�ȭ)
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    cin >> T;

    v.resize(T);

    // ������ �ƴ� ����� v���Ϳ� ���
    for (int i = 0; i < T; i++) {
        cin >> v[i];
    }

    party.resize(M);

    for (int i = 0; i < M; i++) {
        int parties;

        cin >> parties;

        for (int j = 0; j < parties; j++) {
            int temp;

            cin >> temp;

            party[i].push_back(temp);
        }
    }

    // ��Ƽ�� ������ ����� �ϳ��� �׷����� �����
    for (int i = 0; i < M; i++) {
        int firstPeople = party[i][0];

        for (int j = 1; j < party[i].size(); j++) {
            // �� ��Ƽ�� ������ ����� 1���� �׷����� �����
            unionfunc(firstPeople, party[i][j]);
        }
    }

    // �� ��Ƽ���� ������ �ƴ� ����� ���� �׷쿡 �ִٸ� ������ �� ����
    for (int i = 0; i < M; i++) {
        bool isPossible = true;
        int firstPeople = party[i][0];  // �� ��Ƽ�� ��ǥ ���

        for (int j = 0; j < T; j++) {
            // �� ��Ƽ�� ��ǥ ���� ������ �ƴ� ����� ��ǥ ��尡 ���ٸ� ������ �� ����
            if (find(firstPeople) == find(v[j])) {
                isPossible = false;
                break;
            }
        }
        if (isPossible) {
            answer++;
        }
    }

    cout << answer;

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