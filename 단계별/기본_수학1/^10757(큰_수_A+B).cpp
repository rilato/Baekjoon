// 아주 큰 수는 long long 으로도 덧셈할 수 없다.
// 따라서 string을 사용한다.
// 
// string으로 받은 num1과 num2를 뒤집는다.
// 맨 앞자리부터 하나씩 더한다. 10을 넘어가면 carry가 발생한다.
// 더한 수를 다시 뒤집어 원래 수로 만든다.

#include <iostream>
#include <string>

using namespace std;

void reverse(string& s);

int main() {
	string num1, num2, lower, higher;
	string ans;
	long long length;
	int carry = 0;
	int sum;

	cin >> num1 >> num2;

	reverse(num1);
	reverse(num2);

	if (num1.size() >= num2.size()) {
		length = num1.size() - num2.size();
		lower = num2;
		higher = num1;
	}
	else {
		length = num2.size() - num1.size();
		lower = num1;
		higher = num2;
	}

	for (int i = 0; i < lower.size(); i++) {
		sum = stoi(lower.substr(i, 1)) + stoi(higher.substr(i, 1)) + carry;

		if (sum >= 10) {
			carry = 1;
			ans += to_string(sum - 10);
		}

		else {
			carry = 0;
			ans += to_string(sum);
		}

		if (i == lower.size() - 1 && lower.size() == higher.size() && carry == 1)   // 마지막에 더한 수가 10을 넘어갈 때 carry를 반영해야 한다.
			ans += to_string(carry);
	}

	for (int i = lower.size(); i < higher.size(); i++) {
		sum = stoi(higher.substr(i, 1)) + carry;

		if (sum >= 10) {
			carry = 1;
			ans += to_string(sum - 10);
		}

		else {
			carry = 0;
			ans += to_string(sum);
		}

		if (i == higher.size() - 1 && carry == 1)   // 마지막에 더한 수가 10을 넘어갈 때 carry를 반영해야 한다.
			ans += to_string(carry);
	}

	reverse(ans);

	cout << ans;
}

void reverse(string& s) {			// 참조 변수를 이용하여 문자 s를 근본적으로 바꿔준다.
	char temp;

	for (int i = 0; i < s.size() / 2; i++) {
		temp = s[i];
		s[i] = s[s.size() - 1 - i];
		s[s.size() - 1 - i] = temp;
	}
}



// 다른 풀이

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, sum;
int num1[10001], num2[10001];
string s1, s2, tmp;
vector<int> ans;

int main()
{
	cin >> s1 >> s2;

	// 더 긴 수를 s1으로 저장하기
	if (s1.size() < s2.size())
	{
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	// num1, num2 배열을 만드는 과정
	for (int i = 0; i < s1.size(); i++)
		num1[i + 1] = s1[i] - '0';	// - '0'을 통해 문자를 숫자로 변경

	for (int i = 0; i < s2.size(); i++)
		num2[i + 1 + (s1.size() - s2.size())] = s2[i] - '0';	// (s1.size()-s2.size())를 통해 num1과 num2를 더할 때 자릿수를 맞춰줌

	// num배열들의 끝부분부터 덧셈을 하면서 ans벡터에 값 저장
	for (int i = s1.size(); i > 0; i--)
	{
		sum = num1[i] + num2[i];
		if (sum >= 10)
		{
			num1[i - 1]++;	// 앞자리에 carry값(1)을 더함
			sum -= 10;
		}
		ans.push_back(sum);
	}

	// 맨 앞자리수 출력
	if (num1[0] != 0) cout << 1;

	// ans벡터 거꾸로 출력
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i];
	}

}