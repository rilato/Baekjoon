// https://cocoon1787.tistory.com/231
// https://organize-study.tistory.com/60
// 블로그에 나와있는 내용을 참조한다.

#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int n;
int cnt = 0;
int seq[100001];
vector<int> v;
vector<char> ans;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> seq[i]; // 수열 입력

	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
		ans.push_back('+');

		// 벡터가 비어있지않고,  cnt번째 수열이 벡터의 마지막 원소와 같을 경우 while문을 돈다.
		// 벡터가 비어있거나, v의 마지막 원소가 seq[cnt]와 같지 않으면 while문을 탈출한다.
		while (!v.empty() && v.back() == seq[cnt])
		{
			v.pop_back();
			ans.push_back('-');
			cnt++;
		}
	}

	if (!v.empty())
		cout << "NO"; // 수열이 만들어졌다면 벡터가 비어있어야 하므로.
	else
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << '\n';
}