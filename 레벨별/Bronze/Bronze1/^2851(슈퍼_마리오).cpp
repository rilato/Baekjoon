// Ʋ�� Ǯ��
// sum�� 100�� ���� �ʴ� ���, �ƹ��� ����� ���� �ʴ� ������ �߻��Ͽ���.

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


// ���� Ǯ��
// sum�� 100�� ���� �ʴ� ��쿡 ���� ��µǵ��� �Ͽ���.

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