// 시간 초과가 난 풀이
// 문제에서 주어진 함수를 그대로 사용하였더니 시간 초과가 발생했다.
// 재귀의 형태로 이루어져있어서 수가 커질수록 아주 오랜 시간이 걸린다.

#include <iostream>
#include <vector>

using namespace std;

int arr[2] = { 0, };

int fibonacci(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, num;

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;
        fibonacci(num);

        cout << arr[0] << ' ' << arr[1] << '\n';

        arr[0] = 0;
        arr[1] = 0;
    }
}

int fibonacci(int n) {
    if (n == 0) {
        ++arr[0];
        return 0;
    }
    else if (n == 1) {
        ++arr[1];
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}


// 맞은 풀이
// 0 1의 호출 횟수를 출력하는 정답 사이의 관계를 찾아낸다.
// n == 0 일 때 1, 0을 출력하지만
// n == 1 부터는 0과 1 모두 피보나치 수열을 이루어나간다.

#include <iostream>

using namespace std;

int fibArr[41] = { 0, 1, };

int fibonacci(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, num;

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;

        if (num == 0)
            cout << "1 0" << '\n';

        else
            cout << fibonacci(num - 1) << ' ' << fibonacci(num) << '\n';
    }
}

int fibonacci(int n) {
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    if (n >= 2) {
        for (int i = 2; i <= n; i++) {
            fibArr[i] = fibArr[i - 1] + fibArr[i - 2];
        }

        return fibArr[n];
    }
}