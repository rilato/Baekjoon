// ������ ��ġ�� �ִ� �κ��� �׻� ������ �۾��� �������� ������, ������ ��ġ�� �ִ� �κ��� �������� �ʰ� ��ü�� �ű�� �������� ���� ������ ������ �ȴ�.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int cnt = 0;        // �������� ĭ�� ����
int answer = 0;     // �ܰ� �ݺ� Ƚ��
vector <int> v;     // ������ �迭
vector <bool> box;  // ���� ���� ����

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    v.resize(2 * N);
    box.resize(N);  // ������ 0���� N - 1������ ��ġ�Ѵ�. ���� N ũ���� �迭�� �������ش�.

    for (int i = 0; i < 2 * N; i++) {
        cin >> v[i];

        if (v[i] == 0) {
            cnt++;
        }
    }

    while (1) {
        //cout << "box : ";
        //for (int i = 0; i < 2 * N; i++) {
        //    cout << box[i] << ", ";
        //}
        //cout << "\n";

        //cout << "v : ";
        //for (int i = 0; i < 2 * N; i++) {
        //    cout << v[i] << ", ";
        //}
        //cout << "\n";


        // bool �迭�� v �迭 �� ĭ�� ������
        bool tmp = box[N - 1];
        for (int i = N - 1; i >= 1; i--) {
            box[i] = box[i - 1];
        }
        box[0] = tmp;
        box[N - 1] = false; // ������ ��ġ�� �ִ� �κ��� �׻� ����

        int temp = v[2 * N - 1];
        for (int i = 2 * N - 1; i >= 1; i--) {
            v[i] = v[i - 1];
        }
        v[0] = temp;


        //cout << "rotation box : ";
        //for (int i = 0; i < 2 * N; i++) {
        //    cout << box[i] << ", ";
        //}
        //cout << "\n";

        //cout << "rotation v : ";
        //for (int i = 0; i < 2 * N; i++) {
        //    cout << v[i] << ", ";
        //}
        //cout << "\n";


        // �����̾Ʈ�� N - 1��°���� ������.
        // ���� ĭ�� �κ��� �ְ�, �տ� �κ��� ����(���� bool �迭 ���� false) + ���� �������� 1 �̻��̶��(���� v �迭 ���� 1 �̻�) -> �̵�
        for (int i = N - 2; i >= 0; i--) {
            if (box[i] && !box[i + 1] && v[i + 1] >= 1) {
                // ���� ĭ���� �ڽ� �ű��, ���� ĭ�� ������ 1 ���
                box[i + 1] = true;
                box[i] = false;
                v[i + 1]--;

                // �������� �� ��Ҵٸ� cnt++;
                if (v[i + 1] == 0) {
                    cnt++;
                }
            }
        }
        box[N - 1] = false; // ������ ��ġ�� �ִ� �κ��� �׻� ����


        // ���� ĭ�� �κ��� ����, �������� 1 �̻��� �� �ڽ� �ø���
        if (!box[0] && v[0] >= 1) {
            box[0] = true;
            v[0]--;

            // �������� �� ��Ҵٸ� cnt++;
            if (v[0] == 0) {
                cnt++;
            }
        }

        //cout << "after input box : ";
        //for (int i = 0; i < 2 * N; i++) {
        //    cout << box[i] << ", ";
        //}
        //cout << "\n";

        //cout << "after input v : ";
        //for (int i = 0; i < 2 * N; i++) {
        //    cout << v[i] << ", ";
        //}
        //cout << "\n";

        answer++;

        // �������� 0�� ĭ�� K����� ��� �� ����
        if (cnt >= K) {
            cout << answer;
            break;
        }
    }

    return 0;
}