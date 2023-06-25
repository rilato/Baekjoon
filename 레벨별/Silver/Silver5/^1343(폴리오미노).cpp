// Ʋ�� Ǯ��

// �ݷ� : X.X

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

	// X�� ������ Ȧ���� ��� -1�� ����� �� �����Ѵ�.
	if (count % 2) {
		cout << -1;
		return 0;
	}

	// X�� ������ ¦���� ���
	else {
		// count�� ������ 0���� �ʱ�ȭ�� �� X�� ������ ���� �����Ѵ�.
		count = 0;

		for (int i = 0; i < S.size(); i++) {
			if (S[i] == 'X') {
				// X�� ������ 1�� ������Ų��.
				++count;

				// �� ������ ���ڿ� ������ ���, ������� X�� A�� B�� �ٲ㼭 ����Ѵ�.
				if (i == S.size() - 1) {
					// Acount�� A�� ��µǾ���� ������ �ǹ��ϴ� ������.
					Acount = count / 4;
					Acount *= 4;
					// Bcount�� B�� ��µǾ���� ������ �ǹ��ϴ� ������.
					Bcount = count - Acount;

					for (int j = 0; j < Acount; j++)
						cout << "A";

					for (int j = 0; j < Bcount; j++)
						cout << "B";

					return 0;
				}
			}
			// '.' ���ڸ� ���� ���� ������ ����.
			else {
				// X�� �ϳ��� �������� �ʾҴٸ� '.'�� ��� ���� ������ �ǳʶڴ�.
				if (count == 0) {
					cout << '.';
					continue;
				}
				// X�� �������ٸ� ������ ������� �ذ��Ѵ�.
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


// ���� Ǯ��

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