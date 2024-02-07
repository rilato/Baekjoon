// vector의 size 구하기, iter 돌리는 방법을 알아야 한다.

// iterator를 이용하지 않은 방법 / std 생략한 경우

#include <vector>

using namespace std;

long long sum(vector<int>& a)
{
	long long answer = 0;

	for (int i = 0; i < a.size(); i++)
		answer += a[i];

	return answer;
}


// iterator를 이용한 방법 / std 생략하지 않은 경우

#include <vector>

long long sum(vector<int>& a)
{
	long long ans = 0;

	for (std::vector<int>::iterator iter = a.begin(); iter < a.end(); iter++)
		ans += *iter;	// 값을 더하므로, *를 붙인다.

	return ans;
}