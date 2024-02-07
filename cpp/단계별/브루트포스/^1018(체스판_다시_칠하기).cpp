// �������� WB, BW ������ �迭�� ����� ����, �Է� ���� 8 X 8�� �ɰ� �� ������ ������ �迭�� ���Ѵ�.
// �־��� ������ �迭���� ������ �»�� (0, 0)�� ������ ���ϰ� ���� 8 X 8 �迭�� ���� ���, �ݷʰ� �߻��� �� �ִ�.
// ���� ���,
// 
// 9 23
// BBBBBBBBBBBBBBBBBBBBBBB
// BBBBBBBBBBBBBBBBBBBBBBB
// BBBBBBBBBBBBBBBBBBBBBBB
// BBBBBBBBBBBBBBBBBBBBBBB
// BBBBBBBBBBBBBBBBBBBBBBB
// BBBBBBBBBBBBBBBBBBBBBBB
// BBBBBBBBBBBBBBBBBBBBBBB
// BBBBBBBBBBBBBBBBBBBBBBB
// BBBBBBBBBBBBBBBBBBBBBBW
// 
// ���� W�� ���ϴܿ� ��ġ�ϰ�, 8 * 8�� �߶��� ��, �»���� ���� 'B'������, BWArr�� ����ϰԵǸ� count ���� 32�� �ȴ�!
//
// ���� BWArr�� WBArr�� ��� ������ ��, �۰� ���� ���� count������ �����ؾ� �Ѵ�.

#include <iostream>

using namespace std;

int countBW(int x, int y, char** arr, char BWArr[][8]);
int countWB(int x, int y, char** arr, char WBArr[][8]);

int main() {
	char BWArr[8][8] = {
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
	};

	char WBArr[8][8] = {
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W'
	};

	int width, height;
	int count, count1, count2;
	char color;
	int k = 0;

	cin >> height >> width;

	char** arr = new char* [height];
	for (int i = 0; i < height; i++)
		arr[i] = new char[width];

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> color;
			arr[i][j] = color;
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (!isalpha(arr[i][j]))
				arr[i][j] = 0;
		}
	}

	int min = height * width;

	// 8 * 8�϶� for���� �ּ� �ѹ��� ���ƾ��ϴµ�,
	// height�� 8�� ���, height - 8�� 0�� �ǹǷ�, i <= height - 8���� =�� ���Եȴ�!!
	for (int i = 0; i <= height - 8; i++) {
		for (int j = 0; j <= width - 8; j++) {
			count1 = countBW(i, j, arr, BWArr);
			count2 = countWB(i, j, arr, WBArr);

			count = (count1 < count2) ? count1 : count2;	// ���� ������ ��뿡 �����Ѵ�.

			if (count <= min)
				min = count;
		}
	}

	// ������ �ּ� ���� ���ϸ� �ǹǷ�, count ������ ������ �迭�� ���� ������ �ʰ� min�� ���� �� �ִ�.
	cout << min;

	for (int i = 0; i < height; i++)
		delete[] arr[i];

	delete[] arr;
}

int countBW(int x, int y, char** arr, char BWArr[][8]) {
	int count = 0;

	// BWArr�� i,j�� �����Ǿ� 0��° �ε������� 7��° �ε������� ���ƾ� ������,
	// arr�� i, j�� �����̸� x��° �ε������� y��° �ε������� ���ƾ� �ϹǷ�
	// arr�� �ε��̿� [i + x][j + y]�� ����� �Ѵ�!!
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i + x][j + y] != BWArr[i][j])
				++count;
		}
	}

	return count;
}

int countWB(int x, int y, char** arr, char WBArr[][8]) {
	int count = 0;
	string character;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i + x][j + y] != WBArr[i][j])
				++count;
		}
	}

	return count;
}