// 0���� N������ ��忡 �־��� ������ ���� ���Ͽ� ����Ѵ�.


#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> A[10]; // ����� ��, ���� p q�� �ֱ� ���� Ʃ�� ���
long long lcm;
bool visited[10];
long long D[10];    // �� ��� �� ���� �迭

long long gcd(long long a, long long b);
void DFS(int node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    lcm = 1;

    for (int i = 0; i < N - 1; i++) {
        int a, b, p, q;

        cin >> a >> b >> p >> q;

        // ���� ����Ʈ�� �迭�� �ش� ���� ������ ����
        A[a].push_back(make_tuple(b, p, q));
        A[b].push_back(make_tuple(a, q, p));

        lcm *= (p * q / gcd(p, q)); // ��� p q�� ���� �ּҰ���� ���ϱ�.
    }

    // 0�� ��忡 �ּ� ����� ����
    D[0] = lcm;

    DFS(0);

    long long mgcd = D[0];

    // DFS�� ���� ������Ʈ�� �迭 D ���� ������ �ִ� ����� ���
    for (int i = 1; i < N; i++) {
        mgcd = gcd(mgcd, D[i]);
    }

    // �迭 D�� �� ���� �ִ� ������� ����� ���� ���
    for (int i = 0; i < N; i++) {
        cout << D[i] / mgcd << ' ';
    }
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void DFS(int node) { // DFS����
    visited[node] = true;

    //for (tuple<int, int, int> i : A[node]) {
    //    int next = get<0>(i);
    //
    //    if (!visited[next]) {
    //        D[next] = D[node] * get<2>(i) / get<1>(i); //�־��� ������ ���� ��� �� ������Ʈ
    //        DFS(next);
    //    }
    //}

    for (int j = 0; j < A[node].size(); j++) {
        tuple<int, int, int> i = A[node][j];


        // `get<0> (i)`�� Ʃ�� `i`�� ù ��° ��Ҹ� �������� ���� �ǹ��Ѵ�.
        // `i`�� `tuple<int, int, int > ` ������ Ʃ���̹Ƿ�, `get<0 > (i)`�� ù ��° `int` ��Ҹ� ��ȯ�Ѵ�.
        // ���� `int next = get<0>(i); `�� Ʃ�� `i`�� ù ��° ��Ҹ� `next` ������ �Ҵ��ϴ� ���� �ǹ��Ѵ�.
        // �� �ڵ�� �־��� Ʃ�ÿ��� ù ��° ��Ҹ� �����Ͽ� ���� ��带 ��Ÿ���� ���� `next`�� �Ҵ��ϴ� ������ �Ѵ�.
        int next = get<0>(i);

        // ���� ����� ���� ��� �� �湮���� ���� ��忡 ����
        if (!visited[next]) {
            D[next] = D[node] * get<2>(i) / get<1>(i);  // ���� ��尪 = ���� ��尪 * ������ �����ϱ�
            DFS(next);
        }
    }

}