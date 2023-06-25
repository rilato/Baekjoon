// Key�� Value�� ���� map�� ���� �˾ƾ� �Ѵ�.

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
	// ���ڿ��� key, ���ڰ� value�� map 
	map <string, int> m_string;
	// ���ڰ� key, ���ڿ��� value�� map
	map <int, string> m_int;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> S;

		// map�� ���� �ִ� �� ���� ���
		m_string.insert({ S,i });
		m_int.insert(make_pair(i, S));
	}

	for (int i = 0; i < M; i++) {
		int n;

		cin >> S;

		// �� �� ���ڰ� ���ڶ��
		if (isdigit(S[0])) {
			n = stoi(S);
			cout << m_int[n] << '\n';
		}
		else
			cout << m_string[S] << '\n';
	}
}