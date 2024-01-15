// Ʋ�� Ǯ��
// ��Ʈ��ŷ���� �����Ͽ���.
// �ݷʰ� �����Ѵ�.
// 10 
// 9
// 1 2 3 4 5 6 7 8 9
// �� : 11 / �� �� : 12

#include <iostream>
#include <vector>

using namespace std;

int N, M, num, tempN;
int jarisu = 0;
bool notIn[10] = { false, };
vector <int> v;
vector <int> combination;
int cnt = 2100000000;

void Backtracking(int depth, int index);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    tempN = N;

    while (tempN) {
        tempN /= 10;
        jarisu++;
    }

    for (int i = 0; i < M; i++) {
        cin >> num;

        notIn[num] = true;
    }

    for (int i = 0; i < 10; i++) {
        if (!notIn[i]) {
            v.push_back(i);
        }
    }

    // combination �迭�� N�� �ڸ��� ��ŭ�� ������ Ȯ���Ѵ�.
    combination.resize(jarisu);

    // 100�� ���, cnt�� 0�̹Ƿ� Backtracking�� ��ġ�� ����.
    if (N != 100) {
        Backtracking(0, 0);
    }
    else {
        cnt = 0;
    }

    cout << cnt;

    return 0;
}

// ������ ���� ������ ���Ͽ� gap�� ���� ��, �ּ����� gap�� ã�´�.
void Backtracking(int depth, int index) {
    if (depth == jarisu) {
        int number = 0;

        // ���� �������� ������ ���� �����
        for (int i = 0; i < combination.size(); i++) {
            number += combination[i];
            number *= 10;
        }

        number /= 10;

        // �ڸ�����ŭ ���ڸ� ������, +, -�� �� �� ������ �ϴ��� ī��Ʈ
        cnt = min(cnt, jarisu + abs(N - number));

        //for (int i = 0; i < combination.size(); i++) {
        //    cout << combination[i];
        //}

        //cout << '\n';

        return;
    }

    // ���� ���� �ߺ��� �����Ͽ� ���ڸ� �����ϴ� ����� ��� ���ϱ� ���� Backtracking�Լ��� �� �� ���
    for (int i = index; i < v.size(); i++) {
        combination[depth] = v[i];
        Backtracking(depth + 1, index + 1);
        Backtracking(depth + 1, index);
    }
}


// ���� Ǯ��
// �������� �־��� �ִ� ������ 5000000������, �� ������ �������� ��츦 �����ؾ� �ϱ� ������ ���������� ������ 1000000���� ������ �Ѵ�.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M, num, minimum;
bool notIn[10] = { false, };    // false�� ����� �����ϴ� ��ư, true�� �������� �ʴ� ��ư
vector <int> v;

bool check(int now);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> num;

        notIn[num] = true;
    }

    string st = to_string(N);

    // �켱, ���� 100�� ä�ο��� N �� ä�α��� �̵��ϱ� ���� ��ư�� ������ �ϴ� �ִ� Ƚ���� + Ȥ�� - ��ư���� ������ �ϴ� ����.
    // ���� 100-N�� ������ �ִ��� �ȴ�.
    minimum = abs(N - 100);

    // 500000�� �� ���� 1000000���� ����� �Ѵ�.
    for (int i = 0; i <= 1000000; i++) {
        // ���� ���� �ִ� ���ڰ� ���峭 ��ư�� �����ϰ� ���� ������ Ȯ���Ѵ�.
        if (check(i)) {
            // ��� ���峪�� ���� ��ư�̶��, abs(N - num) (+�Ǵ� - ��ư ���� Ƚ��) + ���� ���� �ִ� ������ ����(���� ��ư ���� Ƚ��)
            int tmp = abs(N - i) + to_string(i).size();
            minimum = min(minimum, tmp);
        }
    }

    cout << minimum << endl;

    return 0;
}

bool check(int now) {
    string s = to_string(now);

    // ���� �����ִ� ������ �� �ڸ����� Ȯ���Ѵ�.
    for (int i = 0; i < s.size(); i++) {
        // �������� �ʴ� ��ư�� �����ϴ� ���ڶ��, false�� �����Ѵ�.
        if (notIn[s[i] - 48]) {
            return false;
        }
    }

    // ��� �����ϴ� ��ư�̶�� true�� �����Ѵ�.
    return true;
}