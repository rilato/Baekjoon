// Dynamic Programming인 만큼, 배열에 기존의 값을 저장하고, 그 값을 다시 활용하는 방식으로 코드를 짠다.

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

	// 이미 저장된 값이라면 그 값을 리턴
	else if (arr[a][b][c] != 0)
		return arr[a][b][c];

	// 값을 새롭게 저장
	else if (a < b && b < c)
		arr[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);

	// 값을 새롭게 저장
	else
		arr[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);

	return arr[a][b][c];
}