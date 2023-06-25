// Key와 Value를 갖는 map에 대해 알아야 한다.

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	string S;
	// 문자열이 key, 숫자가 value인 map 
	map <string, int> m_string;
	// 숫자가 key, 문자열이 value인 map
	map <int, string> m_int;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> S;

		// map에 값을 넣는 두 가지 방법
		m_string.insert({ S,i });
		m_int.insert(make_pair(i, S));
	}

	for (int i = 0; i < M; i++) {
		int n;

		cin >> S;

		// 맨 앞 글자가 숫자라면
		if (isdigit(S[0])) {
			n = stoi(S);
			cout << m_int[n] << '\n';
		}
		else
			cout << m_string[S] << '\n';
	}
}