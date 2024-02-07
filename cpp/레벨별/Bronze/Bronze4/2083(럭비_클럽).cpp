#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		string name;
		int age, weight;

		cin >> name >> age >> weight;

		if (name == "#" && !age && !weight)
			break;

		cout << name << " ";

		if (age > 17 || weight >= 80)
			cout << "Senior\n";
		else
			cout << "Junior\n";
	}

	return 0;
}