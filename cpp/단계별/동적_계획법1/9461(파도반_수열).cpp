// 규칙을 찾아보니 0번째 인덱스와 4번째 인덱스의 합이 5번째 인덱스의 값으로 나타난다.
// 6번째 인덱스의 값은 1번째 인덱스의 값과 5번째 인덱스의 값의 합으로 나타난다.
// 즉, 네 칸의 인덱스 차이의 합이 다음 인덱스 값이 되는 것이다.
// [i] = [i - 1] + [i - 5]

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T, N;
	vector <long long> v;

	// 0번째 인덱스는 그냥 0을 넣어주고, (N을 인덱스 값으로 맞추기 위해)
	// 1번째 인덱스부터 5번째 인덱스까지 값을 넣고 시작한다.
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);

	cin >> T;

	for (int i = 6; i <= 100; i++)
		v.push_back(v[i - 1] + v[i - 5]);

	for (int i = 0; i < T; i++) {
		cin >> N;

		cout << v[N] << '\n';
	}
}