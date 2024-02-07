// vector�� size ���ϱ�, iter ������ ����� �˾ƾ� �Ѵ�.

// iterator�� �̿����� ���� ��� / std ������ ���

#include <vector>

using namespace std;

long long sum(vector<int>& a)
{
	long long answer = 0;

	for (int i = 0; i < a.size(); i++)
		answer += a[i];

	return answer;
}


// iterator�� �̿��� ��� / std �������� ���� ���

#include <vector>

long long sum(vector<int>& a)
{
	long long ans = 0;

	for (std::vector<int>::iterator iter = a.begin(); iter < a.end(); iter++)
		ans += *iter;	// ���� ���ϹǷ�, *�� ���δ�.

	return ans;
}