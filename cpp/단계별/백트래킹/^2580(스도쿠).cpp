// https://velog.io/@yhames/C-%EB%B0%B1%EC%A4%80-2580-%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9-03-%EC%83%81%ED%83%9C%EB%B3%B5%EA%B5%AC

// 상태 복구가 필요한 백트래킹
// exit(0)과 return의 차이를 명확히 해야 한다.


#include <iostream>

using namespace std;

int arr[9][9] = { 0, };

void sudoku(int x, int y);
bool promising(int x, int y, int a);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];

	sudoku(0, 0);
}

void sudoku(int x, int y) {
	// 0행부터 탐색을 시작했으므로, 9행이 나왔다는 것은 모든 탐색을 마쳤다는 것을 의미
	// 탐색을 마쳤으므로 출력
	if (x == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}
		// return;으로 마무리 지으면, 틀렸다고 뜬다.
		// return과 exit(0)의 차이는
		// exit(0)은 오류 없이 정상적으로 완전히 종료함을 의미하고
		// return은 이 함수만 종료시키는 것을 의미한다.
		exit(0);
	}
	// 0열부터 탐색했으므로, 9열이 나왔다는 것은 다음 행 탐색을 시작해야함을 의미
	if (y == 9)
		sudoku(x + 1, 0);
	// 만약 해당 자리의 값이 0인 경우,
	if (arr[x][y] == 0) {
		// 스도쿠의 숫자는 1부터 9까지 들어가야 하므로, i는 1부터 시작하여 9까지 탐색
		for (int i = 1; i <= 9; i++) {
			// 현재 행과 열을 각각 x y, 해당 자리에 들어갈 숫자를 i로 지정
			if (promising(x, y, i)) {
				// 조건을 만족한다면, 해당 자리에 i를 넣고
				arr[x][y] = i;
				// 행은 그대로 둔 채로, 다음 열을 탐색
				sudoku(x, y + 1);
				// 상태 복구를 진행한다.
				// 여기서는 검사의 범위가 해당 행과 열 그리고 3*3 정사각형 범위이기 때문에
				// 상태복구를 하지 않으면 유망성검사에서 이전에 할당한 값을 사용하게 된다.
		// 즉, 3 x 3 정사각형 범위가 완전하게 채워지지 않았을 경우, 0으로 복원한 후 다시 따져본다.
		// 같은 행과 열에 비어있는 두 칸이 존재할 수 있기 때문에 숫자 하나를 단정지을 수 없기 때문이다.
				arr[x][y] = 0;
			}
		}
	}
	// 해당 자리의 값이 0이 아닌 경우, 바로 다음 열을 탐색
	else
		sudoku(x, y + 1);
}

// x y는 행과 열의 인덱스, a는 1부터 9까지 숫자를 하나씩 넣어보는 용도로 사용
bool promising(int x, int y, int a) {
	for (int i = 0; i < 9; i++) {
		// 행 고정, 열 이동 또는 열 고정, 행 이동했는데 이미 해당 숫자가 있는 경우 false 반환
		if (arr[x][i] == a || arr[i][y] == a)
			return false;
	}

	// 3 X 3 사이즈 내에서 해당 숫자가 이미 있는 경우 false 반환
	for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++) {
		for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++) {
			if (arr[i][j] == a)
				return false;
		}
	}

	// 불만족하는 조건에 걸리지 않았을 경우에만 true 반환
	return true;
}