// Ʋ�� Ǯ��
// n == 90�� ��� int�� ������ �����

#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    int arr[91] = { 0, };

    cin >> N;

    arr[1] = 1;

    for (int i = 2; i <= N; i++)
        arr[i] = arr[i - 1] + arr[i - 2];

    cout << arr[N];
}


// ���� Ǯ��

#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    long long arr[91] = { 0, };

    cin >> N;

    arr[1] = 1;

    for (int i = 2; i <= N; i++)
        arr[i] = arr[i - 1] + arr[i - 2];

    cout << arr[N];
}