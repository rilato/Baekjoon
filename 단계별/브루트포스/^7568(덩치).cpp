//�ڽź��� ū �����Կ� Ű�� ���� ����� ���� ��� ����� 1� �о���� ������� Ǯ���Ѵ�.

#include <iostream>

using namespace std;

int main() {
	int input, weight, height;
	int rank = 1;

	cin >> input;

	//������ �迭 �����Ҵ�
	int** arr = new int* [input];

	for (int i = 0; i < input; i++) {
		arr[i] = new int[2];
	}

	for (int i = 0; i < input; i++) {
		cin >> weight >> height;
		arr[i][0] = weight;
		arr[i][1] = height;
	}

	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++) {
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
				rank++;
		}
		cout << rank << ' ';
		rank = 1;
	}

	for (int i = 0; i < input; i++) {
		delete[] arr[i];
	}

	delete[] arr;
}