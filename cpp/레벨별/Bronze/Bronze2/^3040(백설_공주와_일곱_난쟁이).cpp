// 총 합이 100이어야 하므로, sum에서 아닌 두 개를 걸러낸다.
// for문을 7번 돌리지 않는다는 것에 주의한다!

#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    int arr[9] = { 0, };
    int num1, num2;
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];

        sum += arr[i];
    }

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (arr[i] == num1 || arr[i] == num2)
            continue;
        else
            cout << arr[i] << '\n';
    }
}