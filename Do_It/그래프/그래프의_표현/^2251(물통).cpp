// Queue�� 3���� ������ �� ���� �־ �������ش�. �ߺ��� Ž���� ���ϱ� ���ؼ� Visit[][][] 3���� �迭�� ����Ѵ�.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int A, B, C;
bool Visit[201][201][201];

vector<int> V;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;

    queue<pair<pair<int, int>, int>> Q;

    // �� ó��, A�� B�� ����ְ� C�� ���ִ� ��Ȳ
    Q.push(make_pair(make_pair(0, 0), C));

    while (!Q.empty()) {
        int a = Q.front().first.first;
        int b = Q.front().first.second;
        int c = Q.front().second;

        Q.pop();

        // Visit[a][b][c] = true�� �ǹ̴� A���뿡 a�� ������, B���뿡 b�� ������, C���뿡 c�� ������ ��� ���� ���� �̹� Ž���߽��ϴ� ��� �ǹ�
        if (Visit[a][b][c] == true) continue;

        Visit[a][b][c] = true;

        if (a == 0) V.push_back(c);

        // A���뿡�� B�������� �� ��, ���� ��ģ�ٸ� B�� ���� �� ������ �� �ֱ�
        if (a + b > B) Q.push(make_pair(make_pair(a + b - B, B), c));
        // ���� ��ġ�� �ʴ´ٸ� A�� �� �� �ֱ�
        else Q.push(make_pair(make_pair(0, a + b), c));

        // A���뿡�� C�������� �� ��
        if (a + c > C) Q.push(make_pair(make_pair(a + c - C, b), C));
        else Q.push(make_pair(make_pair(0, b), a + c));

        // B���뿡�� A�������� �� ��
        if (b + a > A) Q.push(make_pair(make_pair(A, b + a - A), c));
        else Q.push(make_pair(make_pair(b + a, 0), c));

        // B���뿡�� C�������� �� ��
        if (b + c > C) Q.push(make_pair(make_pair(a, b + c - C), C));
        else Q.push(make_pair(make_pair(a, 0), b + c));

        // C���뿡�� A�������� �� ��
        if (c + a > A) Q.push(make_pair(make_pair(A, b), c + a - A));
        else Q.push(make_pair(make_pair(c + a, b), 0));

        // C���뿡�� B�������� �� ��
        if (c + b > B) Q.push(make_pair(make_pair(a, B), c + b - B));
        else Q.push(make_pair(make_pair(a, b + c), 0));
    }

    sort(V.begin(), V.end());

    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";

    return 0;
}
