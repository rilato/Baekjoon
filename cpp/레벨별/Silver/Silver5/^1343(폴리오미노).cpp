// 틀린 풀이

// 반례 : X.X

#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string S;
	int count = 0;
	int Acount, Bcount;

	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'X')
			++count;
	}

	// X의 개수가 홀수인 경우 -1을 출력한 후 종료한다.
	if (count % 2) {
		cout << -1;
		return 0;
	}

	// X의 개수가 짝수인 경우
	else {
		// count의 개수를 0으로 초기화한 후 X의 개수를 세기 시작한다.
		count = 0;

		for (int i = 0; i < S.size(); i++) {
			if (S[i] == 'X') {
				// X의 개수를 1개 증가시킨다.
				++count;

				// 맨 마지막 문자에 도달한 경우, 현재까지 X를 A와 B로 바꿔서 출력한다.
				if (i == S.size() - 1) {
					// Acount는 A가 출력되어야할 개수를 의미하는 변수다.
					Acount = count / 4;
					Acount *= 4;
					// Bcount는 B가 출력되어야할 개수를 의미하는 변수다.
					Bcount = count - Acount;

					for (int j = 0; j < Acount; j++)
						cout << "A";

					for (int j = 0; j < Bcount; j++)
						cout << "B";

					return 0;
				}
			}
			// '.' 문자를 만난 경우는 다음과 같다.
			else {
				// X가 하나도 세어지지 않았다면 '.'을 찍고 다음 내용은 건너뛴다.
				if (count == 0) {
					cout << '.';
					continue;
				}
				// X가 세어졌다면 다음의 방식으로 해결한다.
				else {
					Acount = count / 4;
					Acount *= 4;
					Bcount = count - Acount;

					for (int j = 0; j < Acount; j++)
						cout << "A";

					for (int j = 0; j < Bcount; j++)
						cout << "B";

					count = 0;

					cout << '.';
				}
			}
		}
	}
}


// 맞은 풀이

#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string board, result;
	int cnt = 0;

	cin >> board;

	board += ' ';

	for (int i = 0; i < board.size() - 1; i++) {

		if (board[i] == 'X')
			cnt++;

		if (board[i] == '.') {
			result += ".";

			if (cnt % 2 != 0)
				break;
			else
				cnt = 0;
		}

		if (cnt == 2 && board[i + 1] != 'X') {
			result += "BB";
			cnt = 0;
		}
		else if (cnt == 4) {
			result += "AAAA";
			cnt = 0;
		}


	}

	if (cnt % 2 == 1)
		cout << -1;
	else
		cout << result;
}