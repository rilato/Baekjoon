#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int input, num;
vector <int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cout << v.front() * v.back();
}
