// Ʋ�� Ǯ��
// 1����� �Ʒ� ������ ���������� ���ڰ� ���� Ŀ���ٴ� �߸��� ���� ������ ������ �߻��ߴ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {

    // ������ �迭�� ��, �� ����
    long long N, k;
    long long max;
    long long sum = 0;
    long long prevSum = 0;
    int row = 1;
    int column;

    cin >> N >> k;

    // ����� �밢������ ���� �� ������ ������ �� ���� ������ ���� �� i��.
    max = 2 * N - 1;

    for (int i = max; i >= 1; i -= 2) {
        sum += i;

        if (k <= sum) {
            // �밢���� ������ ������ ���� �� ����
            column = k - prevSum;
            // column�� �밢�� �������κ��� �� ����ŭ �������ִ����� ��Ÿ����.
            column /= 2;
            // ��¥ column��ġ�� ��ȯ�Ѵ�.
            column += row;

            break;
        }

        // �� ��° �������� row��� ������ ���� �����ش�.
        row++;

        // ���� �ܰ��� ���� prevSum�� �����Ѵ�.
        prevSum = sum;
    }

    cout << row * column;
}


// ���� 
// https://hyeo-noo.tistory.com/64 ����

//N = 5, K = 17 �� �־����� ��.

//�� ������ �̺�Ž������ Ǯ�� ���ؼ� 5x5�� ������ 12�� ���� mid�� ��������(lo = 0, hi = 25)

//12�� �� ǥ���� �� ��°�ϱ� ?

//1���� ��� 12���� ���ų� �۴�->cnt += 5
//2�൵ ��� 12���� ���ų� �۴�->cnt += 5
//3���� 4�������� 12���� ���ų� �۴�->cnt += 4
//4���� 3�������� 12���� ���ų� �۴�->cnt += 3
//5���� 2�������� 12���� ���ų� �۴�->cnt += 2
//cnt = 19�� �ǰ� K = 17���� ũ�� ������ mid���� ���ҽ��Ѿ� ���� �� �� �ִ�->hi = mid - 1, mid = (lo + hi) / 2 = 5

//mid��(lo + hi) / 2 �� �缳�����ְ� �� �۾��� �ݺ��ϸ� O(NlogK)���� K��° ���� ���� �� �ִ�.

#include <iostream>

using namespace std;

void Matrix_BS(long long N, long long K);
long long check_count(long long N, long long mid, long long K);

int main() {

    // ������ �迭�� ��, �� ����
    long long N, K;

    cin >> N >> K;

    // �� NlogN��ŭ�� �ð� ���⵵�� ���´�.
    Matrix_BS(N, K);
}

void Matrix_BS(long long N, long long K) {
    long long left = 1;
    long long right = N * N;

    long long answer = 0;

    // ����Ž���̹Ƿ� logN�� �ð� ���⵵�� ���´�.
    while (left <= right) {
        long long mid = (left + right) / 2;

        // mid���� �۰ų� ���� ���� ������ K���� ������, K��° ���� ��� ���� mid���� ũ�ٴ� ���̴�.
        // ���� left�� mid���� �ϳ� ũ�� �����Ѵ�.
        if (check_count(N, mid, K) < K)
            left = mid + 1;
        else {
            answer = mid;
            right = mid - 1;
        }
    }

    cout << answer;
}

// for���� ���� ������ N��ŭ�� �ð� ���⵵�� ���´�.
// mid���� �۰ų� ���� ���� ������ ����.
long long check_count(long long N, long long mid, long long K) {
    long long count = 0;

    for (int i = 1; i <= N; i++)
        // (�� �� ��ü ������ N)��, (�߰� �� / �ش� �� = �߰� ���� ��� ��ġ�� �ִ��� ��ȯ)�� ���Ͽ�, ���� ���� ���Ѵ�.
        count += min(N, mid / i);

    return count;
}