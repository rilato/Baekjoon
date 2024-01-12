// ���� Ǯ������, �쿬�� ���� Ǯ��

#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N + 1);

    v[1] = 3;
    v[2] = 7;

    for (int i = 3; i <= N; i++) {
        v[i] = (v[i - 1] * 2 + v[i - 2]) % 9901;
    }

    cout << v[N] % 9901;

    return 0;
}

// ���� Ǯ��
// https://yabmoons.tistory.com/137

#include <iostream>
#include <vector>

using namespace std;

int N;
vector <vector <int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N + 1, vector <int>(3));

    // v[N][0] : N��° �ٿ� ���ڸ� ��ġ���� �ʴ� ���
    // v[N][1] : N��° �ٿ��� ���ʿ� ���ڸ� ��ġ�ϴ� ���
    // v[N][2] : N��° �ٿ��� �����ʿ� ���ڸ� ��ġ�ϴ� ���

    v[1][0] = 1;    // N = 1�� ��, ���ڰ� ��ġ���� �ʴ� ���� 1�̴�.
    v[1][1] = 1;    // N = 1�� ��, ���ʿ� ���ڰ� ��ġ�Ǵ� ���� 1�̴�.
    v[1][2] = 1;    // N = 1�� ��, �����ʿ� ���ڰ� ��ġ�Ǵ� ���� 1�̴�.

    for (int i = 2; i <= N; i++) {
        // i��° �ٿ� ���ڰ� ��ġ���� �ʴ´ٸ�,
        // i - 1��° �ٿ����� ���ڰ� ��ġ���� �ʾƵ� �ǰ� (v[i - 1][0]),
        // ���ʿ� ���ڰ� ��ġ�Ǿ� �־ �ǰ� (v[i - 1][1]),
        // �����ʿ� ���ڰ� ��ġ�Ǿ� �־ �ȴ� (v[i - 1][2])
        v[i][0] = (v[i - 1][0] + v[i - 1][1] + v[i - 1][2]) % 9901;

        // i��° ��, ���ʿ� ���ڰ� ��ġ�ȴٸ�,
        // i - 1��° �ٿ����� ���ڰ� ��ġ���� �ʾƵ� �ǰ� (v[i - 1][0]),
        // �����ʿ� ���ڰ� ��ġ�Ǿ� �־ �ȴ� (v[i - 1][2])
        v[i][1] = (v[i - 1][0] + v[i - 1][2]) % 9901;

        // i��° ��, �����ʿ� ���ڰ� ��ġ�ȴٸ�,
        // i - 1��° �ٿ����� ���ڰ� ��ġ���� �ʾƵ� �ǰ� (v[i - 1][0]),
        // ���ʿ� ���ڰ� ��ġ�Ǿ� �־ �ȴ� (v[i - 1][1])
        v[i][2] = (v[i - 1][0] + v[i - 1][1]) % 9901;
    }

    cout << (v[N][0] + v[N][1] + v[N][2]) % 9901;

    return 0;
}