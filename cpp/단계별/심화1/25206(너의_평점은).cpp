#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double sum = 0;
    double cnt = 0;
    string subject, grade;
    double subjectTime;

    for (int i = 0; i < 20; i++) {
        cin >> subject >> subjectTime >> grade;

        cnt += subjectTime;

        if (grade == "A+") {
            sum += subjectTime * 4.5;
        }
        else if (grade == "A0") {
            sum += subjectTime * 4.0;
        }
        else if (grade == "B+") {
            sum += subjectTime * 3.5;
        }
        else if (grade == "B0") {
            sum += subjectTime * 3.0;
        }
        else if (grade == "C+") {
            sum += subjectTime * 2.5;
        }
        else if (grade == "C0") {
            sum += subjectTime * 2.0;
        }
        else if (grade == "D+") {
            sum += subjectTime * 1.5;
        }
        else if (grade == "D0") {
            sum += subjectTime * 1.0;
        }
        else if (grade == "F") {
            sum += subjectTime * 0;
        }
        else if (grade == "P") {
            cnt -= subjectTime;
        }
    }

    cout << fixed;
    cout.precision(6);

    cout << (sum / cnt);

    return 0;
}