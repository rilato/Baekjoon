#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	string temp = "";
	string answer = "";
	bool tag = false;

	getline(cin, S);

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '<') {
			tag = true;
			answer += temp;
			temp = "";
		}
		else if (S[i] == '>') {
			tag = false;
			answer += S[i];
			continue;
		}

		if (tag) {
			answer += S[i];
		}
		else if (!tag) {
			if (S[i] == ' ') {
				answer += temp;
				answer += " ";
				temp = "";
			}
			else {
				temp = S[i] + temp;
			}
		}
	}

	answer += temp;

	cout << answer;

	return 0;
}