#include <iostream>
#include <cmath>
#include <limits>
#include "Orlov_MathTask.h"

using namespace std;


int main()
{
    double x = inputAndValidateDouble("Введите вещественное число x: ");
    int y = inputAndValidateNatural("Введите натуральное число y: ");
    
    double rounded = roundToDigits(x, y);
    cout << "Число x, округленное до " << y << " разрядов: " << rounded << endl;
    
    double withoutInteger = dropIntegerPart(x);
    cout << "Число x без целой части: " << withoutInteger << endl;
    
    return 0;
}