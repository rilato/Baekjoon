// 문제를 풀기 위해 for문을 뒤에서부터 접근한다.

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
        // 현재 보고 있는 값이 이전 값보다 크거나 같다면
        // 값을 조정하고 cnt증가
        if (arr[i] >= temp) {
            cnt += arr[i] - temp + 1;
            arr[i] = temp - 1;
        }

        temp = arr[i];
    }

    cout << cnt;
}