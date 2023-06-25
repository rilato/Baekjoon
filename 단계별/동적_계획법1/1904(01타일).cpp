// 틀린 풀이
// long long을 썼음에도 불구하고, 누적 합에서 진작에 long long의 범위를 넘어선다.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	vector <long long> v;

	// 주어진 문제는 피보나치 수열을 따른다.
	v.push_back(0);
	// N = 1 일 때 1
	v.push_back(1);
	// N = 2 일 때 2
	v.push_back(2);

	cin >> N;

	for (int i = 3; i <= N; i++)
		v.push_back(v[i - 1] + v[i - 2]);

	cout << v[N] % 15746;
}


// 맞은 풀이
// 미리미리 나머지를 구해놓고, 값을 더해나간다.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	vector <long long> v;

	// 주어진 문제는 피보나치 수열을 따른다.
	v.push_back(0);
	// N = 1 일 때 1
	v.push_back(1);
	// N = 2 일 때 2
	v.push_back(2);

	cin >> N;

	for (int i = 3; i <= N; i++)
		v.push_back((v[i - 1] + v[i - 2]) % 15746);

	cout << v[N] % 15746;
}