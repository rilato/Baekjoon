// 이 문제는 소수를 구할 때 사용하는 에라토스테네스의 체의 원리를 사용한다.
// 2부터 시작해서 min ~ max 사이에 있는 제곱수를 체크해야 하는데,
// 이때 최대 10 ^ 12까지 입력이 들어오기 때문에 제곱수를 그대로 arr의 index로 사용하게 되면 메모리가 감당하지 못한다.
// (arr[10 ^ 12]로 선언해야 하기 때문이다)

// 따라서 문제에서 다른 제한으로 min과 max의 차이가 최대 10 ^ 6이라고 했기 때문에,
// check(Max - Min + 1) (최대 10 ^ 6의 크기)짜리를 선언하여(제곱수 - min)으로 index를 사용했다.

#include <iostream>
#include <vector>

using namespace std;

long long Min, Max;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Min >> Max;

    // 최댓값과 최솟값의 차이만큼 배열 선언
    vector <bool> check(Max - Min + 1);

    // 1을 제외하고, 2의 제곱수인 4부터 Max보다 작거나 같은 값까지 반복
    for (long long i = 2; i * i <= Max; i++) {
        long long pow = i * i;
        long long start_index = Min / pow;  // Min값에서 제곱수를 나누어 에라토스테네스의 체에서 곱해질 j의 시작 값을 설정

        // Min보다 큰 제곱수부터 시작되도록 하는 작업
        if (Min % pow != 0) {
            // 나머지가 있으면 1을 더해주어야 Min보다 큰 제곱수부터 시작됨
            // ex) Min = 5, pow = 4 => 나머지가 있으므로, start_index는 1이 아닌, 2
            start_index++;
        }

        // 제곱수의 배수를 true로 변경
        for (long long j = start_index; pow * j <= Max; j++) {
            // j * pow는 제곱수의 배수
            check[(int)((j * pow) - Min)] = true;
        }
    }

    int cnt = 0;

    for (int i = 0; i <= Max - Min; i++) {
        if (!check[i]) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}