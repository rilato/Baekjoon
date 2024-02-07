// Ʋ�� Ǯ��
// long long�� �������� �ұ��ϰ�, ���� �տ��� ���ۿ� long long�� ������ �Ѿ��.

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

	// �־��� ������ �Ǻ���ġ ������ ������.
	v.push_back(0);
	// N = 1 �� �� 1
	v.push_back(1);
	// N = 2 �� �� 2
	v.push_back(2);

	cin >> N;

	for (int i = 3; i <= N; i++)
		v.push_back(v[i - 1] + v[i - 2]);

	cout << v[N] % 15746;
}


// ���� Ǯ��
// �̸��̸� �������� ���س���, ���� ���س�����.

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

	// �־��� ������ �Ǻ���ġ ������ ������.
	v.push_back(0);
	// N = 1 �� �� 1
	v.push_back(1);
	// N = 2 �� �� 2
	v.push_back(2);

	cin >> N;

	for (int i = 3; i <= N; i++)
		v.push_back((v[i - 1] + v[i - 2]) % 15746);

	cout << v[N] % 15746;
}