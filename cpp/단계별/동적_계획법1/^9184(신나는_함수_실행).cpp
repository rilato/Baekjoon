// Dynamic Programming�� ��ŭ, �迭�� ������ ���� �����ϰ�, �� ���� �ٽ� Ȱ���ϴ� ������� �ڵ带 §��.

#include <iostream>

using namespace std;

int arr[21][21][21] = { 0, };

int solve(int a, int b, int c);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int a, b, c;

	while (1)
	{
		std::cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << '\n';
	}
}

int solve(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	else if (a > 20 || b > 20 || c > 20)
		return solve(20, 20, 20);

	// �̹� ����� ���̶�� �� ���� ����
	else if (arr[a][b][c] != 0)
		return arr[a][b][c];

	// ���� ���Ӱ� ����
	else if (a < b && b < c)
		arr[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);

	// ���� ���Ӱ� ����
	else
		arr[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);

	return arr[a][b][c];
}