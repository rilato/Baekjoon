#include <iostream>

using namespace std;

void bar(int x);
void recursive(int x);

int n;

int main() {
    cin >> n;

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";

    recursive(n);
}

void bar(int x) {
    for (int i = 0; i < n - x; i++)cout << "____";
}

void recursive(int x) {
    bar(x);
    cout << "\"����Լ��� ������?\"\n";
    if (!x) {
        bar(x);
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        bar(x);
        cout << "��� �亯�Ͽ���.\n";
        return;
    }
    bar(x);
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    bar(x);
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    bar(x);
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    recursive(x - 1);
    bar(x);
    cout << "��� �亯�Ͽ���.\n";
}