//분할 정복 알고리즘 문제라 한다.
//분할 정복법이란 문제를 나눌 수 없을 때까지 나누어서 각각을 풀고 다시 합병하는 방법인데
//N이 27이면 그림처럼 27X27 -> 9X9 -> 3X3 -> 1X1까지 분할시킬 수 있다.

//언제가 공백인지가 관건인데 저런 식으로 공백인 좌표들을 모아 두고 규칙성을 찾아보니
//N이 27인 경우엔 좌표를 9, 3, 1로 나눈 값에 % 3을 한 값이 1일 때
//즉, i / N / 3 % 3, i / N / 3 / 3 % 3, i / N / 3 / 3 / 3 % 3 ... 이 1인 경우가 공백인 경우였다.
//1X1로 만들기 위해 재귀 호출할 때 N을 3으로 나눈 값을 넣어주고
//공백인 경우를 위해 i와 j를 각각 3으로 나눈 값을 넣어준다.

#include <iostream>

using namespace std;

void stars(int i, int j, int num);

int main() {
	int num;

	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			stars(i, j, num);
		}
		cout << '\n';
	}
}

void stars(int i, int j, int num) {
	if (i % 3 == 1 && j % 3 == 1) {
		cout << ' ';
		return;
	}
	else if (num == 1) {		// i, j를 계속해서 끝까지 나눠보아도 i % 3 == 1, j % 3 == 1에 걸리는 것이 없을 때, num == 1이 된다. 이 때 비로소 *을 찍는다.
		cout << '*';
		return;
	}

	return stars(i / 3, j / 3, num / 3);
}