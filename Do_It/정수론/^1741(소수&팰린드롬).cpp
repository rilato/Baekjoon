// � �� N�� 1000000 (�鸸)������ �־�������,
// N���� ũ�ų� ����, �Ӹ������ �� ���� ã���־�� �ϹǷ�,
// �Ҽ� �� �Ӹ���� ���� ã�� �˰��� �� 1000000 (�鸸)�� ��½ �پ�Ѵ� ������ Ž�����־�� �Ѵ�.

// 1. �ð��� �ణ �� �ɸ�����, �޸𸮸� ���� ����ϴ� ���

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;

bool isPrime(int num);
bool isMinPalindrome(string num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    // N���� ũ�ų� ����, �Ҽ��̸� �Ӹ������ ���� ã�� ����, �鸸���� ū ������ Ž���Ѵ�.
    for (int i = 2; i < 10000001; i++) {
        if (isPrime(i) && i >= N && isMinPalindrome(to_string(i))) {
            cout << i;
            break;
        }
    }

    return 0;
}

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

bool isMinPalindrome(string num) {
    int left = 0;
    int right = num.size() - 1;

    while (left < right) {
        if (num[left] != num[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}


// �޸𸮴� �ξ� ���� ��Ƹ�����, �ð��� ���� �� �ɸ��� ���

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;
long A[10000001];

bool isMinPalindrome(string num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 2; i < 10000001; i++) {
        A[i] = i;
    }

    for (int i = 2; i <= sqrt(10000001); i++) { // ������ ������ ����
        if (A[i] == 0) {
            continue;
        }

        for (int j = i + i; j < 10000001; j += i) { // ��� �����
            A[j] = 0;
        }
    }

    // N���� ũ�ų� ����, �Ҽ��̸� �Ӹ������ ���� ã�� ����, �鸸���� ū ������ Ž���Ѵ�.
    for (int i = N; i < 10000001; i++) {
        if (A[i] != 0 && isMinPalindrome(to_string(i))) {
            cout << i;
            break;
        }
    }

    return 0;
}

bool isMinPalindrome(string num) {
    int left = 0;
    int right = num.size() - 1;

    while (left < right) {
        if (num[left] != num[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}