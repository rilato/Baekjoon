#include <iostream>

using namespace std;

int main() {
	int N, row, column;

	cin >> N;

	// col >= row�� ����
	row = N / 2;
	column = N - row;

	cout << (row + 1) * (column + 1);
}