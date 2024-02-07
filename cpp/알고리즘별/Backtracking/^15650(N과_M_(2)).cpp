// 15649���� ��Ʈ��ŷ�� ���� ���� ���ϱ⿴�ٸ�, �̹� ������ ��Ʈ��ŷ�� ���� ���� ���ϱ��� �� �� �ִ�.
// for���� index���� �Բ� ����Լ��� ���ڷ� �Ѱ��ָ� �տ��� �̹� ã�� ������ �ٽ� ���� �ʵ��� ���� �� �ִ�.

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector <int> v;
vector <bool> visited;

void Backtracking(int num, int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(M);
    visited.resize(N + 1);

    Backtracking(1, 0);

    return 0;
}

void Backtracking(int num, int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << v[i] << ' ';
        }

        cout << '\n';

        return;
    }

    for (int i = num; i <= N; i++) {
        if (!visited[i]) {
            // depth�� ���� �ֱ�
            v[depth] = i;
            // �湮�� ���� üũ ó��
            visited[i] = true;
            // depth���� 1��ŭ�� ���̸� �� ���� Ž��
            // for���� index ���� ����Լ��� ���ڷ� �Ѱ������ν� �̹� ã�� ������ �ٽ� ���� �ʵ��� ��
            Backtracking(i + 1, depth + 1);
            // ��� �� return�� �����鼭, false�� �ٽ� �ٲ��ֱ�
            visited[i] = false;
        }
    }
}