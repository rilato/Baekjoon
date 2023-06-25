// 문제에서 의상 종류에 따른 개수가 가장 중요하다.
// 각 의상종류에 + 1 함값을 곱한 뒤에 나온 최종 값에서 - 1을 해준 것이 정답이다.

// 옷의 종류에 1을 더한 이유는, 안입는 경우를 포함하기 위해 더해주는 것이다.
// 마지막에 1을 뺀 이유는, 옷을 하나도 입지 않은 경우를 배제하기 위한 것이다.


// 내가 생각한 맞은 풀이

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector <string> v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num;
	string clothName, clothType;

	cin >> input;

	for (int i = 0; i < input; i++) {
		vector <string> v;

		cin >> num;

		for (int j = 0; j < num; j++) {
			cin >> clothName >> clothType;

			v.push_back(clothType);
		}

		print(v);
	}
}

void print(vector <string> v) {
	int k = 0;
	int arr[31] = { 0, };
	int product = 1;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == " ")
			continue;

		// 겹치는 type이 없더라도, 1개는 있으니까 1을 더하고 시작한다.
		arr[k]++;

		for (int j = i + 1; j < v.size(); j++) {
			// 공백이 있으면 건너뛴다.
			if (v[j] == " ")
				continue;

			// 같은 문자가 있으면 뒤의 자리를 공백으로 바꿔준다.
			if (v[i] == v[j]) {
				v[j] = " ";
				arr[k]++;
			}
		}

		product *= (arr[k] + 1);

		k++;
	}

	cout << product - 1 << '\n';
}


// 다른 맞은 풀이

#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int n;
	string catag, name;

	while (T--)
	{
		map<string, int> m;
		cin >> n;
		while (n--)
		{
			// name은 사용 x
			cin >> name >> catag;

			// find 함수는 찾는 key값이 없으면 end 주소를 리턴
			if (m.find(catag) == m.end())
				m.insert({ catag, 1 });

			else
				m[catag]++;
		}

		int ans = 1;

		// for문에서 auto i : m 형식으로 쓰게 되면, 포인터를 쓰지 않아도 i 자체가 그 값을 가리킨다.
		for (auto i : m)
			ans *= (i.second + 1);

		cout << ans - 1 << '\n';
	}
}