// ���� ���ذ� �� ���� �ʾ� �ٸ� ���� Ǯ�̸� �����ߴ�.
// https://wooono.tistory.com/404

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ������ ��ġ ����� Vector
vector<int> router;

int find_max_dist(int n, int c);

int main() {

    // ������ ����, ��ġ ����
    int n, c;
    cin >> n >> c;

    // ������ ��ġ �Է�
    int loc;
    for (int i = 0; i < n; ++i) {
        cin >> loc;
        router.push_back(loc);
    }

    // ������ ��ġ ����
    sort(router.begin(), router.end());

    // ������ �� �ִ� �Ÿ� Ž�� �Լ� ����
    cout << find_max_dist(n, c);

}

// �ִ� ������ ������ ������ ��ġ ã��
int find_max_dist(int n, int c) {

    // ���� ���� �̺� Ž���� ���� ����
    int l_dist = 0;                     // ù ��° �����⿡�� ù ��° ����������� ����
    int r_dist = router[n - 1] - 1;         // ù ��° �����⿡�� ������ ����������� ����

    // ��� ����
    int result_dist;

    // �̺й��� �����, ��� ���� Ž���� ���������� ����
    while (l_dist <= r_dist) {

        // ��ġ�� ������ ���� (ù ��° ������� ��ġ�ϰ� ����)
        int install_router = 1;

        // ���� ���� ����
        int mid_dist = (l_dist + r_dist) / 2;

        // ù ��° ������ ��ġ
        int start = router[0];

        // �� �������� ���� Ȯ��
        for (int i = 1; i < n; ++i) {

            // ���� Ȯ���� ������ ��ġ
            int end = router[i];

            // ������ ������ ���� ������ �Ѵ��� Ȯ���� ��, �Ѵ� ���ݿ��� �����⸦ ��ġ�ϰ�
            // �ش� ��ġ�� �ٽ� Ž�� ���� ��ġ�� ����
            if (end - start >= mid_dist) {
                install_router += 1;
                start = end;
            }
        }

        // ������ ���� Ž���� ���� ��, ��ġ�� ������ ������ C�� �̻��̶��,
        if (install_router >= c) {
            // ������ ��ġ�� ���� ������ ��� �������� �ӽ� ����
            result_dist = mid_dist;
            // �̺й��� ����� ���� ���� ��, �������� ���� ������ ����ϱ� ����, L ����
            l_dist = mid_dist + 1;
        }
        // ��ġ�� ������ ������ C�� �̸��̶��,
        else {
            // �̺й��� ����� ���� ���� ��, �������� ���� ������ ����ϱ� ����, R ����
            r_dist = mid_dist - 1;
        }
    }

    // ��� �Ÿ� ��ȯ
    return result_dist;

}