/* ���ǻ��� */

// �����տ��� (0 + 0 + (-1)) / 3 = -0.333333... �̰� �̸� ù° �ڸ����� �ݿø��ϸ� 0�̴�. - 0���� ����ϸ� �ȵȴ�!!

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num, maxIndex;
	double average;
	int sum = 0;
	int max = 0;
	int cnt = 0;
	int count[8001] = { 0, };

	cin >> input;

	int* arr = new int[input];

	// ����ڿ��� input��ŭ num���� �Է¹޴µ�, num ��ġ�� �ش��ϴ� �迭 ���� 1�� ������Ų��.
	// �̷��� �Ǹ� �ش� �迭�� ���� �ε��� ���� ���� ��� ���� �󸶳� �ԷµǾ����� �� �� �ִ�.
	for (int i = 0; i < input; i++) {
		cin >> num;
		arr[i] = num;
		++count[num + 4000];
	}

	sort(arr, arr + input);

	//��� ���
	for (int i = 0; i < input; i++)
		sum += arr[i];

	average = (double)sum / input;

	//(0 + 0 + (-1)) / 3 = -0.333333... �̰� �̸� ù° �ڸ����� �ݿø��ϸ� 0�̴�. - 0���� ����ϸ� �ȵȴ�.
	if (round(average) == 0)
		cout << 0 << '\n';
	else
		cout << round(average) << '\n';

	//�߾Ӱ�
	cout << arr[input / 2] << '\n';

	//�ֺ�
	for (int i = 0; i < 8001; i++) {
		if (count[i] > max)
			max = count[i];
	}

	for (int i = 0; i < 8001; i++) {
		if (max == count[i]) {
			++cnt;
			maxIndex = i;
		}
	}

	if (cnt == 1)
		cout << maxIndex - 4000 << '\n';

	if (cnt >= 2) {
		cnt = 0;
		int i = 0;

		while (1) {
			if (cnt == 2)
				break;

			if (count[i] == max) {
				maxIndex = i;
				++cnt;
			}

			++i;
		}

		cout << maxIndex - 4000 << '\n';
	}

	//���� (�ִ밪 - �ּҰ�)
	cout << arr[input - 1] - arr[0];

	delete[] arr;
}



// �ٸ� �ڵ�. �ֺ��� ���� ȿ�������� ���� �ڵ�
// �ֺ��� ���� ���� ���, �� ��°�� ���� ���� ���ؾ��ϹǷ�, �� �� ���� �˻�� �ɷ��� �� �ִ� bool�� ����Ѵ�.

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num, maxIndex;
	double average;
	int sum = 0;
	int max = 0;
	bool flag = false;
	int count[8001] = { 0, };

	cin >> input;

	int* arr = new int[input];

	for (int i = 0; i < input; i++) {
		cin >> num;
		arr[i] = num;
		++count[num + 4000];

		// max���� ���� �� ���⿡ ���� �� �ִ�. �� for�� ����� 1ȸ ���� �� �ִ�.
		if (count[num + 4000] >= max)
			max = count[num + 4000];
	}

	sort(arr, arr + input);

	//��� ���
	for (int i = 0; i < input; i++)
		sum += arr[i];

	average = (double)sum / input;

	//(0 + 0 + (-1)) / 3 = -0.333333... �̰� �̸� ù° �ڸ����� �ݿø��ϸ� 0�̴�. - 0���� ����ϸ� �ȵȴ�.
	if (round(average) == 0)
		cout << 0 << '\n';
	else
		cout << round(average) << '\n';

	//�߾Ӱ�
	cout << arr[input / 2] << '\n';

	//�ֺ�

	for (int i = 0; i < 8001; i++) {
		if (count[i] == max) {
			maxIndex = i;

			if (flag)
				break;

			flag = true;
		}
	}

	cout << maxIndex - 4000 << '\n';

	//���� (�ִ밪 - �ּҰ�)
	cout << arr[input - 1] - arr[0];

	delete[] arr;
}