// string을 long long으로 변환하기 위해 stoll을 쓴다.

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2, s3, s4;
	string temp1, temp2;
	long long ans;

	cin >> s1 >> s2 >> s3 >> s4;

	temp1 = s1 + s2;
	temp2 = s3 + s4;

	// stoll 은 string을 long long으로 변환
	ans = stoll(temp1) + stoll(temp2);

	cout << ans;
}