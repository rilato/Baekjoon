// �ռ� ����ߴ� ��Ĵ�� �Ʒ��� �ڵ带 �ۼ��ϸ� �޸� �ʰ��� �߻��Ѵ�.

//#include <iostream>
//#include <algorithm>

//using namespace std;

//int main() {
	//int input;

	//cin >> input;

	//int* arr = new int[input];

	//for (int i = 0; i < input; i++) {
		//cin >> arr[i];
	//}

	//sort(arr, arr + input);

	//for (int i = 0; i < input; i++)
		//cout << arr[i] << '\n';

	//delete[] arr;
//}



// �Է¹��� ���� ���� �� �Է¹޾Ƽ� �����ϰ� �Ǹ� ���ѵ� 8MB�� �޸𸮸� �ʰ��ع�����.
// ���ڸ� ī��Ʈ �صξ��ٰ� ǥ��������� ��¸� ���ִ� ����� ����ؾ��Ѵ�.

// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);�� ���� ����ȭ�� �����־�� �ӵ��� ���ȴ�.

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num;
	int arr[10001] = { 0, };

	cin >> input;

	// ����ڿ��� input��ŭ num���� �Է¹޴µ�, num ��ġ�� �ش��ϴ� �迭 ���� 1�� ������Ų��.
	// �̷��� �Ǹ� �ش� �迭�� ���� �ε��� ���� ���� ��� ���� �󸶳� �ԷµǾ����� �� �� �ִ�.
	for (int i = 0; i < input; i++) {
		cin >> num;
		arr[num]++;
	}

	for (int i = 0; i < 10001; i++) {
		if (arr[i]) {
			for (int j = 0; j < arr[i]; j++)
				cout << i << '\n';
		}
	}
}