#include <iostream>
#include <cmath>
#include <limits>

using namespace std;



double inputAndValidateDouble(const string& prompt)
{
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите корректное вещественное число." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}


int inputAndValidateNatural(const string& prompt)
{
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите натуральное число (целое > 0)." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}


int inputAndValidateInRange(const string& prompt, int min, int max)
{
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < min || value > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите число от " << min << " до " << max << "." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}


double roundToDigits(double x, int y)
{
    if (x == 0) return 0;
    double factor = pow(10, y - ceil(log10(fabs(x))));
    return round(x * factor) / factor;
}


double dropIntegerPart(double x)
{
    return x - static_cast<long long>(x);
}


