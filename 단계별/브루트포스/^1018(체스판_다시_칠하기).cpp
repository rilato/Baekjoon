// 만들어야할 WB, BW 이차원 배열을 만들어 놓고, 입력 값을 8 X 8로 쪼갠 후 기존의 이차원 배열과 비교한다.
// 주어진 이차원 배열에서 기준을 좌상단 (0, 0)의 값으로 정하고 기존 8 X 8 배열과 비교할 경우, 반례가 발생할 수 있다.
// 예를 들어,
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
// 에서 W가 우하단에 위치하고, 8 * 8로 잘랐을 때, 좌상단의 값은 'B'이지만, BWArr로 계산하게되면 count 값은 32가 된다!
//
// 따라서 BWArr과 WBArr을 모두 돌려본 후, 작게 나온 값을 count값으로 설정해야 한다.

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

	// 8 * 8일때 for문을 최소 한번은 돌아야하는데,
	// height가 8인 경우, height - 8은 0이 되므로, i <= height - 8에서 =이 포함된다!!
	for (int i = 0; i <= height - 8; i++) {
		for (int j = 0; j <= width - 8; j++) {
			count1 = countBW(i, j, arr, BWArr);
			count2 = countWB(i, j, arr, WBArr);

			count = (count1 < count2) ? count1 : count2;	// 삼항 연산자 사용에 주의한다.

			if (count <= min)
				min = count;
		}
	}

	// 어차피 최소 값만 구하면 되므로, count 값들을 저장할 배열을 따로 만들지 않고도 min을 구할 수 있다.
	cout << min;

	for (int i = 0; i < height; i++)
		delete[] arr[i];

	delete[] arr;
}

int countBW(int x, int y, char** arr, char BWArr[][8]) {
	int count = 0;

	// BWArr은 i,j가 고정되어 0번째 인덱스부터 7번째 인덱스까지 돌아야 하지만,
	// arr은 i, j가 움직이며 x번째 인덱스부터 y번째 인덱스까지 돌아야 하므로
	// arr의 인덱싱에 [i + x][j + y]를 해줘야 한다!!
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