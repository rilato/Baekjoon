// ������ ���� ���簢���� ��� ���ؾ� �ϴ����� �����̴�.

// Ʋ�� Ǯ��

#include<iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, direction, length, size;
    int arr[6] = { 0, };
    int max_width = 0;
    int max_width_index = 0;
    int max_height = 0;
    int max_height_index = 0;
    int my_index = 0;
    int small_len1 = 0;
    int small_len2 = 0;

    cin >> K;

    for (int i = 0; i < 6; i++) {
        cin >> direction >> length;

        arr[i] = length;

        if (direction == 1 || direction == 2) {
            if (length > max_width) {
                max_width = length;
                max_width_index = i;
            }
        }
        else {
            if (length > max_height) {
                max_height = length;
                max_height_index = i;
            }
        }
    }

    my_index = max_width_index > max_height_index ? max_width_index : max_height_index;
    // ������ �κ��� �ʺ�� �� ��°�� ���� �� �ʺ񿡼� 2��ŭ �� �� ���� ��ġ
    small_len1 = arr[(my_index + 2) % 6];
    // ������ �κ��� ���̴� ���� �� ���̿��� 4��ŭ �� �� ���� ��ġ
    small_len2 = arr[(my_index + 3) % 6];

    cout << K * (max_width * max_height - small_len1 * small_len2);
}


// ���� Ǯ��

#include <iostream>

using namespace std;

int N;
int arr[6 + 2][2 + 2];  // �־����� ����, ���̽�
int cnt[4]; // ���� �� ���� Ƚ�� ����

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s = 1; // ���� �簢���� ����
    int b = 1; // ū �簢���� ����

    // �Է� �ޱ�
    cin >> N;

    for (int i = 0; i < 6; i++) {
        cin >> arr[i][0] >> arr[i][1];
        cnt[arr[i][0]]++;
    }

    for (int i = 0; i < 6; i++) {

        if (cnt[arr[i][0]] == 1)
            // �� ���� �����ϴ� �����̴�
            b *= arr[i][1]; // ū �簢���� �ʺ�/�����̴�

        int n = (i + 1) % 6;
        int nn = (i + 2) % 6;
        // ��(I)�� �ٴ�����(nn)�� ������ �� ���̿� �ִ� ��(n)�� ���� �簢���� �ʺ�/�����̴�.
        if (arr[i][0] == arr[nn][0]) s *= arr[n][1];
    }

    cout << (b - s) * N;
}