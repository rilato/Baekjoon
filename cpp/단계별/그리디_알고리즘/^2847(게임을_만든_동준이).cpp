// ������ Ǯ�� ���� for���� �ڿ������� �����Ѵ�.

#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, temp;
    int arr[101] = { 0, };
    int cnt = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    temp = arr[N - 1];

    for (int i = N - 2; i >= 0; i--) {
        // ���� ���� �ִ� ���� ���� ������ ũ�ų� ���ٸ�
        // ���� �����ϰ� cnt����
        if (arr[i] >= temp) {
            cnt += arr[i] - temp + 1;
            arr[i] = temp - 1;
        }

        temp = arr[i];
    }

    cout << cnt;
}