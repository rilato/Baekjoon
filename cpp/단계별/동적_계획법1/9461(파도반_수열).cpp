// ��Ģ�� ã�ƺ��� 0��° �ε����� 4��° �ε����� ���� 5��° �ε����� ������ ��Ÿ����.
// 6��° �ε����� ���� 1��° �ε����� ���� 5��° �ε����� ���� ������ ��Ÿ����.
// ��, �� ĭ�� �ε��� ������ ���� ���� �ε��� ���� �Ǵ� ���̴�.
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

	// 0��° �ε����� �׳� 0�� �־��ְ�, (N�� �ε��� ������ ���߱� ����)
	// 1��° �ε������� 5��° �ε������� ���� �ְ� �����Ѵ�.
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