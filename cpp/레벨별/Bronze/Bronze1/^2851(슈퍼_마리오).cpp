// 틀린 풀이
// sum이 100을 넘지 않는 경우, 아무런 출력을 하지 않는 문제가 발생하였다.

#include <iostream>

using namespace std;

int sum = 0;
int temp = 0;
int arr[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 10; i++) {
		sum += arr[i];

		if (sum > 100) {
			if (sum - 100 <= 100 - temp) {
				cout << sum;
				break;
			}
			else {
				cout << temp;
				break;
			}
		}

		temp = sum;
	}
}


// 맞은 풀이
// sum이 100을 넘지 않는 경우에 값이 출력되도록 하였다.

#include <iostream>

using namespace std;

int sum = 0;
int temp = 0;
int arr[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 10; i++) {
		sum += arr[i];

		if (sum > 100) {
			if (sum - 100 <= 100 - temp) {
				cout << sum;
				return 0;
			}
			else {
				cout << temp;
				return 0;
			}
		}

		temp = sum;
	}

	cout << sum;
}